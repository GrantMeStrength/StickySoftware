// CamLink1View.cpp : implementation of the CCamLink1View class
//

#include "stdafx.h"
#include "CamLink1.h"

#include "CamLink1Doc.h"
#include "CamLink1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


HANDLE hFile=NULL;

extern void InitPanel(CDC *pDC);
extern void Display (CDC *pDC);
extern void DisplayBars (CDC *pDC);
extern void DrawThumb(CDC *pDC);
extern void Draw(CDC *pDC);


/////////////////////////////////////////////////////////////////////////////
// CCamLink1View

IMPLEMENT_DYNCREATE(CCamLink1View, CView)

BEGIN_MESSAGE_MAP(CCamLink1View, CView)
	//{{AFX_MSG_MAP(CCamLink1View)
	ON_COMMAND(ID_MENU_CLOSE, OnMenuClose)
	ON_COMMAND(ID_MENU_SNAP, OnMenuSnap)
	ON_COMMAND(ID_MENU_OPEN_96, OnMenuOpen96)
	ON_UPDATE_COMMAND_UI(ID_MENU_OPEN_96, OnUpdateMenuOpen96)
	ON_COMMAND(ID_MENU_DOWNALL, OnMenuDownall)
	ON_COMMAND(ID_MENU_DOWNLOAD, OnMenuDownload)
	ON_COMMAND(ID_MENU_ERASE, OnMenuErase)
	ON_COMMAND(ID_MENU_NEXT, OnMenuNext)
	ON_COMMAND(ID_MENU_OPEN_115, OnMenuOpen115)
	ON_COMMAND(ID_MENU_OPEN_192, OnMenuOpen192)
	ON_COMMAND(ID_MENU_OPEN_384, OnMenuOpen384)
	ON_COMMAND(ID_MENU_OPEN_576, OnMenuOpen576)
	ON_UPDATE_COMMAND_UI(ID_MENU_OPEN_115, OnUpdateMenuOpen115)
	ON_UPDATE_COMMAND_UI(ID_MENU_OPEN_192, OnUpdateMenuOpen192)
	ON_UPDATE_COMMAND_UI(ID_MENU_OPEN_384, OnUpdateMenuOpen384)
	ON_UPDATE_COMMAND_UI(ID_MENU_OPEN_576, OnUpdateMenuOpen576)
	ON_COMMAND(ID_MENU_PREV, OnMenuPrev)
	ON_COMMAND(ID_MENU_RESOLUTION, OnMenuResolution)
	ON_UPDATE_COMMAND_UI(ID_MENU_RESOLUTION, OnUpdateMenuResolution)
	ON_COMMAND(ID_MENU_THUMB, OnMenuThumb)
	ON_COMMAND(ID_TOOLBAR_NEXT, OnToolbarNext)
	ON_COMMAND(ID_TOOLBAR_PREV, OnToolbarPrev)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamLink1View construction/destruction

CCamLink1View::CCamLink1View()
{
	// TODO: add construction code here

}

CCamLink1View::~CCamLink1View()
{
}

BOOL CCamLink1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCamLink1View drawing

void CCamLink1View::OnDraw(CDC* pDC)
{
	CCamLink1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// this is what is called every refresh
	Display(pDC);
	
}

/////////////////////////////////////////////////////////////////////////////
// CCamLink1View diagnostics

#ifdef _DEBUG
void CCamLink1View::AssertValid() const
{
	CView::AssertValid();
}

