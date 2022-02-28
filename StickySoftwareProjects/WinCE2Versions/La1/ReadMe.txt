
// Draw the 3D Globe

#include "stdafx.h"
#include "math.h"



double la=0;
double lo=0;
double pi=3.14159265;
double r=80,s,c,g;
int t;
int x,y,ox,oy;


long SCREEN_WIDTH=240;
long SCREEN_HEIGHT=90;


float World[] = 
{
	25,58.5, -5, 58.5, -3, 57.6, -4, 57.7, -2, 56, -3, 56, -2, 53, 0.5, 53, 1.6, 52, 1.6, 51.5, 0.5, 51.2, 1.4, 51, 1, 50, -6, 51.4, -3.7, 51.8, -5.5, 52.4, -4, 53.3, -4.6, 53.3, -3, 54.8, -3.8, 54.6, -5, 55.5, -5, 56, -6, 57.5, -6, 58, -5.3, 58.5, -5,
	12,55, -6, 55.2, -8.2, 54.3, -8.3, 54.3, -10, 53.4, -10, 53, -9.2, 52, -10.5, 51.4, -9.5, 52.2, -6.2, 54, -6.2, 54.4, -5.4, 55, -6,
	206,71, 27, 70, 19, 64, 10, 62.5, 5, 58.5, 6, 58, 8, 59, 10.3, 55.4, 13, 56, 16, 60, 19, 61, 17, 66, 22, 65.6, 25, 63, 21, 60, 22, 60.6, 28, 60, 30, 59, 22, 55, 20, 54, 14,
	54.5, 10, 55.8, 12.2, 56, 10, 57.6, 10.3, 57, 8, 54, 8.3, 53.3, 5, 51.4, 3.6, 50.9, 1.6, 50.2, 1.5, 49.7, 0.2, 49.3, -0.1, 49.4, -1.1, 49.8, -1.3, 49.8, -2, 48.7, -1.7, 48.8, -3.1, 48.6, -4.7, 48, -4.7, 47.3, -2.5, 46, -1.2,
	43.3, -1.5, 43.7, -7.7, 43, -9.3, 41, -8.6, 38.6, -9.6, 38.6, -9, 37, -9, 37.1, -6.7, 36, -5.4, 36.5, -4.8, 36.8, -2, 38.7, 0.3, 39.5, -0.4, 41.8, 3.3, 42.7, 3, 43.5, 4, 43.2, 6.2, 44.3, 8.9, 43, 10.5, 41.3, 13,
	40, 15.7, 38.9, 16, 36.6, 15, 38, 12.5, 38, 15.6, 39, 17, 39.7, 16.5, 40.5, 17, 40, 18.5, 42.5, 14.1, 43.6, 13.6, 44.4, 12.3, 45.5, 12.3, 45.7, 13.7, 42, 19.5, 40.5, 19.4, 36.5, 22.8, 38, 24, 40.8, 23, 41, 29,
	43, 27, 47, 31, 46, 33.5, 45.5, 32, 44.3, 34, 46, 37, 46.5, 35, 47, 39, 46, 37, 42.5, 42.3, 41, 38, 42, 35, 41, 29,
	40, 26, 37, 28, 37, 36, 31, 34, 31.6, 31, 31, 29, 33, 21, 30, 19, 34, 10, 35, 11, 37, 10, 37, 1, 35, -2, 35, -5, 35.9, -5.4, 35.8, -6, 31, -10, 30, -10, 28, -13, 21, -17,
	17, -16, 14, -17, 8, -13, 5, -8, 5, -2, 6, 4, 3, 10, -1, 9, -11, 14, -18, 12, -35, 19, -34, 26, -25, 36, -20, 35, -16, 41, -5, 39, 4, 48, 12, 51, 10, 45, 14, 40, 28, 33,
	28, 35, 12.5, 44, 18, 56, 23, 60, 24, 56, 25, 56, 24, 53, 29.5, 48, 30, 50, 25, 56, 25, 67, 21, 72, 12, 75, 8, 77, 10, 80, 6.5, 80, 6, 80.5, 6.5, 82, 7, 82,
	10, 80, 15, 80, 23, 92, 17, 97, 9, 98, 4, 101, 1, 104, 5, 103, 9, 99, 13, 100, 8, 105, 11, 109, 15, 109, 19, 106, 22, 108, 21, 110, 23, 117, 30, 122, 38, 118, 41, 121,
	39, 126, 34, 126, 35, 130, 39, 128, 48, 140, 54, 141, 55, 135, 59, 143, 59, 153, 62, 157, 62, 163, 57, 156, 51, 157, 55, 162, 60, 163, 60, 170, 63, 180, 66, 177, 67, 190, 70, 175,
	72, 130, 74, 110, 77, 112, 72, 70, 69, 67, 68, 44, 64, 40, 65, 35, 67, 33, 66.5, 39, 67.8, 41.5, 71, 27,
	7,66.5, -23, 65, -24, 66.5, -16, 65, -14, 63, -19, 64, -22, 66.5, -23,
	10,43, 9.4, 42.4, 8.5, 41.5, 9, 41, 9.5, 39, 9.5, 39, 8.4, 41, 8.4, 41.3, 9.2, 42, 9.6, 43, 9.4,
	6,-13, 49, -17, 44, -25, 44, -25, 47, -15, 50.5, -13, 49,
	11,60, -44, 65, -40, 70, -22, 82, -15, 83, -30, 78, -73, 76, -68, 70, -51, 66, -54, 61, -48, 60, -44,
	76,63, -77, 52, -56, 50, -65, 46, -62, 44, -70, 42, -71, 41, -74, 35, -76, 31, -81, 27, -80, 25, -81, 28, -83, 30, -84, 29, -90, 27, -97, 22, -98, 19, -97, 19, -91, 21, -90, 21, -87,
	16, -89, 15, -83, 10, -83, 9, -82.5, 10, -79, 8, -77, 11, -75, 12, -71, 11, -63, 4, -52, 0, -50, -6, -34, -12, -39, -22, -41, -25, -48, -28, -48, -41, -63, -51, -69, -55, -65, -55, -70,
	-50, -76, -37, -74, -18, -70, -6, -81, 0, -81, 7, -77, 9, -79, 7, -81, 10, -85, 14, -90, 19, -95, 15.5, -97, 20, -106, 22, -106, 31, -113, 31.5, -115, 30, -115, 23, -110, 25, -112, 30, -116,
	34, -118, 35, -121, 39, -124, 48, -125, 59, -138, 61, -148, 54, -165, 59, -158, 62, -166, 68, -167, 71, -157, 68, -110, 70, -80, 60, -95, 54, -80, 63, -77,
	6,23, -82, 22, -84, 22.5, -82, 20, -78, 20, -74, 23, -82,
	5,20, -73, 20, -70, 18, -68, 18, -74, 20, -73,
	28, -10.5, 142, -18, 141, -15, 136, -12, 137, -11, 132, -15, 129, -14, 127, -20, 120, -22, 114, -32, 116, -35, 115, -35, 118, -32, 130, -35, 135, -33, 138, -35, 138, -38, 140, -39, 143, -38, 145, -39, 146,
	-38, 150, -34, 151, -33, 153, -29, 154, -26, 153, -20, 148, -19, 146, -10.5, 142.4,
	23,-63, -56, -66, -65, -73, -75, -73, -100, -75, -100, -75, -137, -78, -160, -78, 170, -72, 170, -66, 135, -66, 115, -67, 90, -70, 75, -68, 70, -66, 55, -69, 40, -71, 20, -70, 0, -71, -10, -78, -35, -75, -60, -64, -59, -63, -56,
	21,45.5, 142, 43.3, 146, 42, 143, 42.6, 141.6, 40, 140, 38, 139.5, 37, 137, 35.5, 136, 35.5, 133, 33.5, 129.5, 31, 130, 31, 131, 33, 132, 34, 131, 34.5, 135, 33.5, 136, 36, 141, 40, 142, 42, 140, 43.5, 141.5, 45.5, 142,
	10,6, 95, -4, 102, -6, 105, -8, 115, -9, 115, -7, 106, -3, 106, 0, 104, 5, 98, 6, 95,
	6,2, 109, 7, 117, 5, 119, -4, 116, -3, 110, 2, 109,
	10,0, 130, -2, 138, -6, 148, -11, 151, -8, 144, -9, 143, -8, 138, -6, 139, -4, 133, 0, 130,
	13,-35, 173, -37, 176, -38, 177, -37.5, 178.5, -41.6, 175, -40.6, 172.5, -43, 171, -46, 166, -47, 169, -40, 175, -39, 174, -38, 175, -35, 173,
};




