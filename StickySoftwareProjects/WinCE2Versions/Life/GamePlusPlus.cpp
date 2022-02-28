// This is the file which contains all the 
// code for the game.

// DrawGrid == display the grid
// DrawCell == Draw a cell
// DrawCells = Draw all the cells
// Generate == Calculate alive and dead

#include "stdafx.h"
#include "Resource.h"
//#include "FileHandler.h"

#define x_off 3
#define y_off 24

int WIDTH;
int HEIGHT;

int CELLX=28;
int CELLY=30;

#define CELLSPACE 8
#define CELLSIZE 4

int total;										// Keep track total alive!
int generation;									// Generation number
extern int status;								// 1 = running, 0 = paused
int speed;										// Speed of generations: 100,500,1000


CBitmap hidden_bitmap;
CDC pMemDC;



CPen aPen,bPen,cPen,dPen;


class LifeGrid {
	short int grid[30+2][32+2];
public:
	LifeGrid();									// Constructor
	void ClearGrid();
	void WriteGrid(int x, int y,short int value);
	short int ReadGrid(int x, int y);
	short int * Where();
	int Size();
	void LoadGrid();
	void SaveGrid();
};


LifeGrid first,second,temp;						// Declare Grids

short int *LifeGrid::Where()
{

	return &grid[0][0];
}

int LifeGrid::Size()
{
	return (sizeof(grid));
}


LifeGrid::LifeGrid()
{
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			grid[x][y]=0;
}


void LifeGrid::ClearGrid()
{
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			grid[x][y]=0;
}

void LifeGrid::WriteGrid(int x,int y,short int value)
{
	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLY+2))
	{
		sndPlaySound(L"Alarm2.wav", SND_SYNC|SND_FILENAME);
		return;
	}

	if ((x==0) || (y==0))
		if (value==1)
			sndPlaySound(L"Alarm3.wav", SND_SYNC|SND_FILENAME);


	grid[x][y]=value;
}


short int LifeGrid::ReadGrid(int x,int y)
{
	if ((x<0) || (x>CELLX+2) || (y<0) || (y>CELLY+2))
	{
		sndPlaySound(L"ROOSTER.WAV", SND_SYNC|SND_FILENAME);
		return -1;
	}

	return grid[x][y];
}

/******************** END OF CLASSES ****************/

void InitGame(CDC *pDC)
{
	first.ClearGrid();
	second.ClearGrid();
	temp.ClearGrid();

	WIDTH=240; //  GetSystemMetrics(SM_CXSCREEN);
	HEIGHT=320;//GetSystemMetrics(SM_CYSCREEN)-24;

	//CELLX=(WIDTH/8)-2;
	//CELLY=(HEIGHT/8)-2;

	aPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	bPen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	cPen.CreatePen(PS_SOLID,1,RGB(80,80,80));
	dPen.CreatePen(PS_SOLID,1,RGB(190,190,190));

	pMemDC.CreateCompatibleDC(pDC);
	hidden_bitmap.CreateCompatibleBitmap(pDC,240,318);
	pMemDC.SelectObject(&hidden_bitmap);

	pMemDC.SelectObject(&cPen);
	pMemDC.SelectStockObject(LTGRAY_BRUSH);
	pMemDC.Rectangle(0,0,240,318);


}



void RandomGrid(CDC *pDC)
{
	InitGame(pDC);

	for (int x=1;x<(CELLX+1);x++)
		for (int y=1;y<(CELLY+1);y++)
			if (Random() &1) 
				first.WriteGrid(x,y,0);
			else
				first.WriteGrid(x,y,1);
}

void DrawAlive(CDC *pDC, int x, int y)
{

	pDC->SelectObject(&bPen);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Rectangle(x+2,y+2,x+CELLSPACE,y+CELLSPACE);

}

void DrawDead(CDC *pDC, int x, int y)
{

	pDC->SelectObject(&cPen);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Rectangle(x+1,y+1,x+CELLSPACE+2,y+CELLSPACE+2);
	//pDC->SelectStockObject(BLACK_BRUSH);
	//pDC->SelectObject(&bPen);
	//pDC->Rectangle(x+2,y+2,x+CELLSIZE,y+CELLSIZE);
}



void DrawCell(CDC* pDC, int cx,int cy,short int alive)
{
	// Given Cell numbers, draw them on screen

	int x,y;

	x=((cx-1)*CELLSPACE)+x_off+4;
	y=((cy-1)*CELLSPACE)+4+y_off;

	first.WriteGrid(cx,cy,alive);

	if (alive==1)
	{
		DrawAlive(pDC,x,y);
	}
	else
	{
		DrawDead(pDC,x,y);
	}

}

void DrawAllCells(CDC* pDC)
{
	for (int cx=1;cx<(CELLX+1);cx++)
		for (int cy=1;cy<(CELLY+1);cy++)
			DrawCell(pDC,cx,cy,first.ReadGrid(cx,cy));
}

