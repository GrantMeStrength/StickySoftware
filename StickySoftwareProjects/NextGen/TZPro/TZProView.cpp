// TZProView.cpp : implementation of the CTZProView class
//

#include "stdafx.h"
#include "TZPro.h"

#include "TZProDoc.h"
#include "TZProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTZProView

IMPLEMENT_DYNCREATE(CTZProView, CView)

BEGIN_MESSAGE_MAP(CTZProView, CView)
	//{{AFX_MSG_MAP(CTZProView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTZProView construction/destruction

CTZProView::CTZProView()
{
}

CTZProView::~CTZProView()
{
}

BOOL CTZProView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTZProView drawing

void CTZProView::OnDraw(CDC* pDC)
{
	CTZProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CTZProView diagnostics

#ifdef _DEBUG
void CTZProView::AssertValid() const
{
	CView::AssertValid();
}

void CTZProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTZProDoc* CTZProView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTZProDoc)));
	return (CTZProDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTZProView message handlers
