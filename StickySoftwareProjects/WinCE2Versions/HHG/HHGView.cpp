// HHGView.cpp : implementation of the CHHGView class
//

#include "stdafx.h"
#include "HHG.h"

#include "HHGDoc.h"
#include "HHGView.h"
#include "Control_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void Initialise(CDC *pDC);
extern void DrawScreen(CDC *pDC);

bool once=false;

CControl_Dialog *cDlg;



/////////////////////////////////////////////////////////////////////////////
// CHHGView

IMPLEMENT_DYNCREATE(CHHGView, CView)

BEGIN_MESSAGE_MAP(CHHGView, CView)
	//{{AFX_MSG_MAP(CHHGView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHHGView construction/destruction

CHHGView::CHHGView()
{
	// TODO: add construction code here

}

CHHGView::~CHHGView()
{
}

BOOL CHHGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHHGView drawing

void CHHGView::OnDraw(CDC* pDC)
{
	CHHGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	if (!once)
	{
		once=true;
		Initialise(pDC);
		cDlg = new CControl_Dialog;
		cDlg->Create(IDD_CONTROL_DIALOG,this);
	}

	DrawScreen(pDC);
	
	
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHHGView diagnostics

#ifdef _DEBUG
void CHHGView::AssertValid() const
{
	CView::AssertValid();
}

void CHHGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHHGDoc* CHHGView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHHGDoc)));
	return (CHHGDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHHGView message handlers
