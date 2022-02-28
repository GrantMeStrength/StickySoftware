// La1View.cpp : implementation of the CLa1View class
//

#include "stdafx.h"
#include "La1.h"

#include "La1Doc.h"
#include "La1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern void Initialise(CDC *pdc);
extern void DrawMoon(CDC *pdc, short int x, short int y,float z);

short int mx=0,my=0;
float mz=1;

bool prepare=false;


/////////////////////////////////////////////////////////////////////////////
// CLa1View

IMPLEMENT_DYNCREATE(CLa1View, CView)

BEGIN_MESSAGE_MAP(CLa1View, CView)
	//{{AFX_MSG_MAP(CLa1View)
	ON_COMMAND(ID_MOVE_DOWN, OnMoveDown)
	ON_COMMAND(ID_MOVE_LEFT, OnMoveLeft)
	ON_COMMAND(ID_MOVE_RIGHT, OnMoveRight)
	ON_COMMAND(ID_MOVE_UP, OnMoveUp)
	ON_COMMAND(ID_MOVE_IN, OnMoveIn)
	ON_COMMAND(ID_MOVE_OUT, OnMoveOut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLa1View construction/destruction

CLa1View::CLa1View()
{
	// TODO: add construction code here

}

CLa1View::~CLa1View()
{
}

BOOL CLa1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLa1View drawing

void CLa1View::OnDraw(CDC* pDC)
{
	CLa1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	if (!prepare)
	{
		prepare=true;
		Initialise(pDC);
	}

	DrawMoon(pDC,mx,my,mz);


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLa1View diagnostics

#ifdef _DEBUG
void CLa1View::AssertValid() const
{
	CView::AssertValid();
}

void CLa1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLa1Doc* CLa1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLa1Doc)));
	return (CLa1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLa1View message handlers

void CLa1View::OnMoveDown() 
{
	my++;
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
	
}

void CLa1View::OnMoveLeft() 
{
	mx--;
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
}

void CLa1View::OnMoveRight() 
{
	mx++;
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
}

void CLa1View::OnMoveUp() 
{
	my--;	
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
}

void CLa1View::OnMoveIn() 
{
	mz/=1.1;
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
	
}

void CLa1View::OnMoveOut() 
{
	mz*=1.1;
	CClientDC dc(this);
	DrawMoon(&dc,mx,my,mz);
	
}
