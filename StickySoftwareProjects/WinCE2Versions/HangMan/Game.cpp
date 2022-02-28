//
// Game logic
///

#include "stdafx.h"
#include "math.h"
#include "Resource.h"
#include "Dialog_GameOver.h"
#include "Dialog_Game_Lost.h"
#include "Dialog_Key.h"

#include "films.h" // 90?
//#include "children.h" //117

#define MX 100 //10
#define MY 30

//extern void UpdateEverything (CDC *pdc);

CRect arect(20,140,200,180);
CPen LTGreyPen,DKGreyPen,BlackPen;

int next=0;

CString target,guess,mess;

short int count;

HFONT		v_hFont;

extern CDialog_Key *aDlg;

void DefinePens(CDC *pDC)
{
	LTGreyPen.CreatePen(PS_SOLID,1,RGB(192,192,192));
	DKGreyPen.CreatePen(PS_SOLID,2,RGB(128,128,128));
	BlackPen.CreatePen(PS_SOLID,3,RGB(0,0,0));

	LOGFONT         lf;
	memset ((char *)&lf, 0, sizeof(lf));
	//lf.lfPitchAndFamily = FIXED_PITCH;// | FF_MODERN;
	lf.lfHeight = 20; // 13?
	v_hFont = CreateFontIndirect (&lf);
	pDC->SelectObject(v_hFont);
}

void Release(CDC *pDC)
{
	LTGreyPen.DeleteObject();
	DKGreyPen.DeleteObject();
	BlackPen.DeleteObject();
	DeleteObject ((HGDIOBJ)v_hFont);
}

void Gallows(CDC *pDC)
{
	pDC->SelectObject(BlackPen);

	pDC->MoveTo(MX-10,MY+60);
	pDC->LineTo(MX+64,MY+60);

	pDC->MoveTo(MX+40,MY+60);
	pDC->LineTo(MX+40,MY-20);
	pDC->LineTo(MX,MY-20);
	pDC->LineTo(MX,MY-12);
	
	pDC->MoveTo(MX+40,MY);
	pDC->LineTo(MX+20,MY-20);



}

void DrawMan(CDC *pDC, short int stage)
{

	Gallows(pDC);

	pDC->SelectObject(DKGreyPen);

	switch (stage)
	{
	case 5: // right leg
		{
			pDC->MoveTo(MX,MY+36);
			pDC->LineTo(MX+10,MY+48);
		//	break;
		}

	case 4: // left leg
		{
			pDC->MoveTo(MX,MY+36);
			pDC->LineTo(MX-10,MY+48);
		//	break;
		}

	case 3:// arms
		{
			pDC->MoveTo(MX-10,MY+20);
			pDC->LineTo(MX+10,MY+20);
		//	break;
		}

	case 2:// body
		{
			pDC->MoveTo(MX,MY+8);
			pDC->LineTo(MX,MY+36);
		//	break;
		}

	case 1:// head
		{
			pDC->Ellipse(MX-8,MY-8,MX+8,MY+8);
			break;

		}

	}
}

void PickWord(CDC *pDC)
{
	// Select the target, and reset
	// guesses

	count=0;

	guess="";

	int which=200;

	do
	{
		which=Random()&127;
	}
	while (which>90);
		
	if (which>90) which=1;

	target=targetwords[which];
	//target="THE REVENGE OF THE CAT PEOPLE FROM MARS";

	for (int i=0;i<target.GetLength();i++)
	{
		if (target[i]!=' ') 
			guess+='*';
		else
			guess+=' ';
	}

	pDC->FillSolidRect(0,0,640,240,RGB(255,255,255));

}

void DrawWord(CDC *pDC)
{
	pDC->SelectObject(v_hFont);
	mess.Format(L"%s\0",guess);
	pDC->FillSolidRect(arect,RGB(255,255,255));
	pDC->DrawText(mess, arect, DT_WORDBREAK |DT_CENTER /*| DT_SINGLELINE*/);
}



void Test(char key, CDC *pdc)
{
	// check to see if there are any 
	// occurances of key in the target
	// and if so, copy them into the
	// guess string.

	// If not, add one to the stage
	// counter. Poor bloke.

	bool found=false;
	int i;

	for (i=0;i<target.GetLength();i++)
	{
		if (target[i]==key) 
		{
			guess.SetAt(i,target[i]);
			found=true;
			DrawWord(pdc);
			sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
		}
	}

	if (!found) 
	{
		count++;
		DrawMan(pdc,count);
		sndPlaySound(L"\\Infend", SND_FILENAME|SND_SYNC);
		
	}

	//DrawMan(pdc,count);
	//DrawWord(pdc);

	if (count>4)
	{
		CDialog_Game_Lost pDlg;
		pDlg.m_string2=target;
		sndPlaySound(L"\\Exclam", SND_FILENAME|SND_ASYNC);
		pDlg.DoModal();
		PickWord(pdc);
		aDlg->ResetKeys();
		Gallows(pdc);
		DrawWord(pdc);
		// lost
	}

	if (target==guess)
	{
		// won
		CDialog_GameOver pDlg;
		pDlg.m_string2=target;
		sndPlaySound(L"\\mssound", SND_FILENAME|SND_ASYNC);
		pDlg.DoModal();
		PickWord(pdc);
		aDlg->ResetKeys();
		Gallows(pdc);
		DrawWord(pdc);
	}

	return;
}

