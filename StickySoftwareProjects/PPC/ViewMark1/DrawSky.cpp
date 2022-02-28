
// Sky drawing stuff
// for the PsPC -- so fix the screen size


#include "stdafx.h"
#include "math.h"
#include "globalstuff.h"
#include "Resource.h"

#ifdef DEMO
#define NUMBEROFSTARS 150
#endif

#ifndef DEMO
#define NUMBEROFSTARS 4652
#endif

#define CONSTNUMBER2 299

#define WHITE 3
#define LTGRAY 2
#define DKGRAY 1
#define BLACK 0

#define LIGHTGREYNESS RGB(192,192,192)
#define DARKGREYNESS RGB(128,128,128)
#define BLACKNESSNESS RGB(0,0,0)
#define WHITENESSNESS RGB(255,255,255)


// ** Double buffer stuff ** //

CBitmap hidden_bitmap;
CDC pMemDC;

//CBitmap star_bitmap;
//CDC sMemDC;


// **** Switches *****

bool flags[33];

short int g_win_alt_deg,g_win_azm_deg;
short int g_win_alt_min,g_win_azm_min;

//int TipCount=0;

#define WIDTH 240
#define HALFWIDTH 120
#define HEIGHT 296
#define HALFHEIGHT 148

extern short int CurrentUnit;
extern short int CurrentJump;
extern short int CurrentTarget;
extern short int CurrentMags;
short int StarLimit=0;

double u_ra;
double u_dec;
double u_rt;
double u_st;
double u_raz;
double u_saz;

#include "TripleClass.h"

extern double Julian;
extern double TimeT;
extern double UT;

extern short int local_day;
extern short int local_month;
extern short int local_year;
extern short int local_hour;
extern short int local_minute;
extern short int local_second;
extern short int local_timezone;
extern short int local_daylight;
extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);
extern void ConvertAltAztoRaDec(double azm, double alt, double *ra, double *dec);
extern void CalculateSolarSystem();
extern void When();
//extern void CalculateDay();
//extern void ResetDate();

short int go_horizontal=0,go_vertical=0;

bool changed_w=true;
bool update=true;		// Re-calc, not just redraw

double cz,sz,sl,cl;

CPen WhitePen,LTGreyPen,DKGreyPen,BlackPen,MoonPen;
CPen ThickPenDark, ThickPenLight;

short int oldmg;

CString mess;
CRect prect,mrect;
CRect brect(4,4,240,20);
CRect crect(4,20,240,36);
CRect drect(4,36,240,52);

//CDC dcMem2;
//CBitmap tools;


#include "StarRountines.h"
#include "MessRoutines.h"
#include "ConstRoutines.h"
#include "CNameRoutines.h"

double zoom=0.4; // useful range is 0.4

class triple win_alt,win_azm;
class triple win_ra,win_dec;

extern struct solartype SolarSystem;

extern double R2D (double angle);
extern double D2R (double angle);

double local_longitude;
double local_latitude;
double SinLat = sin(D2R(local_latitude));
double CosLat = cos(D2R(local_latitude));

double const pi=3.141592649068678;
double const halfpi = 1.570796327;
double const rad=3.141592649068678/180;

struct marker_type {
	double az;
	int direction;
};

struct marker_type markers[8];


void CalculateStarAndMess()
{
	// Take all the RA/Dec values from the star and messier
	// tables and planet arrays, and convert them
	// into their Alt,Az values.

	StarLimit=CurrentMags+1;

	if (flags[StarsOn]) CalculateStars(StarLimit);
	if (flags[MessOn]) CalculateMess();
	if (flags[OutlineOn]) CalculateOutlines();
	if (flags[OutlineOn] || flags[StarsOn]) CalculateCNames();
}



void UsePen(CDC *pDC, int pen)
{
	// pen: 0=black,1=dk,2=lt,3=white
	// unless inverted!

	// 4=red, 7=cyan

	if (flags[InvertOn])
	{
		switch (pen)
		{
		case 4:pDC->SelectObject(BlackPen);break;
		case 3:pDC->SelectObject(BlackPen);break;
		case 2:pDC->SelectObject(DKGreyPen);break;
		case 1:pDC->SelectObject(LTGreyPen);break;
		case 0:pDC->SelectObject(WhitePen);break;
		}
	}
	else
	{
		switch (pen)
		{
		case 0:pDC->SelectObject(BlackPen);break;
		case 1:pDC->SelectObject(DKGreyPen);break;
		case 2:pDC->SelectObject(LTGreyPen);break;
		case 3:pDC->SelectObject(WhitePen);break;
		case 4:pDC->SelectObject(MoonPen);break;
		}
	}
}
	
void UseBrush(CDC *pDC,int brush)
{
	// pen: 0=black,1=dk,2=lt,3=white
	// unless inverted!

	if (flags[InvertOn])
	{
		switch(brush)
		{
			case BLACK:pDC->SelectStockObject(WHITE_BRUSH);break;
			case DKGRAY:pDC->SelectStockObject(LTGRAY_BRUSH);break;
			case LTGRAY:pDC->SelectStockObject(DKGRAY_BRUSH);break;
			case WHITE:pDC->SelectStockObject(BLACK_BRUSH);break;
		}
	}
	else
	{
		switch(brush)
		{
			case BLACK:pDC->SelectStockObject(BLACK_BRUSH);break;
			case DKGRAY:pDC->SelectStockObject(DKGRAY_BRUSH);break;
			case LTGRAY:pDC->SelectStockObject(LTGRAY_BRUSH);break;
			case WHITE:pDC->SelectStockObject(WHITE_BRUSH);break;
		}
	}
}

void Recalculate()
{

	// Time or position has changed,
	// so recalculate everything

	CalculateSolarSystem();
	CalculateStarAndMess(); 

}

