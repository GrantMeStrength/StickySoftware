// TZ2View.cpp : implementation of the CTZ2View class
//

#include "stdafx.h"
#include "TZ2.h"

#include "TZ2Doc.h"
#include "TZ2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTZ2View

IMPLEMENT_DYNCREATE(CTZ2View, CView)

BEGIN_MESSAGE_MAP(CTZ2View, CView)
	//{{AFX_MSG_MAP(CTZ2View)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTZ2View construction/destruction

CTZ2View::CTZ2View()
{
}

CTZ2View::~CTZ2View()
{
}

BOOL CTZ2View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTZ2View drawing

void CTZ2View::OnDraw(CDC* pDC)
{
	CTZ2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CTZ2View diagnostics

#ifdef _DEBUG
void CTZ2View::AssertValid() const
{
	CView::AssertValid();
}

void CTZ2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTZ2Doc* CTZ2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTZ2Doc)));
	return (CTZ2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTZ2View message handlers
