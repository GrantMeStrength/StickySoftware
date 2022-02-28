// TalkingClockView.cpp : implementation of the CTalkingClockView class
//

#include "stdafx.h"
#include "TalkingClock.h"

#include "TalkingClockDoc.h"
#include "TalkingClockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern void Talk();

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockView

IMPLEMENT_DYNCREATE(CTalkingClockView, CView)

BEGIN_MESSAGE_MAP(CTalkingClockView, CView)
	//{{AFX_MSG_MAP(CTalkingClockView)
	ON_COMMAND(IDM_TIME, OnTellMeTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockView construction/destruction

CTalkingClockView::CTalkingClockView()
{
	// TODO: add construction code here

}

CTalkingClockView::~CTalkingClockView()
{
}

BOOL CTalkingClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockView drawing

void CTalkingClockView::OnDraw(CDC* pDC)
{
	CTalkingClockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockView diagnostics

#ifdef _DEBUG
void CTalkingClockView::AssertValid() const
{
	CView::AssertValid();
}

void CTalkingClockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTalkingClockDoc* CTalkingClockView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTalkingClockDoc)));
	return (CTalkingClockDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockView message handlers

void CTalkingClockView::OnTellMeTime() 
{

	// Read out the time!
	Talk();
	
}
