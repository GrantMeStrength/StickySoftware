// scoobyView.cpp : implementation of the CScoobyView class
//

#include "stdafx.h"
#include "scooby.h"
#include "scoobyDoc.h"
#include "scoobyView.h"

bool once=false;
CScooby *cDlg;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoobyView

IMPLEMENT_DYNCREATE(CScoobyView, CView)

BEGIN_MESSAGE_MAP(CScoobyView, CView)
	//{{AFX_MSG_MAP(CScoobyView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoobyView construction/destruction

CScoobyView::CScoobyView()
{
	// TODO: add construction code here

}

CScoobyView::~CScoobyView()
{
}

BOOL CScoobyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CScoobyView drawing

void CScoobyView::OnDraw(CDC* pDC)
{
	CScoobyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (once==false)
	{
		once=true;
		cDlg = new CScooby;
		cDlg->Create(IDD_SCOOBY,this);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CScoobyView diagnostics

#ifdef _DEBUG
void CScoobyView::AssertValid() const
{
	CView::AssertValid();
}

void CScoobyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CScoobyDoc* CScoobyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScoobyDoc)));
	return (CScoobyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScoobyView message handlers
