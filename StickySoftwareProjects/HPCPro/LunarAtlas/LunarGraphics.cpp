//
// Lunar Graphics
//


#include "stdafx.h"
#include "math.h"
#include "Resource.h"

int SY=180;
int SX=180;

#define WIDTH 640
#define HEIGHT 480
#define HALFWIDTH 320
#define HALFHEIGHT 240

double const pi=3.141592649068678;

double size=160;
double walt=-0.05,wazm=0;

double closest=0;
int closest_crater=-1;
int closest_crater_x,closest_crater_y;

bool moon_picture=false;
bool name_seas=false;
bool all_craters=false;

float sin_table[16],cos_table[16];


double zoom=1;

CBitmap hidden_bitmap,lunar_bitmap;
CDC pMemDC,pMemMoonDC;

CString mess;
CRect prect,mrect;
CRect brect(4,4,240,20);
CRect crect(4,20,240,36);
CRect drect(4,36,240,52);

bool once=false,redraw=true;

extern void ClipAndDrawLine(CDC *pDC, int x0, int y0, int x1, int y1);
extern void CalcCord( double alt, double az, double ad, double walt, double wazm,  double *x, double *y, double *z);
extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

extern CString Get_Creater_name(int i);
extern CString Get_Sea_name(int i);


extern double R2D (double angle);
extern double D2R (double angle);

struct Crater_type {
	char name[20];
	float latitude;
	float longitude;
	int diam;
	char desc[80];
} ;
extern struct Crater_type Crater[1542];


struct Sea_type {
	char name[30];
	float latitude;
	float longitude;
	int diam;
	char desc[80];
} ;


extern struct Sea_type Sea[23] ;


void DoOnce(CDC *pDC)
{

	pMemDC.CreateCompatibleDC(pDC);
	hidden_bitmap.CreateCompatibleBitmap(pDC,WIDTH,HEIGHT);
	pMemDC.SelectObject(&hidden_bitmap);

	pMemMoonDC.CreateCompatibleDC(pDC);
	lunar_bitmap.LoadBitmap(IDB_MOON_BITMAP);
	pMemMoonDC.SelectObject(&lunar_bitmap);

	// Make sin/cos table

	int e=0;
	for (double c=0;c<(2*pi);c+=0.4)
	{
		sin_table[e]=sin(c);
		cos_table[e++]=cos(c);
	}

}

void DrawGrid(CDC *pDC, double rotation)
{


	bool draw;
	double alt,azm;
	int ra,dec;
	double x1,y1,z1,x2,y2,z2;

	pDC->SelectStockObject(BLACK_PEN);

	for (ra=0;ra<24;ra++)
	{
		for (dec=-80;dec<80;dec+=10)
		{

			draw=true;
					
			MakeLocal((double)ra,(double)dec,&azm,&alt);
			CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);
			MakeLocal((double)ra,(double)dec+10,&azm,&alt);
			CalcCord(alt,azm,size,walt,wazm,&x2,&y2,&z2);
			
			if (((z1<0) || (z1>pi))) draw=false; // 
			if (((z2<0) || (z2>pi))) draw=false; // 

			if (draw==true)	
				ClipAndDrawLine(pDC,(int)x1,(int)-y1,(int)x2,(int)-y2);
		}
	}
	
	for (dec=-80;dec<=80;dec+=10)
	{	
		for (ra=0;ra<24;ra++)
		{
			draw=true;

			MakeLocal((double)ra,(double)dec,&azm,&alt);
			CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);
			MakeLocal((double)ra+1,(double)dec,&azm,&alt);
			CalcCord(alt,azm,size,walt,wazm,&x2,&y2,&z2);
			
			if (((z1<0) || (z1>pi))) draw=false; // i.e. not behind observer
			if (((z2<0) || (z2>pi))) draw=false; // i.e. not behind observe

			if (draw==true)	
			{
				ClipAndDrawLine(pDC,(int)x1,(int)-y1,(int)x2,(int)-y2);
				
				if ((zoom>6))
				{
					pDC->SetTextColor(RGB(0,0,255));
					mess.Format(L"%2dh %2d°\0",ra,dec);
					x1=HALFWIDTH-x1;
					y1=HALFHEIGHT-y1;
					prect.SetRect(SX+(x1-24),SY+HALFHEIGHT+(-y1+2),SX+(x1+24),SY+HALFHEIGHT+(-y1+18));
					pDC->SetBkMode(TRANSPARENT);
					pDC->DrawText(mess, prect, DT_LEFT | DT_SINGLELINE);
				}
			}
		}
	}
	
}

