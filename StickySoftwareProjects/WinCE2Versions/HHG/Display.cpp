//
// Display Graphics
//
#include "stdafx.h"
#include "Resource.h"


HFONT v_hFont;
CString s;
CRect arect(20,20,220,40);

CBitmap screen_bitmap;
CDC pMemDC;
CPen WhitePen,LTGreyPen,DKGreyPen,BlackPen;



int current=1;


#define CX 20
#define CY 20
#define WHITERGB (RGB(255,255,255))
#define BLACKRGB (RGB(0,0,0))
#define LTGREYRGB (RGB(192,192,192))
#define DKGREYRGB (RGB(80,80,80))


void Initialise(CDC *pDC)
{
	pMemDC.CreateCompatibleDC(pDC);
	screen_bitmap.LoadBitmap(IDB_DONTPANIC); // Don't panic
	pMemDC.SelectObject(&screen_bitmap);

	WhitePen.CreatePen(PS_SOLID,1,WHITERGB);
	LTGreyPen.CreatePen(PS_SOLID,1,LTGREYRGB);
	DKGreyPen.CreatePen(PS_SOLID,1,DKGREYRGB);
	BlackPen.CreatePen(PS_SOLID,1,BLACKRGB);

	//pDC->SelectObject(&BlackPen);
	//pDC->SelectStockObject(DKGRAY_BRUSH);
	//pDC->Rectangle(CX-4,CY-4,CX+200+4,CY+200+4);

	LOGFONT         lf;
	memset ((char *)&lf, 0, sizeof(lf));
	//lf.lfPitchAndFamily = FIXED_PITCH;// | FF_MODERN;
	lf.lfHeight = 20; // 13?
	v_hFont = CreateFontIndirect (&lf);


}

void DrawScreen(CDC *pDC)
{
	// Draw current screen

//	pDC->SelectObject(&BlackPen);
	pDC->SelectObject(&LTGreyPen);
	pDC->SelectStockObject(LTGRAY_BRUSH);
//	pDC->Rectangle(CX-4,CY-4,CX+200+4,CY+160+4);
	pDC->Rectangle(0,0,240,320);

	pDC->BitBlt(CX,CY,200,160,&pMemDC,0,0,SRCCOPY);

}

void DisplayPicture(CDC *pDC, int picture)
{

	switch (picture) {
	case 0:	screen_bitmap.LoadBitmap(IDB_DONTPANIC);break;
	case 1:	screen_bitmap.LoadBitmap(IDB_VOGON1);break;
	case 2:	screen_bitmap.LoadBitmap(IDB_VOGON2);break;
	case 3:	screen_bitmap.LoadBitmap(IDB_VOGON3);break;
	case 4:	screen_bitmap.LoadBitmap(IDB_BABEL1);break;
	case 5:	screen_bitmap.LoadBitmap(IDB_BABEL2);break;
	case 6:	screen_bitmap.LoadBitmap(IDB_BABEL3);break;
	case 7:	screen_bitmap.LoadBitmap(IDB_BABEL4);break;
	case 8:	screen_bitmap.LoadBitmap(IDB_BABEL5);break;
	case 9:	screen_bitmap.LoadBitmap(IDB_ALCOHOL1);break;
	case 10:screen_bitmap.LoadBitmap(IDB_ALCOHOL2);break;
	case 11:screen_bitmap.LoadBitmap(IDB_EARTH);break;
	}

	pMemDC.SelectObject(&screen_bitmap);
	DrawScreen(pDC);
}

void DisplayEntry(CDC *pDC,int entry)
{

	sndPlaySound(L"\\Storage Card\\booksound", SND_FILENAME|SND_SYNC);

	if (entry==0) // Vogons
	{
		DisplayPicture(pDC,1);
		sndPlaySound(L"\\Storage Card\\vog1", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,2);
		sndPlaySound(L"\\Storage Card\\vog2", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,3);
		sndPlaySound(L"\\Storage Card\\vog3", SND_FILENAME|SND_SYNC);
	}

	if (entry==1) // Babel
	{
		DisplayPicture(pDC,4);
		sndPlaySound(L"\\Storage Card\\bab1", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,5);
		sndPlaySound(L"\\Storage Card\\bab2", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,6);
		sndPlaySound(L"\\Storage Card\\bab3", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,7);
		sndPlaySound(L"\\Storage Card\\bab4", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,8);
		sndPlaySound(L"\\Storage Card\\bab5", SND_FILENAME|SND_SYNC);
	}

	if (entry==2) // Alcohol
	{
		DisplayPicture(pDC,9);
		sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
		DisplayPicture(pDC,10);
		sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
	}

		if (entry==3) // Earth
	{
		DisplayPicture(pDC,11);
		sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
	}
	
	
}