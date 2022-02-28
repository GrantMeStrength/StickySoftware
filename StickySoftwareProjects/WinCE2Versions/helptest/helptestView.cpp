// helptestView.cpp : implementation of the CHelptestView class
//

#include "stdafx.h"
#include "helptest.h"

#include "helptestDoc.h"
#include "helptestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelptestView

IMPLEMENT_DYNCREATE(CHelptestView, CView)

BEGIN_MESSAGE_MAP(CHelptestView, CView)
	//{{AFX_MSG_MAP(CHelptestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelptestView construction/destruction

CHelptestView::CHelptestView()
{
	// TODO: add construction code here

}

CHelptestView::~CHelptestView()
{
}

BOOL CHelptestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHelptestView drawing

void CHelptestView::OnDraw(CDC* pDC)
{
	CHelptestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHelptestView diagnostics

#ifdef _DEBUG
void CHelptestView::AssertValid() const
{
	CView::AssertValid();
}

void CHelptestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelptestDoc* CHelptestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelptestDoc)));
	return (CHelptestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHelptestView message handlers
