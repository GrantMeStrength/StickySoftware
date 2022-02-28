// PalmUniverseView.cpp : implementation of the CPalmUniverseView class
//

#include "stdafx.h"
#include "PalmUniverse.h"

#include "PalmUniverseDoc.h"
#include "PalmUniverseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseView

IMPLEMENT_DYNCREATE(CPalmUniverseView, CView)

BEGIN_MESSAGE_MAP(CPalmUniverseView, CView)
	//{{AFX_MSG_MAP(CPalmUniverseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseView construction/destruction

CPalmUniverseView::CPalmUniverseView()
{
	// TODO: add construction code here

}

CPalmUniverseView::~CPalmUniverseView()
{
}

BOOL CPalmUniverseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseView drawing

void CPalmUniverseView::OnDraw(CDC* pDC)
{
	CPalmUniverseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseView diagnostics

#ifdef _DEBUG
void CPalmUniverseView::AssertValid() const
{
	CView::AssertValid();
}

void CPalmUniverseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPalmUniverseDoc* CPalmUniverseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPalmUniverseDoc)));
	return (CPalmUniverseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseView message handlers
