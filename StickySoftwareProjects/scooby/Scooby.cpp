// scooby.cpp : Defines the class behaviors for the application.
//



#include "stdafx.h"
#include "scooby.h"

#include "MainFrm.h"
#include "scoobyDoc.h"
#include "scoobyView.h"


#define MAXAPP 300

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString path;

#define dim(x) (sizeof(x) / sizeof(x[0]))  
int SrchDirectory (LPTSTR pszDir);
int nTotal = 0;
int nFiles = 0;

int limit=0;		// limit cannot exceed 100 files


CString appnames[MAXAPP],tappnames[MAXAPP];
CString fullappnames[MAXAPP],tfullappnames[MAXAPP];
CString badnames[15];


int appcount=0;


bool settings[16];
CString userprogname[4];

extern void	CleanFiles();
extern void	CleanRegistry();
extern void CleanDatabase();

int current_button=0;
int buttons[4];
//CString current_text[8];

#define GRAPHIC 0
#define TASKS 1
#define VOICE 2
#define CHANNELS 3
#define NOTES 4
#define INBOX 5
#define CALCULATOR 6
#define CONTACTS 7
#define CALENDAR 8
#define USER1 9
#define USER2 10
#define USER3 11
#define USER4 12
#define DATE 13
#define UTILITIES 14
#define PILOT 15



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

CScoobyApp theApp(_T("BarneyButtons"));

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

	SetDialogBkColor(RGB(192,192,192),RGB(0,0,0));

	struct HWND__ *tmp;

		if (tmp=FindWindow(NULL,_T("BarneyButtons")))
		{
			ShowWindow(tmp,SW_SHOW);
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

//	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_USER1);
//	pCBox->AddString(L"List of Applications");

	
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
	m_calculator = settings[CALCULATOR];
	m_calendar = settings[CALENDAR];
	m_channels = settings[CHANNELS];
	m_contacts = settings[CONTACTS];
	m_inbox = settings[INBOX];
	m_notes = settings[NOTES];
	m_tasks = settings[TASKS];
	m_voice = settings[VOICE];
	m_graphic = settings[GRAPHIC];
	m_dropuser1 = -1;
	m_date = FALSE;
	m_utilities = FALSE;
	m_dropbut = -1;
	m_pilot = FALSE;
	//}}AFX_DATA_INIT
}


void CScooby::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CScooby)
	DDX_Check(pDX, IDC_CHECK_APP_CALCULATOR, m_calculator);
	DDX_Check(pDX, IDC_CHECK_APP_CALENDAR, m_calendar);
	DDX_Check(pDX, IDC_CHECK_APP_CHANNELS, m_channels);
	DDX_Check(pDX, IDC_CHECK_APP_CONTACTS, m_contacts);
	DDX_Check(pDX, IDC_CHECK_APP_INBOX, m_inbox);
	DDX_Check(pDX, IDC_CHECK_APP_NOTES, m_notes);
	DDX_Check(pDX, IDC_CHECK_APP_TASKS, m_tasks);
	DDX_Check(pDX, IDC_CHECK_APP_VOICE, m_voice);
	DDX_Check(pDX, IDC_CHECK_GRAPHIC, m_graphic);
	DDX_CBIndex(pDX, IDC_COMBO_USER1, m_dropuser1);
	DDX_Check(pDX, IDC_CHECK_DATE, m_date);
	DDX_Check(pDX, IDC_CHECK_UTILITIES, m_utilities);
	DDX_CBIndex(pDX, IDC_COMBO_BUTLIST, m_dropbut);
	DDX_Check(pDX, IDC_CHECK_PILOT, m_pilot);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScooby, CDialog)
	//{{AFX_MSG_MAP(CScooby)
	ON_BN_CLICKED(IDC_CHECK_GRAPHIC, OnCheckGraphic)
	ON_BN_CLICKED(IDC_CHECK_APP_VOICE, OnCheckAppVoice)
	ON_BN_CLICKED(IDC_CHECK_APP_TASKS, OnCheckAppTasks)
	ON_BN_CLICKED(IDC_CHECK_APP_CHANNELS, OnCheckAppChannels)
	ON_BN_CLICKED(IDC_CHECK_APP_CONTACTS, OnCheckAppContacts)
	ON_BN_CLICKED(IDC_CHECK_APP_INBOX, OnCheckAppInbox)
	ON_BN_CLICKED(IDC_CHECK_APP_NOTES, OnCheckAppNotes)
	ON_BN_CLICKED(IDC_CHECK_APP_CALENDAR, OnCheckAppCalendar)
	ON_BN_CLICKED(IDC_CHECK_APP_CALCULATOR, OnCheckAppCalculator)
	ON_BN_CLICKED(IDC_CHECK_APP_USER1, OnCheckAppUser1)
	ON_BN_CLICKED(IDC_CHECK_APP_USER2, OnCheckAppUser2)
	ON_BN_CLICKED(IDC_CHECK_APP_USER3, OnCheckAppUser3)
	ON_BN_CLICKED(IDC_CHECK_APP_USER4, OnCheckAppUser4)
	ON_BN_CLICKED(IDC_CHECK_DATE, OnCheckDate)
	ON_BN_CLICKED(IDC_CHECK_UTILITIES, OnCheckUtilities)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN, OnButtonClean)
	ON_CBN_CLOSEUP(IDC_COMBO_BUTLIST, OnCloseupComboButlist)
	ON_CBN_CLOSEUP(IDC_COMBO_USER1, OnCloseupComboUser1)
	ON_BN_CLICKED(IDC_CHECK_PILOT, OnCheckPilot)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScooby message handlers



