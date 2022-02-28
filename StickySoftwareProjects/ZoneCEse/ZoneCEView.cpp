// ZoneCEView.cpp : implementation of the CZoneCEView class
//

#include "stdafx.h"
#include "ZoneCE.h"

#include "ZoneCEDoc.h"
#include "ZoneCEView.h"

#include "ThreeD.h"

#include "RegStuff.h"

extern bool Key_left, Key_right, Key_up, Key_down, Key_fire;
extern int GameState;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define VFAST 20
#define FAST 50
#define MEDIUM 100
#define SLOW 200

int speed=FAST;		// The speed of timer events
bool status=false;	// true if the time exists.
bool pause=false;
extern bool Sound,Flicker;
extern bool Landscape,Shaded;

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView

IMPLEMENT_DYNCREATE(CZoneCEView, CView)

BEGIN_MESSAGE_MAP(CZoneCEView, CView)
	//{{AFX_MSG_MAP(CZoneCEView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
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
	ON_COMMAND(ID_MENU_LANDSCAPE, OnMenuLandscape)
	ON_UPDATE_COMMAND_UI(ID_MENU_LANDSCAPE, OnUpdateMenuLandscape)
	ON_COMMAND(ID_MENU_SHADING, OnMenuShading)
	ON_UPDATE_COMMAND_UI(ID_MENU_SHADING, OnUpdateMenuShading)
	ON_COMMAND(ID_GAME_PAUSE, OnGamePause)
	ON_UPDATE_COMMAND_UI(ID_GAME_PAUSE, OnUpdateGamePause)
	ON_UPDATE_COMMAND_UI(ID_START_GAME, OnUpdateStartGame)
	ON_COMMAND(ID_MENU_FLICKER, OnMenuFlicker)
	ON_UPDATE_COMMAND_UI(ID_MENU_FLICKER, OnUpdateMenuFlicker)
	ON_COMMAND(ID_DELETE_INFO, OnDeleteInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZoneCEView construction/destruction

CZoneCEView::CZoneCEView()
{
	// TODO: add construction code here

}

CZoneCEView::~CZoneCEView()
{
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

	// TODO: add draw code for native data here

	// Start the game ticking!
	if (status) return;
	SetTimer(1, FAST, NULL);
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


void CZoneCEView::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this);
	if (pause && GameState==20) ;
	else Game(&dc);
	CView::OnTimer(nIDEvent);	
}

void CZoneCEView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	switch (nChar) {
	case 39:Key_left=true;break;
	case 37:Key_right=true;break;
	case 38:Key_up=true;break;
	case 40:Key_down=true;break;
	case 16:Key_fire=true;break;
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CZoneCEView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
switch (nChar) {

	case 39:Key_left=false;break;
	case 37:Key_right=false;break;
	case 38:Key_up=false;break;
	case 40:Key_down=false;break;
	case 16:Key_fire=false;break;
	}	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
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

void CZoneCEView::OnMenuLandscape() 
{
	Landscape=!Landscape; 	
}

void CZoneCEView::OnUpdateMenuLandscape(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(Landscape);	
}

void CZoneCEView::OnMenuShading() 
{
	Shaded=!Shaded;
}

void CZoneCEView::OnUpdateMenuShading(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(Shaded);
	
}

void CZoneCEView::OnGamePause() 
{
	// Stop timer if it has been started,
	// Start timer if it has been stopped!

	if (GameState==50) // Turn Paused off
	{
		pause=!pause;
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
	if (!pause) pCmdUI->SetText(L"&Pause");
	else pCmdUI->SetText(L"&Resume");
}

void CZoneCEView::OnUpdateStartGame(CCmdUI* pCmdUI) 
{
	if ((GameState<10) || (GameState==45)) 
		pCmdUI->SetText(L"New Game");
	else
		pCmdUI->SetText(L"End Game");	
}

void CZoneCEView::OnMenuFlicker() 
{
	Flicker=!Flicker;	
}

void CZoneCEView::OnUpdateMenuFlicker(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(!Flicker);
	
}

void CZoneCEView::OnDeleteInfo() 
{

	// Menu option to delete current hi-score
	// which means the registry key

	void DeleteInfo();

}
