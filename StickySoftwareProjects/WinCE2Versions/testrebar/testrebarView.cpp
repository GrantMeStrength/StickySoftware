// testrebarView.cpp : implementation of the CTestrebarView class
//

#include "stdafx.h"
#include "testrebar.h"

#include "testrebarDoc.h"
#include "testrebarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestrebarView

IMPLEMENT_DYNCREATE(CTestrebarView, CView)

BEGIN_MESSAGE_MAP(CTestrebarView, CView)
	//{{AFX_MSG_MAP(CTestrebarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestrebarView construction/destruction

CTestrebarView::CTestrebarView()
{
	// TODO: add construction code here

}

CTestrebarView::~CTestrebarView()
{
}

BOOL CTestrebarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestrebarView drawing

void CTestrebarView::OnDraw(CDC* pDC)
{
	CTestrebarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestrebarView diagnostics

#ifdef _DEBUG
void CTestrebarView::AssertValid() const
{
	CView::AssertValid();
}

void CTestrebarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestrebarDoc* CTestrebarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestrebarDoc)));
	return (CTestrebarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestrebarView message handlers
