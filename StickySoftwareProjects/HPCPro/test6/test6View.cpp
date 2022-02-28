// test6View.cpp : implementation of the CTest6View class
//

#include "stdafx.h"
#include "test6.h"

#include "test6Doc.h"
#include "test6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest6View

IMPLEMENT_DYNCREATE(CTest6View, CView)

BEGIN_MESSAGE_MAP(CTest6View, CView)
	//{{AFX_MSG_MAP(CTest6View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest6View construction/destruction

CTest6View::CTest6View()
{
	// TODO: add construction code here

}

CTest6View::~CTest6View()
{
}

BOOL CTest6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View drawing

void CTest6View::OnDraw(CDC* pDC)
{
	CTest6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View diagnostics

#ifdef _DEBUG
void CTest6View::AssertValid() const
{
	CView::AssertValid();
}

void CTest6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest6Doc* CTest6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest6Doc)));
	return (CTest6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest6View message handlers
