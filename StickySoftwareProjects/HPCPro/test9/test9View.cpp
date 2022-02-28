// test9View.cpp : implementation of the CTest9View class
//

#include "stdafx.h"
#include "test9.h"

#include "test9Doc.h"
#include "test9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest9View

IMPLEMENT_DYNCREATE(CTest9View, CView)

BEGIN_MESSAGE_MAP(CTest9View, CView)
	//{{AFX_MSG_MAP(CTest9View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest9View construction/destruction

CTest9View::CTest9View()
{
	// TODO: add construction code here

}

CTest9View::~CTest9View()
{
}

BOOL CTest9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest9View drawing

void CTest9View::OnDraw(CDC* pDC)
{
	CTest9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest9View diagnostics

#ifdef _DEBUG
void CTest9View::AssertValid() const
{
	CView::AssertValid();
}

void CTest9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest9Doc* CTest9View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest9Doc)));
	return (CTest9Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest9View message handlers