void makegrid(CDC *pDC)
{
	// Called once, at the very start of the program
	// and sets pens, and reads system clock. 

	pMemDC.CreateCompatibleDC(pDC);
	hidden_bitmap.CreateCompatibleBitmap(pDC,WIDTH,HEIGHT);
	pMemDC.SelectObject(&hidden_bitmap);

//	sMemDC.CreateCompatibleDC(pDC);
//	star_bitmap.LoadBitmap(IDB_BITMAP_STAR);
//	sMemDC.SelectObject(&star_bitmap);


	MoonPen.CreatePen(PS_SOLID,2,WHITENESSNESS);
	WhitePen.CreatePen(PS_SOLID,1,WHITENESSNESS);
	LTGreyPen.CreatePen(PS_SOLID,1,RGB(192,192,192));
	DKGreyPen.CreatePen(PS_SOLID,1,RGB(128,128,128));
	BlackPen.CreatePen(PS_SOLID,1,BLACKNESSNESS);

	ThickPenLight.CreatePen(PS_SOLID,2,RGB(192,192,192));
	ThickPenDark.CreatePen(PS_SOLID,2,RGB(128,128,128));

	if (flags[HourGlassOn]) SetCursor((HCURSOR)IDC_WAIT);

	When();
	Recalculate();

	//Markers
	for (short int i=0;i<8;i++)
	{
		markers[i].az=pi*((double)i/4);
		markers[i].direction=i;
	}

}




// faster
inline short int FindClipCode(int x, int y)
{
	short int code=0;

	if (y>HALFHEIGHT) code|=1;
	else if (y<-HALFHEIGHT) code|=2;
	if (x>HALFWIDTH) code|=4;
	else if (x<-HALFWIDTH) code|=8;
	return code;
}


void ClipAndDrawLine(CDC *pDC, int x0, int y0, int x1, int y1)
{

	short int code0, code1, codeout;
	bool accept=false, done=false;
	code0=FindClipCode(x0,y0);
	code1=FindClipCode(x1,y1);

	do {
		if (!(code0 | code1)) { /* Trival -- both inside */ 
			accept=true;done=true;
		} else if (code0 & code1)	/* Both outside */
			done=true;
		else {
			double x,y;
			codeout=code0 ? code0 : code1;
			if (codeout & 1) {
				x=x0+(x1-x0)*(HALFHEIGHT-y0)/(y1-y0);
				y=HALFHEIGHT;
			} else if (codeout & 2) {
				x=x0+(x1-x0)*(-HALFHEIGHT-y0)/(y1-y0);
				y=-HALFHEIGHT;
			} else if (codeout & 4) {
				y=y0+(y1-y0)*(HALFWIDTH-x0)/(x1-x0);
				x=HALFWIDTH;
			} else {
				y=y0+(y1-y0)*(-HALFWIDTH-x0)/(x1-x0);
				x=-HALFWIDTH;
			}
			if (codeout==code0) {
				x0=x;y0=y;code0=FindClipCode(x0,y0);
			} else {
				x1=x;y1=y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {
		pDC->MoveTo(x0+ORIGIN+HALFWIDTH,y0+ORIGIN+HALFHEIGHT);
		pDC->LineTo(x1+ORIGIN+HALFWIDTH,y1+ORIGIN+HALFHEIGHT);
	}

}

void FindClipLine(int x0, int y0, int x1, int y1, 
				  long *cx0, long *cy0, long *cx1, long *cy1)
{

	int code0, code1, codeout;
	bool accept=false, done=false;
	code0=FindClipCode(x0,y0);
	code1=FindClipCode(x1,y1);

	do {
		if (!(code0 | code1)) { /* Trival -- both inside */ 
			accept=true;done=true;
		} else if (code0 & code1)	/* Both outside */
			done=true;
		else {
			double x,y;
			codeout=code0 ? code0 : code1;
			if (codeout & 1) {
				x=x0+(x1-x0)*(HALFHEIGHT-y0)/(y1-y0);
				y=HALFHEIGHT;
			} else if (codeout & 2) {
				x=x0+(x1-x0)*(-HALFHEIGHT-y0)/(y1-y0);
				y=-HALFHEIGHT;
			} else if (codeout & 4) {
				y=y0+(y1-y0)*(HALFWIDTH-x0)/(x1-x0);
				x=HALFWIDTH;
			} else {
				y=y0+(y1-y0)*(-HALFWIDTH-x0)/(x1-x0);
				x=-HALFWIDTH;
			}
			if (codeout==code0) {
				x0=x;y0=y;code0=FindClipCode(x0,y0);
			} else {
				x1=x;y1=y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {
		*cx0=x0; *cy0=y0;
		*cx1=x1; *cy1=y1;
	} 
	else 
	{
		*cx0=-9999;
		*cx1=-9999;
	}

}





void UpdateViewWindow()
{

	double walt,wazm,wra,wdec;

	walt=win_alt.get_all();
	wazm=win_azm.get_all();

	walt+=go_vertical;
	wazm-=go_horizontal;

	if (walt>90) walt=90;
	if (walt<-90) walt=-90;
	if (wazm>=360) wazm-=360;
	if (wazm<0) wazm+=360;

	win_alt.set_all(walt);
	win_azm.set_all(wazm);

	go_horizontal=0;go_vertical=0;

	// To display the current Ra,Dec
	// we need to convert back from Az,Alt...

	ConvertAltAztoRaDec(D2R(wazm),D2R(walt),&wra,&wdec);
	win_ra.set_all(wra);
	win_dec.set_all(wdec);

	u_ra=wra;
	u_dec=wdec;	// in degrees!


	// Keep an eye on Zoom factor

	if (zoom>MAXZOOM) zoom=MAXZOOM;
	if (zoom<MINZOOM) zoom=MINZOOM;

	// Update this so new S/C values worked out
	changed_w=true;

/* // must be quicker to put this in here!
	cz=cos(wazm);
	sz=sin(wazm);
	cl=cos(walt);
	sl=sin(walt);
*/
}

void DrawSun(CDC *pDC,int x, int y)
{
	float size;

	if (flags[RealSizeOn])	size=(HALFWIDTH/(120*zoom))*SolarSystem.body[MOON].size;
	else size=10;
	UsePen(pDC,WHITE);
	UseBrush(pDC,WHITE);
	pDC->Ellipse(x-(size),y-(size),x+(size),y+(size));

}

void DrawMoon(CDC *pDC,int x, int y, bool venus)
{
	// Doubles up drawing Venus

	short int i,t;
	double xx,yy;
	float size;
	float phase;
	short int s;
	

	if (venus)
	{
		phase=SolarSystem.body[VENUS].phase;
		size=6;
	}
	else
	{
		phase=SolarSystem.body[MOON].phase;
		if (flags[RealSizeOn]) size=(HALFWIDTH/(120*zoom))*SolarSystem.body[MOON].size;
		else size=10;
	}

	//t1=int(phase*100);
	UsePen(pDC,DKGRAY);
	UseBrush(pDC,DKGRAY);
	pDC->Ellipse(x-(size),y-(size),x+(size),y+(size));
	//UsePen(pDC,WHITE);
	UsePen(pDC,4);

	t=(180/size)/2.5;

	if (t<1) t=1;
	if (t>180) t=180;

		s=1;
		for (i=0;i<=91;i+=t)
		{
			xx=sin(D2R(i))*size;
			yy=cos(D2R(i))*size;

			if (phase<0) 
			{
				xx=-xx;
				s=-1;
		
			}
		
			pDC->MoveTo(x-xx,y+yy);
			pDC->LineTo(x-(xx-(phase*xx*2*s)),y+yy);

			pDC->MoveTo(x-xx,y-yy);
			pDC->LineTo(x-(xx-(phase*xx*2*s)),y-yy);

		}
}



//
//void PlotStar1(CDC *pDC,int x,int y,short int mg)
//{
//	  pDC->BitBlt(x,y,4,4,&sMemDC,0,0,SRCCOPY);
//}

void PlotStar(CDC *pDC,int x,int y,short int mg)
{

	switch (mg) {
		case 0: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,WHITE);
				UseBrush(pDC,WHITE);
				oldmg=mg;
			}
			pDC->Ellipse(x-3,y-3,x+3,y+3);
			break;
		}
		case 1: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,WHITE);
				UseBrush(pDC,WHITE);
				oldmg=mg;
			}
			pDC->Ellipse(x-2,y-2,x+3,y+3);
			break;
		}
		case 2: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,WHITE);
				UseBrush(pDC,WHITE);
				oldmg=mg;
			}
			pDC->Ellipse(x-2,y-2,x+2,y+2);
			break;
		}
		case 3: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,WHITE);
				UseBrush(pDC,WHITE);
				oldmg=mg;
			}
			pDC->Ellipse(x-2,y-2,x+1,y+1);
			break;
		}

		case 4: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,LTGRAY);
				UseBrush(pDC,LTGRAY);
				oldmg=mg;
			}
			pDC->Ellipse(x-2,y-2,x+1,y+1);
			break;
		}
		case 5: 
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,LTGRAY);
				UseBrush(pDC,LTGRAY);
				oldmg=mg;
			}
			pDC->Ellipse(x-1,y-1,x+1,y+1);
			break;
		}
		case 6:
		{
			if (oldmg!=mg)
			{
				UsePen(pDC,DKGRAY);
				UseBrush(pDC,DKGRAY);
				oldmg=mg;
			}
			pDC->Ellipse(x-1,y-1,x+1,y+1);
			break;
		}
		default:
		{
			if (oldmg!=mg)
			{
				pDC->SetPixel(x,y,DKGRAY);
				oldmg=mg;
			}
			break;
		}
	}		
}


