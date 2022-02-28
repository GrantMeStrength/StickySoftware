// ConvertView.cpp : implementation of the CConvertView class
//

#include "stdafx.h"
#include "Convert.h"

#include "ConvertDoc.h"
#include "ConvertView.h"

extern void convert(void);

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConvertView

IMPLEMENT_DYNCREATE(CConvertView, CView)

BEGIN_MESSAGE_MAP(CConvertView, CView)
	//{{AFX_MSG_MAP(CConvertView)
	ON_COMMAND(IDM_MENU_DOIT, OnMenuDoit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertView construction/destruction

CConvertView::CConvertView()
{
	// TODO: add construction code here

}

CConvertView::~CConvertView()
{
}

BOOL CConvertView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CConvertView drawing

void CConvertView::OnDraw(CDC* pDC)
{
	CConvertDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CConvertView diagnostics

#ifdef _DEBUG
void CConvertView::AssertValid() const
{
	CView::AssertValid();
}

void CConvertView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConvertDoc* CConvertView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConvertDoc)));
	return (CConvertDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConvertView message handlers

void CConvertView::OnMenuDoit() 
{
	convert();	
}
