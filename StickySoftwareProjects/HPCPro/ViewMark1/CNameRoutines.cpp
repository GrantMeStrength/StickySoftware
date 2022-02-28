
// Handle the Const and Star names

#include "stdafx.h"

#define CNUMNAMES 55

extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

struct cname_type {
	 char name[15];
	float ra,dec;
} ;

struct cname_cords_type {
	float alt,azm;
} ;

struct cname_cords_type cncords[CNUMNAMES];

struct cname_type cname[CNUMNAMES]=
{
// 32 Constellation Names

{"ARIES",2.5,23},
{"PISCES",1.5,10},
{"AQUARIUS",22.66,-7.88},
{"CAPRICORN",20.75,-19},
{"SAGITTARIUS",19,-32},
{"SCORPIUS",17.2,-35},
{"LIBRA",15.5,-20},
{"VIRGO",12.78,4.5},
{"LEO",10.75,18},
{"CANCER",8.8,17},
{"GEMINI",7.33,25},
{"TAURUS",4.3,18},
{"ANDROMEDA",1.33,38},
{"URSA MAJOR",11.5,48},
{"URSA MINOR",15,80},
{"PEGASUS",22.75,18},
{"CASSIOPEIA",1,55},
{"ORION",5.5,-0.5},
{"DRACO",17.5,60},
{"CYGNUS",20,39.5},
{"LEO MINOR",10.6,33.38},
{"CANIS MAJOR",6.8,-23.2},
{"CANIS MINOR",7.5,6.5},
{"CETUS",2,-6},
{"BOOTES",15,35},
{"HYDRA",10,-18},
{"CRUX", 12.5,-54.59},
{"VELA",10,-45},
{"TELESCOPIUM",19.3, -50},
{"TRIANGULUM AUS",16.66,-63},
{"CHAMAELEON",12,-82},
{"AQUILA",19.73,-1.38}, 


// Now the 23 `nicest` stars

{"Sirius",float(6.75246417),float(-16.7161083)},
{"Canopus",float(6.39919972),float(-52.6956945)},
{"Alpha Centauri",float(14.6599681),float(-60.8354)},
{"Arcturus",float(14.2610214),float(19.1824195)},
{"Vega",float(18.6156478),float(38.7836583)},
{"Capella",float(5.27815361),float(45.9980278)},
{"Rigel",float(5.24229667),float(-8.20166111)},
{"Procyon",float(7.65503139),float(5.22501667)},
{"Achernar",float(1.62857),float(-57.2367167)},
{"Hadar",float(14.0637245),float(-60.3729972)},
{"Altair",float(19.8463895),float(8.86834167)},
{"Betelgeuse",float(5.91952972),float(7.40704167)},
{"Aldebaran",float(4.59867695),float(16.509275)},
{"Acrux",float(12.4432975),float(-63.09905)},
{"Spica",float(13.4198853),float(-11.1613083)}, 
{"Antares",float(16.490122),float(-26.4319861)},
{"Pollux",float(7.75526278),float(28.0261833)},
{"Fomalhaut",float(22.9608486),float(-29.62225)},
{"Deneb",float(20.6905325),float(45.2803639)},
{"Castor",float (7.57666583),float(31.8884806)},
{"Polaris",float(2.53019556),float(89.2640889)},
{"Algol",float(3.1361475),float(40.955675)},
{"Mizar",float(12.9004856),float(55.9598528)}

};


void CalculateCNames()
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the Messier objects

	double az,alt;
	int i;

	for (i=0;i<CNUMNAMES;i++)
	{
		MakeLocal((double)cname[i].ra,(double)cname[i].dec,&az,&alt);
		cncords[i].alt=float(alt); // radians
		cncords[i].azm=float(az);   // radians
	}
}


double Get_CName_Alt(int i)
{
	return cncords[i].alt;
}

double Get_CName_Azm(int i)
{
	return cncords[i].azm;
}

/*
char * Get_CName(int i)
{
	return &cname[i].name[0];
}
*/

CString Get_CString(int i)
{
	return cname[i].name;
}