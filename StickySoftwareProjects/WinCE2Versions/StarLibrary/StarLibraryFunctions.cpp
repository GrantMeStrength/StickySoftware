
#include <windows.h>

#include "starlibraryfunctions.h"

////////////////////////////////////////////////////////////////////////////
///
// Dll entry point
BOOL WINAPI DllMain(HANDLE hInst, DWORD dwReason, LPVOID lpv)
{
MessageBox(NULL,L"I Loaded",L"The DLL",0);
return TRUE;
}

#include "stardata.h"

extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

EXPORTDLL void Library_CalculateStars(int starlimit)
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the currently displayed
	// stars

	double az,alt;
	int i;

	for (i=0;i<BS_NUMBER;i++)
	{
		if (BSstars[i].mag>starlimit) {i=BS_NUMBER;break;}
		MakeLocal((double)BSstars[i].ra,(double)BSstars[i].dec,&az,&alt);
		stars[i].alt=float(alt); // radians
		stars[i].azm=float(az);   // radians
	}
}

EXPORTDLL int Library_Get_Stars()
{
	return BS_NUMBER;
}

EXPORTDLL short int Library_Get_Star_Mag(int i)
{
	return BSstars[i].mag;
}

EXPORTDLL double Library_Get_Star_Azm(int i)
{
	return stars[i].azm;
}

EXPORTDLL double Library_Get_Star_Alt(int i)
{
	return stars[i].alt;
}

EXPORTDLL void Library_Get_Name(char *name)
{
	name="Bright Star Calaog";

	return;
}