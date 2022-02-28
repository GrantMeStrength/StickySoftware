// dummy2View.cpp : implementation of the CDummy2View class
//

#include "stdafx.h"
#include "dummy2.h"

#include "dummy2Doc.h"
#include "dummy2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDummy2View

IMPLEMENT_DYNCREATE(CDummy2View, CView)

BEGIN_MESSAGE_MAP(CDummy2View, CView)
	//{{AFX_MSG_MAP(CDummy2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDummy2View construction/destruction

CDummy2View::CDummy2View()
{
	// TODO: add construction code here

}

CDummy2View::~CDummy2View()
{
}

BOOL CDummy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDummy2View drawing

void CDummy2View::OnDraw(CDC* pDC)
{
	CDummy2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDummy2View diagnostics

#ifdef _DEBUG
void CDummy2View::AssertValid() const
{
	CView::AssertValid();
}

void CDummy2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDummy2Doc* CDummy2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDummy2Doc)));
	return (CDummy2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDummy2View message handlers
