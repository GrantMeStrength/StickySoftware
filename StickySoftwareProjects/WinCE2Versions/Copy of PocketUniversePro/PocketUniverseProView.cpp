// PocketUniverseProView.cpp : implementation of the CPocketUniverseProView class
//

#include "stdafx.h"
#include "PocketUniversePro.h"

#include "PocketUniverseProDoc.h"
#include "PocketUniverseProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



///////////////////////////////// my stuff ////////////////////

#include "globalstuff.h"
#include "RegStuff.h"
#include "TripleClass.h"


///////////////////////// variables

// Settings used by the auto update feature

int CurrentDelay=5; // The delay in seconds between updates
int CurrentJump=5;  // Measure of how much to jump each update
int CurrentUnit=0; //Unit of Jump: 0=s,1=m,2=h,3=d,4=m,5=y
int CurrentTarget=10; // Target, if any. 0=sun
int CurrentMags=1;		// Limit of visible stars

bool KeyOn=false;
bool Expired=false;
bool TimerOn = false;
bool keypressed = false;
bool eastwest=true;
bool northsouth=true;

bool first_run=true;

///////////////////////// externs
extern bool flags[33];
extern HWND mymenubar;
extern int g_win_alt_deg,g_win_azm_deg;
extern int g_win_alt_min,g_win_azm_min;
extern short int display_mode;
extern bool update;
extern double zoom;
extern int go_horizontal,go_vertical;
extern double Julian;
extern double local_longitude;
extern double local_latitude;
extern short int local_day;
extern short int local_month;
extern short int local_year;
extern short int local_hour;
extern short int local_minute;
extern short int local_second;
extern short int local_timezone;
extern short int local_daylight;
extern double u_ra;
extern double u_dec;
extern double u_rt;
extern double u_st;
extern double u_raz;
extern double u_saz;

extern void makegrid(CDC *pDC);
extern void DrawSky(CDC *pDC);
extern void Recalculate();
extern void DefinePens();
extern void Ephemeris();
extern void RedPrepare();
extern void	RedRemove();
extern void DrawSky(CDC *pDC);
extern void makegrid(CDC *pDC);
extern void Recalculate();
extern void When();
extern double R2D (double angle);
extern double D2R (double angle);
extern void GotoAltAz(CDC *pDC);
extern void GotoRaDec(CDC *pDC);
extern void CentreBody(CDC *pDC,int body);
extern void CentreConst(CDC *pDC,int body);
extern void GotoMouse(CDC *pDC,long x,long y);
extern void WhereMouse(CDC *pDC,long x,long y);
extern void ResetDate();
extern void TimeAdvance(CDC *pDC, double i);
extern void SplitI(double number,  int *deg,  int *min,  int *sec);
//extern void DisplayAbout();
extern double Get_Mess_Alt(int i);
extern double Get_Mess_Azm(int i);
extern void CalculateDay();
extern void CalculateJulian();



/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProView

IMPLEMENT_DYNCREATE(CPocketUniverseProView, CView)

BEGIN_MESSAGE_MAP(CPocketUniverseProView, CView)
	//{{AFX_MSG_MAP(CPocketUniverseProView)
	ON_COMMAND(ID_MENU_SETTIMEDATE, OnMenuSettimedate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProView construction/destruction

CPocketUniverseProView::CPocketUniverseProView()
{
//	CClientDC aDC(this);
//	RedPrepare();
	LoadInfo();	
//	flags[ToolOn] = false;
//	if (flags[TipsOn]) DisplayAbout();
//	makegrid(&aDC);
//	Recalculate();
}

CPocketUniverseProView::~CPocketUniverseProView()
{
//	SaveInfo(); 
//	RedRemove();
}

BOOL CPocketUniverseProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProView drawing

void CPocketUniverseProView::OnDraw(CDC* pDC)
{
	CPocketUniverseProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//if (first_run)
	//{
	//	flags[ToolOn] = false;
	//	if (flags[TipsOn]) DisplayAbout();
		makegrid(pDC);
		Recalculate();
		//SetForegroundWindow();
	//	first_run=false;
	//}

	DrawSky(pDC);
	//UpdateButtons();

	//if ((flags[ToolOpen])&&(!flags[ToolOn]))
	//{
	//	Tooladlg =new CToolbox_Dialog;
	//	Tooladlg->Create(IDD_TOOLBOX_DIALOG,this);
	//	flags[ToolOn]=true;	
	//}

}

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProView diagnostics

#ifdef _DEBUG
void CPocketUniverseProView::AssertValid() const
{
	CView::AssertValid();
}

void CPocketUniverseProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPocketUniverseProDoc* CPocketUniverseProView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPocketUniverseProDoc)));
	return (CPocketUniverseProDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProView message handlers

void CPocketUniverseProView::OnMenuSettimedate() 
{
	CClientDC aDC(this);	
	update=true;
	DrawSky(&aDC);
}
