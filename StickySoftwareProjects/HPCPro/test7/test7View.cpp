// test7View.cpp : implementation of the CTest7View class
//

#include "stdafx.h"
#include "test7.h"

#include "test7Doc.h"
#include "test7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest7View

IMPLEMENT_DYNCREATE(CTest7View, CView)

BEGIN_MESSAGE_MAP(CTest7View, CView)
	//{{AFX_MSG_MAP(CTest7View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest7View construction/destruction

CTest7View::CTest7View()
{
	// TODO: add construction code here

}

CTest7View::~CTest7View()
{
}

BOOL CTest7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest7View drawing

void CTest7View::OnDraw(CDC* pDC)
{
	CTest7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest7View diagnostics

#ifdef _DEBUG
void CTest7View::AssertValid() const
{
	CView::AssertValid();
}

void CTest7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest7Doc* CTest7View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest7Doc)));
	return (CTest7Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest7View message handlers
