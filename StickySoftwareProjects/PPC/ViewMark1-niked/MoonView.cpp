//
//	Draw the Moon taking phase into account
//
//


#include "stdafx.h"
#include "math.h"
#include "globalstuff.h"

extern double R2D (double angle);
extern double D2R (double angle);

void DrawMoon(CDC *pDC,int x, int y, float phase)
{
	pDC->Ellipse(x-10,y-10,x+10,y+10);	

	int i,j;
	double xx,yy,xx2;
	
		for (i=0;i<180;i++)
		{
			xx=sin(D2R(i))*50;
			yy=cos(D2R(i))*50;
			xx2=(phase*sin(D2R(i))*50);
			pDC->MoveTo(x+xx,y+yy);
			// White pen
			pDC->LineTo(x+xx-xx2,y+yy);
			// DK grey pen
			pDC->LineTo(x-xx,y+yy);

		}
	
}