//void PlotStar(CDC *pDC,int x,int y,short int mg)
//{
//
//	if (flags[SitesOn])
//		PlotStar1(pDC,x,y,mg);
//	else
//		PlotStar2(pDC,x,y,mg);
//}

void DrawSites(CDC *pDC,int x,int y)
{
//	return;

	UsePen(pDC,DKGRAY);

	pDC->MoveTo(x-5,y-5);
	pDC->LineTo(x-10,y-10);
	pDC->MoveTo(x+5,y+5);
	pDC->LineTo(x+10,y+10);
	pDC->MoveTo(x-5,y+5);
	pDC->LineTo(x-10,y+10);
	pDC->MoveTo(x+5,y-5);
	pDC->LineTo(x+10,y-10);

}

// faster!!
//inline 
void CalcCord( double alt, double az, double ad, double walt, double wazm,  double *x, double *y, double *z)
{
	// All inputs in Radians
	// Alt,Az		= the location of the body in question
	// ad			= magnification factor
	// walt, wazm	= window display position
	// Output
	// x,y,z		= cartesian co-ords for plotting

	//double q;

	double xx,yy,zz;
	//float xx,yy,zz; // does this speed it up?

	// Convert to x,y,z

	// Fixes to help Alt/Az fit cos/sin
	az+=halfpi;
	alt=(halfpi)-alt;

//	if (az>2*pi) az-=2*pi;
//	if (az<0) az+=2*pi;
//	if (az>2*pi) az-=2*pi;
//	if (az<0) az+=2*pi;

	double sa=sin(alt);

	xx=sa*cos(az);
	zz=sa*sin(az);
	yy=cos(alt);

	 // Rotate the co-ords 


	if (changed_w==true)
	{
		cz=cos(wazm);
		sz=sin(wazm);
		cl=cos(walt);
		sl=sin(walt);
		changed_w=false;
	}

 // First translation -- side to side

	*x=xx*cz+zz*sz;
//	*y=yy;
	*z=-xx*sz+zz*cz;

	zz=*z;
//	xx=*x;
	 
	// Second translation -- up and down	

	*y=yy*cl-zz*sl;
	*z=yy*sl+zz*cl;

	*y*=ad;
	*x*=ad;


/*

	// new projection

	//	q=(pi/4)-(alt/2);
	//	*x=ad*sin(q)/cos(q)*sin(2*pi-az);
	//	*y=ad*sin(q)/cos(q)*cos(2*pi-az);
*/

}


