//
// Game code
//

#include "stdafx.h"
#include "Resource.h"
#include "Dialog_Finished.h"

HFONT v_hFont;
CString s;
CRect arect(20,20,220,40);

int current_pattern=1;
int turns;
int grid[4][4];
bool shuffle=false;
bool complete=false;

CBitmap hidden_bitmap,drawing_bitmap,logo_bitmap;
CDC pMemDC,dMemDC,lMemDC;
CPen WhitePen,LTGreyPen,DKGreyPen,BlackPen;


#define SX 20
#define SY 50
#define SIZE 50
#define WHITERGB (RGB(255,255,255))
#define BLACKRGB (RGB(0,0,0))
#define LTGREYRGB (RGB(192,192,192))
#define DKGREYRGB (RGB(80,80,80))


void Initialise(CDC *pDC)
{
	pMemDC.CreateCompatibleDC(pDC);
	hidden_bitmap.CreateCompatibleBitmap(pDC,240,320);
	pMemDC.SelectObject(&hidden_bitmap);

	dMemDC.CreateCompatibleDC(pDC);
	drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR1);
	dMemDC.SelectObject(&drawing_bitmap);

	lMemDC.CreateCompatibleDC(pDC);
	logo_bitmap.LoadBitmap(IDB_BITMAP_LOGO);
	lMemDC.SelectObject(&logo_bitmap);

	pMemDC.SelectStockObject(WHITE_BRUSH);
	pMemDC.Rectangle(0,0,240,318);

	pMemDC.SelectStockObject(LTGRAY_BRUSH);
	pMemDC.Rectangle(SX-4,SY-4,SX+(SIZE*4)+4,SY+(SIZE*4)+4);

	WhitePen.CreatePen(PS_SOLID,1,WHITERGB);
	LTGreyPen.CreatePen(PS_SOLID,1,LTGREYRGB);
	DKGreyPen.CreatePen(PS_SOLID,1,DKGREYRGB);
	BlackPen.CreatePen(PS_SOLID,1,BLACKRGB);

	LOGFONT         lf;
	memset ((char *)&lf, 0, sizeof(lf));
	//lf.lfPitchAndFamily = FIXED_PITCH;// | FF_MODERN;
	lf.lfHeight = 20; // 13?
	v_hFont = CreateFontIndirect (&lf);
	
	turns=0;
}

void Tile(CDC *pDC, int xx, int yy, int block)
{
	// Draw at xx,yy the tile given by block
	int fx,fy;
	int bx,by;


	by=block/4;
	bx=(block-(by*4));

	fx=bx*SIZE;
	fy=by*SIZE;

	if ((block==15) && (complete==false))
		pDC->BitBlt(xx,yy,SIZE,SIZE,&lMemDC,0,0,SRCCOPY);
	else
		pDC->BitBlt(xx,yy,SIZE,SIZE,&dMemDC,fx,fy,SRCCOPY);

}

void DrawBlock(CDC *pDC, int x, int y)
{


	int xx,yy;

	xx=SX+SIZE*x;
	yy=SY+SIZE*y;

	Tile(&pMemDC,xx,yy,grid[x][y]);

}




void DrawAllBlocks(CDC *pDC)
{
	int x,y;

	for (y=0;y<4;y++)
		for (x=0;x<4;x++)
			DrawBlock(&pMemDC,x,y);

	pDC->BitBlt(0,0,240,318,&pMemDC,0,0,SRCCOPY);
	pDC->SelectObject(v_hFont);
	pDC->SelectObject(&BlackPen);
	s.Format (L"Turns: %5d",turns);
	pDC->DrawText(s, arect, DT_CENTER | DT_SINGLELINE);



}

void AnimateBlock(CDC *pDC, int x, int y, int block, int dx, int dy)
{

	int xx,yy;

	xx=SX+SIZE*x;
	yy=SY+SIZE*y;

	// Draw new
	DrawAllBlocks(pDC);
	//pDC->BitBlt(0,0,240,320,&pMemDC,0,0,SRCCOPY);

	for (int q=1;q<(SIZE/4);q++)
	{

		pMemDC.SelectStockObject(LTGRAY_BRUSH);
		pMemDC.Rectangle(SX,SY,SX+(SIZE*4),SY+(SIZE*4));

		pDC->BitBlt(xx,yy,50,50,&pMemDC,xx,yy,BLACKNESS);

		xx+=dx*4;
		yy+=dy*4;

	
		Tile(&pMemDC,xx,yy,block);
		pDC->BitBlt(xx,yy,50,50,&pMemDC,xx,yy,SRCCOPY);
		//pDC->BitBlt(xx,yy,50,50,&pMemDC,xx,yy,SRCCOPY);
		//pDC->BitBlt(xx,yy,50,50,&pMemDC,xx,yy,SRCCOPY);
	}

}



