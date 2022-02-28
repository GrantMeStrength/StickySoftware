// TankView.cpp : implementation of the CTankView class
//

#include "stdafx.h"
#include "Tank.h"

#include "TankDoc.h"
#include "TankView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// My Includes

#include "ThreeD.h"
#include "RegStuff.h"

// My Includes

extern bool Key_left, Key_down, Key_right, Key_up, Key_fire;
extern short int GameState;
extern short int High;
extern void DrawBackground(CDC *pDC, bool wipe);
extern bool Sound;

//  My Defines

#define CY 16
#define CX 180
#define VFAST 15
#define FAST 40
#define MEDIUM 80
#define SLOW 150


// My variables

short int speed=FAST;		// The speed of timer events
bool status=false;			// true if the time exists.
bool pause=false;
bool moveup=false,movedown=false,moveleft=false,moveright=false;
bool firsttime=true;
/////////////////////////////////////////////////////////////////////////////
// CTankView

IMPLEMENT_DYNCREATE(CTankView, CView)

BEGIN_MESSAGE_MAP(CTankView, CView)
	//{{AFX_MSG_MAP(CTankView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENU_DELETE, OnMenuDelete)
	ON_COMMAND(ID_MENU_ENDGAME, OnMenuEndgame)
	ON_COMMAND(ID_MENU_PAUSE, OnMenuPause)
	ON_UPDATE_COMMAND_UI(ID_MENU_PAUSE, OnUpdateMenuPause)
	ON_COMMAND(ID_MENU_SOUNDS, OnMenuSounds)
	ON_UPDATE_COMMAND_UI(ID_MENU_SOUNDS, OnUpdateMenuSounds)
	ON_COMMAND(ID_MENU_SPEED_FAST, OnMenuSpeedFast)
	ON_UPDATE_COMMAND_UI(ID_MENU_SPEED_FAST, OnUpdateMenuSpeedFast)
	ON_COMMAND(ID_MENU_SPEED_MEDIUM, OnMenuSpeedMedium)
	ON_UPDATE_COMMAND_UI(ID_MENU_SPEED_MEDIUM, OnUpdateMenuSpeedMedium)
	ON_COMMAND(ID_MENU_SPEED_SLOW, OnMenuSpeedSlow)
	ON_UPDATE_COMMAND_UI(ID_MENU_SPEED_SLOW, OnUpdateMenuSpeedSlow)
	ON_COMMAND(ID_MENU_SPEED_VFAST, OnMenuSpeedVfast)
	ON_UPDATE_COMMAND_UI(ID_MENU_SPEED_VFAST, OnUpdateMenuSpeedVfast)
	ON_UPDATE_COMMAND_UI(ID_MENU_ENDGAME, OnUpdateMenuEndgame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankView construction/destruction

CTankView::CTankView()
{
	High=LoadInfo();
	if (High==-1) // i.e. nothing there yet
	{
		SaveInfo(100); 
		High=100;
	}
}

CTankView::~CTankView()
{
	// Save high score?
}

BOOL CTankView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTankView drawing

void CTankView::OnDraw(CDC* pDC)
{
	CTankDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	DrawBackground(pDC,true);

	// Start the game ticking!
	if (status) return;
	SetTimer(1, speed, NULL);
	status=TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTankView diagnostics

#ifdef _DEBUG
void CTankView::AssertValid() const
{
	CView::AssertValid();
}

void CTankView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTankDoc* CTankView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTankDoc)));
	return (CTankDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankView message handlers


void ScanKeyboard()
{

	//Key_fire=Key_left=Key_right=Key_up=false;

	Key_up=GetAsyncKeyState(VK_UP);
	Key_down=GetAsyncKeyState(VK_DOWN);
	Key_left=GetAsyncKeyState(VK_RIGHT);
	Key_right=GetAsyncKeyState(VK_LEFT);

	if (!Key_fire)	Key_fire=GetAsyncKeyState(VK_SHIFT);

	Key_up|=moveup;
	Key_left|=moveleft;
	Key_right|=moveright;
}



void CTankView::OnTimer(UINT nIDEvent) 
{
//	if (!firsttime)
//	{
		ScanKeyboard();
		CClientDC dc(this);
		if (pause && GameState==20) ;
		else 
			Game(&dc);
//	}
///	else
//		firsttime=false;

	CView::OnTimer(nIDEvent);		
}



void CTankView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	long x,y;
	CClientDC dc(this);
	CPoint pos = point;
	x=pos.x;
	y=pos.y;
	
	if (y>390) 
		Key_fire=true;
	else
	{
		if (y<354) {moveup=!moveup; if (moveup) movedown=false;}
		//if (y>(CY+32)) {movedown=!movedown; if (movedown) moveup=false;}
		if ((y>354) && (y<390) && (x<566)) {moveright=!moveright; if (moveright) moveleft=false;}
		if ((y>354) && (y<390) && (x>(594))) {moveleft=!moveleft; if (moveleft) moveright=false;}
		if ((y>354) && (y<390) && (x>594) && (x<566)) 
				{moveup=false;movedown=false;moveleft=false;moveright=false;};
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CTankView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	moveup=false;movedown=false;moveleft=false;moveright=false;	
	CView::OnLButtonUp(nFlags, point);
}

void CTankView::OnMenuDelete() 
{
	DeleteInfo();
}

void CTankView::OnMenuEndgame() 
{
	if ((GameState<10) || (GameState==45))
		GameState=10;
	else
		GameState=40;
}

void CTankView::OnUpdateMenuEndgame(CCmdUI* pCmdUI) 
{
	if ((GameState<10) || (GameState==45)) 
		pCmdUI->SetText(L"New Game");
	else
		pCmdUI->SetText(L"End Game");	
}

void CTankView::OnMenuPause() 
{
	if (GameState==50) // Turn Paused off
	{
		pause=!pause;
		CClientDC dc(this);
		DrawBackground(&dc,true);
		GameState=20;
		return;
	}

	if (GameState==20) // Become paused
	{
		pause=!pause;
		GameState=50;
		return;
	}	
}

void CTankView::OnUpdateMenuPause(CCmdUI* pCmdUI) 
{
if (!pause) pCmdUI->SetText(L"Pause");
	else pCmdUI->SetText(L"Resume");	
}

void CTankView::OnMenuSounds() 
{
	Sound=!Sound;	
}

void CTankView::OnUpdateMenuSounds(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(Sound);
}

void CTankView::OnMenuSpeedFast() 
{
	if (status) KillTimer(1);
	speed=FAST;
	status=true;
	SetTimer(1, speed, NULL);	
}

void CTankView::OnUpdateMenuSpeedFast(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==FAST);
	
}

void CTankView::OnMenuSpeedMedium() 
{
	if (status) KillTimer(1);
	speed=MEDIUM;
	status=true;
	SetTimer(1, speed, NULL);	
}

void CTankView::OnUpdateMenuSpeedMedium(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==MEDIUM);
	
}

void CTankView::OnMenuSpeedSlow() 
{
	if (status) KillTimer(1);
	speed=SLOW;
	status=true;
	SetTimer(1, speed, NULL);
	
}

void CTankView::OnUpdateMenuSpeedSlow(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==SLOW);
	
}

void CTankView::OnMenuSpeedVfast() 
{
	if (status) KillTimer(1);
	speed=VFAST;
	status=true;
	SetTimer(1, speed, NULL);
	
}

void CTankView::OnUpdateMenuSpeedVfast(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==VFAST);
}