void DrawStars(CDC *pDC)
{
	double alt,az;
	double x,y,z;
	double ad;
	bool fail;
	short int mg;

	ad=HALFWIDTH/zoom;

	double walt;
	double wazm;
	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	oldmg=99;

	for (short int i=0;i<NUMBEROFSTARS;i++)
	{
		fail=false;

		mg=Get_Star_Mag(i);

		if (mg>StarLimit) {i=NUMBEROFSTARS;break;}
		alt=Get_Star_Alt(i);
		az=Get_Star_Azm(i);
	
//		CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

		if ((flags[HideOn]) || (flags[HorizonOn])) 
			if ((alt)<0) fail=true; // Star beneath horizon...
			
		if (fail==false)
		{
			CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

			if ((z>0) && (z<pi)) // i.e. not behind observer
			{
				if ((x<-HALFWIDTH) || (x>HALFWIDTH) || (y<-HALFHEIGHT) || (y>HALFHEIGHT)) fail=true;
				if (fail==false)// Star visible
					PlotStar(pDC,-x+HALFWIDTH,-y+HALFHEIGHT,mg);
			}
		}
	}
}


void DrawOutlines(CDC *pDC)
{
	double alt,az;
	double x,y,z,ox,oy;
	double ad;
	//int fail;
	bool draw;

	UsePen(pDC,LTGRAY);
	UseBrush(pDC,LTGRAY);

	double walt;
	double wazm;

	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	ad=HALFWIDTH/zoom;

	for (short int i=0;i<CONSTNUMBER2;i++)
	{
		//fail=0;

		alt=Get_Outlines_Alt(i);
		az=Get_Outlines_Azm(i);

		draw=true;
		if (az==-1)
		{
			draw=false; // Goto
			i++;
			alt=Get_Outlines_Alt(i);
			az=Get_Outlines_Azm(i);
		}

		CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

		if ((flags[HideOn]) || (flags[HorizonOn])) 
			if ((alt)<0) draw=false; // Star beneath horizon...
	
		if ((z<0) || (z>pi)) draw=false; // i.e. not behind observer

		y=-y;
		x=-x;
		if (draw==true)	ClipAndDrawLine(pDC,ox,oy,x,y);
		ox=x;
		oy=y;

	}
}

void DrawGrid(CDC *pDC)
{
	double alt,azm;
	short int ra,dec,decp;
	double x1,y1,z1,x2,y2,z2;
	double ad;
	bool draw;

	UsePen(pDC,DKGRAY);

	if (!flags[InvertOn])
	{
		pDC->SetBkColor(BLACKNESSNESS);
		//pDC->SetTextColor(RGB(80,80,80));
		pDC->SetTextColor(RGB(80,80,80));
		
	}
	else
	{
		pDC->SetBkColor(WHITENESSNESS);
		
		pDC->SetTextColor(RGB(192,192,192));
		
	}


	double walt;
	double wazm;

	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	ad=HALFWIDTH/zoom;

for (ra=0;ra<24;ra++)
	{
		for (dec=-80;dec<80;dec+=20)
		{

			draw=true;
					
			MakeLocal((double)ra,(double)dec,&azm,&alt);
			CalcCord(alt,azm,ad,walt,wazm,&x1,&y1,&z1);
			MakeLocal((double)ra,(double)dec+20,&azm,&alt);
			CalcCord(alt,azm,ad,walt,wazm,&x2,&y2,&z2);
		
			//if (flags[HideOn]) 
			//	if ((alt)<0) draw=false; // Point beneath horizon...
	
			if (((z1<0) || (z1>pi))) draw=false; // 
			if (((z2<0) || (z2>pi))) draw=false; // 

			//y1=-y1;x1=-x1;y2=-y2;x2=-x2;
			if (draw==true)	
			{
				ClipAndDrawLine(pDC,-x1,-y1,-x2,-y2);
			}
		}
	}
	for (dec=-80;dec<=80;dec+=20)
	{	
		for (ra=0;ra<24;ra++)
		{
			draw=true;

			MakeLocal((double)ra,(double)dec,&azm,&alt);
			CalcCord(alt,azm,ad,walt,wazm,&x1,&y1,&z1);
			MakeLocal((double)ra+1,(double)dec,&azm,&alt);
			CalcCord(alt,azm,ad,walt,wazm,&x2,&y2,&z2);
		
			//if (flags[HideOn]) 
			//	if ((alt)<0) draw=false; // Point beneath horizon...
	
			if (((z1<0) || (z1>pi))) draw=false; // i.e. not behind observer
			if (((z2<0) || (z2>pi))) draw=false; // i.e. not behind observe

			//y1=-y1;x1=-x1;y2=-y2;x2=-x2;
			if (draw==true)	
			{
				ClipAndDrawLine(pDC,-x1,-y1,-x2,-y2);
				if ((flags[LabelsOn]) && (zoom<0.5))
				{
					mess.Format(L"%2dh %2d°\0",ra,dec);
					//UsePen(pDC,DKGRAY);
					x1=HALFWIDTH-x1;
					y1=HALFHEIGHT-y1;
					prect.SetRect(x1-24,y1+2,x1+24,y1+18);
					pDC->SetBkMode(TRANSPARENT);
					pDC->DrawText(mess, prect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);
				}
			}
		}
	}
}


void DrawEcliptic(CDC *pDC)
{
	double alt,azm;
	short int ra,dec1,dec2;
	double x1,y1,z1,x2,y2,z2;
	double ad;
	bool draw;

	UsePen(pDC,DKGRAY);

	if (!flags[InvertOn])
		pDC->SelectObject(&ThickPenDark);
	else
		pDC->SelectObject(&ThickPenLight);


	double walt;
	double wazm;

	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	ad=HALFWIDTH/zoom;

	for (ra=0;ra<24;ra++)
	{
		// Calculate the tilt
		dec1=23.5*sin(D2R(ra*15));
		dec2=23.5*sin(D2R((ra+1)*15));
		draw=true;

		MakeLocal((double)ra,(double)dec1,&azm,&alt);
		CalcCord(alt,azm,ad,walt,wazm,&x1,&y1,&z1);
		MakeLocal((double)ra+1,(double)dec2,&azm,&alt);
		CalcCord(alt,azm,ad,walt,wazm,&x2,&y2,&z2);
		
		if (((z1<0) || (z1>pi))) draw=false; // i.e. not behind observer
		if (((z2<0) || (z2>pi))) draw=false; // i.e. not behind observe

		
		if (draw==true)	
			ClipAndDrawLine(pDC,-x1,-y1,-x2,-y2);
		
		
	}	
}

