

// Stars, Constellations, Messier, Bright Stars, Names...

#include "StdAfx.h"
#include "newfk5data.h"

#define NUMBEROFSTARS 9096
#define CONSTNUMBER 299  // 227 
#define CNUMNAMES 55 // (including Bright Stars)


extern double R2D (double angle);
extern double D2R (double angle);
extern void MakeLocal(double RA,double Dec, double *Az, double *Alt);

struct star_type
{
	float alt,azm;
};


struct star_type stars[STARNUM];


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

struct mess_type {
	 char name[20];
	float ra,dec;
} ;

struct mess_cords_type {
	float alt,azm;
} ;

struct mess_cords_type mcords[110];

struct mess_type mess[110]=
{
{"1 Crab Nebula",5.56805556,22.0166667},
{"2",21.5513889,-0.816666667},
{"3",13.7005556,28.3833333},
{"4",16.385,-26.5333333},
{"5",15.3016667,2.08333333},
{"6",17.6669445,-32.2166667},
{"7",17.8858333,-34.8166667},
{"8 Lagoon Nebula",18.0522222,-24.3833333},
{"9",17.3172222,-18.5166667},
{"10",16.9502778,-4.1},
{"11",18.8502778,-6.26666667},
{"12",16.7838889,-1.95},
{"13",16.6852778,36.4666667},
{"14",17.6183333,-3.25},
{"15",21.5,12.1666667},
{"16 Eagle Nebula",18.3022222,-13.7833333},
{"17 Omega Nebula",18.3355556,-16.1833333},
{"18",18.3191667,-17.1333333},
{"19",17.035,-26.2666667},
{"20 Trifid Nebula",18.035,-23.0333333},
{"21",18.0683333,-22.5},
{"22",18.6011111,-23.9},
{"23",17.9355556,-19.0166667},
{"24",18.2691667,-18.4833333},
{"25",18.5183333,-19.25},
{"26",18.7505556,-9.4},
{"27 Dumbbell Nebula",19.985,22.7166667},
{"28",18.4013889,-24.8666667},
{"29",20.3858333,38.5333333},
{"30",21.6677778,-23.1833333},
{"31 Andromeda Galaxy",0.701944445,41.2666667},
{"32",0.701944445,40.8666667},
{"33",1.5525,30.65},
{"34",2.7,42.7833333},
{"35",6.13583333,24.3333333},
{"36",5.60027778,34.1333333},
{"37",5.86777778,32.55},
{"38",5.46861111,35.8333333},
{"39",21.5338889,48.4333333},
{"40",12.3677778,58.0833333},
{"41",6.78333333,-20.7333333},
{"42 Orion Nebula",5.58444445,-5.45},
{"43",5.585,-5.26666667},
{"44 Beehive Cluster",8.66694445,19.9833333},
{"45 Pleiades",3.78333333,24.1166667},
{"46",7.68555556,-14.8166667},
{"47",7.60166667,-14.5},
{"48",8.21888889,-5.8},
{"49",12.4855556,8},
{"50",7.05055556,-8.33333333},
{"51 Whirlpool Galaxy",13.4858333,47.2},
{"52",23.4005556,61.5833333},
{"53",13.2025,18.1666667},
{"54",18.9169445,-30.4833333},
{"55",19.6666667,-30.9666667},
{"56",19.2683333,30.1833333},
{"57 Ring Nebula",18.885,33.0333333},
{"58",12.6186111,11.8166667},
{"59",12.7,11.65},
{"60",12.7186111,11.55},
{"61",12.3525,4.46666667},
{"62",17.0172222,-30.1166667},
{"63",13.2522222,42.0333333},
{"64 Blackeye Galaxy",12.9352778,21.6833333},
{"65",11.3025,13.0833333},
{"66",11.3338889,12.9833333},
{"67",8.83444445,11.8166667},
{"68",12.6513889,-26.75},
{"69",18.5677778,-32.35},
{"70",18.7172222,-32.3},
{"71",19.8855556,18.7833333},
{"72",20.8847222,-12.5333333},
{"73",20.9691667,-12.6333333},
{"74",1.60194445,15.7833333},
{"75",20.1002778,-21.9166667},
{"76",1.70111111,51.5666667},
{"77",2.70194445,-0.0166666667},
{"78",5.76861111,0.05},
{"79",5.40138889,-24.55},
{"80",16.2833333,-22.9833333},
{"81",9.91833333,69.0666667},
{"82",9.91888889,69.6833333},
{"83",13.6166667,-29.8666667},
{"84",12.4169445,12.8833333},
{"85",12.4177778,18.1833333},
{"86",12.4338889,12.95},
{"87",12.5022222,12.4},
{"88",12.5333333,14.4166667},
{"89",12.5852778,12.55},
{"90",12.6022222,13.1666667},
{"91",12.5844445,14.5},
{"92",17.2836111,43.1333333},
{"93",7.735,-23.8666667},
{"94",12.8358333,41.1166667},
{"95",10.7333333,11.7},
{"96",10.7688889,11.8166667},
{"97 Owl Nebula",11.2355556,55.0166667},
{"98",12.2188889,14.9},
{"99",12.3022222,14.4166667},
{"100",12.3691667,15.8166667},
{"101",14.0508333,54.35},
{"102",15.1013889,55.75},
{"103",1.55055556,60.7},
{"104",12.6666667,-11.6166667},
{"105",10.7855556,12.5833333},
{"106",12.3166667,47.3},
{"107",16.5347222,-13.05},
{"108",11.1847222,55.6666667},
{"109",11.9516667,53.3833333},
{"110",0.667777778,41.6833333}
};


