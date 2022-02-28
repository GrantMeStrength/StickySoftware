// Life2View.cpp : implementation of the CLife2View class
//

#include "stdafx.h"
#include "Life2.h"

#include "Life2Doc.h"
#include "Life2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLife2View

IMPLEMENT_DYNCREATE(CLife2View, CView)

BEGIN_MESSAGE_MAP(CLife2View, CView)
	//{{AFX_MSG_MAP(CLife2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLife2View construction/destruction

CLife2View::CLife2View()
{
	// TODO: add construction code here

}

CLife2View::~CLife2View()
{
}

BOOL CLife2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLife2View drawing

void CLife2View::OnDraw(CDC* pDC)
{
	CLife2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLife2View diagnostics

#ifdef _DEBUG
void CLife2View::AssertValid() const
{
	CView::AssertValid();
}

void CLife2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLife2Doc* CLife2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLife2Doc)));
	return (CLife2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLife2View message handlers
