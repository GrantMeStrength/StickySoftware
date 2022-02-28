// PocketUniverseView.cpp : implementation of the CPocketUniverseView class
//

#include "stdafx.h"
#include "PocketUniverse.h"

#include "PocketUniverseDoc.h"
#include "PocketUniverseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseView

IMPLEMENT_DYNCREATE(CPocketUniverseView, CView)

BEGIN_MESSAGE_MAP(CPocketUniverseView, CView)
	//{{AFX_MSG_MAP(CPocketUniverseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseView construction/destruction

CPocketUniverseView::CPocketUniverseView()
{
	// TODO: add construction code here

}

CPocketUniverseView::~CPocketUniverseView()
{
}

BOOL CPocketUniverseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseView drawing

void CPocketUniverseView::OnDraw(CDC* pDC)
{
	CPocketUniverseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseView diagnostics

#ifdef _DEBUG
void CPocketUniverseView::AssertValid() const
{
	CView::AssertValid();
}

void CPocketUniverseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPocketUniverseDoc* CPocketUniverseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPocketUniverseDoc)));
	return (CPocketUniverseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseView message handlers
