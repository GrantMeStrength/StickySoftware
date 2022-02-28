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
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolbox_Dialog, CDialog)
	//{{AFX_MSG_MAP(CToolbox_Dialog)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(ID_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolbox_Dialog message handlers

void CToolbox_Dialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	long x,y;
	double z;

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

void CToolbox_Dialog::PostNcDestroy() 
{
	delete this;
	
	//CDialog::PostNcDestroy();
}


void CToolbox_Dialog::OnOK() 
{
//shut
	//flags[ToolOn]=false;
	//flags[ToolOpen]=false;
	DestroyWindow();
//	CDialog::OnOK();
}

void CToolbox_Dialog::KillDialog()
{
	//flags[ToolOn]=false;
	//flags[ToolOpen]=false;
	DestroyWindow();
	delete this;
	//DestroyWindow();
}

BOOL CToolbox_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Load the button images
	
	CBitmapButton button1,button2;
	//button1.AutoLoad(ID_BUTTON1,this);
	//button2.LoadBitmaps(IDB_BUTTON2,IDB_BUTTON2);
	//button2.Invalidate(true);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CToolbox_Dialog::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
}
