// FileTestView.cpp : implementation of the CFileTestView class
//

#include "stdafx.h"
#include "FileTest.h"

#include "FileTestDoc.h"
#include "FileTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileTestView

IMPLEMENT_DYNCREATE(CFileTestView, CView)

BEGIN_MESSAGE_MAP(CFileTestView, CView)
	//{{AFX_MSG_MAP(CFileTestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileTestView construction/destruction

CFileTestView::CFileTestView()
{
	// TODO: add construction code here

}

CFileTestView::~CFileTestView()
{
}

BOOL CFileTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFileTestView drawing

void CFileTestView::OnDraw(CDC* pDC)
{
	CFileTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFileTestView diagnostics

#ifdef _DEBUG
void CFileTestView::AssertValid() const
{
	CView::AssertValid();
}

void CFileTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileTestDoc* CFileTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileTestDoc)));
	return (CFileTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileTestView message handlers

void CFileTestView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class

	// Added by me. Something has changed the document, i.e. loaded
	// new settings.

	
}
