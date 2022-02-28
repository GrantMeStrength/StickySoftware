

// Handle the Star routines, and
// try to keep the data away until
// the linking process

#include "stdafx.h"
#include "newfk5data.h"

#define NUMBEROFSTARS 9096

extern double R2D (double angle);
extern double D2R (double angle);
extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

void CalculateStars(int starlimit)
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the currently displayed
	// stars

	double az,alt;
	int i;

	for (i=0;i<NUMBEROFSTARS;i++)
	{
		if (fk5stars[i].mag>starlimit) {i=NUMBEROFSTARS;break;}
		MakeLocal((double)fk5stars[i].ra,(double)fk5stars[i].dec,&az,&alt);
		stars[i].alt=float(alt); // radians
		stars[i].azm=float(az);   // radians
	}
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


