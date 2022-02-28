// TestProView.cpp : implementation of the CTestProView class
//

#include "stdafx.h"
#include "TestPro.h"

#include "TestProDoc.h"
#include "TestProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestProView

IMPLEMENT_DYNCREATE(CTestProView, CView)

BEGIN_MESSAGE_MAP(CTestProView, CView)
	//{{AFX_MSG_MAP(CTestProView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestProView construction/destruction

CTestProView::CTestProView()
{
}

CTestProView::~CTestProView()
{
}

BOOL CTestProView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestProView drawing

void CTestProView::OnDraw(CDC* pDC)
{
	CTestProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CTestProView diagnostics

#ifdef _DEBUG
void CTestProView::AssertValid() const
{
	CView::AssertValid();
}

void CTestProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestProDoc* CTestProView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestProDoc)));
	return (CTestProDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestProView message handlers
