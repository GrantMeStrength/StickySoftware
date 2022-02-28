// PicClickView.cpp : implementation of the CPicClickView class
//

#include "stdafx.h"
#include "PicClick.h"

#include "PicClickDoc.h"
#include "PicClickView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicClickView

IMPLEMENT_DYNCREATE(CPicClickView, CView)

BEGIN_MESSAGE_MAP(CPicClickView, CView)
	//{{AFX_MSG_MAP(CPicClickView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicClickView construction/destruction

CPicClickView::CPicClickView()
{
	// TODO: add construction code here

}

CPicClickView::~CPicClickView()
{
}

BOOL CPicClickView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPicClickView drawing

void CPicClickView::OnDraw(CDC* pDC)
{
	CPicClickDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPicClickView diagnostics

#ifdef _DEBUG
void CPicClickView::AssertValid() const
{
	CView::AssertValid();
}

void CPicClickView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPicClickDoc* CPicClickView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicClickDoc)));
	return (CPicClickDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicClickView message handlers