void DrawMess(CDC *pDC)
{
	double alt,az;
	double x,y,z;
	double ad;
	short int fail;
	//char name[20];  // name of messier object
	//char *np;

	UsePen(pDC,LTGRAY);
	UseBrush(pDC,DKGRAY);

	ad=HALFWIDTH/zoom;
	
	double walt;
	double wazm;
	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	for (short int i=0;i<110;i++)
	{
		fail=0;

		alt=Get_Mess_Alt(i);
		az=Get_Mess_Azm(i);

		CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

		if ((flags[HideOn])&&(flags[HorizonOn])) 
			if ((alt)<0) fail=1; // Mess beneath horizon...

		if ((z>0) && (z<pi)) // i.e. not behind observer
		//if ((z<90) || (z>270))
		{
			if ((x<-HALFWIDTH) || (x>HALFWIDTH)) fail=1;
			if ((y<-HALFHEIGHT) || (y>HALFHEIGHT)) fail=1;

			x=-x;
			x=x+HALFWIDTH;
			y=-y+HALFHEIGHT;
			
			if (fail==0) // Object visible
			{
				UsePen(pDC,LTGRAY);
				UseBrush(pDC,DKGRAY);
				pDC->Rectangle(x-2,y-2,x+3,y+3);
				prect.SetRect(x-32,y+8,x+96,y+28);

				if (flags[LabelsOn]) 
				{	
					
					mess="M"+Get_Mess_String(i);
					
					UsePen(pDC,DKGRAY);
					pDC->MoveTo(int(x),int(y));
					pDC->LineTo(int(x-12),int(y+16));
					if (!flags[InvertOn])
					{
						pDC->SetBkColor(BLACKNESSNESS);
						pDC->SetTextColor(RGB(170,170,170));
					}
					else
					{
						pDC->SetBkColor(WHITENESSNESS);
						pDC->SetTextColor(RGB(80,80,80));
					}
				pDC->DrawText(mess, prect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);
				}
			}
		}
	}
}

void DrawCompass(CDC *pDC)
{
	short int ly;

	UsePen(pDC,WHITE);
	UseBrush(pDC,WHITE);
	pDC->Ellipse(WIDTH-34-(16),32-(16),WIDTH-34+(16),32+(16));
	UsePen(pDC,BLACK);
	UseBrush(pDC,BLACK);
	pDC->Ellipse(WIDTH-34-(15),32-(15),WIDTH-34+15,32+(15));
	UsePen(pDC,WHITE);
	UseBrush(pDC,WHITE);
	pDC->Ellipse(WIDTH-34-(2),32-(2),WIDTH-34+(2),32+(2));

	pDC->MoveTo(WIDTH-34,32);

	pDC->LineTo(WIDTH-34+(sin(D2R(win_azm.get_deg()))*12),32-(cos(D2R(win_azm.get_deg()))*12));


	// Draw alt line
	UsePen(pDC,WHITE);
	UseBrush(pDC,WHITE);
	pDC->Rectangle(WIDTH-16,32-(16),WIDTH-2,32+(16));
	UsePen(pDC,BLACK);
	UseBrush(pDC,BLACK);
	pDC->Rectangle(WIDTH-15,32-(15),WIDTH-3,32+(15));
	UsePen(pDC,WHITE);
	ly=32-(sin(D2R(win_alt.get_deg()))*12);
	pDC->MoveTo(WIDTH-14,ly);
	pDC->LineTo(WIDTH-4,ly);


}

void DrawConstNames(CDC *pDC)
{
	// Draw names of constellations
	// and also the brightest stars

	double alt,az;
	double x,y,z;
	double ad;
	short int fail;
	//char name[15];  // name of constellation 
	//char *np;
	bool starname;	// used to determine colour
	bool zodiac;	// ditto

	UsePen(pDC,LTGRAY);
	UseBrush(pDC,DKGRAY);

	ad=HALFWIDTH/zoom;

	short int l1;
	short int l2;

	if (flags[StarsOn]==true) l2=55; else l2=32;
	if (flags[OutlineOn]==true) l1=0; else l1=32;
	if (l1==l2) return;

	double walt;
	double wazm;
	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());


	for (short int i=l1;i<l2;i++)
	{
		fail=0;
		if (i<32) starname=false; else starname=true;
		if (i<12) zodiac=true; else zodiac=false;
		
		alt=Get_CName_Alt(i);
		az=Get_CName_Azm(i);

		CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

		if ((flags[HideOn]) || (flags[HorizonOn])) 
			if (alt<0) fail=1; // Constname beneath horizon...

		if ((z>0) && (z<pi)) // i.e. not behind observer
		{
			if ((x<-HALFWIDTH) || (x>HALFWIDTH)) fail=1;
			if ((y<-HALFHEIGHT) || (y>HALFHEIGHT)) fail=1;

			x=-x;
			x=x+HALFWIDTH;
			y=-y+HALFHEIGHT;
			
			if (fail==0) // Object visible
			{
				mess=Get_CString(i);
				UsePen(pDC,DKGRAY);

				pDC->MoveTo(int(x),int(y));
				if (i>24) pDC->LineTo(int(x-12),int(y+16));
				prect.SetRect(x-32,y+8,x+96,y+28);

				if (!flags[InvertOn])
				{
					pDC->SetBkColor(BLACKNESSNESS);
					if (starname) pDC->SetTextColor(RGB(192,192,192));
					if (!starname) pDC->SetTextColor(RGB(255,255,255));
					if ((!starname)&&(zodiac)) pDC->SetTextColor(RGB(192,192,192));
				}
				else
				{
					pDC->SetBkColor(WHITENESSNESS);
					pDC->SetTextColor(RGB(128,128,128));
				}

				pDC->SetBkMode(TRANSPARENT);
				pDC->DrawText(mess, prect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);
			}
		}
	}
}