void CScooby::OnCheckGraphic() 
{
	settings[GRAPHIC]=!settings[GRAPHIC];
}

void CScooby::OnCheckAppVoice() 
{
	settings[VOICE]=!settings[VOICE];
	
}

void CScooby::OnCheckAppTasks() 
{
	settings[TASKS]=!settings[TASKS];
	
}

void CScooby::OnCheckAppChannels() 
{
	settings[CHANNELS]=!settings[CHANNELS];
	
}

void CScooby::OnCheckAppContacts() 
{
	settings[CONTACTS]=!settings[CONTACTS];
	
}

void CScooby::OnCheckAppInbox() 
{
	settings[INBOX]=!settings[INBOX];
	
}

void CScooby::OnCheckAppNotes() 
{
	settings[NOTES]=!settings[NOTES];
	
}

void CScooby::OnCheckAppCalendar() 
{
	settings[CALENDAR]=!settings[CALENDAR];
	
}

void CScooby::OnCheckAppCalculator() 
{
	settings[CALCULATOR]=!settings[CALCULATOR];
}

void CScooby::OnCheckAppUser1() 
{
	settings[USER1]=!settings[USER1];
}

void CScooby::OnCheckAppUser2() 
{
	settings[USER2]=!settings[USER2];
}

void CScooby::OnCheckAppUser3() 
{
	settings[USER3]=!settings[USER3];	
}

void CScooby::OnCheckAppUser4() 
{
	settings[USER4]=!settings[USER4];	
}


void CScooby::OnCheckDate() 
{
	settings[DATE]=!settings[DATE];
}

void CScooby::OnCheckUtilities() 
{
	settings[UTILITIES]=!settings[UTILITIES];
	
}




	
	//
	//CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_USER1);
	//pCBox->AddString(L"List of Applications");

	//

CString trim (CString name)
{
	int nl=name.GetLength();
	if (nl<1) return "Error";

	CString justname="";
	name=name.Left(nl-4);
	
	for (int l=name.GetLength();l>0;l--)
	{
		if (name.GetAt(l-1)=='\\') break;
		justname+=name.GetAt(l-1);
	}
	justname.MakeReverse();
	return justname;
}

BOOL CScooby::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	return TRUE;

	int i,j,k;

	TCHAR plop[7];
	plop[0]='\\';
	plop[1]='*';
	plop[2]='.';
	plop[3]='l';
	plop[4]='n';
	plop[5]='k';
	plop[6]='\0';

	SetCursor((HCURSOR)IDC_WAIT);


#ifdef STICKYDEBUG	
	MessageBox(L"Search started..",L"Status report",MB_OK);
#endif

	limit=0;
	SrchDirectory (plop);

	/*
	CString ta;

	for (int a=0;a<20;a++)
	{
		ta.Format(L"Program %d",a);
		appnames[a]=ta;
		fullappnames[a]=ta;
	}
	nFiles=20;
	*/

	SetCursor(NULL);

#ifdef STICKYDEBUG	
	MessageBox(L"Search end..",L"Status report",MB_OK);
#endif

	badnames[1]="Task Manager";
	badnames[2]="Backlight";
	badnames[3]="Dialing";
	badnames[4]="PC Connection";
	badnames[5]="Double Tap";
	badnames[6]="Memory";
	badnames[7]="Sounds";
	badnames[8]="Help";
	badnames[9]="Power Off";
	badnames[0]="eventrst";

#ifdef STICKYDEBUG	
	MessageBox(L"Files filtered..",L"Status report",MB_OK);
#endif

	for (i=0;i<nFiles;i++)
		for (j=0;j<10;j++)
			if (tappnames[i]==badnames[j]) tappnames[i]="invalid";
	
	int dup;
	j=0;
	for (i=0;i<nFiles;i++)
	if (tappnames[i]!="invalid")
	{
		dup=0;
		for (k=0;k<i;k++)
			if (tappnames[i]==tappnames[k]) dup++;

		if (dup<1)
		{
			appnames[j]=tappnames[i];
			fullappnames[j++]=tfullappnames[i];
		}
	}
	nFiles=j;

#ifdef STICKYDEBUG	
	MessageBox(L"Files assigned..",L"Status report",MB_OK);
#endif

	CComboBox * pCBox1 = (CComboBox*)GetDlgItem(IDC_COMBO_USER1);


	pCBox1->AddString(L"< Not Active >");
	pCBox1->AddString(trim(userprogname[0]));

	for (i=0;i<nFiles;i++)
	{
		pCBox1->AddString(appnames[i]);
	}
	pCBox1->SetCurSel(buttons[0]);


	CString butname;
	CComboBox * pCButBox = (CComboBox*)GetDlgItem(IDC_COMBO_BUTLIST);
	for (i=1;i<5;i++)
	{
		butname.Format(L"Button %d",i);
		pCButBox->AddString(butname);
	}
	pCButBox->SetCurSel(0);