POINT cords[100];

void PlotCrater(CDC *pDC, 
				double dec, double ra, double diam, 
				int number,bool solid)
{
	double x1,y1,z1,x2,y2,z2;
	double alt,azm;
	double c_dec1,c_ra1,c_dec2,c_ra2;
	double step=0.4;
	bool draw;
	double distance;

	diam=diam/60;
	int cc=0;

	// Quick check for visible side only

	if ((ra>90) || (ra<-90)) return;

	MakeLocal((double)(ra/15),(double)dec,&azm,&alt);
	CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);

	if (((z1<0) || (z1>pi))) ;
	else
	{
		distance=(((SX+x1)-HALFWIDTH)*((SX+x1)-HALFWIDTH))+(((SY-y1)-HALFHEIGHT)*((SY-y1)-HALFHEIGHT));
		if (distance<closest)
		{
			closest=distance;
			closest_crater=number;
		}
	}


	for (int c=0;c<16;c++)
	{

		draw=true;
	
		c_dec1=dec+(sin_table[c]*diam);
		c_ra1=ra+(cos_table[c]*diam);

		c_ra1=c_ra1/15;
			
		MakeLocal((double)c_ra1,(double)c_dec1,&azm,&alt);
		CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);
		
		if (((z1<0) || (z1>pi))) draw=false; 

		if (draw==true) 
		{
			cords[cc].x=SX+x1;
			cords[cc++].y=SY-y1;
			if (cc>99) cc=99;
		}
	}	

	if ((cc!=0) &&(solid)) pDC->Polygon(&cords[0],cc);
	if ((cc!=0) &&(!solid)) pDC->Polyline(&cords[0],cc);

}

void NameCrater(double dec, double ra, double diam, int number,int xx,int yy )
{
	double x1,y1,z1;
	double alt,azm;
	double distance;

	diam=diam/60;

	if ((ra>90) || (ra<-90)) return;

	MakeLocal((double)(ra/15),(double)dec,&azm,&alt);
	CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);

	if (((z1<0) || (z1>pi))) ;
	else
	{
		distance=(((SX+x1)-xx)*((SX+x1)-xx))+(((SY-y1)-yy)*((SY-y1)-yy));
		if (distance<closest)
		{
			closest=distance;
			closest_crater=number;
			closest_crater_x=x1;
			closest_crater_y=y1;
		}
	}
}




void PlotFeature(CDC *pDC,  double dec,double ra)
{
	double x1,y1,z1;
	double alt,azm;

	ra=ra/15;

	MakeLocal((double)ra,(double)dec,&azm,&alt);
	CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);

	if (((z1<0) || (z1>pi))) return;

	
	pDC->Ellipse(SX+x1-4,SY-y1-4,SX+x1+4,SY-y1+4);
	
}

void DrawCraters(CDC *pDC)
{
	pDC->SelectStockObject(LTGRAY_BRUSH);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->SetBkMode(TRANSPARENT);

	int limit;

	if (all_craters) limit=1542; else limit=150;
	for (int i=0;i<limit;i++)

		PlotCrater(	pDC,
					Crater[i].latitude,
					Crater[i].longitude,
					Crater[i].diam,
					i,!moon_picture);


}



