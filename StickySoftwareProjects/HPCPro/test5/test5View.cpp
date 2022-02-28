// test5View.cpp : implementation of the CTest5View class
//

#include "stdafx.h"
#include "test5.h"

#include "test5Doc.h"
#include "test5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest5View

IMPLEMENT_DYNCREATE(CTest5View, CView)

BEGIN_MESSAGE_MAP(CTest5View, CView)
	//{{AFX_MSG_MAP(CTest5View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest5View construction/destruction

CTest5View::CTest5View()
{
	// TODO: add construction code here

}

CTest5View::~CTest5View()
{
}

BOOL CTest5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View drawing

void CTest5View::OnDraw(CDC* pDC)
{
	CTest5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View diagnostics

#ifdef _DEBUG
void CTest5View::AssertValid() const
{
	CView::AssertValid();
}

void CTest5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest5Doc* CTest5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest5Doc)));
	return (CTest5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest5View message handlers
