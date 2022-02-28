// ViewMark1View.cpp : implementation of the CViewMark1View class
//

#include "stdafx.h"
#include "math.h"
#include "ViewMark1.h"
#include "ViewMark1Doc.h"
#include "ViewMark1View.h"

#include "LocationDialog.h"
#include "TimeDateDialog.h"
#include "FindDialog.h"
#include "SettingsDialog.h"
#include "GotoAltAzDialog.h"
#include "GotoRaDecDialog.h"
#include "Key_Dialog.h"
#include "Toolbox_Dialog.h"
#include "Data_Dialog.h"
#include "UpdateDialog2.h"
#include "Jovian_Dialog.h"
#include "CKeyDefineDialog.h"
#include "GotoMessDialog.h"


#include "RegStuff.h"

extern short int g_win_alt_deg,g_win_azm_deg;
extern short int g_win_alt_min,g_win_azm_min;
short int remember_mess=1;

class triple {
	short int deg;
	short int min;
	short int sec;
	double all;
	bool flag;
public:
	triple();
	int get_deg(void);
	int get_min(void);
	double get_sec(void);
	void set_deg(int);
	void set_min(int);
	void set_sec(double);
	double get_all(void);
	void set_all(double);
	void add_deg(int);
};


#include "globalstuff.h"

extern void DrawSky(CDC *pDC);
extern void makegrid(CDC *pDC);
extern void Recalculate();
extern void When();
extern double R2D (double angle);
extern double D2R (double angle);
extern void GotoAltAz(CDC *pDC);
extern void GotoRaDec(CDC *pDC);
extern void CentreBody(CDC *pDC,int body);
extern void GotoMouse(CDC *pDC,long x,long y);
extern void WhereMouse(CDC *pDC,long x,long y);
extern void SplitI(double number,  int *deg,  int *min,  int *sec);
extern void ResetDate();
extern void TimeAdvance(CDC *pDC, double i);

extern double zoom;
extern short int go_horizontal,go_vertical;
extern double Julian;

extern void DisplayAbout();


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

extern void CalculateDay();
extern void CalculateJulian();

extern class triple win_alt,win_azm;
extern class triple win_ra,win_dec;

bool KeyOn=false;
bool Expired=false;
bool TimerOn = false;
bool keypressed = false;
bool eastwest=true;
bool northsouth=true;

extern double Get_Mess_Alt(int i);
extern double Get_Mess_Azm(int i);

short int OrdTimer;

CToolbox_Dialog* Tooladlg;
CKey_Dialog* Keyadlg;

extern bool flags[33];
extern bool update;



// Settings used by the auto update feature

short int CurrentDelay=5; // The delay in seconds between updates
short int CurrentJump=5;  // Measure of how much to jump each update
short int CurrentUnit=0; //Unit of Jump: 0=s,1=m,2=h,3=d,4=m,5=y
short int CurrentTarget=10; // Target, if any. 0=sun
short int CurrentMags=1;		// Limit of visible stars



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewMark1View

IMPLEMENT_DYNCREATE(CViewMark1View, CView)

