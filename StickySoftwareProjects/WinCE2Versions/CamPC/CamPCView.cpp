// CamPCView.cpp : implementation of the CCamPCView class
//

#include "stdafx.h"
#include "CamPC.h"

#include "CamPCDoc.h"
#include "CamPCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void InitPanel(CDC *pDC);

/////////////////////////////////////////////////////////////////////////////
// CCamPCView

IMPLEMENT_DYNCREATE(CCamPCView, CView)

BEGIN_MESSAGE_MAP(CCamPCView, CView)
	//{{AFX_MSG_MAP(CCamPCView)
	ON_COMMAND(ID_MENU_CLOSE, OnMenuClose)
	ON_COMMAND(ID_MENU_OPEN, OnMenuOpen)
	ON_COMMAND(ID_MENU_SNAP, OnMenuSnap)
	ON_COMMAND(ID_MENU_STATUS, OnMenuStatus)
	ON_COMMAND(ID_MENU_OPEN_192, OnMenuOpen192)
	ON_COMMAND(ID_MENU_OPEN_384, OnMenuOpen384)
	ON_COMMAND(ID_MENU_THUMB, OnMenuThumb)
	ON_COMMAND(ID_MENU_NEXT, OnMenuNext)
	ON_COMMAND(ID_MENU_PREV, OnMenuPrev)
	ON_COMMAND(ID_MENU_DRAW, OnMenuDraw)
	ON_COMMAND(ID_MENU_OPEN_576, OnMenuOpen576)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamPCView construction/destruction

CCamPCView::CCamPCView()
{
	// TODO: add construction code here

}

CCamPCView::~CCamPCView()
{
}

BOOL CCamPCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCamPCView drawing

void CCamPCView::OnDraw(CDC* pDC)
{
	CCamPCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCamPCView diagnostics

#ifdef _DEBUG
void CCamPCView::AssertValid() const
{
	CView::AssertValid();
}

void CCamPCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCamPCDoc* CCamPCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCamPCDoc)));
	return (CCamPCDoc*)m_pDocument;
}
#endif //_DEBUG


/////

extern int camdata[20];
extern int error;			// Display error number
extern int model;			// Camera model
extern long baud;			// Camera connection speed
extern int flash;			// Camera's flash mode		
extern bool resolution;		// Camera's resolution
extern int hi_pic_gone;		// Number of hi-res pictures taken
extern int lo_pic_gone;		// Number of lo-res pictures taken
extern int hi_pic_free;		// Number of hi-res pictures free
extern int lo_pic_free;		// Number of lo-res pictures free
extern int all_pic_gone;	// Number of pictures taken
extern int all_pic_free;	// Number of pictures free
extern bool battery;		// battery state
extern int current_picture;	// Pic to be displayed, downloaded etc
extern void Display (CDC *pDC);
extern void DrawThumb(CDC *pDC);
extern void Draw(CDC *pDC);

HANDLE hFile=NULL;

char camera[12][8] = {
	{0x41,0,0x96,0,0,0,0,0x1a}, // 0 Init 9600
	{0x41,0,0x19,0x20,0,0,0,0x1a}, // 1 Init 19200
	{0x41,0,0x38,0x40,0,0,0,0x1a}, // 2 Init 38400
	{0x41,0,0x57,0x60,0,0,0,0x1a}, // 3 Init 57600
	{0x41,0,0x11,0x52,0,0,0,0x1a}, // 4 Init 115200
	{0x77,0,0,0,0,0,0,0x1a},	// 5 Take picture
	{0x7f,0,0,0,0,0,0,0x1a},	// 6 Return Status
	{0x7a,0,0,0,0,0,0,0x1a},	// 7 Erase memory
	{0x51,0,0,0,0,0,0,0x1a},	// 8 Download picture
	{0x56,0,0,1,0,0,0,0x1a},	// 9 Download thumbnail
	{0x71,0,0,0,0,0,0,0x1a},	// 10 High res
	{0x71,0,1,0,0,0,0,0x1a},	// 11 Low res
	};
	