void DrawSolidHorizon(CDC *pDC)
{
	double alt,az;
	double x,y,z,ox,oy;
	double ad;

	POINT pt[4];

	UsePen(pDC,LTGRAY);
	UseBrush(pDC,LTGRAY);
	ad=HALFWIDTH/zoom;

	ox=-1;oy=-1;
	for (short int i=360;i>270;i-=10)
	{
		az=D2R(i);
		alt=D2R(win_alt.get_all());
		y=sin(alt)*cos(az)*ad;
		x=sin(az)*ad;

		z=R2D(az);

		//if ((z>270))// || (z>270))
		{

			if (ox!=-1)
			{
				if (x<-HALFWIDTH) 
				{
					x=-HALFWIDTH;
					i=260;
				}

				FindClipLine(x,y,x,HALFHEIGHT,&pt[0].x,&pt[0].y,&pt[1].x,&pt[1].y);
				FindClipLine(ox,HALFHEIGHT,ox,oy,&pt[2].x,&pt[2].y,&pt[3].x,&pt[3].y);

				if ((pt[0].x!=-9999) && (pt[2].x!=-9999))
					{
						pt[0].x+=HALFWIDTH;pt[0].y+=HALFHEIGHT;
						pt[1].x+=HALFWIDTH;pt[1].y+=HALFHEIGHT;
						pt[2].x+=HALFWIDTH;pt[2].y+=HALFHEIGHT;
						pt[3].x+=HALFWIDTH;pt[3].y+=HALFHEIGHT;
						pDC->Polygon(pt,4);
						pt[0].x=WIDTH-pt[0].x;
						pt[1].x=WIDTH-pt[1].x;
						pt[2].x=WIDTH-pt[2].x;
						pt[3].x=WIDTH-pt[3].x;
						pDC->Polygon(pt,4);
					}
			}
			ox=x;oy=y;
		}
	}
}


void DrawLineHorizon(CDC *pDC)
{
	double alt,az;
	double x,y,z,ox,oy;
	double ad;

	if (!flags[InvertOn])
		pDC->SelectObject(&ThickPenLight);
	else
		pDC->SelectObject(&ThickPenDark);


	ad=HALFWIDTH/zoom;

	ox=-9999;oy=-1;
	for (short int i=360;i>270;i-=10)
	{
		az=D2R(i);
		alt=D2R(win_alt.get_all());
		y=sin(alt)*cos(az)*ad;
		x=sin(az)*ad;
		z=R2D(az);

		if (ox!=-9999)
		{
			if (x<-HALFWIDTH) 
			{
				x=-HALFWIDTH;
				i=260;
			}
			ClipAndDrawLine(pDC,x,y,ox,oy);
			ClipAndDrawLine(pDC,-x,y,-ox,oy);
		}
		ox=x;oy=y;
	}
}


void DrawMarkers(CDC *pDC)
{
	double alt,az;
	double x,y,z;
	double ad;
	short int fail;


	UsePen(pDC,LTGRAY);

	ad=HALFWIDTH/zoom;

	double walt;
	double wazm;
	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	for (short int i=0;i<8;i++)
	{
		fail=0;

		alt=0;
		az=markers[i].az;

	
		CalcCord(alt,az,ad,walt,wazm,&x,&y,&z);

		if ((z>0) && (z<pi)) // i.e. not behind observer
		//if ((z<90) || (z>270))
		{
			// Draw Marker
			x=-x;
			x=x+HALFWIDTH;
			y=-y+HALFHEIGHT;
	
			mrect.SetRect(x-16,y-16,x+16,y+16);
			switch (markers[i].direction) 
			{
				case 0: {mess="N";break;}
				case 1: {mess="NE";break;}
				case 2: {mess="E";break;}
				case 3: {mess="SE";break;}
				case 4: {mess="S";break;}
				case 5: {mess="SW";break;}
				case 6: {mess="W";break;}
				case 7: {mess="NW";break;}
			}
				if (!flags[InvertOn])
					{
						pDC->SetBkColor(BLACKNESSNESS);
						pDC->SetTextColor(LIGHTGREYNESS);
					}
					else
					{
						pDC->SetBkColor(WHITENESSNESS);
						pDC->SetTextColor(DARKGREYNESS);
					}
			pDC->DrawText(mess, mrect, DT_CENTER | DT_SINGLELINE);
		}
	}
}


void DrawHorizon(CDC *pDC)
{
	if (flags[HorizonOn]) DrawSolidHorizon(pDC);
	else  DrawLineHorizon(pDC);

}


