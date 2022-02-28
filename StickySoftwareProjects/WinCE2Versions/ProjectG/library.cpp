//
// Library of useful routines
//

extern int HALFHEIGHT;
extern int HALFWIDTH;

#include "stdafx.h"


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
				x0=x;y0=y;code0=FindClipCode(x0,y0);
			} else {
				x1=x;y1=y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {
		pDC->MoveTo(x0+HALFWIDTH,y0+HALFHEIGHT);
		pDC->LineTo(x1+HALFWIDTH,y1+HALFHEIGHT);
	}

}