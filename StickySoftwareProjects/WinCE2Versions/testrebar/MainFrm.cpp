// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "testrebar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// Array tbSTDButton contains relevant buttons of bitmap IDB_STD_SMALL_COLOR


extern HINSTANCE g_hInstance;
extern HWND g_pWindow;
#define BANDS_ID 42
#define ID_MENUBAND 43
#define ID_BUTTONBAND 44

static TBBUTTON g_tbSTDButton[] = {
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0},  
	{0,	ID_FILE_NEW,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{1, ID_FILE_OPEN,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{2, ID_FILE_SAVE,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{3, ID_EDIT_CUT,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{4, ID_EDIT_COPY,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{5, ID_EDIT_PASTE,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{6, ID_APP_ABOUT,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0}
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;


	INITCOMMONCONTROLSEX icex;
	icex.dwSize = sizeof (icex);
	icex.dwICC = ICC_BAR_CLASSES | ICC_COOL_CLASSES;
	InitCommonControlsEx(&icex);
	
	HWND hwndCmdBands, hwnd;
	REBARBANDINFO arbbi[2];

	HIMAGELIST himl = ImageList_Create(16,16,ILC_COLOR, 2, 0);
	hwndCmdBands = CommandBands_Create(g_hInstance,g_pWindow,BANDS_ID,RBS_VARHEIGHT | RBS_BANDBORDERS, himl);

	arbbi[0].cbSize=sizeof(REBARBANDINFO);
	arbbi[0].fMask=RBBIM_ID | RBBIM_STYLE | RBBIM_SIZE | RBBIM_IMAGE ;
	arbbi[0].fStyle=RBBS_NOGRIPPER;
	arbbi[0].wID=ID_MENUBAND;
	arbbi[0].cx=100;
	arbbi[0].iImage=0;

	arbbi[1].cbSize=sizeof(REBARBANDINFO);
	arbbi[1].fMask=RBBIM_ID | RBBIM_SIZE | RBBIM_IMAGE ;
	arbbi[1].wID=ID_BUTTONBAND;
	arbbi[1].cx=125;
	arbbi[1].iImage=1;

	CommandBands_AddBands(hwndCmdBands, g_hInstance, 2, arbbi);

	hwnd=CommandBands_GetCommandBar(hwndCmdBands,0);
	CommandBar_InsertMenubar(hwnd,g_hInstance,IDR_MAINFRAME,0);

	hwnd=CommandBands_GetCommandBar(hwndCmdBands,1);
	CommandBar_AddBitmap(hwnd,HINST_COMMCTRL,IDB_STD_SMALL_COLOR,0,0,0);
	CommandBar_AddButtons(hwnd,sizeof(g_tbSTDButton)/sizeof(TBBUTTON),g_tbSTDButton);

	CommandBands_AddAdornments(hwndCmdBands, g_hInstance, CMDBAR_HELP,NULL);

	// Add the buttons to the CommandBar.
	// NOTE: In order for AddAdornments() to work properly, NImages must be
	//       the true number of button images in the bitmap file (even if not
	//       all of them are used).
	/*
	if (!InsertButtons( g_tbSTDButton,
		sizeof(g_tbSTDButton)/sizeof(TBBUTTON),		// NButtons
		IDR_MAINFRAME,					// toolbar bitmap
		7 ))						// NImages
	{
		TRACE0("Failed to add command bar buttons\n");
		return -1;
	}
	*/

	// Add Exit button

	/*
	if (!AddAdornments(0))
	{
		TRACE0("Failed to add exit button\n");
		return -1;      // fail to create command bar
	}
	*/

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

