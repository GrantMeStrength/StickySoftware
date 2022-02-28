// benchmarkView.cpp : implementation of the CBenchmarkView class
//

#include "stdafx.h"
#include "benchmark.h"

#include "benchmarkDoc.h"
#include "benchmarkView.h"

extern void StartTests(CDC *aDC);

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkView

IMPLEMENT_DYNCREATE(CBenchmarkView, CView)

BEGIN_MESSAGE_MAP(CBenchmarkView, CView)
	//{{AFX_MSG_MAP(CBenchmarkView)
	ON_COMMAND(ID_MENUITEM_START, OnMenuitemStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkView construction/destruction

CBenchmarkView::CBenchmarkView()
{
	// TODO: add construction code here

}

CBenchmarkView::~CBenchmarkView()
{
}

BOOL CBenchmarkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkView drawing

void CBenchmarkView::OnDraw(CDC* pDC)
{
	CBenchmarkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkView diagnostics

#ifdef _DEBUG
void CBenchmarkView::AssertValid() const
{
	CView::AssertValid();
}

void CBenchmarkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBenchmarkDoc* CBenchmarkView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBenchmarkDoc)));
	return (CBenchmarkDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkView message handlers

void CBenchmarkView::OnMenuitemStart() 
{
	// Start the tests!
	
	CClientDC aDC(this);
	StartTests(&aDC);

}
