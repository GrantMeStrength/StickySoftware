// PowerWatchView.cpp : implementation of the CPowerWatchView class
//

#include "stdafx.h"
#include "PowerWatch.h"

#include "PowerWatchDoc.h"
#include "PowerWatchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchView

IMPLEMENT_DYNCREATE(CPowerWatchView, CView)

BEGIN_MESSAGE_MAP(CPowerWatchView, CView)
	//{{AFX_MSG_MAP(CPowerWatchView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchView construction/destruction

CPowerWatchView::CPowerWatchView()
{
	// TODO: add construction code here

}

CPowerWatchView::~CPowerWatchView()
{
}

BOOL CPowerWatchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchView drawing

void CPowerWatchView::OnDraw(CDC* pDC)
{
	CPowerWatchDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchView diagnostics

#ifdef _DEBUG
void CPowerWatchView::AssertValid() const
{
	CView::AssertValid();
}

void CPowerWatchView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPowerWatchDoc* CPowerWatchView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPowerWatchDoc)));
	return (CPowerWatchDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchView message handlers