BEGIN_MESSAGE_MAP(CViewMark1View, CView)
	//{{AFX_MSG_MAP(CViewMark1View)
	ON_COMMAND(ID_CONTROL_ZOOM_IN, OnControlZoomIn)
	ON_COMMAND(ID_CONTROL_ZOOM_OUT, OnControlZoomOut)
	ON_COMMAND(ID_CONTROL_LOOK_DOWN, OnControlLookDown)
	ON_COMMAND(ID_CONTROL_LOOK_UP, OnControlLookUp)
	ON_COMMAND(ID_CONTROL_LOOK_LEFT, OnControlLookLeft)
	ON_COMMAND(ID_CONTROL_LOOK_RIGHT, OnControlLookRight)
	ON_COMMAND(ID_CONTROL_LOCATION, OnControlLocation)
	ON_COMMAND(IDD_WHEN_DIALOG, OnWhenDialog)
	ON_COMMAND(IDD_FIND_DIALOG, OnFindDialog)
	ON_COMMAND(IDD_HOW_DIALOG, OnHowDialog)
	ON_COMMAND(IDD_GOTO_ALTAZ_DIALOG, OnGotoAltazDialog)
	ON_COMMAND(IDD_GOTO_RADEC_DIALOG, OnGotoRadecDialog)
	ON_COMMAND(IDD_KEY_DIALOG, OnKeyDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_CONTROL_TIME_NOW, OnControlTimeNow)
	ON_WM_TIMER()
	ON_COMMAND(IDD_UPDATE_DIALOG, OnUpdateDialog)
	ON_COMMAND(ID_CONTROL_TIME_MINUS, OnControlTimeMinus)
	ON_COMMAND(ID_CONTROL_TIME_PLUS, OnControlTimePlus)
	ON_COMMAND(IDD_TOOL_DIALOG, OnToolDialog)
	ON_COMMAND(ID_TASK_INVERT, OnTaskInvert)
	ON_COMMAND(ID_TASK_PLANETS, OnTaskPlanets)
	ON_COMMAND(ID_TASK_STARS, OnTaskStars)
	ON_COMMAND(ID_TASK_AUTOTIME, OnTaskAutotime)
	ON_COMMAND(ID_TASK_OUTLINES, OnTaskOutlines)
	ON_COMMAND(IDD_COMPASS, OnCompass)
	ON_UPDATE_COMMAND_UI(IDD_COMPASS, OnUpdateCompass)
	ON_COMMAND(ID_TASK_MESS, OnTaskMess)
	ON_COMMAND(ID_TASK_LABELS, OnTaskLabels)
	ON_COMMAND(ID_MENU_JUPITER, OnMenuJupiter)
	ON_COMMAND(ID_CONTROL_LOOK_NORTH, OnControlLookNorth)
	ON_COMMAND(ID_CONTROL_LOOK_EAST, OnControlLookEast)
	ON_COMMAND(ID_CONTROL_LOOK_SOUTH, OnControlLookSouth)
	ON_COMMAND(ID_CONTROL_LOOK_WEST, OnControlLookWest)
	ON_COMMAND(ID_CONTROL_LOOK_ZENITH, OnControlLookZenith)
	ON_COMMAND(ID_CONTROL_LOOK_HORIZON, OnControlLookHorizon)
	ON_COMMAND(IDD_KEY_DEFINE, OnKeyDefine)
	ON_COMMAND(IDD_GOTO_MESS_DIALOG, OnGotoMessDialog)
	ON_UPDATE_COMMAND_UI(IDD_TOOL_DIALOG, OnUpdateToolDialog)
	ON_UPDATE_COMMAND_UI(IDD_KEY_DIALOG, OnUpdateKeyDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewMark1View construction/destruction

CViewMark1View::CViewMark1View()
{
	// TODO: add construction code here
	CClientDC aDC(this);
	LoadInfo();	
	win_azm.set_deg(g_win_azm_deg);win_azm.set_min(g_win_azm_min);win_azm.set_sec(0);
	win_alt.set_deg(g_win_alt_deg);win_alt.set_min(g_win_alt_min);win_alt.set_sec(0);

	flags[ToolOn] = false;
	if (flags[TipsOn]) DisplayAbout();
	makegrid(&aDC);
	Recalculate();
}

CViewMark1View::~CViewMark1View()
{
	if (TimerOn) KillTimer(1);
	SaveInfo(); // The right place?
}

BOOL CViewMark1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}



/////////////////////////////////////////////////////////////////////////////
// CViewMark1View drawing

void CViewMark1View::OnDraw(CDC* pDC)
{
	CViewMark1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	DrawSky(pDC);

	if ((flags[ToolOpen])&&(!flags[ToolOn]))
	{
		Tooladlg =new CToolbox_Dialog;
		Tooladlg->Create(IDD_TOOLBOX_DIALOG,this);
		flags[ToolOn]=true;	
	}
}

/////////////////////////////////////////////////////////////////////////////
// CViewMark1View diagnostics

#ifdef _DEBUG
void CViewMark1View::AssertValid() const
{
	CView::AssertValid();
}

