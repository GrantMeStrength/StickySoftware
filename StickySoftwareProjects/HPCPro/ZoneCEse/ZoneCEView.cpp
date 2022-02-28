// ZoneCEView.cpp : implementation of the CZoneCEView class
//

#include "stdafx.h"
#include "ZoneCE.h"

#include "ZoneCEDoc.h"
#include "ZoneCEView.h"

#include "ThreeD.h"

#include "RegStuff.h"

extern bool Key_left, Key_down, Key_right, Key_up, Key_fire;
extern short int GameState;
extern short int High;
extern void DrawBackground(CDC *pDC, bool wipe);

LPVOID pSound1;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CY 16
#define CX 180

#define VFAST 15
#define FAST 40
#define MEDIUM 80
#define SLOW 150

short int speed=FAST;		// The speed of timer events
bool status=false;	// true if the time exists.
bool pause=false;
extern bool Sound;


bool moveup=false,movedown=false,moveleft=false,moveright=false;

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView

IMPLEMENT_DYNCREATE(CZoneCEView, CView)

BEGIN_MESSAGE_MAP(CZoneCEView, CView)
	//{{AFX_MSG_MAP(CZoneCEView)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENU_VFAST, OnMenuVfast)
	ON_UPDATE_COMMAND_UI(ID_MENU_VFAST, OnUpdateMenuVfast)
	ON_COMMAND(ID_MENU_FAST, OnMenuFast)
	ON_UPDATE_COMMAND_UI(ID_MENU_FAST, OnUpdateMenuFast)
	ON_COMMAND(ID_MENU_MEDIUM, OnMenuMedium)
	ON_COMMAND(ID_MENU_SLOW, OnMenuSlow)
	ON_UPDATE_COMMAND_UI(ID_MENU_MEDIUM, OnUpdateMenuMedium)
	ON_UPDATE_COMMAND_UI(ID_MENU_SLOW, OnUpdateMenuSlow)
	ON_COMMAND(ID_MENU_SOUND, OnMenuSound)
	ON_UPDATE_COMMAND_UI(ID_MENU_SOUND, OnUpdateMenuSound)
	ON_COMMAND(ID_START_GAME, OnStartGame)
	ON_COMMAND(ID_GAME_PAUSE, OnGamePause)
	ON_UPDATE_COMMAND_UI(ID_GAME_PAUSE, OnUpdateGamePause)
	ON_UPDATE_COMMAND_UI(ID_START_GAME, OnUpdateStartGame)
	ON_COMMAND(ID_DELETE_INFO, OnDeleteInfo)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView construction/destruction

CZoneCEView::CZoneCEView()
{
	// TODO: add construction code here

	
	High=LoadInfo();
	if (High==-1) // i.e. nothing there yet
	{
		SaveInfo(100); 
		High=100;
	}

}

CZoneCEView::~CZoneCEView()
{

	SaveInfo(High);
}

BOOL CZoneCEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView drawing

void CZoneCEView::OnDraw(CDC* pDC)
{
	CZoneCEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Redraw background

	DrawBackground(pDC,true);

	// Start the game ticking!
	if (status) return;
	SetTimer(1, speed, NULL);
	status=TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView diagnostics

#ifdef _DEBUG
void CZoneCEView::AssertValid() const
{
	CView::AssertValid();
}

void CZoneCEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZoneCEDoc* CZoneCEView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZoneCEDoc)));
	return (CZoneCEDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView message handlers


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

void CZoneCEView::OnTimer(UINT nIDEvent) 
{

	// Read Key values!

	ScanKeyboard();

	CClientDC dc(this);
	if (pause && GameState==20) ;
	else Game(&dc);
	CView::OnTimer(nIDEvent);	
}



void CZoneCEView::OnMenuVfast() 
{
	if (status) KillTimer(1);
	speed=VFAST;
	status=true;
	SetTimer(1, speed, NULL);
}

void CZoneCEView::OnUpdateMenuVfast(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==VFAST);
}

void CZoneCEView::OnMenuFast() 
{
	if (status) KillTimer(1);
	speed=FAST;
	status=true;
	SetTimer(1, speed, NULL);
	
}

void CZoneCEView::OnUpdateMenuFast(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==FAST);
}

void CZoneCEView::OnMenuMedium() 
{
	if (status) KillTimer(1);
	speed=MEDIUM;
	status=true;
	SetTimer(1, speed, NULL);
}

void CZoneCEView::OnUpdateMenuMedium(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==MEDIUM);	
}

void CZoneCEView::OnMenuSlow() 
{
	
	if (status) KillTimer(1);
	speed=SLOW;
	status=true;
	SetTimer(1, speed, NULL);
	
}


void CZoneCEView::OnUpdateMenuSlow(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(speed==SLOW);	
}

void CZoneCEView::OnMenuSound() 
{
	Sound=!Sound;	
}

void CZoneCEView::OnUpdateMenuSound(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(Sound);
}

void CZoneCEView::OnStartGame() 
{
	// Start game for those who can't
	// read instructions... it turns
	// into end game.

	if ((GameState<10) || (GameState==45))
		GameState=10;
	else
		GameState=40;

}


void CZoneCEView::OnGamePause() 
{
	// Stop timer if it has been started,
	// Start timer if it has been stopped!

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


void CZoneCEView::OnUpdateGamePause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	// If paused, make text Resume and vice versa
	if (!pause) pCmdUI->SetText(L"Pause");
	else pCmdUI->SetText(L"Resume");
}

void CZoneCEView::OnUpdateStartGame(CCmdUI* pCmdUI) 
{
	if ((GameState<10) || (GameState==45)) 
		pCmdUI->SetText(L"New Game");
	else
		pCmdUI->SetText(L"End Game");	
}



void CZoneCEView::OnDeleteInfo() 
{

	// Menu option to delete current hi-score
	// which means the registry key

	 DeleteInfo();

}



void CZoneCEView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
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


void CZoneCEView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	moveup=false;movedown=false;moveleft=false;moveright=false;

	CView::OnLButtonUp(nFlags, point);
}

int CZoneCEView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	HGLOBAL hResource1 =::LoadResource(NULL,::FindResource(NULL,MAKEINTRESOURCE(IDR_WAVE1),RT_RCDATA));
	pSound1 = LockResource(hResource1);

	return 0;
}
