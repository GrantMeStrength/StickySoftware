

// Handle the Star routines, and
// try to keep the data away until
// the linking process

#include "stdafx.h"
#include "newfk5data.h"

//#define DEMO

#ifndef DEMO
#define NUMBEROFSTARS 4652
#endif
#ifdef DEMO
#define NUMBEROFSTARS 154
#endif


extern double R2D (double angle);
extern double D2R (double angle);
extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

void CalculateStars(int starlimit)
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the currently displayed
	// stars

	double az,alt;
	short int i;

	for (i=0;i<NUMBEROFSTARS;i++)
	{
		if (fk5stars[i].mag>starlimit) {i=NUMBEROFSTARS;break;}
		MakeLocal((double)fk5stars[i].ra,(double)fk5stars[i].dec,&az,&alt);
		stars[i].alt=float(alt); // radians
		stars[i].azm=float(az);   // radians
	}

	
	i=0;
/*	int lt,zm;

	for (lt=-90;lt<90;lt+=10)
		for (zm=-180;zm<180;zm+=10)
		{
			stars[i].alt=D2R(lt);
			stars[i++].azm=D2R(zm);
		}
*/	
}


double Get_Star_Alt(int i)
{
	// return radians
	return stars[i].alt;
}

double Get_Star_Azm(int i)
{
	return stars[i].azm;
}

int Get_Star_Mag(int i)
{
	return int(fk5stars[i].mag);
}