void CViewMark1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CViewMark1Doc* CViewMark1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewMark1Doc)));
	return (CViewMark1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewMark1View message handlers


void Zoom(CDC *pDC,double factor)
{
	if ((zoom<=MINZOOM) && (factor<1)) return;
	if ((zoom>=MAXZOOM) && (factor>1)) return;

	zoom*=factor;
	if (keypressed) zoom*=factor;
	update=true;
	DrawSky(pDC);
}


void CViewMark1View::OnControlZoomIn() 
{
	CClientDC aDC(this);
	Zoom(&aDC,(1/1.1));
}

void CViewMark1View::OnControlZoomOut() 
{
	CClientDC aDC(this);
	Zoom(&aDC,1.1);
}


void Look(CDC *pDC, short int dir)
{
	go_vertical=dir;
	if (keypressed) go_vertical=dir*5;
	update=true;
	DrawSky(pDC);
}


void CViewMark1View::OnControlLookDown() 
{
	CClientDC aDC(this);
	if (flags[KeyLook])	Look(&aDC,-1);
	if (flags[KeyZoom]) Zoom(&aDC,1.1);
	if (flags[KeyTime]) TimeAdvance(&aDC,-1);
}

void CViewMark1View::OnControlLookUp() 
{
	CClientDC aDC(this);

	if (flags[KeyLook])	Look(&aDC,1);
	if (flags[KeyZoom]) Zoom(&aDC,1/(1.1));
	if (flags[KeyTime]) TimeAdvance(&aDC,1);
}



void CViewMark1View::OnControlLookLeft() 
{
	go_horizontal=1;
	if (keypressed) go_horizontal=5;
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}

void CViewMark1View::OnControlLookRight() 
{
	go_horizontal=-1;
	if (keypressed) go_horizontal=-5;
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}


void CViewMark1View::OnControlLocation() 
{
	// This menu call pops-up the location dialog

	double templat,templong;
	bool changensew=false;
	bool onorthsouth,oeastwest;

	onorthsouth=northsouth;
	oeastwest=eastwest;

	LocationDialog adlg;

	templat=fabs(local_latitude);
	templong=fabs(local_longitude);

	SplitI(templat, &adlg.m_LAT_DEG,&adlg.m_LAT_MIN,&adlg.m_LAT_SEC);
	SplitI(templong, &adlg.m_LONG_DEG,&adlg.m_LONG_MIN,&adlg.m_LONG_SEC);

	adlg.m_timezone=abs(local_timezone);


	if (adlg.DoModal()==IDOK)
	{
		changensew=true;

		local_longitude=fabs(double(adlg.m_LONG_DEG))+(double(adlg.m_LONG_MIN)/60.0)+(double(adlg.m_LONG_SEC)/3600.0);
		local_latitude=fabs(double(adlg.m_LAT_DEG))+(double(adlg.m_LAT_MIN)/60.0)+(double(adlg.m_LAT_SEC)/3600.0);
			
		local_timezone=adlg.m_timezone;

		if (!eastwest) local_longitude=-local_longitude;
		if (!northsouth) local_latitude=-local_latitude;
		if (!eastwest) local_timezone=-local_timezone;

		// Recalc and redraw

		ResetDate();	// Needed, as location alters local time.
		Recalculate();
		CClientDC aDC(this);
		update=true;
		DrawSky(&aDC);
	}

	if (!changensew)
	{
		northsouth=onorthsouth;
		eastwest=oeastwest;
	}

}



void CViewMark1View::OnWhenDialog() 
{

	CTimeDateDialog adlg;
	CalculateDay();
	CClientDC aDC(this);

	adlg.m_day=local_day;
	adlg.m_month=local_month;
	adlg.m_year=local_year;
	
	adlg.m_sec=local_second;
	adlg.m_min=local_minute;
	adlg.m_hour=local_hour;

	int reply=adlg.DoModal();

	if (reply==IDOK)
	{

		#ifdef DEMO
		MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
		update=true;
		DrawSky(&aDC);
		return;
		#endif

		local_day=adlg.m_day;
		local_month=adlg.m_month;
		local_year=adlg.m_year;
	
		local_second=adlg.m_sec;
		local_minute=adlg.m_min;
		local_hour=adlg.m_hour;

		//local_daylight=adlg.m_dl;

		ResetDate();
		CalculateJulian();
		Recalculate();
		update=true;
		DrawSky(&aDC);
	}
}

void CViewMark1View::OnFindDialog() 
{
	// Launch Find Dialog
	CFindDialog adlg;

	if (adlg.DoModal()==IDOK)
	{
		CClientDC aDC(this);
		CentreBody(&aDC,adlg.m_body);
	}
}

void CViewMark1View::OnHowDialog() 
{

	// Launch Settings Dialog
	CSettingsDialog adlg;
	CClientDC aDC(this);

	short int oldmags = CurrentMags;

	adlg.m_hourglass=	flags[HourGlassOn];
	adlg.m_grid=		flags[GridOn];
	adlg.m_horizon=		flags[HorizonOn];
	adlg.m_stars=		flags[StarsOn];
	adlg.m_planets=		flags[PlanetsOn];
	adlg.m_sites=		flags[SitesOn];
	adlg.m_markers=		flags[MarkersOn];
	adlg.m_labels=		flags[LabelsOn];
	adlg.m_invert=		flags[InvertOn];
	adlg.m_text=		flags[TextOn];
	adlg.m_mess=		flags[MessOn];
	adlg.m_parallax=	flags[ParallaxOn];
	adlg.m_hide=		flags[HideOn];
	adlg.m_sunmoon=		flags[SunMoonOn];
	adlg.m_outline=		flags[OutlineOn];
	adlg.m_realsize=	flags[RealSizeOn];


	if (adlg.DoModal()==IDOK)
	{

		#ifdef DEMO
		MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
		update=true;
		DrawSky(&aDC);
		return;
		#endif

		flags[HourGlassOn]=		adlg.m_hourglass;
		flags[GridOn]=			adlg.m_grid;
		flags[HorizonOn]=		adlg.m_horizon;
		flags[PlanetsOn]=		adlg.m_planets;
		flags[MarkersOn]=		adlg.m_markers;
		flags[LabelsOn]=		adlg.m_labels;
		flags[StarsOn]=			adlg.m_stars;
		flags[SitesOn]=			adlg.m_sites;
		flags[InvertOn]=		adlg.m_invert;
		flags[TextOn]=			adlg.m_text;
		flags[MessOn]=			adlg.m_mess;
		flags[ParallaxOn]=		adlg.m_parallax;
		flags[HideOn]=			adlg.m_hide;
		flags[SunMoonOn]=		adlg.m_sunmoon;
		flags[OutlineOn]=		adlg.m_outline;
		flags[RealSizeOn]=		adlg.m_realsize;
		CurrentMags=			adlg.m_visible_mags;

		Recalculate();
		update=true;
		DrawSky(&aDC);
	}
}

void CViewMark1View::OnGotoAltazDialog() 
{
	// Pop open the goto alt/az menu	

	CGotoAltAzDialog adlg;
	
	adlg.m_gotoazdeg=win_azm.get_deg();
	adlg.m_gotoazmin=win_azm.get_min();
	adlg.m_gotoazsec=int(win_azm.get_sec());
	adlg.m_gotoaltdeg=win_alt.get_deg();
	adlg.m_gotoaltmin=win_alt.get_min();
	adlg.m_gotoaltsec=int(win_alt.get_sec());


	if (adlg.DoModal()==IDOK)
	{
	
		win_azm.set_deg(adlg.m_gotoazdeg);
		win_azm.set_min(adlg.m_gotoazmin);
		win_azm.set_sec(adlg.m_gotoazsec);
		win_alt.set_deg(adlg.m_gotoaltdeg);
		win_alt.set_min(adlg.m_gotoaltmin);
		win_alt.set_sec(adlg.m_gotoaltsec);
		
		CClientDC aDC(this);
		GotoAltAz(&aDC);
	}
}

void CViewMark1View::OnGotoRadecDialog() 
{
	// Pop open the goto ra/dec menu	

	CGotoRaDecDialog adlg;

	adlg.m_gotorahour=win_ra.get_deg();
	adlg.m_gotoramin=win_ra.get_min();
	adlg.m_gotorasec=int(win_ra.get_sec());
	adlg.m_gotodecdeg=win_dec.get_deg();
	adlg.m_gotodecmin=win_dec.get_min();
	adlg.m_gotodecsec=int(win_dec.get_sec());

	if (adlg.DoModal()==IDOK)
	{
		
		win_ra.set_deg(adlg.m_gotorahour);
		win_ra.set_min(adlg.m_gotoramin);
		win_ra.set_sec(adlg.m_gotorasec);
		win_dec.set_deg(adlg.m_gotodecdeg);
		win_dec.set_min(adlg.m_gotodecmin);
		win_dec.set_sec(adlg.m_gotodecsec);

		CClientDC aDC(this);
		GotoRaDec(&aDC);
	}
}

void CViewMark1View::OnKeyDialog() 
{
	// Pop open the key window if one
	// isn't open!

	if (KeyOn==true) 
	{
		Keyadlg->KillDialog();
		return;
	}

	Keyadlg =new CKey_Dialog;
	Keyadlg->Create(IDD_KEY_DIALOG,this);
	KeyOn=true;

}

void CViewMark1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Tap on the screen...
	long x,y;
	CClientDC dc(this);
	CPoint pos = point;
	x=pos.x;
	y=pos.y;

	GotoMouse(&dc,x,y);

	CView::OnLButtonDown(nFlags, point);

}

