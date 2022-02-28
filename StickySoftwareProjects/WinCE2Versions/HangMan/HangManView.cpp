// HangManView.cpp : implementation of the CHangManView class
//

#include "stdafx.h"
#include "HangMan.h"

#include "HangManDoc.h"
#include "HangManView.h"

#include "Dialog_Key.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CDialog_Key *aDlg;
bool KeysOpen=false;

extern short int count;
extern void DrawMan(CDC *pDC, short int stage);
extern void DrawWord(CDC *pDC);
extern void PickWord(CDC *pDC);
extern void DefinePens(CDC *pDC);
extern void Release(CDC *pDC);

/////////////////////////////////////////////////////////////////////////////
// CHangManView

IMPLEMENT_DYNCREATE(CHangManView, CView)

BEGIN_MESSAGE_MAP(CHangManView, CView)
	//{{AFX_MSG_MAP(CHangManView)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHangManView construction/destruction

CHangManView::CHangManView()
{
	// TODO: add construction code here

}

CHangManView::~CHangManView()
{
}

BOOL CHangManView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHangManView drawing

void CHangManView::OnDraw(CDC* pDC)
{
	CHangManDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here


	if (!KeysOpen)
	{
		aDlg =new CDialog_Key;
		aDlg->Create(IDD_DIALOG_KEY,this);
		KeysOpen=true;
		DefinePens(pDC);
		PickWord(pDC);
	}

	DrawMan(pDC,count);
	DrawWord(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CHangManView diagnostics

#ifdef _DEBUG
void CHangManView::AssertValid() const
{
	CView::AssertValid();
}

void CHangManView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHangManDoc* CHangManView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHangManDoc)));
	return (CHangManDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHangManView message handlers





void CHangManView::OnDestroy() 
{

	// Delete stuff

	CClientDC dc(this);

	if (KeysOpen)
	{
		aDlg->KillDialog();
		Release(&dc);
	}
	
	CView::OnDestroy();
	
	
}