void CCamLink1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCamLink1Doc* CCamLink1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCamLink1Doc)));
	return (CCamLink1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////

//
// Camera control strings...
// Most common to both DC20 and DC25
//

char camera[12][8] = {
	{0x41,0,0x96,0,0,0,0,0x1a}, // 0 Init 9600
	{0x41,0,0x96,0,0,0,0,0x1a}, // 1 Init 19200
	{0x41,0,0x96,0,0,0,0,0x1a}, // 2 Init 38400
	{0x41,0,0x96,0,0,0,0,0x1a}, // 3 Init 57600
	{0x41,0,0x96,0,0,0,0,0x1a}, // 4 Init 115200
	{0x77,0,0,0,0,0,0,0x1a},	// 5 Take picture
	{0x7f,0,0,0,0,0,0,0x1a},	// 6 Return Status
	{0x7a,0,0,0,0,0,0,0x1a},	// 7 Erase memory
	{0x51,0,0,0,0,0,0,0x1a},	// 8 Download picture
	{0x56,0,0,0,0,0,0,0x1a},	// 9 Download thumbnail
	{0x71,0,0,0,0,0,0,0x1a},	// 10 High res
	{0x71,0,1,0,0,0,0,0x1a},	// 11 Low res
	};
	

/////

extern bool valid;
extern int error;			// Display error number
extern int model;			// Camera model
extern long baud;			// Camera connection speed
extern int flash;			// Camera's flash mode		
extern bool resolution;		// Camera's resolution (DC20)
extern int hi_pic_gone;		// Number of hi-res pictures taken
extern int lo_pic_gone;		// Number of lo-res pictures taken
extern int hi_pic_free;		// Number of hi-res pictures free
extern int lo_pic_free;		// Number of lo-res pictures free
extern int all_pic_gone;	// Number of pictures taken
extern int all_pic_free;	// Number of pictures free
extern bool battery;		// battery state (DC20)
extern int current_picture;	// Pic to be displayed, downloaded etc

DWORD currentbaud=9600;

BYTE picsdata1[124928];		// Ooo.. never heard of dynamic
							// memory allocation, then?
							// This bugger stores the downloaded
							// image and thumbnail data -- only
							// either, not both.


int GetAck()
{
	unsigned long bytesread;
	char pBuffer[2];
	BYTE b;
	ReadFile(hFile,pBuffer,1,&bytesread,NULL);
	b=pBuffer[0];
	if (b==0xd1) return true; else return false;
	//MessageBox("No Ack","Comms Report",MB_OK);
}

bool GetZero()
{
	unsigned long bytesread;
	char pBuffer[2];
	BYTE b;
	ReadFile(hFile,pBuffer,1,&bytesread,NULL);
	b=pBuffer[0];
	if (b==0) return true; else return false;
	//MessageBox("No Zero","Comms Report",MB_OK);
}


bool SendCommand(int n)
{
	// Send a command to the camera
	unsigned long byteswritten=0;
	WriteFile(hFile,&camera[n],8,&byteswritten,NULL);
	if (byteswritten==8) return true; else return false;
	//MessageBox("Unable to send eight bytes","Comms Report",MB_OK);
}


bool SendByte(char n)
{
	// Send a command to the camera
	unsigned long byteswritten=0;
	WriteFile(hFile,&n,1,&byteswritten,NULL);
	if (byteswritten==1) return true; else return false;
	//MessageBox("Unable to send a byte","Comms Report",MB_OK);
}

int GetStatus()
{
	// Get and display camera status

	char pBuffer[260];
	unsigned long bytesread;

	valid=false;

	if (!SendCommand(6)) return 10;


	// Must treat the Ack as a part of the 
	// incoming status block, or camera loses
	// sync with serial port. Stupid serial ports,
	// I hate them. Give me a flash card any day.


	//if (!GetAck()) return 11;

	ReadFile(hFile,&pBuffer[0],258,&bytesread,NULL);
	if (bytesread!=258) return bytesread+1000;

	if (!SendByte(0xd2)) return 13;
	if (!GetZero()) return 14;

	if (pBuffer[2]==0x20) model=20; else model=25;
	if (pBuffer[30]==1) battery=false; else battery=true;


	if (model==20)	// DC20
	{
		if (pBuffer[24]==0) resolution=true; else resolution=true;
		all_pic_gone=pBuffer[10];
		all_pic_free=pBuffer[12];
	}
	else			// DC25
	{
		hi_pic_gone=pBuffer[18];
		lo_pic_gone=pBuffer[20];
		hi_pic_free=pBuffer[22];
		lo_pic_free=pBuffer[24];
		flash=pBuffer[10];
	}

	valid=true;
	return 15;
}





int GetThumb25(char n)
{

	// Download a thumbnail

	unsigned long bytesread;

	camera[9][3]=n;		// Set the picture to download

	if (!SendCommand(9)) return 20;

	if (!GetAck()) return 21;
	// Assume the ack is part of it...

	int a=0,i;

	for (i=0;i<15;i++)
	{
	ReadFile(hFile,&picsdata1[a],1024,&bytesread,NULL);
	GetZero(); 
	if (!SendByte(0xd2)) return 200+i;//10000+bytesread;
	if (bytesread!=1024) return 10000+bytesread;// bytesread;
	a=a+1024;
	}
	GetZero(); 
	return 99;	
}


int GetThumb20(char n)
{
	// Download a thumbnail

	unsigned long bytesread;

	camera[9][3]=n;		// Set the picture to download

	if (!SendCommand(9)) return 20;

	if (!GetAck()) return 21;
	// Assume the ack is part of it...


	ReadFile(hFile,&picsdata1[0000],1024,&bytesread,NULL);	GetZero(); if (!SendByte(0xd2)) return 23;
	ReadFile(hFile,&picsdata1[1024],1024,&bytesread,NULL);	GetZero(); if (!SendByte(0xd2)) return 23;
	ReadFile(hFile,&picsdata1[2048],1024,&bytesread,NULL);	GetZero(); if (!SendByte(0xd2)) return 23;
	ReadFile(hFile,&picsdata1[3072],1024,&bytesread,NULL);	GetZero(); if (!SendByte(0xd2)) return 23;
	ReadFile(hFile,&picsdata1[4096],1024,&bytesread,NULL);	GetZero(); if (!SendByte(0xd2)) return 23;

	if (!GetZero()) return 22;
	return 29;
}

int GetThumb(char n)
{
	// Download the thumbnail view

	if (model==20)
		return GetThumb20(n);
	else
		return GetThumb25(n);
}


int GetPicture(char n)
{
	// Download the picture `n`...

	unsigned long bytesread;
	camera[8][3]=n;	
	if (!SendCommand(8)) return 40;
	if (!GetAck()) return 41;


	long a=0;
	int i;

	for (i=0;i<61;i++)
	{

		ReadFile(hFile,&picsdata1[a],1024,&bytesread,NULL);
		GetZero(); 
		if (!SendByte(0xd2)) return 800+i;//10000+bytesread;
		a+=1024;
	}

	a=62464;

	if (picsdata1[4]==0)
	{
		for (i=0;i<61;i++)
		{	
			ReadFile(hFile,&picsdata1[a],1024,&bytesread,NULL);
			GetZero(); 
			if (!SendByte(0xd2)) return 800+i;//10000+bytesread;
			a+=1024;
		}
	}
	
	GetZero();
	return -99;
}

bool OpenPort(DWORD baudrate)
{
	DCB		PortDCB;
	COMMTIMEOUTS CommTimeouts;
    PortDCB.DCBlength = sizeof(DCB);

	// Open the serial port
	
	hFile=CreateFile(L"COM1:",
		GENERIC_READ|GENERIC_WRITE,
		0,NULL,OPEN_EXISTING,0,NULL);
	
	if (!hFile)	return false;		// Failure to open port
		

	// Set port settings

	// Get the port info.
    GetCommState(hFile, &PortDCB);

	PortDCB.BaudRate = baudrate; //9600;
	PortDCB.fBinary = TRUE;
	PortDCB.fParity = TRUE;
	PortDCB.fOutxCtsFlow    = FALSE;  // ignore possible hangups
	PortDCB.fOutxDsrFlow    = FALSE;    // don't wait on the DSR line
	PortDCB.fDtrControl     = DTR_CONTROL_DISABLE;// DTR_CONTROL_ENABLE;
	PortDCB.fDsrSensitivity = FALSE;
	PortDCB.fTXContinueOnXoff = TRUE;
	PortDCB.fOutX           = FALSE; // no XON/XOFF control
	PortDCB.fInX            = FALSE;
	PortDCB.fErrorChar      = FALSE;
	PortDCB.fNull           = FALSE;
	PortDCB.fRtsControl     = RTS_CONTROL_ENABLE;
	PortDCB.fAbortOnError   = FALSE;
	PortDCB.ByteSize        = 8;
	PortDCB.Parity          = EVENPARITY;
	PortDCB.StopBits        = ONESTOPBIT;

	SetCommState(hFile, &PortDCB);

	// Should we initialize the parameters?
//	if (!EscapeCommFunction (hFile, CLRIR)) MessageBox(L"Error CLRIR",L"Comms Report",MB_OK);
//	EscapeCommFunction (hFile, CLRRTS);
//	EscapeCommFunction (hFile, CLRDTR);

	EscapeCommFunction (hFile, CLRIR);

	GetCommTimeouts (hFile, &CommTimeouts);
    CommTimeouts.ReadIntervalTimeout = 100;
    CommTimeouts.ReadTotalTimeoutMultiplier = 200; // was 1000;
    CommTimeouts.ReadTotalTimeoutConstant = 5000;	// Read timeout at 50msec
	SetCommTimeouts (hFile, &CommTimeouts);

	return true;
}

bool InitCamera(DWORD baudrate)
{
	int command;

	switch (baudrate) {
		case 9600:command=0;break;
		case 19200:command=1;break;
		case 38400:command=2;break;
		case 57600:command=3;break;
		case 115200:command=4;break;
		default:command=0;break;
	}

	if (!SendCommand(command)) return false;
	if (!GetAck()) return false; // Ack at old rate
	baud=baudrate;
	return true;
}

int ChangeBaudrate(DWORD baudrate)
{
	// Port is open

	// 1. Tell camera new speed
	// 2. Close port
	// 3. Re-open port at new speed
	// 4. Perform Status

	if (!InitCamera(baudrate)) return 5;
	CloseHandle(hFile);
	hFile=NULL;
	if (!OpenPort(baudrate)) return 6;

	return 7;
}

int OpenAndInit(DWORD baudrate)
{
	
	// If serial port is already open, close it first

	if (hFile!=NULL)
	{
		// Already open, goto Change
		return ChangeBaudrate(baudrate);
	}



	// If not opening at 9600, must open at this
	// speed first...

	// 2. Initialise the serial port
	
	if (!OpenPort(baudrate)) return 1;

	// 3. Initialise the camera

	if (!InitCamera(baudrate)) return 2;

	return 3;

}


/////////////////////////////////////////////////////////////
// CCamLink1View message handlers
/////////////////////////////////////////////////////////////


void CCamLink1View::OnMenuClose() 
{
	// Close the serial port
	
	CloseHandle(hFile);
	hFile=NULL;
}




void CCamLink1View::OnMenuSnap() 
{
	// Tell camera to take a picture

	if (!SendCommand(5)) MessageBox(L"Error Snap",L"Comms Report",MB_OK);
	if (!GetAck()) MessageBox(L"Error Ack",L"Comms Report",MB_OK);
	// Possible delay
	if (!GetZero()) MessageBox(L"Error Zero",L"Comms Report",MB_OK);

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
	

}


void CCamLink1View::OnMenuDownall() 
{

	// Test greyscale

	CClientDC pDC(this);
	DisplayBars(&pDC);
	
}

void CCamLink1View::OnMenuDownload() 
{
	// TODO: Add your command handler code here
	
}

void CCamLink1View::OnMenuErase() 
{
	// TODO: Add your command handler code here
	
}

void CCamLink1View::OnMenuNext() 
{
	current_picture++;	
	CClientDC pDC(this);
	Display(&pDC);
	
}


void CCamLink1View::OnMenuOpen96() 
{
	// Initialize the port info.

	currentbaud=9600;

	if (!OpenAndInit(currentbaud))
		MessageBox(L"Cannot open link to camera at 9600.",L"Comms Report",MB_OK);

	error=0;
	error=GetStatus();
		
	CClientDC pDC(this);

	InitPanel(&pDC);

	Display(&pDC);
	
}


void CCamLink1View::OnMenuOpen115() 
{
	currentbaud=115200;

	if (!OpenAndInit(currentbaud))
		MessageBox(L"Cannot open link to camera at 19200.",L"Comms Report",MB_OK);

	error=GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
	
	
}

void CCamLink1View::OnMenuOpen192() 
{
	currentbaud=19200;

	error=OpenAndInit(currentbaud);

	if (error>2)
	{
		MessageBox(L"Cannot open link to camera at 19200.",L"Comms Report",MB_OK);
	}

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
	
	
}



void CCamLink1View::OnMenuOpen384() 
{
	currentbaud=38400;

	if (!OpenAndInit(currentbaud))
		MessageBox(L"Cannot open link to camera at 38400.",L"Comms Report",MB_OK);

	error=GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
	
}

void CCamLink1View::OnMenuOpen576() 
{
	currentbaud=57600;


	if (!OpenAndInit(currentbaud))
		MessageBox(L"Cannot open link to camera at 38400.",L"Comms Report",MB_OK);

	error=GetStatus();
	CClientDC pDC(this);
	Display(&pDC);

	
}


void CCamLink1View::OnUpdateMenuOpen96(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(currentbaud==9600);
	
}

void CCamLink1View::OnUpdateMenuOpen115(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(currentbaud==115200);	
}

void CCamLink1View::OnUpdateMenuOpen192(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(currentbaud==19200);	
	
}

void CCamLink1View::OnUpdateMenuOpen384(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(currentbaud==38400);	
	
}

void CCamLink1View::OnUpdateMenuOpen576(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(currentbaud==57600);	
	
}

void CCamLink1View::OnMenuPrev() 
{
	current_picture--;	
	CClientDC pDC(this);
	Display(&pDC);
	
}

void CCamLink1View::OnMenuResolution() 
{
	// TODO: Add your command handler code here

	//MessageBox("Not implemented","Comms Report",MB_OK);
	
	CClientDC pDC(this);
	InitPanel(&pDC);
}

void CCamLink1View::OnUpdateMenuResolution(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	//MessageBox("Not implemented","Comms Report",MB_OK);

	
}

void CCamLink1View::OnMenuThumb() 
{
	// Get thumbnail

	error=GetThumb(current_picture);
	CClientDC pDC(this);
	Display(&pDC);
	DrawThumb(&pDC);
	
}

void CCamLink1View::OnToolbarNext() 
{
	current_picture++;	
	CClientDC pDC(this);
	Display(&pDC);
}

void CCamLink1View::OnToolbarPrev() 
{
	current_picture--;	
	CClientDC pDC(this);
	Display(&pDC);
	
}
