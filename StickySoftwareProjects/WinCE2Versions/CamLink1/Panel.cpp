

//
//
// Panel
//
// This file contains the main code which displays the 
// camera's status as well as drawing the thumbnails 
//
//

#include "stdafx.h"


int first=0;		// Smallest picture numbber
int last=0;			// last picture number

bool valid=false;	// Decide if status information is valid
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
long HEIGHT=180;

long THUMBX=150;
long THUMBY=30;



struct palentrytype {
    BYTE peRed; 
    BYTE peGreen; 
    BYTE peBlue; 
    BYTE peFlags; 
	} ;


//
// Define bitmap to hold thumbnail
// Need to store thumbnail as bitmap once
// downloaded, so that opening a menu or
// other screen redraws don't destroy it
//


CBitmap thumb_bitmap;
CDC dcMem;


int screeny=4;

void print(CDC *pDC,BYTE r, BYTE g, BYTE b)
{

	CString ms;
	CRect arect(4,4,320,20);
	arect.SetRect(20,screeny,150,screeny+20);
	ms.Format(L"R:%d G:%d B:%d\0",r,g,b);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);
	//screeny+=20;
}

void DisplayBars(CDC *pDC)
{
	BYTE j=0;

	for (int i=0;i<160;i++)
	{
		pDC->FillSolidRect(THUMBX+i,THUMBY+124,1,8,RGB(j,j,j));
		j=(i*1.6);
	}

//	pDC->FillSolidRect(1,1,1,1,RGB(255,255,255));

}

void PrepDisplay(CDC *pDC)
{
	long x,y;

	x=THUMBX;
	y=THUMBY;

	//COLORREF c;

	pDC->FillSolidRect(0,0,WIDTH,HEIGHT,RGB(192,192,192));
	pDC->FillSolidRect(x-2,y-2,164,124,RGB(255,255,255));
	pDC->FillSolidRect(x,y,160,120,RGB(128,128,128));
	pDC->SetBkColor(RGB(192,192,192));
}


void Display (CDC *pDC)
{
	CString ms;
	CRect arect(4,4,320,20);

	int sy=4;

	CString camera,fl,ba,res;

	PrepDisplay(pDC);

	arect.SetRect(THUMBX+20,4,THUMBX+150,20);
	ms.Format(L"Current picture:%d\0",current_picture);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	if (model==20) camera="DC20\0"; else camera="DC25\0";

	switch (flash) {
		case 0:fl="Auto mode\0";break;
		case 1:fl="Fill mode\0";break;
		case 2:fl="Off\0";break;
		default:fl="Unknown\0";break;
	}

	if (battery==true) ba="OK\0"; else ba="Flat\0";
	if (resolution==true) res="High\0"; else res="Standard\0";

	sy=4;

	arect.SetRect(4,sy,320,sy+16);sy+=16;
	ms.Format(L"Error number:%d\0",error);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	if (valid==false) return;

	arect.SetRect(4,sy,320,sy+16);sy+=16;
	ms.Format(L"Camera is a %s \0",camera);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	arect.SetRect(4,sy,320,sy+16);sy+=16;
	ms.Format(L"Baud rate:%ld\0",baud);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);


	if (model==25)
	{
		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"High res picures left:%d\0",hi_pic_free);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"High res picures taken:%d\0",hi_pic_gone);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Low res picures left:%d\0",lo_pic_free);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Low res picures taken:%d\0",lo_pic_gone);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Flash set to: %s.\0",fl);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);
	}

	if (model==20)
	{

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Resolution set to: %s.\0",res);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Picures remaining:%d\0",all_pic_free);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

		arect.SetRect(4,sy,320,sy+16);sy+=16;
		ms.Format(L"Pictures taken:%d\0",all_pic_gone);
		pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	}

	arect.SetRect(4,sy,320,sy+16);sy+=16;
	ms.Format(L"Battery is: %s.\0",ba);
	pDC->DrawText(ms, arect, DT_LEFT | DT_SINGLELINE);

	if (dcMem)
	{
		pDC->StretchBlt(THUMBX,THUMBY, 160, 120, &dcMem, 0, 0, 80, 60, SRCCOPY);
		DisplayBars(pDC);
	}

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
			i=(BYTE)(int(GetData(y,x))+int(GetData(y,x+1)))/2;
			pDC->SetPixel(xx,yy,RGB(i,i,i));
		}
	}

}




void DrawThumbToBitmap (CDC *pDC)
{

	// DC25 version

	int a=0;
	BYTE i;
	int j,k,l;

	int x,y,cx;

	if (model==25)
	{

		for (y=0;y<60;y++)
		{
			cx=0;
			for (x=0;x<240;x+=3)
			{
				j= picsdata1[a++];
				k= picsdata1[a++];
				l= picsdata1[a++];
				i=(j+k+l)/3;
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

/*  Draw bars on the image
	BYTE q=0;

	for (i=0;i<80;i++)
	{
		pDC->FillSolidRect(i,50,1,4,RGB(q,q,q));
		q=(i*3.2);
	}

	pDC->FillSolidRect(1,1,1,1,RGB(255,255,255));
*/

} 


void InitPanel(CDC *pDC)
{
	if (initdone) return;


	// Define palette

	
	struct paltype {
		WORD	a;
		WORD	b;
		palentrytype PY[16];
	};

	struct paltype mypalette;

	mypalette.a=0x300;
	mypalette.b=16;


	BYTE c=0;
	for (int i=0;i<16;i++)
	{
		mypalette.PY[i].peRed=c;
		mypalette.PY[i].peGreen=c;
		mypalette.PY[i].peBlue=c;
		mypalette.PY[i].peFlags=0;
		c+=15;
	};
	
	
	HPALETTE handle_mypalette;

	handle_mypalette=CreatePalette((const struct tagLOGPALETTE *)&mypalette);


	if (handle_mypalette==NULL)
	{
		error=-1;
		return;
	}
	else
	{
		error=42;
	}

	if (::SelectPalette(pDC->m_hDC,handle_mypalette,FALSE)==NULL)
	{
		error=-2;
		return;
	}
	error=::RealizePalette(pDC->m_hDC);

// Init bitmap

	dcMem.CreateCompatibleDC(pDC);
	//thumb_bitmap.CreateBitmap(80,60,4,4,NULL);
	//thumb_bitmap.LoadBitmap(IDB_BITMAP1); // <- read only :-(
	thumb_bitmap.CreateCompatibleBitmap(pDC,80,60);
	dcMem.SelectObject(&thumb_bitmap);

// pointer to logical color palette 

	initdone=true;
}

void DrawThumb (CDC *pDC)
{


	DrawThumbToBitmap(&dcMem);

	// Copy the thumbnail image to the screen
	//pDC->BitBlt(THUMBX,THUMBY,160,120,&dcMem,0,0,SRCCOPY);

	pDC->StretchBlt(THUMBX,THUMBY, 160, 120, &dcMem, 0, 0, 80, 60, SRCCOPY); 

//	DrawThumbToBitmap(pDC);

}