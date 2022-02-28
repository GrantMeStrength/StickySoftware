// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "RegStuff.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Array tbSTDButton contains relevant buttons of bitmap IDB_STD_SMALL_COLOR

static TBBUTTON g_tbSTDButton[] = {
	//{0, 0,				  TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0},  
	{0,	ID_TASK_AUTOTIME, TBSTATE_ENABLED, TBSTYLE_CHECK,  0, 0, 0, -1},
	//{1, IDD_UPDATE_DIALOG,TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{1, IDD_FIND_DIALOG,  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{2, IDD_HOW_DIALOG,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{3, ID_TASK_OUTLINES, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{0, 0,				  TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{4, ID_TASK_INVERT,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{5, ID_TASK_STARS,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{6, ID_TASK_PLANETS,  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{7, ID_TASK_OUTLINES, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{8, ID_TASK_MESS,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{9, ID_TASK_LABELS,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	//{0, 0,				  TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	//{10, ID_HELP,		  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
//	{8, ID_APP_ABOUT,	  TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},

};


static TCHAR * tooltips[] = 
{
		L"",
		L"Start clock",
		L"Goto Object",
		L"Display Options",
		L"Toggle Constellations",
		L"Invert colours",
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
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
	
	// Add the buttons to the CommandBar.
	// NOTE: In order for AddAdornments() to work properly, NImages must be
	//       the true number of button images in the bitmap file (even if not
	//       all of them are used).
	if (!InsertButtons( g_tbSTDButton, 
			           sizeof(g_tbSTDButton)/sizeof(TBBUTTON), // NButtons
					   //IDR_MAINFRAME,	                       // toolbar bitmap
					   IDR_TOOLBAR,	                       // toolbar bitmap
					   5 ))                                    // NImages
	{
		TRACE0("Failed to add command bar buttons\n");
		return -1;
	}

	// Add Exit button
	if (!AddAdornments(0))
	{
		TRACE0("Failed to add exit button\n");
		return -1;      // fail to create command bar
	}

// trying tooltips

	CommandBar_AddToolTips(m_hCommandBar,13,tooltips);

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




void CMainFrame::OnClose() 
{

	// I think this happens when the user quits
	// the program, so it's here that I store
	// the current settings in the Registry
	
	//SaveInfo();

	// I've moved this information to
	// a menu option.

	CFrameWnd::OnClose();
}