void CViewMark1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// A key has been pressed

	if (nChar==16) keypressed=true;
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CViewMark1View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// A key has been released

	if (nChar==16) keypressed=false;
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}



void CViewMark1View::OnControlTimeNow() 
{

	//	MessageBox(L"This feature only available in full version.",L"Sorry!",MB_OK);
	//	return;

		When();
		Recalculate();
		CClientDC aDC(this);
		update=true;
		DrawSky(&aDC);
}



void CViewMark1View::OnTimer(UINT nIDEvent) 
{
	// This is the timer event
	CClientDC aDC(this);
	TimeAdvance(&aDC,1);
	CView::OnTimer(nIDEvent);
}

void CViewMark1View::OnUpdateDialog() 
{

	// Open dialog


// if (Expired==true) MessageBox(L"The expiry date for this program has passed.",L"Sorry!",MB_OK);


	CUpdateDialog2 adlg;

	adlg.m_jumpvalue=CurrentJump;
	adlg.m_delayvalue=CurrentDelay;
	adlg.m_how=CurrentUnit;
	adlg.m_who=CurrentTarget;

	if (adlg.DoModal()==IDOK)
	{
		CurrentJump=adlg.m_jumpvalue;
		CurrentDelay=adlg.m_delayvalue;
		CurrentUnit=adlg.m_how;
		CurrentTarget=adlg.m_who;

		if (TimerOn)
		{
			// Kill timer, use new settings
			// Switch timer back on
			KillTimer(1);
			if (!(OrdTimer=SetTimer(1,(1000*CurrentDelay),NULL)))
			{
				MessageBox(L"Timer could not be started.",L"",MB_OK);

				//AfxMessageBox(L"Sorry -- Timer initialisation failed.",MB_OK);
				//AfxAbort();
			}
		}
	}
}