#ifdef STICKYDEBUG 
	MessageBox(L"Initialisation complete..",L"Status report",MB_OK);
#endif

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}




//----------------------------------------------------------------------
// SrchDirectory - Recursive routine that searches a dir and all
// child dirs for matching files
//
int SrchDirectory (LPTSTR pszDir) {
    WIN32_FIND_DATA fd;
    TCHAR szNew[MAX_PATH];
    INT i, rc, nErr = 0;
    HANDLE hFind;
    TCHAR *pPtr, *pSrcSpec;


//	if (limit>90) return -1;
	limit++;

    // Separate subdirectory from search specification.
    for (pSrcSpec = pszDir + lstrlen (pszDir); pSrcSpec >= pszDir; 
         pSrcSpec--)
        if (*pSrcSpec == TEXT ('\\'))
            break;

    // Copy the search specification up to the last directory
    // separation character.
    if (pSrcSpec <= pszDir)
        lstrcpy (szNew, TEXT ("\\"));
    else {
        for (i = 0; (i < dim(szNew)-10) && 
                    ((pszDir+i) <= pSrcSpec); i++)
            szNew[i] = *(pszDir+i);
        szNew[i] = TEXT ('\0');
    }
    pPtr = szNew + lstrlen (szNew);

    // Find matching files.
    hFind = FindFirstFile (pszDir, &fd);
    if (hFind != INVALID_HANDLE_VALUE) {

        do {
            // Report all matching files.
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
			{
                //wprintf (L"  %9d\t %s%s\n", fd.nFileSizeLow, szNew, 
                 //        fd.cFileName);

				//apppaths[appcount]=szNew;
				path=szNew;
				path+=fd.cFileName;
				tfullappnames[appcount]=path;
				path=fd.cFileName;
				tappnames[appcount++]=path.Left(path.GetLength()-4);
				if (appcount==MAXAPP) 
				{
					appcount=MAXAPP-1;
				}
				else
					nFiles++;


				//nTotal += fd.nFileSizeLow;
                
            }

            rc = FindNextFile (hFind, &fd);
        } while (rc);

        FindClose (hFind);
    } else {
        rc = GetLastError();
        if ((rc != ERROR_FILE_NOT_FOUND)  && 
            (rc != ERROR_NO_MORE_FILES)) {
            //wprintf (L"1Find Error.  Str:%s rc:%d", pszDir, rc);
            return -1;
        }
    }

    // Create generic search string for all directories.
    lstrcat (szNew, TEXT ("*.*"));

    hFind = FindFirstFile (szNew, &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // Recurse to the lower directory
                lstrcpy (pPtr, fd.cFileName);
                lstrcat (pPtr, pSrcSpec);
                nErr = SrchDirectory (szNew);
                if (nErr) break;
                *pPtr = TEXT ('\0');
            }
            rc = FindNextFile (hFind, &fd);
        } while (rc);

        FindClose (hFind);
    } else {
        rc = GetLastError();
        if ((rc != ERROR_FILE_NOT_FOUND) && 
            (rc != ERROR_NO_MORE_FILES)) {
           // wprintf (L"2Find Error:%d", rc);
            return -1;
        }
    }
    return nErr;
}


void CScooby::OnButtonClean() 
{

		// Nuke previous references

	if (IDCANCEL==MessageBox(L"If you tap OK, all files related to this program will be deleted. Ensure Sticky Buttons is the LAST entry in the Active Desktop list.",L"Purge!",MB_OKCANCEL ))
		return;
	CleanFiles();
	CleanRegistry();
	for (int i=1;i<5;i++)
		CleanDatabase();
	MessageBox(L"All done! Now Cancel the configuration program, and run Settings/Display.",L"Purge!");
}


void CScooby::OnCloseupComboButlist() 
{
	// Select button number
	CComboBox * pCButBox = (CComboBox*)GetDlgItem(IDC_COMBO_BUTLIST);
	current_button=pCButBox->GetCurSel();

	CComboBox * pCBox1 = (CComboBox*)GetDlgItem(IDC_COMBO_USER1);

	// Delete current number 1 and add userprogram instead
	
	pCBox1->DeleteString(1);
	pCBox1->InsertString(1,trim(userprogname[current_button]));

	pCBox1->SetCurSel(buttons[current_button]);
	
	
}

void CScooby::OnCloseupComboUser1() 
{
		CComboBox * pCBox1 = (CComboBox*)GetDlgItem(IDC_COMBO_USER1);
		int b=pCBox1->GetCurSel();
		buttons[current_button]=b;
		if (b==0) settings[USER1+current_button]=false; 
		else settings[USER1+current_button]=true;
}

void CScooby::OnCheckPilot() 
{
		settings[PILOT]=!settings[PILOT];
	
}