void NewPattern(CDC *pDC)
{
	int i,x,y;

	complete=false;
	i=0;

	for (y=0;y<4;y++)
		for (x=0;x<4;x++)
			grid[x][y]=i++;

		switch(current_pattern) {
		case 1:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR1);break;
		case 2:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR2);break;
		case 3:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR3);break;
		case 4:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR4);break;
		case 5:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR5);break;
		case 6:drawing_bitmap.LoadBitmap(IDB_BITMAP_COLOR6);break;
		}
		dMemDC.SelectObject(&drawing_bitmap);

			turns=0;
	DrawAllBlocks(pDC);
	shuffle=false;


}


bool CheckGrid()
{
	
	int i,x,y;

	i=0;

	for (y=0;y<4;y++)
		for (x=0;x<4;x++)
			if (grid[x][y]!=i++) return false;

	return true;
}

void GameOverYet(CDC *pDC)
{
	if (!CheckGrid()) return;

	//CString mess;
	//mess.Format(L"You did it in %d moves.",turns);
	//CDialog_Finished pDlg;
	//pDlg.m_string=mess;
	sndPlaySound(L"\\Exclam", SND_FILENAME|SND_ASYNC);
	//pDlg.DoModal();
	complete=true;
	drawing_bitmap.LoadBitmap(IDB_BITMAP_FINISHED);
	dMemDC.SelectObject(&drawing_bitmap);
	DrawAllBlocks(pDC);


	//NewPattern(pDC);
}


void Shuffle(CDC *pDC)
{


	int block;
	int nx=-1,ny=-1;
	int x,y;
	int c=0;
	for (int t=0;t<400;t++)
	{
		nx=-1;ny=-1;
		x=Random()&3;
		y=Random()&3;

		block=grid[x][y];

		if (block!=15) 
		{

			// Up
			if (y>0)
				if (grid[x][y-1]==15) {nx=x;ny=y-1;};

			// Down

			if (y<3)
				if (grid[x][y+1]==15) {nx=x;ny=y+1;};

			// Left
			if (x>0)
				if (grid[x-1][y]==15) {nx=x-1;ny=y;};

			// Right
			if (x<3)
				if (grid[x+1][y]==15) {nx=x+1;ny=y;};

			if ((nx!=-1) && (ny!=-1)) 
			{	
				grid[nx][ny]=block;
				grid[x][y]=15;
				c++;
				if (c>20)
				{
					c=0;
					DrawAllBlocks(pDC);
				}

			}
		}
	}
	DrawAllBlocks(pDC);
}


void MoveBlock(CDC *pDC, int xx, int yy)
{

	// Convert to block number

	if (complete) return;

	if (shuffle==false)
	{

		shuffle=true;
		Shuffle(pDC);
		return;
	}

	int x,y,block;
	int nx=-1,ny=-1;
	int dx=0,dy=0;


	x=(xx-SX)/SIZE;
	y=(yy-SY)/SIZE;

	if ((x<0) || (x>3) || (y<0) || (y>3)) return;

	//sndPlaySound(L"MenuSel.wav", SND_ASYNC|SND_FILENAME);

	block=grid[x][y];

	if (block==15) return;

	// Up
	if (y>0)
		if (grid[x][y-1]==15) {nx=x;ny=y-1;dy=-1;};

	// Down

	if (y<3)
		if (grid[x][y+1]==15) {nx=x;ny=y+1;dy=1;};

	// Left
	if (x>0)
		if (grid[x-1][y]==15) {nx=x-1;ny=y;dx=-1;};

	// Right

	if (x<3)
		if (grid[x+1][y]==15) {nx=x+1;ny=y;dx=1;};


	// Move block

	if ((nx==-1) || (ny==-1)) return;

	//sndPlaySound(L"MenuSel.wav", SND_ASYNC|SND_FILENAME);

	grid[nx][ny]=15;
	grid[x][y]=15;

	// Animate block

	AnimateBlock(pDC,x,y,block,dx,dy);

	// Draw blocks

	grid[nx][ny]=block;

	turns++;

	DrawAllBlocks(pDC);

	GameOverYet(pDC);
}