void CViewMark1View::OnControlTimeMinus() 
{
	// Step back a unit	

	CClientDC aDC(this);
	TimeAdvance(&aDC,-1);
}

void CViewMark1View::OnControlTimePlus() 
{
	// Step forward one unit
	
	CClientDC aDC(this);
	TimeAdvance(&aDC,1);
}


void CViewMark1View::OnToolDialog() 
{
	#ifdef DEMO
	MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
	return;
	#endif

	// Two flags for the tool box.
	// One to say, yes, it's active don't open it again
	// The other to say, next time you start, open it.

	if (flags[ToolOn]) 
	{
		// Close it!
		Tooladlg->KillDialog();
		flags[ToolOn]=false;
		flags[ToolOpen]=false;
		return;
	}
	Tooladlg =new CToolbox_Dialog;
	Tooladlg->Create(IDD_TOOLBOX_DIALOG,this);
	flags[ToolOn]=true;
	flags[ToolOpen]=true;
}

void CViewMark1View::OnTaskInvert() 
{
	// Invert the screen colours	
	flags[InvertOn]=!flags[InvertOn];
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}

void CViewMark1View::OnTaskPlanets() 
{
	// Toggle planets on and off
	flags[PlanetsOn]=!flags[PlanetsOn];
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
	
}

void CViewMark1View::OnTaskStars() 
{
	// Toggle stars on and off
	flags[StarsOn]=!flags[StarsOn];
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}



void CViewMark1View::OnTaskAutotime() 
{
	//Switch timer on and off

	#ifdef DEMO
	MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
	return;
	#endif
	
	if (TimerOn) // if timer is already on..
	{
		// Switch timer off
		KillTimer(1);
		TimerOn=false;
	}
	else		// time is not on
	{
		// Create timer
		if (!(OrdTimer=SetTimer(1,(1000*CurrentDelay),NULL)))
		{
			//MessageBox error for timer failure
			MessageBox(L"Error creating timer.",MB_OK);

		}
		else 
			TimerOn=true;
	}	
}



/*
void CViewMark1View::OnControlDelete() 
{
	// Remove Registry details

	#ifdef DEMO
	MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
	return;
	#endif

	DeleteInfo();
	MessageBox(L"Registry settings deleted.",L"Registry settings",MB_OK);
}
*/
/*
void CViewMark1View::OnContolSave() 
{
	// Save Registry settings

	#ifdef DEMO
	MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
	return;
	#endif

	SaveInfo();
	MessageBox(L"Registry settings saved.",L"Registry settings",MB_OK);
}
*/

