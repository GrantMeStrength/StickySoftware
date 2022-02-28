//
// Common Graphics Routines
//

#include "stdafx.h"
#include "math.h"

#define HALFHEIGHT 240
#define HALFWIDTH 320
#define ORIGIN 0

extern int SX,SY;

double const halfpi = 1.570796327;

double R2D (double angle)
{
	// Convert Radians to Degrees
	return (5.729577951e1*angle);
}

double D2R (double angle)
{
	// Convert Degrees to radians
	return (1.745329252e-2*angle);
}



void MakeLocal(double RA,double Dec, double *Az, double *Alt)
{
	// Convert Dec,RA of an object
	// into local Az, Alt cords for plotting 

	// Values coming in are in Degrees
	// Values leaving are in Radians

	//RA=LST-RA;

	double sy,cy,cx,sx,a,q,cq,b,cp,p;
	double HR,x,y;

	HR=(RA);
	x=D2R(HR*15);
	y=D2R(Dec);

	*Az=(x);
	*Alt=(y);

}


int FindClipCode(int x, int y)
{
	int code=0;

	if (y>HALFHEIGHT) code|=1;
	else if (y<-HALFHEIGHT) code|=2;
	if (x>HALFWIDTH) code|=4;
	else if (x<-HALFWIDTH) code|=8;
	return code;
}


void ClipAndDrawLine(CDC *pDC, int x0, int y0, int x1, int y1)
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
				x0=(int)x;y0=(int)y;code0=FindClipCode(x0,y0);
			} else {
				x1=(int)x;y1=(int)y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {
		pDC->MoveTo(x0+SX,y0+SY);
		pDC->LineTo(x1+SX,y1+SY);
	}

}

void CalcCord( double alt, double az, double ad, double walt, double wazm,  double *x, double *y, double *z)
{
	// All inputs in Radians
	// Alt,Az		= the location of the body in question
	// ad			= magnification factor
	// walt, wazm	= window display position
	// Output
	// x,y,z		= cartesian co-ords for plotting

	double xx,yy,zz;
	double cz,sz,cl,sl;

	az+=halfpi;
	alt=(halfpi)-alt;

	double sa=sin(alt);

	xx=sa*cos(az);
	zz=sa*sin(az);
	yy=cos(alt);

	 // Rotate the co-ords 

	cz=cos(wazm);
	sz=sin(wazm);
	cl=cos(walt);
	sl=sin(walt);
	
	*x=xx*cz+zz*sz;
	*z=-xx*sz+zz*cz;
	zz=*z;
	*y=yy*cl-zz*sl;
	*z=yy*sl+zz*cl;
	*y*=ad;
	*x*=ad;
}

