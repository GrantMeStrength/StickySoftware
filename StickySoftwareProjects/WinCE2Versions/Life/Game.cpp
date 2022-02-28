// This is the file which contains all the 
// code for the game.

// DrawGrid == display the grid
// DrawCell == Draw a cell
// DrawCells = Draw all the cells
// Generate == Calculate alive and dead

#include "stdafx.h"
#include "Resource.h"

#define x_off 2
#define y_off 2

#define CELLX 30
#define CELLY 15

int total;				// Keep track total alive!
int generation;			// Generation number
extern int status;		// 1 = running, 0 = paused
int speed;				// Speed of generations: 100,500,1000

short int grid[CELLX+2][CELLY+2]; // 1..CELLn are the TRUE cells,
short int grod[CELLX+2][CELLY+2]; // 0 and CELLn+1 are the border cells.
short int temp[CELLX+2][CELLY+2]; // Store for previous setting

void WriteGrid(int x,int y,short int value)
{
	// All grid access through here to
	// check for errors. Yes, it should
	// be in a class.

	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLX+2))
	{
		sndPlaySound(L"ROOSTER.WAV", SND_SYNC|SND_FILENAME);
		return;
	}

	grid[x][y]=value;
}

short int ReadGrid(int x,int y)
{
	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLX+2))
	{
		sndPlaySound(L"ROOSTER.WAV", SND_SYNC|SND_FILENAME);
		return -1;
	}

	return grid[x][y];
}

void WriteGrod(int x,int y,short int value)
{
	// All grid access through here to
	// check for errors. Yes, it should
	// be in a class.

	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLX+2))
	{
		sndPlaySound(L"ROOSTER.WAV", SND_SYNC|SND_FILENAME);
		return;
	}

	grod[x][y]=value;
}

short int ReadGrod(int x,int y)
{
	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLX+2))
	{
		sndPlaySound(L"ROOSTER.WAV", SND_SYNC|SND_FILENAME);
		return -1;
	}

	return grod[x][y];
}

void InitGame()
{
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
		{	
			WriteGrod(x,y,0);
			//grod[x][y]=0;
			WriteGrid(x,y,0);
			//grid[x][y]=0;
			temp[x][y]=0;
		}
}

void RandomGrid()
{
	InitGame();

	for (int x=1;x<(CELLX+1);x++)
		for (int y=1;y<(CELLY+1);y++)
			if (Random() &1) 
				WriteGrid(x,y,0);
			else
				WriteGrid(x,y,1);

}

void DrawCell(CDC* pDC, int cx,int cy,short int alive)
{
	// Given Cell numbers, draw them on screen

	cx-=1;	// We do this because of the
	cy-=1;	// one cell border!

	int x,y;


	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(&aPen);

	x=(cx*12)+x_off+4;
	y=(cy*12)+4+y_off;


	CBitmap cell_bitmap;
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	cell_bitmap.LoadBitmap(IDB_CELL);
	dcMem.SelectObject(&cell_bitmap);

	//grod[cx][cy]=alive;
	WriteGrod(cx,cy,alive);
	total+=alive;

	if (alive==1)
		pDC->BitBlt(x,y,8,8,&dcMem,0,0,SRCCOPY);
	else
		pDC->Rectangle(x,y,x+8,y+8);
		
	dcMem.DeleteDC();
}

void DrawAllCells(CDC* pDC)
{
	int x,y;
	short int alive;

	total=0;
	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(&aPen);

	CBitmap cell_bitmap;
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	cell_bitmap.LoadBitmap(IDB_CELL);
	dcMem.SelectObject(&cell_bitmap);

	for (int cx=1;cx<(CELLX+1);cx++)
		for (int cy=1;cy<(CELLY+1);cy++)
		{
			//alive=grid[cx][cy];
			alive=ReadGrid(cx,cy);
			x=((cx-1)*12)+x_off+4;
			y=((cy-1)*12)+4+y_off;
			total+=alive;
			if (alive==1)
				pDC->BitBlt(x,y,8,8,&dcMem,0,0,SRCCOPY);
			else
				pDC->Rectangle(x,y,x+8,y+8);
		}

	dcMem.DeleteDC();
}

void UpdateAllCells(CDC* pDC)
{
	// Use the last known grid settings
	// To only draw when required.

	int x,y;
	short int alive,last;

	total=0;
	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(&aPen);

	CBitmap cell_bitmap;
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	cell_bitmap.LoadBitmap(IDB_CELL);
	dcMem.SelectObject(&cell_bitmap);

	for (int cx=1;cx<(CELLX+1);cx++)
		for (int cy=1;cy<(CELLY+1);cy++)
		{
			//alive=grid[cx][cy];
			alive=ReadGrid(cx,cy);
			last=ReadGrod(cx,cy);
			//last=grod[cx][cy];
			x=((cx-1)*12)+x_off+4;
			y=((cy-1)*12)+4+y_off;
			total+=alive;

			if ((alive==1) && (last==0))
				pDC->BitBlt(x,y,8,8,&dcMem,0,0,SRCCOPY);

			if ((alive==0) && (last==1))
				pDC->Rectangle(x,y,x+8,y+8);
		}

	dcMem.DeleteDC();
}


