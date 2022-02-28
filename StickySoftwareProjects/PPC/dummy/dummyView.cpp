// dummyView.cpp : implementation of the CDummyView class
//

#include "stdafx.h"
#include "dummy.h"

#include "dummyDoc.h"
#include "dummyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDummyView

IMPLEMENT_DYNCREATE(CDummyView, CView)

BEGIN_MESSAGE_MAP(CDummyView, CView)
	//{{AFX_MSG_MAP(CDummyView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDummyView construction/destruction

CDummyView::CDummyView()
{
	// TODO: add construction code here

}

CDummyView::~CDummyView()
{
}

BOOL CDummyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDummyView drawing

void CDummyView::OnDraw(CDC* pDC)
{
	CDummyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDummyView diagnostics

#ifdef _DEBUG
void CDummyView::AssertValid() const
{
	CView::AssertValid();
}

void CDummyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDummyDoc* CDummyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDummyDoc)));
	return (CDummyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDummyView message handlers
