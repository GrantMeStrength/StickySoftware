// The tests

// 1. Integer
// 2. Floating point
// 3. Displaying text

#include "stdafx.h"
#include "math.h"

extern long When();

	CString s;
	CRect arect(10,60,200,80);
	CRect crect(10,80,200,100);
	CRect drect(10,100,200,120);
	CRect brect(10,200,230,220);

void Test1()
{
	int x;
	int y;

	for (int z=1;z<20000;z++)
	{
		y=0;
		for (x=0;x<20000;x++)
		{
			if (x<5000) y+=10; else y-=10;
			if (x<5000) y+=20; else y-=20;
			if (x<5000) y+=40; else y-=30;
		}
	}
}

void Test2()
{
	double x;
	double y;
	long int z;
	long int zz;

	for (z=0;z<8;z++)
	{
		for (zz=1;zz<5000;zz++)
		{
			x=double (z)/5000;
			y=sin(x)*cos(x);
			y+=sin(x)*sin(x);
			y+=cos(x)*cos(x);
			y+=sin(x)*cos(x);
			y=sin(x)*cos(x);
			y+=sin(x)*sin(x);
			y+=cos(x)*cos(x);
			y+=sin(x)*cos(x);
			y=y*y;
			y=y/12.1;
		}
	}
}

void Test3(CDC *aDC)
{

	for (int z=1;z<1000;z++)
	{
		s.Format (L"STICKY SOFTWARE");
		aDC->DrawText(s, brect, DT_LEFT | DT_SINGLELINE);
		s.Format (L"                                   ");
		aDC->DrawText(s, brect, DT_LEFT | DT_SINGLELINE);
	}
}

void StartTests(CDC *aDC)
{
	long Start;
	long End;
	long Length;

	Start=When();
	Test1();
	End=When();
	Length=End-Start;
	s.Format (L"Int:%1d seconds",Length);
	aDC->DrawText(s, arect, DT_LEFT | DT_SINGLELINE);

	Start=When();
	Test2();
	End=When();
	Length=End-Start;
	s.Format (L"Flt:%1d seconds",Length);
	aDC->DrawText(s, crect, DT_LEFT | DT_SINGLELINE);

	Start=When();
	Test3(aDC);
	End=When();
	Length=End-Start;
	s.Format (L"Gfx:%1d seconds",Length);
	aDC->DrawText(s, drect, DT_LEFT | DT_SINGLELINE);
}