void DrawLine(CDC *dc,double ff, double ll)
{
	double d,q,m,u,v,z;

	d=(ll-lo)*g;
	q=sin(d);m=cos(d);
	u=cos(ff*g);v=sin(ff*g);


	x=r*u*q;
	y=(r*(u*m*s-v*c));
	//y=r*v*s+u*m*c;


	x+=SCREEN_WIDTH;
	y+=SCREEN_HEIGHT;

	if (t==0)
	{ 
		ox=x;
		oy=y;
		t=1;
		return;
	}
	
	z=v*s+u*m*c;
	if (z>=0)
	{
		dc->MoveTo(ox,oy);
		dc->LineTo(x,y);
	}
	ox=x;
	oy=y;
	t=1;

}

void DrawGlobe(CDC *dc)
{
	int count=0;
	double ff,ll;
	int n;
	int cc;
	int l,f;

	g=pi/180;
//	r=mag*80;
	s=sin(la*g);
	c=cos(la*g);

	dc->FillSolidRect(0,0,639,180,RGB(255,255,255));

	dc->Ellipse(SCREEN_WIDTH-r,SCREEN_HEIGHT-r,SCREEN_WIDTH+r,SCREEN_HEIGHT+r);


	t=0;for (l=0;l<372;l+=12) DrawLine(dc,66.5,double(l));
	t=0;for (l=0;l<372;l+=12) DrawLine(dc,-66.5,double(l));
	t=0;for (l=0;l<372;l+=12) DrawLine(dc,23.5,double(l));
	t=0;for (l=0;l<372;l+=12) DrawLine(dc,-23.5,double(l));
	t=0;for (l=0;l<372;l+=12) DrawLine(dc,0,double(l));

	t=0;
	for (l=0;l<180;l+=30)
	{
		for (f=-180;f<192;f+=12)DrawLine(dc,double(f),double(l));
		t=0;
	}

	for (cc=0;cc<17;cc++)
	{
		n=int(World[count++]);
		t=0;
		for (int i=0;i<n;i++)
		{
			ff=World[count++];
			ll=World[count++];
			DrawLine(dc,ff,ll);
		}
	}
}


