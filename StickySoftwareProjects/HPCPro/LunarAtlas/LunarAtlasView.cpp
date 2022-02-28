// LunarAtlasView.cpp : implementation of the CLunarAtlasView class
//

#include "stdafx.h"
#include "LunarAtlas.h"

#include "LunarAtlasDoc.h"
#include "LunarAtlasView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Toolbox.h"

extern void RefreshDisplay(CDC *pDC);
extern void RefreshCalculate(CDC *pDC);
extern void	GotoMouse(CDC *pDC,long x,long y);
extern void	FindMouse(CDC *pDC,long x,long y);

bool shift=false;
extern bool redraw;
extern bool moon_picture;
extern bool name_seas;
extern bool all_craters;

CToolBox* Tooladlg;
bool toolopen=false;

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasView

IMPLEMENT_DYNCREATE(CLunarAtlasView, CView)

BEGIN_MESSAGE_MAP(CLunarAtlasView, CView)
	//{{AFX_MSG_MAP(CLunarAtlasView)
	ON_COMMAND(IDD_OPEN_TOOLBOX, OnOpenToolbox)
	ON_UPDATE_COMMAND_UI(IDD_OPEN_TOOLBOX, OnUpdateOpenToolbox)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(IDD_GO_UP, OnGoUp)
	ON_COMMAND(IDD_GO_DOWN, OnGoDown)
	ON_COMMAND(IDD_GO_LEFT, OnGoLeft)
	ON_COMMAND(IDD_GO_RIGHT, OnGoRight)
	ON_COMMAND(IDD_MENU_IMAGE, OnMenuImage)
	ON_UPDATE_COMMAND_UI(IDD_MENU_IMAGE, OnUpdateMenuImage)
	ON_COMMAND(IDD_NAME_SEAS, OnNameSeas)
	ON_UPDATE_COMMAND_UI(IDD_NAME_SEAS, OnUpdateNameSeas)
	ON_COMMAND(IDD_ALL_CRATERS, OnAllCraters)
	ON_UPDATE_COMMAND_UI(IDD_ALL_CRATERS, OnUpdateAllCraters)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasView construction/destruction

CLunarAtlasView::CLunarAtlasView()
{
	// TODO: add construction code here

}

CLunarAtlasView::~CLunarAtlasView()
{
}

BOOL CLunarAtlasView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasView drawing

void CLunarAtlasView::OnDraw(CDC* pDC)
{
	CLunarAtlasDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	/*
	if (toolopen)
	{
		Tooladlg =new CToolBox;
		Tooladlg->Create(IDD_TOOLBOX_DIALOG,this);
		toolopen=true;	
	}
	*/
	// TODO: add draw code for native data here
	
	RefreshDisplay(pDC);

}

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasView diagnostics

#ifdef _DEBUG
void CLunarAtlasView::AssertValid() const
{
	CView::AssertValid();
}

void CLunarAtlasView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLunarAtlasDoc* CLunarAtlasView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLunarAtlasDoc)));
	return (CLunarAtlasDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasView message handlers

void CLunarAtlasView::OnOpenToolbox() 
{
	if (toolopen) 
	{	
		Tooladlg->KillDialog();
		toolopen=false;
		return;
	}
	Tooladlg =new CToolBox;
	Tooladlg->Create(IDD_TOOLBOX_DIALOG,this);
	toolopen=true;
}	



void CLunarAtlasView::OnUpdateOpenToolbox(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(toolopen);	
}

void CLunarAtlasView::OnLButtonDown(UINT nFlags, CPoint point) 
{

	// Name object at this location
	long x,y;
	CClientDC dc(this);
	CPoint pos = point;
	x=pos.x;
	y=pos.y;

	if (shift)
		GotoMouse(&dc,x,y);
	else
		FindMouse(&dc,x,y);

	CView::OnLButtonDown(nFlags, point);
}


void CLunarAtlasView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar==16) shift=true;	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLunarAtlasView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar==16) shift=false;	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CLunarAtlasView::OnGoUp() 
{
	// TODO: Add your command handler code here
	
}

void CLunarAtlasView::OnGoDown() 
{
	// TODO: Add your command handler code here
	
}

void CLunarAtlasView::OnGoLeft() 
{
	// TODO: Add your command handler code here
	
}

void CLunarAtlasView::OnGoRight() 
{
	// TODO: Add your command handler code here
	
}

void CLunarAtlasView::OnMenuImage() 
{
	moon_picture=!moon_picture;
	CClientDC dc(this);
	redraw=true;
	RefreshDisplay(&dc);
}

void CLunarAtlasView::OnUpdateMenuImage(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(moon_picture);	
	
}

void CLunarAtlasView::OnNameSeas() 
{
	name_seas=!name_seas;
	CClientDC dc(this);
	redraw=true;
	RefreshDisplay(&dc);
	
}

void CLunarAtlasView::OnUpdateNameSeas(CCmdUI* pCmdUI) 
{
		pCmdUI->SetCheck(all_craters);	
	
}

void CLunarAtlasView::OnAllCraters() 
{
	all_craters=!all_craters;
	CClientDC dc(this);
	redraw=true;
	RefreshDisplay(&dc);
	
}

void CLunarAtlasView::OnUpdateAllCraters(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(all_craters);
	
}
