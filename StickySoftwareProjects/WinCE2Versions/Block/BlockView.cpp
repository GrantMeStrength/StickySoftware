// BlockView.cpp : implementation of the CBlockView class
//

#include "stdafx.h"
#include "Block.h"

#include "BlockDoc.h"
#include "BlockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



extern void NewPattern(CDC *pDC);
extern void DrawAllBlocks(CDC *pDC);
extern void MoveBlock(CDC *pDC, int x, int y);
extern void Initialise(CDC *pDC);
extern void Shuffle(CDC *pDC);
extern int current_pattern;

bool once=false;


/////////////////////////////////////////////////////////////////////////////
// CBlockView

IMPLEMENT_DYNCREATE(CBlockView, CView)

BEGIN_MESSAGE_MAP(CBlockView, CView)
	//{{AFX_MSG_MAP(CBlockView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_GAME_PATTERN1, OnGamePattern1)
	ON_COMMAND(ID_GAME_PATTERN2, OnGamePattern2)
	ON_COMMAND(ID_GAME_PATTERN3, OnGamePattern3)
	ON_COMMAND(ID_GAME_PATTERN4, OnGamePattern4)
	ON_COMMAND(ID_GAME_PATTERN5, OnGamePattern5)
	ON_COMMAND(ID_GAME_PATTERN6, OnGamePattern6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlockView construction/destruction

CBlockView::CBlockView()
{
	// TODO: add construction code here

}

CBlockView::~CBlockView()
{
}

BOOL CBlockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBlockView drawing

void CBlockView::OnDraw(CDC* pDC)
{
	CBlockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!once)
	{
		once=true;
		Initialise(pDC);
		NewPattern(pDC);
	}

		DrawAllBlocks(pDC);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBlockView diagnostics

#ifdef _DEBUG
void CBlockView::AssertValid() const
{
	CView::AssertValid();
}

void CBlockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBlockDoc* CBlockView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBlockDoc)));
	return (CBlockDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBlockView message handlers


void CBlockView::OnLButtonDown(UINT nFlags, CPoint point) 
{

	int x,y;
	CClientDC dc(this);

	CPoint pos = point;
	
	x=pos.x;
	y=pos.y;

	MoveBlock(&dc,x,y);

	CView::OnLButtonDown(nFlags, point);
}

void CBlockView::OnGamePattern1() 
{
	CClientDC dc(this);
	current_pattern=1;
	NewPattern(&dc);
}

void CBlockView::OnGamePattern2() 
{
	CClientDC dc(this);
	current_pattern=2;
	NewPattern(&dc);

	
}

void CBlockView::OnGamePattern3() 
{
	CClientDC dc(this);
	current_pattern=3;
	NewPattern(&dc);
	
}

void CBlockView::OnGamePattern4() 
{
	CClientDC dc(this);
	current_pattern=4;
	NewPattern(&dc);
	
}

void CBlockView::OnGamePattern5() 
{
	CClientDC dc(this);
	current_pattern=5;
	NewPattern(&dc);
}

void CBlockView::OnGamePattern6() 
{
	CClientDC dc(this);
	current_pattern=6;
	NewPattern(&dc);
	
}
