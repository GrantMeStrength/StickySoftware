// scooby.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "scooby.h"

#include "MainFrm.h"
#include "scoobyDoc.h"
#include "scoobyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoobyApp

BEGIN_MESSAGE_MAP(CScoobyApp, CWinApp)
	//{{AFX_MSG_MAP(CScoobyApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoobyApp construction

CScoobyApp::CScoobyApp(LPCTSTR lpszAppName)
	: CWinApp(lpszAppName)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CScoobyApp object

// WCE MFC apps require the application name to be specified in the CWinApp 
// constructor. A help contents filename may also be specified.

CScoobyApp theApp(_T("scooby"));

/////////////////////////////////////////////////////////////////////////////
// CScoobyApp initialization

BOOL CScoobyApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.

	//	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	//LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	struct HWND__ *tmp;

		if (tmp=FindWindow(NULL,_T("scooby")))
		{
			ShowWindow(tmp,SW_RESTORE);
			UpdateWindow(tmp);
			return FALSE;
		}

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CScoobyDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CScoobyView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	void NukeDialog();
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();		// Added for WCE apps
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CScoobyApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CScoobyApp commands
// Added for WCE apps

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CenterWindow();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DisplayAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CScooby dialog


CScooby::CScooby(CWnd* pParent /*=NULL*/)
	: CDialog(CScooby::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScooby)
	//}}AFX_DATA_INIT
}


void CScooby::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScooby)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScooby, CDialog)
	//{{AFX_MSG_MAP(CScooby)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScooby message handlers

int ypos=16;
HWND next=NULL;

void PrintText(CDC *pdc,CString text)
{
	CRect brect(10,ypos,240,ypos+16);
	pdc->SetTextColor(RGB(0,0,0));
	pdc->SetBkMode(TRANSPARENT);
	pdc->DrawText(text, brect, DT_LEFT | DT_SINGLELINE);
	ypos+=12;
}

char text[32][32];
int number[32];
int textcounter=0;
long int special[32];

long int magic=268435456;

BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{
	bool end=true;
	next=hwnd;
	long status;
	
//	special[textcounter]=GetWindowLong(next,GWL_EXSTYLE);
	special[textcounter]=GetWindowLong(next,GWL_STYLE);


	//if (GetWindowTextLength(next)!=0)
	if (special[textcounter]&0x10000000L)
	{

		char name[32];
		LPTSTR pointer=(LPTSTR)&name[0];
		GetWindowText(next,pointer,30);
		for (int i=0;i<30;i++)
			text[textcounter][i]=name[i];
		textcounter++;
			if (textcounter>20) textcounter=20;
	}
	

	//if (status&WS_MAXIMIZE)
	//{
			//SetForegroundWindow(next);
			//end=false;
			//sndPlaySound(L"alarm3", SND_FILENAME|SND_SYNC);
	//}


	return end;
}


void CScooby::OnButton1() 
{
	// List current window details
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	CString p;

	EnumWindows(EnumWindowsProc,NULL);


	for (int i=0;i<textcounter;i++)
	{
		p.Format(L"%s %X",text[i],special[i]);
		//p.Format(L"Hello");
		PrintText(&pdc,p);
	}
}

void CScooby::OnButton2() 
{
	// List all window details

		EnumWindows(EnumWindowsProc,NULL);
}


