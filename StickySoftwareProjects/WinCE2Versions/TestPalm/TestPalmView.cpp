// TestPalmView.cpp : implementation of the CTestPalmView class
//

#include "stdafx.h"
#include "TestPalm.h"

#include "TestPalmDoc.h"
#include "TestPalmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPalmView

IMPLEMENT_DYNCREATE(CTestPalmView, CView)

BEGIN_MESSAGE_MAP(CTestPalmView, CView)
	//{{AFX_MSG_MAP(CTestPalmView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPalmView construction/destruction

CTestPalmView::CTestPalmView()
{
}

CTestPalmView::~CTestPalmView()
{
}

BOOL CTestPalmView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestPalmView drawing

void CTestPalmView::OnDraw(CDC* pDC)
{
	CTestPalmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CTestPalmView diagnostics

#ifdef _DEBUG
void CTestPalmView::AssertValid() const
{
	CView::AssertValid();
}

void CTestPalmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestPalmDoc* CTestPalmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestPalmDoc)));
	return (CTestPalmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPalmView message handlers