void NameSeas(CDC *pDC)
{
	pDC->SelectStockObject(DKGRAY_BRUSH);

	for (int i=0;i<23;i++)

	{

		double x1,y1,z1;
		double ra,dec,azm,alt;

		ra=Sea[i].longitude;
		dec=Sea[i].latitude;
	
		ra=ra/15;

		MakeLocal((double)ra,(double)dec,&azm,&alt);
		CalcCord(alt,azm,size,walt,wazm,&x1,&y1,&z1);

		if (!(((z1<0) || (z1>pi))))
		{
			pDC->Ellipse(SX+x1-1,SY-y1-1,SX+x1+1,SY-y1+1);
			pDC->MoveTo(SX+x1,SY-y1);
			pDC->LineTo(SX+x1-10,SY-y1+8);
			prect.SetRect(SX+x1-60,SY-y1+8,SX+x1+60,SY-y1+24);
			pDC->SetTextColor(RGB(0,0,255));
			mess=Get_Sea_name(i);
			pDC->DrawText(mess, prect, DT_CENTER | DT_SINGLELINE);
		}

	}
		
}


void DrawMoonGrid(CDC *pDC)

// Draw the moon in grid form

{

	closest=1e9;
	closest_crater=-1;

	pDC->FillSolidRect(0,0,WIDTH,HEIGHT,RGB(0,0,0)); 

	//	pDC->BitBlt(SX-size,SY-size,320,320,&pMemMoonDC,0,0,SRCCOPY);

		
		
//		int x, int y, int nWidth, int nHeight, CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop );

	

	// 1. Draw circle

	if (moon_picture)

		pDC->StretchBlt(SX-size,SY-size,size*2,size*2,&pMemMoonDC,0,0,320,320,SRCCOPY);

	else
	{
	pDC->SelectStockObject(LTGRAY_BRUSH);
	pDC->Ellipse(SX-size,SY-size,SX+size,SY+size);
	}


	// 3. Plot points of interest

	if (name_seas) NameSeas(pDC);
	DrawCraters(pDC);

	// 2. Draw grid

	DrawGrid(pDC,0);

	// Draw sights

	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Rectangle(HALFWIDTH-2,HALFHEIGHT-2,HALFWIDTH+2,HALFHEIGHT+2);

	// Draw details

	pDC->SetTextColor(RGB(255,0,0));

	mess.Format(L"Latitude:%d\0",(int)wazm);
	pDC->DrawText(mess, brect, DT_LEFT | DT_SINGLELINE);
	mess.Format(L"Longitude:%d\0",(int)walt);
	pDC->DrawText(mess, crect, DT_LEFT | DT_SINGLELINE);
	if (closest_crater!=-1)
	{
		mess=Get_Creater_name(closest_crater);
		//mess.Format(L"Closest crater:%d '%s'\0",(int)closest,Crater[closest_crater].name);
		pDC->DrawText(mess, drect, DT_LEFT | DT_SINGLELINE);
	}
}

void RecalulateDisplay()
{
	size=160*zoom;

	DrawMoonGrid(&pMemDC);
}

void RefreshDisplay(CDC *pDC)
{
	if (!once) {DoOnce(pDC);once=true;}
	if (redraw) {RecalulateDisplay();redraw=false;};

	pDC->BitBlt(0,0,WIDTH,HEIGHT,&pMemDC,0,0,SRCCOPY);
}

void GotoMouse(CDC *pDC,long x,long y)
{

	SX=(SX+(HALFWIDTH-(int)x));
	SY=(SY+(HALFHEIGHT-(int)y));
	//SY=SY+((int)y-SY);
	redraw=true;
	RefreshDisplay(pDC);
}

void FindMouse(CDC *pDC,long x,long y)
{
	closest=1e9;
	closest_crater=-1;
	
	for (int i=0;i<1542;i++)

	NameCrater(	Crater[i].latitude,
				Crater[i].longitude,
				Crater[i].diam,
				i,x,y);

	RefreshDisplay(pDC);

	pDC->SelectStockObject(WHITE_PEN); 
	PlotCrater(pDC,
		Crater[closest_crater].latitude,
		Crater[closest_crater].longitude,
		Crater[closest_crater].diam,
		closest_crater,false);

	

	//pDC->SetBkMode(TRANSPARENT);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->SelectStockObject(LTGRAY_BRUSH);
	x=SX+closest_crater_x;
	y=SY-closest_crater_y;
	prect.SetRect(x-40,y+8,x+40,y+24);
	pDC->SetTextColor(RGB(0,0,0));
	mess=Get_Creater_name(closest_crater);
	pDC->DrawText(mess, prect, DT_LEFT | DT_SINGLELINE);
	
}
