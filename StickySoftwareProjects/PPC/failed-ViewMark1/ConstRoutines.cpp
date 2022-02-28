
// Handle the Messier routines, and
// try to keep the data away until
// the linking process


// 1. A list of ra,dec (-1 = goto)
// 2. A list of alt,azm
// 3. A list of ra,dec and names

#include "stdafx.h"

#define CONSTNUMBER 299  // 227

extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

struct outline_type {
	float ra,dec;
} ;

struct outline_cords_type {
	float alt,azm;
} ;

struct outline_cords_type outlines[CONSTNUMBER];

struct outline_type outlinedata[CONSTNUMBER]=
{
	
	{-1,-1},		// Orion
	{5.9,7.4},
	{5.6,9.5},
	{5.4,6.3},
	{5.5,-0.7},
	{5.3,-8.2},
	{5.8,-9.6},
	{5.7,-1.9},
	{5.9,7.4},
	{-1,-1},		// Ursa Major
	{13.8,49.1},
	{13.4,54.4},
	{12.9,55.6},
	{12.2,56.9},
	{11,61.5},
	{11,56.2},
	{11.9,53.5},
	{12.2,56.9},
	{-1,-1},		// Cassiopeia
	{1.9,63.4},
	{1.4,59.8},
	{0.9,60.4},
	{0.7,56.3},
	{0.2,58.8},
	{-1,-1},		// Cygnus
	{20.7,45.21},
	{20.38,40.15},
	{19.51,27.88},
	{-1,-1},
	{20.78,33.95},
	{20.38,40.15},
	{19.76,44.95},
	{-1,-1},		// Draco
	{15.41,58.96},
	{16.03,58.9},
	{17.15,65.71},
	{18.35,72.73},
	{19.8,70.266},
	{19.21,67.66},
	{17.9,56.872},
	{17.95,51.49},
	{17.51,52.3},
	{17.55,55.173},
	{17.9,56.872},
	{-1,-1},		// Andromeda
	{1.633,48.629},
	{0.95,38.498},
	{0.61,33.719},
	{0.15,29.093},
	{0.667,30.861},
	{1.1667,35.622},
	{2.0667,42.320},
	{-1,-1},		// Pegasus
	{22.7,10.831},
	{23.083,15.206},
	{0.233,15.184},
	{0.15,29.093},
	{23.04,28.080},
	{23.083,15.206},
	{-1,-1},
	{22.78,23.565},
	{23.04,28.080},
	{22.71,30.222},
	{22.11,25.344},
	{21.75,25.645},
	{-1,-1},			// Cetus
	{0.33,-8.24},
	{0.73,-17.98},
	{1.15,-10.18},
	{1.4,-8.188},
	{1.86,-10.33},
	{2.46,-2.97},
	{2.67,0.326},
	{2.73,3.32},
	{3.05,4.09},
	{3,8.9},
	{2.75,10.11},
	{2.46,8.45},
	{2.67,0.326},
	{-1,-1},
	{0.73,-17.98},
	{1.73,-15.94},
	{-1,-1},		// Taurus
	{3.41,9.03},
	{3.35,12.93},
	{4,12.5},
	{4.33,15.62},
	{4.6,15.51},
	{5.63,21.14},
	{-1,-1},
	{4.05,5.98},
	{4.26,8.89},
	{4,12.5},
	{4.33,15.62},
	{4.48,19.179},
	{-1,-1},		// Gemini
	{6.63,16.39},
	{7.33,21.981},
	{7.75,24.39},
	{7.76,28.02},
	{7.58,31.88},
	{7.18,30.24}, 
	{6.38,22.513},
	{6.25,22.50},
	{-1,-1},
	{7.33,21.981},
	{7.3,16.54},
	{-1,-1},
	{7.18,30.24},
	{6.88,33.95},
	{-1,-1},		// Ursa Minor
	{15.73,77.79},
	{16.3,75.75},
	{15.35,71.83},
	{14.85,74.15},
	{15.73,77.79},
	{16.76,82.03},
	{2.31,89.24},
	{-1,-1},		// Cancer
	{8.28,9.185},
	{8.98,11.85},
	{8.75,18.15},
	{8.78,28.75},
	{-1,-1},		// Bootes
	{14.68,16.41},
	{14.26,19.21},
	{15.26,33.31},
	{15.03,40.39},
	{14.53,38.3},
	{14.53,30.37},
	{14.26,19.21},
	{13.9,18.4},
	{-1,-1},		// Leo
	{9.533,22.966},
	{9.76,23.77},
	{9.88,26.0},
	{10.28,23.41},
	{10.33,19.84},
	{10.13,16.76},
	{10.15,11.96},
	{10.55,9.3},
	{11.4,10.53},
	{11.25,15.42},
	{11.23,20.52},
	{11.82,14.57},
	{11.25,15.42},
	{-1,-1},		 //Leo Minor
	{10.9,34.22},
	{10.46,36.7},
	{10.13,35.1},
	{-1,-1},		//Hydra
	{14.12,-26.68},
	{13.31,-23.17},
	{11.88,-33.9},
	{11.55,-31.86},
	{10.61,-27.4},
	{10.83,-16.19},
	{10.43,-16.84},
	{9.86,-14.95},
	{9.46,-8.66},
	{9.66,-1.14},
	{9.25,2.32},
	{8.93,5.94},
	{8.78,6.42},
	{8.63,5.7},
	{8.65,3.35},
	{8.73,3.38},
	{8.93,5.94},
	{-1,-1},			// Canus minor
	{7.66,5.23},
	{7.45,8.28},
	{-1,-1},			// new south ones -- Crux {12.5,-54.59},
	{12.5,-57.1},
	{12.45,-63.1},
	{-1,-1},
	{12.8,-59.6},
	{12.25,-58.75},
	{-1,-1},			// Vela {10,-45},
	{10.25,-42.12},
	{10.78,-49.42},
	{9.95,-54.57},
	{8.75,-54.7},
	{8.17,-47.3},
	{8.75,-42.71},
	{9.13,-43.42},
	{10.25,-42.12},
	{-1,-1},		//	Telescopium {19.3, -50},
	{18.45,-45.97},
	{18.48,-49},
	{19.6,-47.98},
	{20.13,-52.7},
	{19.8,-56.2},
	{-1,-1},		// Triangulum Aus {16.66,-63},
	{15.91,-63.42},
	{19.81,-69.02},
	{15.31,-68.67},
	{15.91,-63.42},
	{-1,-1},		//  Chamaeleon {12,-2}
	{10.6,-78.6},
	{12.31,-79.3},
	{10.76,-80.54},
	{8.35,-77.42},
	{8.31,-76.86},
	{10.6,-78.6}, // 204
	{-1,-1},		// {"SCORPIUS",17.2,-35}
	{17.56,-37.1},
	{17.72,-39.02},
	{17.8,-40.12},
	{17.6,-43},
	{17.2,-43.2},
	{16.8,-38.01},
	{16.85,-34.28},
	{16.6,-28.21},
	{16.5,-26.4},
	{16.35,-26},
	{16.1,-22.6},
	{16.1,-19.8},
	{16.1,-22.6},
	{15.98,-26.06},
	{-1,-1},		// {"AQUILA",19.73,-1.38}
	{19.43,3.115},
	{19.1,13.866},
	{19.783,10.614},
	{19.85,8.864},
	{20.2333,-1.008},
	{19.43,3.115},
	{19.11,-4.88},		//227
	{-1,-1},			//ARIES 228
	{3.2,19.725},
	{2.833,27.26},
	{2.11,23.464},
	{1.91,20.8},
	{1.9,19.297},
	{-1,-1},		// Pisces
	{1.2,30.09},
	{1.33,27.263},
	{1.23,24.583},
	{1.533,15.345},
	{2.03,2.763},
	{0.816,7.585},
	{0,6.684},
	{23.66,5.631},
	{23.466,6.38},
	{23.28,3.282},
	{23.45,1.256},
	{23.7,1.781},
	{23.66,5.631},
	{-1,-1},		// Capricorn
	{20.35,-14.779},
	{21.1,-17.231},
	{21.66,-16.66},
	{21.788,-16.121},
	{21.45,-22.410},
	{20.866,-26.917},
	{20.766,-25.267},
	{-1,-1},		//Libra
	{15.61,-20.132},
	{16.08,-11.371},
	{15.283,-9.38},
	{14.85,-15.994},
	{15.006,-25.280},
	{-1,-1},		//Virgo
	{13.58,-0.596},
	{13.41,-11.159},
	{12.7,-1.449}, //arm
	{12.33,-0.66},
	{11.85,1.76},
	{-1,-1},
	{13.03,10.958},
	{12.93,3.398},
	{12.7,-1.449}, //arm
	{-1,-1},
	{12.93,3.398},
	{13.58,-0.596},
	{14.03,-1.546},
	{-1,-1},		//Aquarius
	{21.52,-5.57},
	{20.8,-9.494},
	{21.166,-11.469},
	{21.52,-5.57},
	{22.11,-0.366},
	{22.48,-0.019},
	{22.6,-0.115},
	{22.883,-7.579},
	{22.833,-13.592},
	{22.883,-7.579},
	{23.25,-6.046},
	{-1,-1},		//sagittarius
	{19.366,-17.046},
	{18.96,-21.104},
	{18.466,-25.416},
	{18.35,-29.826},
	{18.4,-34.381},
	{-1,-1},
	{19.05,-29.878},
	{18.916,-26.25},
	{19.083,-21.739},
	{18.916,-26.25},
	{18.466,-25.416}
};	



void CalculateOutlines()
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the outline objects

	double azm,alt;
	float ra,dec;
	short int i;

	for (i=0;i<CONSTNUMBER;i++)
	{
		azm=-1;alt=-1;
		ra=outlinedata[i].ra;dec=outlinedata[i].dec;
		if (ra!=-1) MakeLocal((double)ra,(double)dec,&azm,&alt);
		outlines[i].alt=float(alt); // radians
		outlines[i].azm=float(azm);   // radians
	}
	

}


double Get_Outlines_Alt(int i)
{
	return outlines[i].alt;
}

double Get_Outlines_Azm(int i)
{
	return outlines[i].azm;
}
