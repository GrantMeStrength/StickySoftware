// ProjectGView.cpp : implementation of the CProjectGView class
//

#include "stdafx.h"
#include "ProjectG.h"

#include "ProjectGDoc.h"
#include "ProjectGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern double viewpoint1;
extern void DrawView(CDC *pDC);
extern void StartUp();

/////////////////////////////////////////////////////////////////////////////
// CProjectGView

IMPLEMENT_DYNCREATE(CProjectGView, CView)

BEGIN_MESSAGE_MAP(CProjectGView, CView)
	//{{AFX_MSG_MAP(CProjectGView)
	ON_COMMAND(ID_MENU_DRAW, OnMenuDraw)
	ON_COMMAND(ID_MENU_ANGLE1MINUS, OnMenuAngle1minus)
	ON_COMMAND(ID_MENU_ANGLE1PLUS, OnMenuAngle1plus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjectGView construction/destruction

CProjectGView::CProjectGView()
{
	//CClientDC aDC(this);
	StartUp();	

}

CProjectGView::~CProjectGView()
{
}

BOOL CProjectGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProjectGView drawing

void CProjectGView::OnDraw(CDC* pDC)
{
	CProjectGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProjectGView diagnostics

#ifdef _DEBUG
void CProjectGView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectGDoc* CProjectGView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectGDoc)));
	return (CProjectGDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProjectGView message handlers

void CProjectGView::OnMenuDraw() 
{
		// Draw current view

		CClientDC dc(this);
		DrawView(&dc);

}

void CProjectGView::OnMenuAngle1minus() 
{
		viewpoint1-=0.5;
		CClientDC dc(this);
		DrawView(&dc);
	
}

void CProjectGView::OnMenuAngle1plus() 
{
		viewpoint1+=0.5;
		CClientDC dc(this);
		DrawView(&dc);
	
}
