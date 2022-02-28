// Toolbox_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Toolbox_Dialog.h"
#include "globalstuff.h"

extern bool update;
extern bool flags[33];
extern double zoom;
extern void TimeAdvance(CDC *pDC,double i);
extern void Zoom(CDC *pDC,double factor);

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

extern short int go_horizontal,go_vertical;
extern class triple win_alt,win_azm;
extern class triple win_ra,win_dec;
extern void DrawSky(CDC *pDC);


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolbox_Dialog dialog


CToolbox_Dialog::CToolbox_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CToolbox_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToolbox_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CToolbox_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolbox_Dialog)
	DDX_Control(pDX, IDC_ZOOM_SLIDER, m_zoom);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolbox_Dialog, CDialog)
	//{{AFX_MSG_MAP(CToolbox_Dialog)
	ON_BN_CLICKED(IDC_BUTTON_NORTH, OnButtonNorth)
	ON_BN_CLICKED(IDC_BUTTON_SOUTH, OnButtonSouth)
	ON_BN_CLICKED(IDC_BUTTON_WEST, OnButtonWest)
	ON_BN_CLICKED(IDC_BUTTONDOWN, OnButtondown)
	ON_BN_CLICKED(IDC_BUTTONLEFT, OnButtonleft)
	ON_BN_CLICKED(IDC_BUTTONRIGHT, OnButtonright)
	ON_BN_CLICKED(IDC_BUTTONUP, OnButtonup)
	ON_BN_CLICKED(IDC_BUTTON_EAST, OnButtonEast)
	ON_BN_CLICKED(IDC_BUTTON_TIMEPLUS, OnButtonTimeplus)
	ON_BN_CLICKED(IDC_BUTTON_TIMEMINUS, OnButtonTimeminus)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_ZOOMOUT, OnButtonZoomout)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMIN, OnButtonZoomin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbox_Dialog message handlers
/*
void CToolbox_Dialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	long x,y;
	//double z;

	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);

	CPoint pos = point;
	x=pos.x;
	y=pos.y;
	
	x=x-2;
	//y=y-(HEIGHT-92);

	//t1=x;t2=y;
	

	// Up, down, left, right
	
	if ((x<22) && (y<22)) go_horizontal=2;
	if ((x>22) && (y<22)) go_horizontal=-2;
	if ((x<22) && (y<42) && (y>22)) go_vertical=-2;
	if ((x>22) && (y<42) && (y>22)) go_vertical=2;


	// North, south, east, west


	if ((y>62) && (y<76))
	{
		if (x<11)				win_azm.set_all(0);
		if ((x>11) && (x<22))	win_azm.set_all(90);
		if ((x>21) && (x<32))	win_azm.set_all(180);
		if (x>32)				win_azm.set_all(270);
	}
	
	// Time controls

	if ((x<22) && (y<62) && (y>42)) {TimeAdvance(&pdc,1);return;}
	if ((x>22) && (y<62) && (y>42)) {TimeAdvance(&pdc,-1);return;}


	// Zooms
	
	if ((y>76) && (x<13)) zoom=MAXZOOM; // Planetarium view


	if ((y>76) && (x>12))
	{
		z=(x-12)/(2.5);
		zoom=1/z;
	}

	
	update=true;
	DrawSky(&pdc);

	CDialog::OnLButtonDown(nFlags, point);
}
*/

void CToolbox_Dialog::PostNcDestroy() 
{
	delete this;
	
	//CDialog::PostNcDestroy();
}

// If this doesn't work, you'll need to
// add this function again, and make sure
// it sets all the correct 

void CToolbox_Dialog::OnOK() 
{
//shut
	//sndPlaySound(L"\\Alarm2", SND_FILENAME|SND_SYNC);
	flags[ToolOn]=false;
	flags[ToolOpen]=false;
	DestroyWindow();
//	CDialog::OnOK();
}


void CToolbox_Dialog::KillDialog()
{
	flags[ToolOn]=false;
	flags[ToolOpen]=false;
	delete this;
	//DestroyWindow();

	//DestroyWindow();
}

BOOL CToolbox_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	pSlide=(CSliderCtrl *)GetDlgItem(IDC_ZOOM_SLIDER);
	pSlide->SetRange(0,8);
	pSlide->SetPageSize(1);
	//pSlide->SetLineSize(5);
	pSlide->SetPos(int(zoom*8)); //1..12.5
	pSlide->SetTicFreq(1);
	
	buttonup.AutoLoad(IDC_BUTTONUP,this);
	buttondown.AutoLoad(IDC_BUTTONDOWN,this);
	buttonleft.AutoLoad(IDC_BUTTONLEFT,this);
	buttonright.AutoLoad(IDC_BUTTONRIGHT,this);

	buttonnorth.AutoLoad(IDC_BUTTON_NORTH,this);
	buttonsouth.AutoLoad(IDC_BUTTON_SOUTH,this);
	buttoneast.AutoLoad(IDC_BUTTON_EAST,this);
	buttonwest.AutoLoad(IDC_BUTTON_WEST,this);

	buttontimeminus.AutoLoad(IDC_BUTTON_TIMEMINUS,this);
	buttontimeplus.AutoLoad(IDC_BUTTON_TIMEPLUS,this);
	buttonzoomin.AutoLoad(IDC_BUTTON_ZOOMIN,this);
	buttonzoomout.AutoLoad(IDC_BUTTON_ZOOMOUT,this);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


/*
void CToolbox_Dialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
	zoom=double(pSlide->GetPos())/100;

	CWnd* phwnd=GetParent();
	//CClientDC dc(this);
	CClientDC pdc(phwnd);
	update=true;
	DrawSky(&pdc);
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
*/


void CToolbox_Dialog::Redraw()
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	update=true;
	DrawSky(&pdc);
}

void CToolbox_Dialog::OnButtonNorth() 
{
	win_azm.set_all(0);
	Redraw();	
}

void CToolbox_Dialog::OnButtonSouth() 
{
	win_azm.set_all(180);
	Redraw();
}



void CToolbox_Dialog::OnButtonWest() 
{
	win_azm.set_all(270);
	Redraw();
	
}

void CToolbox_Dialog::OnButtonEast() 
{
	win_azm.set_all(90);
	Redraw();
	
}


void CToolbox_Dialog::OnButtondown() 
{
	go_vertical=-2;
	Redraw();
}

void CToolbox_Dialog::OnButtonleft() 
{
	go_horizontal=2;
	Redraw();
	
}

void CToolbox_Dialog::OnButtonright() 
{
	go_horizontal=-2;
	Redraw();	
}

void CToolbox_Dialog::OnButtonup() 
{
	go_vertical=2;
	Redraw();	
}




void CToolbox_Dialog::OnButtonTimeplus() 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	TimeAdvance(&pdc,1);
}

void CToolbox_Dialog::OnButtonTimeminus() 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	TimeAdvance(&pdc,-1);
}

void CToolbox_Dialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	pSlide=(CSliderCtrl*)pScrollBar;
	//zoom=(double(pSlide->(GetPos()))+.5)/8;
	zoom=(double(pSlide->GetPos())+0.1)/8;
	Redraw();
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CToolbox_Dialog::OnButtonZoomout() 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	Zoom(&pdc,(1.1));	
	pSlide->SetPos(int(zoom*8));
}

void CToolbox_Dialog::OnButtonZoomin() 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	Zoom(&pdc,(1/1.1));
	pSlide->SetPos(int(zoom*8));
	
}