void DrawPlanets(CDC *pDC)
{
	double alt,az;
	double xx,yy,zz;
	short int x,y;
	double ad;
	short int fail;

	UsePen(pDC,WHITE);
	UseBrush(pDC,DKGRAY);

	ad=HALFWIDTH/zoom;

	double walt;
	double wazm;
	walt=D2R(win_alt.get_all());
	wazm=D2R(win_azm.get_all());

	for (short int i=0;i<10;i++)
	{
		fail=0;

		if ((!flags[PlanetsOn]) && ((i>SUN) && (i<MOON))) fail=1;
		if ((!flags[SunMoonOn]) && ((i==SUN) || (i==MOON))) fail=1;

		alt=SolarSystem.body[i].alt;
		az=SolarSystem.body[i].az;

		CalcCord(alt,az,ad,walt,wazm,&xx,&yy,&zz);


		if ((flags[HideOn]) || (flags[HorizonOn])) 
			if (alt<0) fail=1; // planets beneath horizon...

			
		
		if ((zz>0) && (zz<pi)) // i.e. not behind observer
		//if ((zz<90) || (zz>270))
		{
			if ((xx<-HALFWIDTH) || (xx>HALFWIDTH)) fail=1;
			if ((yy<-HALFHEIGHT) || (yy>HALFHEIGHT)) fail=1;

			xx=-xx;
			x=int(xx+HALFWIDTH);
			y=int(-yy+HALFHEIGHT);

			UsePen(pDC,WHITE);
			UseBrush(pDC,LTGRAY);

			if (fail==0) // Body visible
			{
				prect.SetRect(x-36,y+6,x+36,y+20);
				switch (i) {
				case SUN: 
					{
				
						DrawSun(pDC,x,y);
						mess="Sun";
						break;
					}
				case MOON: 
					{
						DrawMoon(pDC,x,y,false);
						mess="Moon";
						break;
					}

				case MERCURY:
					{
						pDC->Ellipse(x-1,y-1,x+1,y+1);
						mess="Mercury";
						break;
					}

				case VENUS:
					{
						if (flags[EclipticOn])
							DrawMoon(pDC,x,y,true);
						else
						{
							//UsePen(pDC,LTGRAY);
							pDC->Ellipse(x-2,y-2,x+2,y+2);
						}
						mess="Venus";
						break;
					}

				case MARS:
					{
						pDC->Ellipse(x-2,y-2,x+2,y+2);
						mess="Mars";
						break;
					}
				
				case JUPITER:
					{
						pDC->Ellipse(x-5,y-5,x+5,y+5);
						mess="Jupiter";
						break;
					}
				case SATURN:
					{
						
						pDC->Ellipse(x-4,y-4,x+4,y+4);
						pDC->MoveTo(int(x-6),int(y-6));
						pDC->LineTo(x+6,y+6);
						mess="Saturn";
						break;
					}
				case URANUS:
					{
						pDC->Ellipse(int(x-3),int(y-3),int(x+3),int(y+3));
						mess="Uranus";
						break;
					}
				case NEPTUNE:
					{
						pDC->Ellipse(int(x-3),int(y-3),int(x+3),int(y+3));
						mess="Neptune";
						break;
					}
				case PLUTO:
					{
						pDC->Ellipse(int(x-1),int(y-1),int(x+1),int(y+1));
						mess="Pluto";
						break;
					}
			
				default :;
				}
				if (flags[LabelsOn]) 
				{	
					UsePen(pDC,DKGRAY);
					pDC->MoveTo(int(x),int(y));
					pDC->LineTo(int(x-16),int(y+12));
					if (!flags[InvertOn])
					{
						pDC->SetBkColor(BLACKNESSNESS);
						pDC->SetTextColor(RGB(170,170,170));
					}
					else
					{
						pDC->SetBkColor(WHITENESSNESS);
						pDC->SetTextColor(BLACKNESSNESS);
					}
					pDC->DrawText(mess, prect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);
				}
			}
		}

	}

}



void DrawHiddenSky (CDC *pDC)
{

	CString ms;


	if (!flags[InvertOn])
		pDC->FillSolidRect(ORIGIN,ORIGIN,ORIGIN+WIDTH+4,ORIGIN+HEIGHT+4,BLACKNESSNESS); 

	else
		pDC->FillSolidRect(ORIGIN,ORIGIN,ORIGIN+WIDTH+4,ORIGIN+HEIGHT+4,WHITENESSNESS); 

	UpdateViewWindow();
	if (flags[GridOn]) DrawGrid(pDC);
	if (flags[OutlineOn]) DrawOutlines(pDC);
	if (flags[LabelsOn]) DrawConstNames(pDC);
	if (flags[EclipticOn]) DrawEcliptic(pDC);
	if (flags[StarsOn]) DrawStars(pDC);
	if (flags[MessOn]) DrawMess(pDC);
	DrawPlanets(pDC);
	DrawHorizon(pDC);
	if (flags[MarkersOn]) DrawMarkers(pDC);
	if (flags[SitesOn]) DrawSites(pDC,HALFWIDTH,HALFHEIGHT);
	if (flags[CompassOn]) DrawCompass(pDC);

	if (flags[TextOn])
	{
		
		if (!flags[InvertOn])
		{
			pDC->SetBkColor(BLACKNESSNESS);
			pDC->SetTextColor(WHITENESSNESS);
		}
		else
		{
			pDC->SetBkColor(WHITENESSNESS);
			pDC->SetTextColor(BLACKNESSNESS);
		}

		pDC->SetBkMode(OPAQUE);

		switch (local_month) {
		case 1:ms=L"Jan";break;
		case 2:ms=L"Feb";break;
		case 3:ms=L"Mar";break;
		case 4:ms=L"Apr";break;
		case 5:ms=L"May";break;
		case 6:ms=L"Jun";break;
		case 7:ms=L"Jul";break;
		case 8:ms=L"Aug";break;
		case 9:ms=L"Sep";break;
		case 10:ms=L"Oct";break;
		case 11:ms=L"Nov";break;
		case 12:ms=L"Dec";break;
		default:ms=L"---";break;
		}

		mess.Format(L"%02d:%02d:%02d  %2d %s %d\0",local_hour,local_minute,local_second,local_day,ms,local_year);
		pDC->DrawText(mess, brect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);

		mess.Format(L"Az:%03d:%02d Alt:%02d:%02d\0",win_azm.get_deg(),win_azm.get_min(),win_alt.get_deg(),win_alt.get_min());
		pDC->DrawText(mess, crect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);

		mess.Format(L"Ra:%02d:%02d Dec: %02d:%02d\0",win_ra.get_deg(),win_ra.get_min(),win_dec.get_deg(),win_dec.get_min());
		pDC->DrawText(mess, drect, DT_NOCLIP | DT_LEFT | DT_SINGLELINE);
	}

}


void DrawSky (CDC *pDC)
{
	// Draw everything to hidden bitmap

	if (update) 
	{
		if (flags[HourGlassOn]) SetCursor((HCURSOR)IDC_WAIT);
		DrawHiddenSky(&pMemDC);
		update=false;
		if (flags[HourGlassOn]) SetCursor(NULL);
	}

	pDC->BitBlt(0,0,WIDTH,HEIGHT,&pMemDC,0,0,SRCCOPY);

	g_win_alt_min=win_alt.get_min();
	g_win_azm_min=win_azm.get_min();
	g_win_alt_deg=win_alt.get_deg();
	g_win_azm_deg=win_azm.get_deg();
}


void GotoAltAz(CDC *pDC)
{
	update=true;
	DrawSky(pDC);
}