void CalculateMess()
{
	// Using the current time,location etc calculate
	// the Alt.Az for all the Messier objects

	double az,alt;
	int i;

	for (i=0;i<110;i++)
	{
		MakeLocal((double)mess[i].ra,(double)mess[i].dec,&az,&alt);
		mcords[i].alt=float(alt); // radians
		mcords[i].azm=float(az);   // radians
	}
}


double Get_Mess_Alt(int i)
{
	return mcords[i].alt;
}

double Get_Mess_Azm(int i)
{
	return mcords[i].azm;
}

CString Get_Mess_String(int i)
{

	return mess[i].name;

}

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
	int i;

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

{"Achernar",float(1.62857),float(-57.2367167)},
{"Acrux",float(12.4432975),float(-63.09905)},
{"Aldebaran",float(4.59867695),float(16.509275)},
{"Alpha Centauri",float(14.6599681),float(-60.8354)},
{"Altair",float(19.8463895),float(8.86834167)},
{"Algol",float(3.1361475),float(40.955675)},
{"Antares",float(16.490122),float(-26.4319861)},
{"Arcturus",float(14.2610214),float(19.1824195)},
{"Betelgeuse",float(5.91952972),float(7.40704167)},
{"Canopus",float(6.39919972),float(-52.6956945)},
{"Capella",float(5.27815361),float(45.9980278)},
{"Castor",float (7.57666583),float(31.8884806)},
{"Deneb",float(20.6905325),float(45.2803639)},
{"Fomalhaut",float(22.9608486),float(-29.62225)},
{"Rigel",float(5.24229667),float(-8.20166111)},
{"Hadar",float(14.0637245),float(-60.3729972)},
{"Mizar",float(12.9004856),float(55.9598528)},
{"Polaris",float(2.53019556),float(89.2640889)},
{"Pollux",float(7.75526278),float(28.0261833)},
{"Procyon",float(7.65503139),float(5.22501667)},
{"Sirius",float(6.75246417),float(-16.7161083)},
{"Spica",float(13.4198853),float(-11.1613083)}, 
{"Vega",float(18.6156478),float(38.7836583)},
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


CString Get_CString(int i)
{
	return cname[i].name;
}