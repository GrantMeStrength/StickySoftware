

//
//
// Panel
//
// This file contains the main code which displays the 
// camera's status as well as thumbnail images and so on
//
//

#include "stdafx.h"

int camdata[20];

int error;			// Pass error to display
int model;			// Camera model
long baud;			// Camera connection speed
int flash;			// Camera's flash mode		
bool resolution;	// Camera's resolution
int hi_pic_gone;	// Number of hi-res pictures taken
int lo_pic_gone;	// Number of lo-res pictures taken
int hi_pic_free;	// Number of hi-res pictures free
int lo_pic_free;	// Number of lo-res pictures free
int all_pic_gone;	// Number of pictures taken
int all_pic_free;	// Number of pictures free
bool battery;		// battery state
int current_picture=1;	// Pic to be displayed, downloaded etc
bool initdone=false;
extern BYTE picsdata1[62464];

long WIDTH=480;
long HEIGHT=240;

long THUMBX=150;
long THUMBY=50;

// Define bitmap to hold thumbnail

CBitmap thumb_bitmap;
CDC dcMem;



void PrepDisplay(CDC *pDC)
{
	long x,y;

	x=THUMBX;
	y=THUMBY;

	pDC->FillSolidRect(0,0,WIDTH,HEIGHT,RGB(192,192,192));
	pDC->FillSolidRect(x,y,160,120,RGB(128,128,128));
	
}


void Display (CDC *pDC)
{
	CString ms;
	CRect arect(4,4,320,20);

	int sy=4;

	CString camera,fl,ba,res;

	PrepDisplay(pDC);

	if (model==20) camera="DC20\0"; else camera="DC25\0";

	switch (flash) {
		case 0:fl="Auto mode\0";break;
		case 1:fl="Fill mode\0";break;
		case 2:fl="Off\0";break;
		default:fl="Unknown\0";break;
	}

	if (battery==true) ba="OK\0"; else ba="Flat\0";
	if (resolution==true) res="High\0"; else res="Standard\0";

	arect.SetRect(4,sy,320,sy+20);sy+=20;
	ms.Format("Error number:%d\0",error);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	arect.SetRect(4,sy,320,sy+20);sy+=20;
	ms.Format("Current picture:%d\0",current_picture);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	arect.SetRect(4,sy,320,sy+20);sy+=20;
	ms.Format("Camera is a %s \0",camera);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	arect.SetRect(4,sy,320,sy+20);sy+=20;
	ms.Format("Baud rate:%ld\0",baud);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);


	if (model==25)
	{

		for (int i=0;i<20;i+=2)
		{
			arect.SetRect(4,sy,320,sy+20);sy+=20;
			ms.Format("Mem:%2d:%d Mem:%2d:%2d\0",i+10,camdata[i],i+11,camdata[i+1]);
			pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);
		}
	
	}

	if (model==20)
	{

		arect.SetRect(4,sy,320,sy+20);sy+=20;
		ms.Format("Resolution set to: %s.\0",res);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+20);sy+=20;
		ms.Format("Picures remaining:%d\0",all_pic_free);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+20);sy+=20;
		ms.Format("Pictures taken:%d\0",all_pic_gone);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	}

	arect.SetRect(4,sy,320,sy+20);sy+=20;
	ms.Format("Battery is: %s.\0",ba);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

}


BYTE GetData(int row, int col)
{
	long a=512;

	long b=(row*512)+col;
	return picsdata1[a+b];
}


void Draw(CDC *pDC)
{
	long a=0;
	BYTE i;

	int x,y,xx,yy;


	for (y=0;y<243;y++)
	{
		for (x=0;x<512;x+=2)
		{
			xx=300+x/2;
			yy=30+y;
			i=(GetData(y,x)+GetData(y,x+1))/2;
			pDC->SetPixel(xx,yy,RGB(i,i,i));
		}
	}

}




void DrawThumbToBitmap (CDC *pDC)
{

	// DC25 version

	int a=0;
	BYTE i;

	int x,y,cx;

	if (model==25)
	{

		for (y=0;y<60;y++)
		{
			cx=0;
			for (x=0;x<240;x+=3)
			{
				i= picsdata1[a+=3];
				pDC->SetPixel(cx,y,RGB(i,i,i));
				cx++;
			}
		}
	}
	else		// DC20 version
	{

		for (y=0;y<60;y++)
			for (x=0;x<80;x++)
			{
				i=picsdata1[a++];
				pDC->SetPixel(x,y,RGB(i,i,i));
			}	
	}
} 


void InitPanel(CDC *pDC)
{
	if (initdone) return;
	dcMem.CreateCompatibleDC(pDC);
	thumb_bitmap.CreateCompatibleBitmap(&dcMem,160,120);
	dcMem.SelectObject(&thumb_bitmap);
	initdone=true;
}

void DrawThumb (CDC *pDC)
{


	DrawThumbToBitmap(&dcMem);

	// Copy the thumbnail image to the screen
	//pDC->BitBlt(THUMBX,THUMBY,160,120,&dcMem,0,0,SRCCOPY);

	pDC->StretchBlt(THUMBX,THUMBY, 160, 120, &dcMem, 0, 0, 80, 60, SRCCOPY); 

}