void CentreBody(CDC *pDC,int body)
{

	// Centre the necessary thing

	if ((body<0) || (body>10)) return;

	win_alt.set_all(R2D(SolarSystem.body[body].alt));
	win_azm.set_all(R2D(SolarSystem.body[body].az));
	update=true;
	DrawSky(pDC);
}

void CentreConst(CDC *pDC,int which)
{

	// Centre the necessary thing

	win_alt.set_all(R2D(Get_CName_Alt(which)));
	win_azm.set_all(R2D(Get_CName_Azm(which)));
	update=true;
	DrawSky(pDC);
}

void TimeAdvance(CDC *pDC,double i)
{
	switch (CurrentUnit)
	{
		case 0:Julian+=(i*double(CurrentJump)/86400);break; //Second
		case 1:Julian+=(i*double(CurrentJump)/1440);break; //Minute
		case 2:Julian+=(i*double(CurrentJump)/24);break; // hour
		case 3:Julian+=i*double(CurrentJump);break; // day
		case 4:Julian+=i*double(CurrentJump)*30;break; // Months
		case 5:Julian+=i*double(CurrentJump)*365.25;break; // years
	}

	Recalculate();
	if (CurrentTarget!=10)
		CentreBody(pDC,CurrentTarget);
	else
	{
		update=true;
		DrawSky(pDC);
	}
}

void GotoRaDec(CDC *pDC)
{
	// Centre the display on given Ra and Dec
	// co-ordinates
	double alt,az;
	double ra,dec;

	ra=win_ra.get_all();
	dec=win_dec.get_all();

	// CORRECT VALUES FOR RA/DEC REACH HERE in degrees
	
	//t1=ra;t2=dec;

	MakeLocal(ra,dec,&az,&alt); // in degs, out rads
	
	alt=R2D(alt);
	az=R2D(az);
	win_alt.set_all(alt);
	win_azm.set_all(az);

	ConvertAltAztoRaDec(D2R(az),D2R(alt),&ra,&dec);
	win_ra.set_all(ra);
	win_dec.set_all(dec);

	//t3=ra;t4=dec;

	update=true;
	DrawSky(pDC);
}

void DrawKey(CDC *pDC)
{
	// Draw some stars for the key window

	short int y=30;
	oldmg=99;
	UseBrush(pDC,BLACK);

	pDC->Rectangle(40,22,68,116);

	for (short int i=0;i<6;i++)
	{
		PlotStar(pDC,54,y,i);
		y+=16;
	}

}


bool SearchAzm(double l1, double l2, double step, 
			   double x, double falt, double *fazm,
			   double walt, double wazm, double ad)
{
	// Find the closest Azm to produce a similar X-cord
	
	double closest=1e20;
	double distance;

	*fazm=-1;

	double tazm;
	double xx,yy,zz;

	double ls;

	if (l2<l1) {ls=l1;l1=l2;l2=ls;};

	for (tazm=l1;tazm<l2;tazm+=step)
	{
		CalcCord(D2R(falt),D2R(tazm),ad,walt,wazm,&xx,&yy,&zz);
		
		if ((zz>0) && (zz<pi))
		{

			xx=-xx;
			xx=xx+HALFWIDTH;

			if ((xx>0) && (xx<WIDTH))
			{
	
				distance=(xx-x)*(xx-x);
				if (distance<closest)
				{
					closest=distance;
					*fazm=tazm;
				}
			}
		}
	
	}

	if (*fazm==-1) return false; else return true;
}

bool SearchAlt(double l1, double l2, double step, 
			   double y, double *falt, double fazm,
			   double walt, double wazm, double ad)
{
	// Find the closest Alt to produce a similar Y-cord
	
	double closest=1e20;
	double distance;

	*falt=-1;

	double talt;
	double xx,yy,zz;

	double ls;
	if (l2<l1) {ls=l1;l1=l2;l2=ls;};

	for (talt=l1;talt<l2;talt+=step)
	{
		CalcCord(D2R(talt),D2R(fazm),ad,walt,wazm,&xx,&yy,&zz);
		
		yy=-yy;
		yy=yy+HALFHEIGHT;

		if ((yy>0) && (yy<HEIGHT))
		{
			distance=(yy-y)*(yy-y);
			if (distance<closest)
			{
				closest=distance;
				*falt=talt;
			}
		}
	}

	if (*falt==-1) return false; else return true;
}

void FindLocation(long x,long y)
{
	double ad;
	double wazm,walt;

	walt=(win_alt.get_all());
	wazm=(win_azm.get_all());

	double fazm,falt;
	ad=HALFWIDTH/zoom;
	falt=0;

	// Phase one search...

	if (!SearchAzm(0,360,1,x,falt,&fazm,walt,wazm,ad)) return;
	if (!SearchAlt(-90,90,1,y,&falt,fazm,walt,wazm,ad)) return;

	// Phase two search

	if (!SearchAzm(fazm-5,fazm+5,.1,x,falt,&fazm,walt,wazm,ad)) return;
	if (!SearchAlt(falt-5,falt+5,.1,y,&falt,fazm,walt,wazm,ad)) return;

	// Phase three search

	if (!SearchAzm(fazm-4,fazm+4,.1,x,falt,&fazm,walt,wazm,ad)) return;
	if (!SearchAlt(falt-4,falt+4,.1,y,&falt,fazm,walt,wazm,ad)) return;

	// Phase four search

	if (!SearchAzm(fazm-2,fazm+2,.05,x,falt,&fazm,walt,wazm,ad)) return;
	if (!SearchAlt(falt-2,falt+2,.05,y,&falt,fazm,walt,wazm,ad)) return;

	win_alt.set_all(falt);
	win_azm.set_all(fazm);
	update=true;


}
void GotoMouse(CDC *pDC,long x,long y)
{
	update=false;
	UsePen(pDC,LTGRAY);
	DrawSites(pDC,x,y);
	FindLocation(x,y);
	if (update==false) 
	{ // fix freezing
		if (win_alt.get_all()==90)
		{	
			update=true;
			win_alt.set_all(89.9999);
		}
	}

	DrawSky(pDC);
}
