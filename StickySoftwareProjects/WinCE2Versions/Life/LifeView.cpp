// LifeView.cpp : implementation of the CLifeView class
//

//#include "iostream.h"
#include "stdafx.h"
#include "Life.h"

#include "LifeDoc.h"
#include "LifeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "Game.h"

int status;	//	0=nothing, 1=generating


/////////////////////////////////////////////////////////////////////////////
// CLifeView

IMPLEMENT_DYNCREATE(CLifeView, CView)

BEGIN_MESSAGE_MAP(CLifeView, CView)
	//{{AFX_MSG_MAP(CLifeView)
	ON_COMMAND(ID_LIFE_START, OnLifeStart)
	ON_COMMAND(ID_LIFE_CLEAR, OnLifeClear)
	ON_COMMAND(ID_LIFE_STOP, OnLifeStop)
	ON_COMMAND(ID_LIFE_RANDOM, OnLifeRandom)
	ON_WM_TIMER()
	ON_COMMAND(ID_LIFE_ONCE, OnLifeOnce)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_LIFE_FAST, OnLifeFast)
	ON_COMMAND(ID_LIFE_SLOW, OnLifeSlow)
	ON_COMMAND(ID_LIFE_PREVIOUS, OnLifePrevious)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLifeView construction/destruction

CLifeView::CLifeView()
{
	// TODO: add construction code here

	// Init my variables

	CClientDC dc(this);

	status=0;
	speed=500;
	InitGame(&dc);
	generation=0;
}

CLifeView::~CLifeView()
{
}

BOOL CLifeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLifeView drawing

void CLifeView::OnDraw(CDC* pDC)
{
	CLifeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	DrawEverything(pDC);

}



/////////////////////////////////////////////////////////////////////////////
// CLifeView diagnostics

#ifdef _DEBUG
void CLifeView::AssertValid() const
{
	CView::AssertValid();
}

void CLifeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLifeDoc* CLifeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLifeDoc)));
	return (CLifeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLifeView message handlers



void CLifeView::OnLifeStart() 
{
	// TODO: Add your command handler code here

	// Start the timer
	if (status==1) return; // Already running!
	CClientDC dc(this);
	CopyToTemp();
	SetTimer(1, speed, NULL);
	status=1;
	UpdateText(&dc);
}

void CLifeView::OnLifeClear() 
{
	// TODO: Add your command handler code here
	
	// Stop generating,
	// Clear the grid,
	// Redraw

	CClientDC dc(this);

	if (status==1) KillTimer(1);
	status=0;
	InitGame(&dc);
	generation=0;
	DrawEverything(&dc);

}

void StopTimer()
{
	if (status==1) KillTimer(1);
}

void CLifeView::OnLifeStop() 
{
	
	// Stop the timer

	if (status==1)  KillTimer(1);
	status=0;
	CClientDC dc(this);
	DrawEverything(&dc);
}

void CLifeView::OnLifeRandom() 
{

	// Stop generating,
	// Randomise the grid,
	// Redraw
	
	CClientDC dc(this);
	if (status==1) KillTimer(1);
	status=0;
	RandomGrid(&dc);
	generation=0;
	DrawEverything(&dc);
	
}

void CLifeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);
	Generate();
	UpdateAllCells(&dc);
	if (total==0)			// All dead!
	{
		KillTimer(1);
		status=0;
		sndPlaySound(L"MenuSel.wav", SND_ASYNC|SND_FILENAME);
	}
	generation++;
	UpdateText(&dc);
	CView::OnTimer(nIDEvent);
}

void CLifeView::OnLifeOnce() 
{
	if (status==1) return;	// If generation already, return.
	CopyToTemp();
	CClientDC dc(this);
	Generate();
	generation++;
	UpdateText(&dc);
	UpdateAllCells(&dc);
}

void CLifeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int x,y;
	CClientDC dc(this);

	CPoint pos = point;
	
	x=pos.x;
	y=pos.y;

	SwapCell(&dc,x,y);

	CView::OnLButtonDown(nFlags, point);
}


void CLifeView::OnLifeFast() 
{
	// Make faster!
	if (status==0) return;
	if (speed==100) return;
	speed-=100;
	KillTimer(1);
	sndPlaySound(L"MenuSel.wav", SND_ASYNC|SND_FILENAME);
	SetTimer(1, speed, NULL);
}


void CLifeView::OnLifeSlow() 
{
	// Make Slower
	if (speed==1000) return;
	if (status==0) return;
	speed+=100;
	KillTimer(1);
	sndPlaySound(L"MenuSel.wav", SND_ASYNC|SND_FILENAME);
	SetTimer(1, speed, NULL);	
}


//void CLifeView::OnFileSaveAs() 
//{
//	CClientDC dc(this);
//	if (status==1) KillTimer(1);
//	status=0;
//	SaveData();	
//}

	

//void CLifeView::OnFileOpen() 
//{
//	CClientDC dc(this);
//	if (status==1) KillTimer(1);
//	status=0;
//	LoadData();
//	generation=0;
//	DrawEverything(&dc);
//}

//void CLifeView::OnFileSave() 
//{

//}

void CLifeView::OnLifePrevious() 
{
	CClientDC dc(this);
	if (status==1) KillTimer(1);
	status=0;
	CopyFromTemp();
	generation=0;
	DrawEverything(&dc);
	
}