========================================================================
     Microsoft Foundation Class Library for Windows CE: La1
========================================================================


AppWizard has created this La1 application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your La1 application.

La1.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CLa1App application class.

La1.cpp
    This is the main application source file that contains the application
    class CLa1App.

La1.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Developer Studio.

res\La1.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file La1.rc.

res\La1.rc2
    This file contains resources that are not edited by Microsoft 
	Developer Studio.  You should place all resources not
	editable by the resource editor in this file.

La1.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.

res\Cmdbar.bmp
    This bitmap file is used to create tiled images for the command bar.
    The initial command bar is constructed in the CMainFrame class. 
    Edit this cmdbar bitmap along with the array in MainFrm.cpp 
    to add more command bar buttons.


/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

La1Doc.h, La1Doc.cpp - the document
    These files contain your CLa1Doc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CLa1Doc::Serialize).

La1View.h, La1View.cpp - the view of the document
    These files contain your CLa1View class.
    CLa1View objects are used to view CLa1Doc objects.



/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named La1.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Developer Studio reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFCWCXXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFCWCDEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////


int FindClipCode(int x, int y)
{
	int code=0;

	if (y>HALFHEIGHT) code|=1;
	else if (y<-HALFHEIGHT) code|=2;
	if (x>HALFWIDTH) code|=4;
	else if (x<-HALFWIDTH) code|=8;
	return code;
}

void ClipAndDrawLine(CDC *pDC, float dx0, float dy0, float dx1, float dy1)
{

	int code0, code1, codeout;
	bool accept=false, done=false;

	int x0=(int)dx0;
	int x1=(int)dx1;
	int y0=(int)dy0;
	int y1=(int)dy1;

	code0=FindClipCode(x0,y0);
	code1=FindClipCode(x1,y1);

	do {
		if (!(code0 | code1)) { /* Trival -- both inside */ 
			accept=true;done=true;
		} else if (code0 & code1)	/* Both outside */
			done=true;
		else {
			float x,y;
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
				x0=(int)x;y0=(int)y;code0=FindClipCode(x0,y0);
			} else {
				x1=(int)x;y1=(int)y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {
		pDC->MoveTo(x0+ORIGINX+HALFWIDTH,y0+ORIGIN+HALFHEIGHT);
		pDC->LineTo(x1+ORIGINX+HALFWIDTH,y1+ORIGIN+HALFHEIGHT);
	}

}