//BYTE thumbdata[15400];
BYTE picsdata1[124928];


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

	if (!SendCommand(6)) return 10;


	// Must treat the Ack as a part of the 
	// incoming status block

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

		for (int i=0;i<20;i++)
			camdata[i]=pBuffer[10+i];



	}

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
	
	hFile=CreateFile("COM1:",
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
//	if (!EscapeCommFunction (hFile, CLRIR)) MessageBox("Error CLRIR","Comms Report",MB_OK);
//	EscapeCommFunction (hFile, CLRRTS);
//	EscapeCommFunction (hFile, CLRDTR);

	GetCommTimeouts (hFile, &CommTimeouts);
    CommTimeouts.ReadIntervalTimeout = 100;
   CommTimeouts.ReadTotalTimeoutMultiplier = 1000;
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
		ChangeBaudrate(baudrate);
		return 4;
	}



	// If not opening at 9600, must open at this
	// speed first...

	// 2. Initialise the serial port
	
	if (!OpenPort(baudrate)) return 1;

	// 3. Initialise the camera

	if (!InitCamera(baudrate)) return 2;

	return 3;

}

/////////////////////////////////////////////////////////////////////////////
// CCamPCView message handlers

void CCamPCView::OnMenuClose() 
{
	// Close the serial port
	
	CloseHandle(hFile);
	hFile=NULL;
	
}



void CCamPCView::OnMenuOpen() 
{
	// Initialize the port info.

	DWORD baudrate=9600;

	if (!OpenAndInit(baudrate))
		MessageBox("Cannot open link to camera at 9600.","Comms Report",MB_OK);

	error=0;
	error=GetStatus();
		
	CClientDC pDC(this);

	InitPanel(&pDC);

	Display(&pDC);

}

void CCamPCView::OnMenuSnap() 
{
	// Tell camera to take a picture

	if (!SendCommand(5)) MessageBox("Error Snap","Comms Report",MB_OK);
	if (!GetAck()) MessageBox("Error Ack","Comms Report",MB_OK);
	// Possible delay
	if (!GetZero()) MessageBox("Error Zero","Comms Report",MB_OK);

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);

}

void CCamPCView::OnMenuStatus() 
{
	// Get and display camera status
	
	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
}

void CCamPCView::OnMenuOpen192() 
{
	DWORD baudrate=19200;

	/*
	int p;
	p=OpenAndInit(baudrate);
	char plop[6]="{*}\0";
	plop[1]=48+p;
	MessageBox(&plop[0],"Comms Report",MB_OK);
	return;
	*/

	if (!OpenAndInit(baudrate))
		MessageBox("Cannot open link to camera at 19200.","Comms Report",MB_OK);

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);
	
}

void CCamPCView::OnMenuOpen384() 
{
	DWORD baudrate=38400;

	/*
	int p;
	p=OpenAndInit(baudrate);
	char plop[6]="{*}\0";
	plop[1]=48+p;
	MessageBox(&plop[0],"Comms Report",MB_OK);
	return;
	*/

	if (!OpenAndInit(baudrate))
		MessageBox("Cannot open link to camera at 38400.","Comms Report",MB_OK);

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);

}

void CCamPCView::OnMenuThumb() 
{
	// Get thumbnail

	error=GetThumb(current_picture);
	CClientDC pDC(this);
	Display(&pDC);
	DrawThumb(&pDC);
}

void CCamPCView::OnMenuNext() 
{
	current_picture++;	
	CClientDC pDC(this);
	Display(&pDC);
}

void CCamPCView::OnMenuPrev() 
{
	current_picture--;	
	CClientDC pDC(this);
	Display(&pDC);
}

void CCamPCView::OnMenuDraw() 
{
	// Draw the downloaded image	
	GetPicture(current_picture);
	CClientDC pDC(this);
	Draw(&pDC);
}

void CCamPCView::OnMenuOpen576() 
{
	DWORD baudrate=57600;


	if (!OpenAndInit(baudrate))
		MessageBox("Cannot open link to camera at 38400.","Comms Report",MB_OK);

	GetStatus();
	CClientDC pDC(this);
	Display(&pDC);

	
}