void UpdateAllCells(CDC* pDC)
{
	// Use the last known grid settings
	// To only draw when required.

	int x,y;
	short int alive,last;

	total=0;

	for (int cx=1;cx<(CELLX+1);cx++)
		for (int cy=1;cy<(CELLY+1);cy++)
		{
			alive=first.ReadGrid(cx,cy);
			last=second.ReadGrid(cx,cy);
			x=((cx-1)*CELLSPACE)+x_off+4;
			y=((cy-1)*CELLSPACE)+4+y_off;

			total+=alive;

			//


			if (last==2)
			{
				DrawCell(&pMemDC,cx,cy,alive);
			}
		
			else

			{
				if ((alive==1) && (last==0))
				{
					DrawAlive(&pMemDC,x,y);
				}

				if ((alive==0) && (last==1))
				{
					DrawDead(&pMemDC,x,y);
				}
			}
			
		}

	pDC->BitBlt(0,0,WIDTH,HEIGHT,&pMemDC,0,0,SRCCOPY);

}





void Generate()
{
	int i,j;
	int s=0;
	int t=0;
	short int al;

	for (i=0;i<(CELLX+2);i++)
		for (j=0;j<(CELLY+2);j++)
			second.WriteGrid(i,j,first.ReadGrid(i,j));

	for (i=1;i<(CELLX+1);i++)
	{
		for (j=1;j<(CELLY+1);j++)
		{
			s=second.ReadGrid(i-1,j-1);
			s+=second.ReadGrid(i-1,j);
			s+=second.ReadGrid(i-1,j+1);
			s+=second.ReadGrid(i,j-1);
			s+=second.ReadGrid(i,j+1);
			s+=second.ReadGrid(i+1,j-1);
			s+=second.ReadGrid(i+1,j);
			s+=second.ReadGrid(i+1,j+1);
			al=second.ReadGrid(i,j);

			t=0;
			if ((s==2) || (s==3)) t=1; else t=0;

			first.WriteGrid(i,j,0);

			if ((al==0) && (s==3)) first.WriteGrid(i,j,1);
			if ((al==1) && (t==1)) first.WriteGrid(i,j,1);

		}
	}
};

void SwapCell(CDC* pDC,int sx, int sy)
{
	// Swap the state of the cell
	// at given screen co-ords
		
	int cx,cy;

	cx=sx-4-x_off;
	cx=(cx/CELLSPACE)+1;

	cy=sy-4-y_off;
	cy=(cy/CELLSPACE)+1;

	if ((cy<1) || (cy>(CELLY)) || (cx<1) || (cx>(CELLX))) return;

	if (first.ReadGrid(cx,cy)==0)
	{
		second.WriteGrid(cx,cy,2);
		first.WriteGrid(cx,cy,1);
		//DrawCell(pDC,cx,cy,1);
	}
	else
	{
		second.WriteGrid(cx,cy,2);
		first.WriteGrid(cx,cy,0);
		//DrawCell(pDC,cx,cy,0);
	}

	UpdateAllCells(pDC);

}


void UpdateText(CDC* pDC)
{

//	OnPrepareDC(&pDC);

	CString s;

	CRect brect(10,278,130,300);

	pDC->SetBkColor(RGB(190,190,190));
	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkMode(OPAQUE);
	s.Format (L"Generation:%d    ", generation);
	pDC->DrawText(s, brect, DT_LEFT | DT_SINGLELINE);



	if (status==1) 
	{
		pDC->SelectObject(&bPen);
		CRect arect(160,278,240,300);
		
		pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
		pDC->SetBkMode(OPAQUE);
		s.LoadString(ID_LIFE_STATUS);
		pDC->DrawText(s, arect, DT_LEFT | DT_SINGLELINE);
	}
	else
	{

		pDC->SelectObject(&dPen);
		pDC->SelectStockObject(LTGRAY_BRUSH);
		pDC->Rectangle(160,278,239,300);
	}
}

void DrawEverything(CDC* pDC)
{
	//DrawGrid(pDC);
	DrawAllCells(&pMemDC);
	UpdateText(&pMemDC);
	pDC->BitBlt(0,0,240,318,&pMemDC,0,0,SRCCOPY);
};

void CopyToTemp()
{
	// Copy the contents of the grid
	// so it can be recalled.
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			temp.WriteGrid(x,y,first.ReadGrid(x,y));
}

void CopyFromTemp()
{
	// Copy to grid from temp
	for (int x=0;x<(CELLX+2);x++)
		for (int y=0;y<(CELLY+2);y++)
			first.WriteGrid(x,y,temp.ReadGrid(x,y));
}


/*void LifeGrid::SaveGrid()
{
	// Get file name 
	LPTSTR SaveFileName=NULL;
	SaveFileName=CreateCellFile();
	if (SaveFileName==NULL) return;
	// Save file

	HANDLE hFile;
    DWORD   dwNumberOfBytesRote;
    hFile = CreateFile(	SaveFileName, GENERIC_WRITE,0,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL );
    if ( hFile )
    {
		WriteFile( hFile,first.grid,sizeof(first.grid),&dwNumberOfBytesRote,NULL);
        CloseHandle(hFile);
	}
}


void LifeGrid::LoadGrid()
{
	// Get file name...

	LPTSTR LoadFileName=NULL;
	LoadFileName=OpenCellFile();
	if (LoadFileName==NULL) return;	

	// Read file...
	HANDLE hFile;
    DWORD   dwNumberOfBytesRead;
    hFile = CreateFile(	LoadFileName, GENERIC_READ ,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL );
    if ( hFile )
    {
		ReadFile( hFile,first.grid,sizeof(first.grid),&dwNumberOfBytesRead,NULL);
        CloseHandle(hFile);
		} 
}

void LoadData()
{
	first.LoadGrid();
}

void SaveData()
{
	first.SaveGrid();
}
*/
	