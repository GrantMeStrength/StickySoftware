// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Piano.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Array tbSTDButton contains relevant buttons of bitmap IDB_STD_SMALL_COLOR

static TBBUTTON g_tbSTDButton[] = {
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0},  
//	{0,	ID_FILE_NEW,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, ID_FILE_OPEN,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{1, ID_FILE_SAVE,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
	{2, IDM_RECORD,		TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{3, IDM_PLAY,		TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{4, IDM_STOP,		TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0, -1},
//	{6, ID_APP_ABOUT,	TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, -1},
//	{0, 0,				TBSTATE_ENABLED, TBSTYLE_SEP,    0, 0, 0,  0}
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Global help commands
	//ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
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
					   IDR_MAINFRAME,	                       // toolbar bitmap
			           5 ))                                    // NImages
	{
		TRACE0("Failed to add command bar buttons\n");
		return -1;
	}

	// Add Exit and Help buttons
	//if (!AddAdornments( CMDBAR_HELP ))
	//{
//		TRACE0("Failed to add exit and help buttons\n");
//		return -1; 
//	}


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

