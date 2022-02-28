// Jovian_Dialog.cpp : implementation file
// (HPC shared)

#include "stdafx.h"
#include "ViewMark1.h"
#include "Jovian_Dialog.h"

extern double Julian;
extern CPen WhitePen,LTGreyPen,DKGreyPen,BlackPen;
extern CBrush WhiteBrush;
extern COLORREF WHITENESSNESS;

extern short int local_day;
extern short int local_month;
extern short int local_year;
extern short int local_hour;
extern short int local_minute;
extern short int local_second;
extern short int local_timezone;
extern short int local_daylight;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJovian_Dialog dialog


CJovian_Dialog::CJovian_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CJovian_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJovian_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJovian_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJovian_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJovian_Dialog, CDialog)
	//{{AFX_MSG_MAP(CJovian_Dialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_JOVE_TIME_PLUS, OnJoveTimePlus)
	ON_BN_CLICKED(IDC_JOVE_TIME_MINUS, OnJoveTimeMinus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJovian_Dialog message handlers


#include "math.h"
extern double TimeT,DJ;
const double pi=3.1415926536;
const double tpi=6.283185307;
double x[5];

extern double Integer(double d);

	double jovian_time; // The Jovian Time

double FNrange(double x)
{
	double b=x/tpi;
	double a=tpi*(b-Integer(b));

	if (a<0) a= tpi+a;
	return a;
}


double CalculateTime()
{



	double lh=double(local_hour)+double(local_minute)/60;
	long c=275*Integer(local_month/9);
	long a=Integer((local_month+9)/12);
	long b=Integer(a/4);

	return 367*local_year-Integer(7*(local_year+Integer((local_month+9)/12))/4)+Integer(275*local_month/9)+local_day-730531.5+(lh/24);

}

void CalculatePositions(double d)
{

	double v,pj,mj,me;
	double j,k,aj,bj; 
	double rads=pi/180;
	double res,rjs,rej,phi,dd,u1,u2,u3,u4,Gj,Hj;
	double r1,r2,r3,r4;



	me = FNrange((357.529 + 0.9856003 * d) * rads);

	v = (172.74 + 0.00111588 * d) * rads;
	pj = 0.329 * sin(v) * rads;
	mj = FNrange((20.02 + 0.0830853 * d) * rads + pj);

	j = FNrange((66.115 + 0.9025179 * d) * rads - pj);
	aj = (1.915 * sin(me) + 0.02 * sin(2 * me)) * rads;
	bj = (5.555 * sin(mj) + 0.168 * sin(2 * mj)) * rads;
	k = j + aj - bj;

	res = 1.00014 - 0.01671 * cos(me) - 0.00014 * cos(2 * me);
	rjs = 5.20872 - 0.25208 * cos(mj) - 0.00611 * cos(2 * mj);
	rej = sqrt(res*res + rjs*rjs - 2 * res * rjs * cos(k));
	phi = asin(res / rej * sin(k));

	dd = d - rej / 173;
	u1 = FNrange((163.8067 + 203.4058643 * dd) * rads + phi - bj);
	u2 = FNrange((358.4108 + 101.2916334 * dd) * rads + phi - bj);
	u3 = FNrange((5.7129 + 50.2345179 * dd) * rads + phi - bj);
	u4 = FNrange((224.8151 + 21.4879801 * dd) * rads + phi - bj);

	Gj = FNrange((331.18 + 50.310482 * dd) * rads);
	Hj = FNrange((87.4 + 21.569231 * dd) * rads);
	r1 = 5.9073 - 0.0244 * cos(2 * (u1 - u2));
	r2 = 9.3991 - 0.0882 * cos(2 * (u2 - u3));
	r3 = 14.9924 - 0.0216 * cos(Gj);
	r4 = 26.3699 - 0.1935 * cos(Hj);
	x[1] = r1 * sin(u1);
	x[2] = r2 * sin(u2);
	x[3] = r3 * sin(u3);
	x[4] = r4 * sin(u4);

}

BOOL CJovian_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Do sums, find locations, plot them

	// Store original time

	jovian_time=CalculateTime();
	CalculatePositions(jovian_time);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

#define MX 94
#define MY 72 //78

void CJovian_Dialog::OnPaint() 
{
	
	CPaintDC dc(this); // device context for painting
	
	// Display stuff

	// Plot them

	CString jmess;
	CRect jrect;

	dc.SetTextColor(WHITENESSNESS);
	dc.SetBkMode(TRANSPARENT);
	dc.FillSolidRect(10,40,175,70,RGB(0,0,0));

	

	// Moons

	int sx=12;
	int by=12;

for (short int i=1;i<5;i++)
	{
		dc.SelectObject(&DKGreyPen);
		dc.MoveTo(3*x[i]+MX,MY);
		dc.LineTo(3*x[i]+MX,MY+sx);
		jrect.SetRect(3*x[i]+MX-2,MY+by,3*x[i]+MX+6,MY+by+12);

		switch (i) {
		case 1:jmess.Format(L"I\0");break;
		case 2:jmess.Format(L"E\0");break;
		case 3:jmess.Format(L"G\0");break;
		case 4:jmess.Format(L"C\0");break;
		}
			
		dc.DrawText(jmess, jrect, DT_LEFT | DT_SINGLELINE);
		sx=-sx;
		if (by==12) by=-28; else by=12;

		dc.SelectObject(&WhiteBrush);
		dc.SelectObject(&WhitePen);
		dc.Ellipse(3*x[i]+MX-2,MY-2,3*x[i]+MX+2,MY+2);
	}

	// Jupiter
	//dc.SelectObject(&WhitePen);
	dc.Ellipse(MX-5,MY-5,MX+5,MY+5);


	//jmess.Format(L"%02d %02d %02d %02d \0",int(x1),int(x2),int(x3),int(x4));
	//dc.DrawText(jmess, jrect, DT_LEFT | DT_SINGLELINE);



	// Do not call CDialog::OnPaint() for painting messages
}

void CJovian_Dialog::OnJoveTimePlus() 
{
	jovian_time+=0.1;
	CalculatePositions(jovian_time);
	InvalidateRect(0);
}

void CJovian_Dialog::OnJoveTimeMinus() 
{
	jovian_time-=0.1;
	CalculatePositions(jovian_time);
	InvalidateRect(0);	
}
