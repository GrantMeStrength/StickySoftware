// Draw the moon!

#include "stdafx.h"
#include "Resource.h"
#include "math.h"

#define CX=120
#define CY=160

CBitmap lunar_bitmap;
CDC pMemDC;



void Initialise(CDC *pDC)
{
	pMemDC.CreateCompatibleDC(pDC);
	lunar_bitmap.LoadBitmap(IDB_MOON_BITMAP);
	pMemDC.SelectObject(&lunar_bitmap);
}


void DrawGrid(CDC *pDC)
{



void DrawMoon(CDC *pDC, short int x, short int y, float z)
{

//	pDC->BitBlt(0,0,240,240,&pMemDC,x,y,SRCCOPY);

	pDC->StretchBlt(0,0,240,240,&pMemDC,x,y,(240*z),(240*z),SRCCOPY);


}