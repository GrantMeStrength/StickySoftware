//
// Graphics and Drawing routines 
//
//


// Variables

int HALFHEIGHT;
int HALFWIDTH;
int WIDTH;
int HEIGHT;

double viewpoint1=0; //.75;
double viewpoint2;
double zoom=200;
double f=1;

bool start=false;

struct patch_type {
	int height;
	int type; // 0-fair,1-rough,2-wood,3-water,4-sand,5-green
};

struct patch_type course[100][100];

// Includes

#include "math.h"
#include "stdafx.h"

extern void ClipAndDrawLine(CDC *pDC, int x0, int y0, int x1, int y1);


// Functions

void StartUp()
{
	// Once off things
	if (start) return;

	WIDTH=GetSystemMetrics(SM_CXSCREEN);
	HALFWIDTH=WIDTH/2;
	HEIGHT=GetSystemMetrics(SM_CYSCREEN);
	HALFHEIGHT=HEIGHT/2;


	int x,y;
	int r;

	for (x=0;x<100;x++)
		for (y=0;y<100;y++)
		{
			r=int(Random()&3);
			course[x][y].height=1+r; //+Random()&3;
			course[x][y].type=0;
		}

	start=true;
}


void drawpatch(int x, int y, CDC *pDC)
{

	int px1,py1; double pz1;
	int px2,py2; double pz2;
	int px3,py3; double pz3;
	int px4,py4; double pz4;

	int x1,y1,x2,y2,x3,y3,x4,y4;

	px1=x;
	pz1=y;
	py1=double(course[x][y].height)/f;

	px2=x;
	pz2=y+1;
	py2=double(course[x][y+1].height)/f;
	
	px3=x+1;
	pz3=y+1;
	py3=double(course[x+1][y+1].height)/f;

	px4=x+1;
	pz4=y;
	py4=double(course[x+1][y].height)/f;

	// Transform points

	double xx,yy;
	double s,c;

	c=cos(viewpoint1);
	s=sin(viewpoint1);

	xx=double(px1)*c-double(py1)*s;
	yy=double(px1)*s+double(py1)*c;

	x1=xx*zoom/pz1;
	y1=yy*zoom/pz1;

	xx=double(px2)*c-double(py2)*s;
	yy=double(px2)*s+double(py2)*c;

	x2=xx*zoom/pz2;
	y2=yy*zoom/pz2;

	xx=double(px3)*c-double(py3)*s;
	yy=double(px3)*s+double(py3)*c;

	x3=xx*zoom/pz3;
	y3=yy*zoom/pz3;

	xx=double(px4)*c-double(py4)*s;
	yy=double(px4)*s+double(py4)*c;

	x4=xx*zoom/pz4;
	y4=yy*zoom/pz4;

	// Draw patch

	ClipAndDrawLine(pDC, x1,y1,x2,y2);
	ClipAndDrawLine(pDC, x2,y2,x3,y3);
	ClipAndDrawLine(pDC, x3,y3,x4,y4);
	ClipAndDrawLine(pDC, x4,y4,x1,y1);




}

void DrawView(CDC *pDC)
{

	int x,y;

	for (x=0;x<99;x++)
		for (y=0;y<99;y++)
			drawpatch(x,y,pDC);




}