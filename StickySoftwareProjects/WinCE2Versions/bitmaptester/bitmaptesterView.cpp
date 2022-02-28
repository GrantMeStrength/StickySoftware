// bitmaptesterView.cpp : implementation of the CBitmaptesterView class
//

#include "stdafx.h"
#include "bitmaptester.h"

#include "bitmaptesterDoc.h"
#include "bitmaptesterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterView

IMPLEMENT_DYNCREATE(CBitmaptesterView, CView)

BEGIN_MESSAGE_MAP(CBitmaptesterView, CView)
	//{{AFX_MSG_MAP(CBitmaptesterView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterView construction/destruction

CBitmaptesterView::CBitmaptesterView()
{
	// TODO: add construction code here

}

CBitmaptesterView::~CBitmaptesterView()
{
}

BOOL CBitmaptesterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterView drawing

void CBitmaptesterView::OnDraw(CDC* pDC)
{
	CBitmaptesterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterView diagnostics

#ifdef _DEBUG
void CBitmaptesterView::AssertValid() const
{
	CView::AssertValid();
}

void CBitmaptesterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitmaptesterDoc* CBitmaptesterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmaptesterDoc)));
	return (CBitmaptesterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterView message handlers