void CViewMark1View::OnTaskOutlines() 
{
	#ifdef DEMO
	MessageBox(L"Pocket Universe, Demo version.",L"Demo Software",MB_OK);
	#endif

	// Toggle outlines on or off	
	flags[OutlineOn]=!flags[OutlineOn];
	Recalculate();
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}

void CViewMark1View::OnTaskMess() 
{
	// Toggle outlines on or off	
	flags[MessOn]=!flags[MessOn];
	Recalculate();
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}

void CViewMark1View::OnCompass() 
{
	flags[CompassOn]=!flags[CompassOn];
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
	
}

void CViewMark1View::OnUpdateCompass(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(flags[CompassOn]);	
}



void CViewMark1View::OnTaskLabels() 
{
	#ifdef DEMO
	MessageBox(L"Pocket Universe, Demo version.",L"Demo Software",MB_OK);
	#endif

	flags[LabelsOn]=!flags[LabelsOn];
	Recalculate();
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);	
}

void CViewMark1View::OnMenuJupiter() 
{
	// Open Jupiter dialog
	#ifdef DEMO
	MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
	return;
	#endif

	CJovian_Dialog adlg;
	adlg.DoModal();
}

void CViewMark1View::OnControlLookNorth() 
{
	// Quickly look North
	win_azm.set_all(0);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);	
}

void CViewMark1View::OnControlLookEast() 
{
		// Quick look east
	win_azm.set_all(90);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);	
}

void CViewMark1View::OnControlLookSouth() 
{
		// Quick look south	
	win_azm.set_all(180);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);		
}

void CViewMark1View::OnControlLookWest() 
{
	// Quick look west
	win_azm.set_all(270);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);	
}

void CViewMark1View::OnControlLookZenith() 
{
	win_alt.set_all(90);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
}

void CViewMark1View::OnControlLookHorizon() 
{
	win_alt.set_all(0);
	CClientDC aDC(this);
	update=true;
	DrawSky(&aDC);
	
}

void CViewMark1View::OnKeyDefine() 
{
		// Open the Key Define Box

	CCKeyDefineDialog aDlg;

	if (flags[KeyLook]) aDlg.keymode=1;
	if (flags[KeyZoom]) aDlg.keymode=2;
	if (flags[KeyTime]) aDlg.keymode=3;

	if (aDlg.DoModal() == IDOK)
	{

		#ifdef DEMO
		MessageBox(L"Sorry, this feature is only available\nin the full version.",L"Demo Software",MB_OK);
		update=true;
		CClientDC aDC(this);
		DrawSky(&aDC);
		return;
		#endif


		flags[KeyLook]=flags[KeyZoom]=flags[KeyTime]=false;

		switch (aDlg.keymode) 
		{
			case 1:flags[KeyLook]=true;break;
			case 2:flags[KeyZoom]=true;break;
			case 3:flags[KeyTime]=true;break;
		}
	}
}

void CViewMark1View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{

	// Re calc and redraw, as the setting have all changed!
	// Hey, really :-)

	CClientDC aDC(this);
	//When();
	ResetDate();
	CalculateJulian();
	win_azm.set_deg(g_win_azm_deg);win_azm.set_min(g_win_azm_min);win_azm.set_sec(0);
	win_alt.set_deg(g_win_alt_deg);win_alt.set_min(g_win_alt_min);win_alt.set_sec(0);

	Recalculate();
	update=true;
	DrawSky(&aDC);

}

void CViewMark1View::OnGotoMessDialog() 
{
	// Pop open the dialog, and goto the right location. Cool.

	CGotoMessDialog aDlg;
	short int m;

	aDlg.m_messnumber=remember_mess;

	if (aDlg.DoModal() == IDOK)
	{
		remember_mess=aDlg.m_messnumber;
		if (!flags[MessOn])
		{
				flags[MessOn]=true;
				Recalculate();
		}
		m=aDlg.m_messnumber-1;
		win_alt.set_all(R2D(Get_Mess_Alt(m)));
		win_azm.set_all(R2D(Get_Mess_Azm(m)));
		update=true;
		CClientDC aDC(this);
		DrawSky(&aDC);
	}
}

void CViewMark1View::OnUpdateToolDialog(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(flags[ToolOn]);	
}

void CViewMark1View::OnUpdateKeyDialog(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(KeyOn);
	
}
