/*
** Informational global to several files.
*/

//#define DEMO

// **** Zoominness **** //

#define MINZOOM 1//0.1// 0.01
#define MAXZOOM 3.0

// **** Switches *****

#define HorizonOn	0
#define StarsOn		1
#define PlanetsOn	2
#define SitesOn		3
#define MarkersOn	4
#define LabelsOn	5
#define InvertOn	6
#define TextOn		7
#define MessOn		8
#define ParallaxOn	9
#define HideOn		10
#define SunMoonOn	11
#define OutlineOn	12
#define TipsOn		13
#define RealSizeOn	14
#define CompassOn	15
////
#define ToolOpen	16		// Open the toolbox next time please
#define NorthNess	17
#define EastNess	18
#define KeyLook		19
#define KeyZoom		20
#define KeyTime		21
#define GridOn		22
#define HourGlassOn	23
//#define HighContrast 24
#define GfxMoon		25
#define EclipticOn	26
#define Display1	27
#define Display2	28

// Not saved...
#define ToolOn		33

// Bodies... oo,err

#define SUN 0
#define MERCURY 1
#define VENUS 2
#define MARS 3
#define JUPITER 4
#define SATURN 5
#define URANUS 6
#define NEPTUNE 7
#define PLUTO 8
#define MOON 9

#define ORIGIN 0
//#define HEIGHT 216 // 192
//#define HALFHEIGHT 108 // 96

struct bodytype {
	double alt;
	double az;
	double ra;
	double dec;
	float mag;
	float phase;
	float size;
	float distance;
	double risetime;
	double settime;
	double riseaz;
	double setaz;
};


struct solartype {
	double JD;
	double LST;
	double GST;
	struct bodytype body[10];
};
