// pp1View.cpp : implementation of the CPp1View class
//

#include "stdafx.h"
#include "pp1.h"

#include "pp1Doc.h"
#include "pp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPp1View

IMPLEMENT_DYNCREATE(CPp1View, CView)

BEGIN_MESSAGE_MAP(CPp1View, CView)
	//{{AFX_MSG_MAP(CPp1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPp1View construction/destruction

CPp1View::CPp1View()
{
	// TODO: add construction code here

}

CPp1View::~CPp1View()
{
}

BOOL CPp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPp1View drawing

void CPp1View::OnDraw(CDC* pDC)
{
	CPp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPp1View diagnostics

#ifdef _DEBUG
void CPp1View::AssertValid() const
{
	CView::AssertValid();
}

void CPp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPp1Doc* CPp1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPp1Doc)));
	return (CPp1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPp1View message handlers
