// ViewMark1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ViewMark1.h"

#include "MainFrm.h"
#include "ViewMark1Doc.h"
#include "ViewMark1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "globalstuff.h"
extern bool flags[33];
//extern int TipCount;

/////////////////////////////////////////////////////////////////////////////
// CViewMark1App

BEGIN_MESSAGE_MAP(CViewMark1App, CWinApp)
	//{{AFX_MSG_MAP(CViewMark1App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewMark1App construction

//CViewMark1App::CViewMark1App(LPCTSTR lpszAppName)
//	: CWinApp(lpszAppName)
//{
//	// TODO: add construction code here,
//	// Place all significant initialization in InitInstance
//}

CViewMark1App::CViewMark1App(LPCTSTR lpszAppName, LPCTSTR lpszHelpName)
	: CWinApp(lpszAppName, lpszHelpName)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CViewMark1App object

// WCE MFC apps require the application name to be specified in the CWinApp 
// constructor. A help contents filename may also be specified.

//CViewMark1App theApp(_T("PUniverse"), _T("puhelp.htc"));
CViewMark1App theApp(_T("Pocket Universe"), _T("puhelp.htc"));

 
/////////////////////////////////////////////////////////////////////////////
// CViewMark1App initialization

BOOL CViewMark1App::InitInstance()
{

	LoadStdProfileSettings();

	// Touch of class :-)
	SetDialogBkColor(RGB(192,192,192),RGB(0,0,0));


	struct HWND__ *tmp;

		if (tmp=FindWindow(NULL,_T("Pocket Universe")))
		{
			SetForegroundWindow(tmp);
			//ShowWindow(tmp,SW_RESTORE);
			//UpdateWindow(tmp);
			return FALSE;
		}

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CViewMark1Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CViewMark1View));
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
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckTip();
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
	ON_BN_CLICKED(IDC_CHECK_TIP, OnCheckTip)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CViewMark1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CViewMark1App commands

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (flags[TipsOn])	CheckDlgButton(IDC_CHECK_TIP,1);
	else CheckDlgButton(IDC_CHECK_TIP,0);

	int TipCount=Random()&15;

	switch (TipCount) {
	case 10:SetDlgItemText(IDC_TOP_TIP,L"Switch outlines on and stars off to make looking around the sky a lot quicker.");break;
	case 11:SetDlgItemText(IDC_TOP_TIP,L"Turn off planets if you don't need them, as this will speed up calculations.");break;
	case 12:SetDlgItemText(IDC_TOP_TIP,L"If you know the location of an object, use the Goto Ra/Dec dialog to enter the values.");break;
	case 13:SetDlgItemText(IDC_TOP_TIP,L"Remember to set Daylight Saving Time if necessary! It's in the Set Time/Date dialog.");break;
	case 1: SetDlgItemText(IDC_TOP_TIP,L"Visit the Sticky Net website for news on upgrades and new Windows CE programs.");break;
	case 15:SetDlgItemText(IDC_TOP_TIP,L"Switch on the 'Real Size' Display option for a more realistic view of the Sun and Moon.");break;
	case 14:SetDlgItemText(IDC_TOP_TIP,L"Remember to switch on parallax when viewing eclipse events.");break;
	case 2:	SetDlgItemText(IDC_TOP_TIP,L"Try and find as many Messier objects as you can in one night!");break;
	case 3:	SetDlgItemText(IDC_TOP_TIP,L"Toggle the outlines off and on to teach yourself the constellation names.");break;
	case 4:	SetDlgItemText(IDC_TOP_TIP,L"Hold down the shift key when pressing the cursor or zoom keys for larger steps.");break;
	case 5:	SetDlgItemText(IDC_TOP_TIP,L"Use the Toolbox to quickly zoom In and Out of the display.");break;
	case 6:	SetDlgItemText(IDC_TOP_TIP,L"Set up the Update feature, and Pocket Universe becomes a personal time machine!");break;
	case 7:	SetDlgItemText(IDC_TOP_TIP,L"Set Update to 5 second jumps every 5 seconds for a 'real time' view of the sky.");break;
	case 8:	SetDlgItemText(IDC_TOP_TIP,L"If you Goto an object and can't see  it, it could be hidden below the horizon.");break;
	case 9:	SetDlgItemText(IDC_TOP_TIP,L"Don't for get you can tap a location to centre it in the screen.");break;
	case 0: SetDlgItemText(IDC_TOP_TIP,L"If the sky looks wrong, double-check your TimeZone setting as well as your location.");break;
	default:break;
	}

	CenterWindow();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAboutDlg::OnCheckTip() 
{
		flags[TipsOn]=!flags[TipsOn];	
}

void DisplayAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