void DrawGrid(CDC* pDC)
{
	// Draw grid where cells will sit on screen

	int x,y;

	CPen aPen;
	aPen.CreatePen(PS_SOLID,1,RGB(50,50,50));
	pDC->SelectObject(&aPen);

	//pDC->Rectangle(10,10,200,100);

	for (y=2;y<192;y+=12)
	{
		pDC->MoveTo(2+x_off,y+y_off);
		pDC->LineTo(362+x_off,y+y_off);
	}

	for (x=2;x<368;x+=12)
	{
		pDC->MoveTo(x+x_off,2+y_off);
		pDC->LineTo(x+x_off,182+y_off);
	}

	//DrawAllCells(pDC);

};


void Generate()
{
	int i,j;
	int s=0;
	int t=0;
	short int al;

	for (i=0;i<(CELLX+2);i++)
		for (j=0;j<(CELLY+2);j++)
			//grod[i][j]=grid[i][j];
			WriteGrod(i,j,ReadGrid(i,j));

	for (i=1;i<(CELLX+1);i++)
	{
		for (j=1;j<(CELLY+1);j++)
		{
			/*
			s=grod[i-1][j-1];
			s+=grod[i-1][j];
			s+=grod[i-1][j+1];

			s+=grod[i][j-1];
			s+=grod[i][j+1];

			s+=grod[i+1][j-1];
			s+=grod[i+1][j];
			s+=grod[i+1][j+1];

			al=grod[i][j];
			*/

			s=ReadGrod(i-1,j-1);
			s+=ReadGrod(i-1,j);
			s+=ReadGrod(i-1,j+1);
			s+=ReadGrod(i,j-1);
			s+=ReadGrod(i,j+1);
			s+=ReadGrod(i+1,j-1);
			s+=ReadGrod(i+1,j);
			s+=ReadGrod(i+1,j+1);
			al=ReadGrod(i,j);


			t=0;
			if ((s==2) || (s==3)) t=1; else t=0;

			WriteGrid(i,j,0);
			//grid[i][j]=0;

			if ((al==0) && (s==3)) WriteGrid(i,j,1);// grid[i][j]=1;
			if ((al==1) && (t==1)) WriteGrid(i,j,1);// grid[i][j]=1;

		}
	}
};

void SwapCell(CDC* pDC,int sx, int sy)
{
	// Swap the state of the cell
	// at given screen co-ords
		
	int cx,cy;

	cx=sx-4-x_off;
	cx=(cx/12)+1;

	cy=sy-4-y_off;
	cy=(cy/12)+1;

	if ((cy<1) || (cy>(CELLY)) || (cx<1) || (cx>(CELLX))) return;

	if (ReadGrid(cx,cy)==0) // if (grid[cx][cy]==0)
	{
		//grid[cx][cy]=1;
		WriteGrid(cx,cy,1);
		DrawCell(pDC,cx,cy,1);
	}
	else
	{
		//grid[cx][cy]=0;
		WriteGrid(cx,cy,0);
		DrawCell(pDC,cx,cy,0);
	}
}



void UpdateText(CDC* pDC)
{

	CPen aPen;
	CString s;

	CRect brect(380,80,460,100);
	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkMode(OPAQUE);
	s.Format (L"Generation:%d.    ", generation);
	pDC->DrawText(s, brect, DT_LEFT | DT_SINGLELINE);

	CRect crect(380,120,460,140);
	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkMode(OPAQUE);
	s.Format (L"Cells:%d.         ", total);
	pDC->DrawText(s, crect, DT_LEFT | DT_SINGLELINE);

	if (status==1) 
	{
		aPen.CreatePen(PS_SOLID,1,RGB(0,0,0));
		pDC->SelectObject(&aPen);
		CRect arect(380,40,460,60);
		pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
		pDC->SetBkMode(OPAQUE);
		s.LoadString(ID_LIFE_STATUS);
		pDC->DrawText(s, arect, DT_LEFT | DT_SINGLELINE);
	}
	else
	{
		aPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
		pDC->SelectObject(&aPen);
		pDC->Rectangle(380,40,460,60);
	}
}

void DrawEverything(CDC* pDC)
{
	DrawGrid(pDC);
	DrawAllCells(pDC);
	UpdateText(pDC);
};

void CopyToTemp()
{
	// Copy the contents of the grid
	// so it can be recalled.
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			temp[x][y]=ReadGrid(x,y); // grid[x][y];
}

void CopyFromTemp()
{
	// Copy to grid from temp
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			//grid[x][y]=temp[x][y];
			WriteGrid(x,y,temp[x][y]);
}

	