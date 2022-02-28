
//
// Pocket BattleZone for PsPC
// 3D Drawing routines
//

#define PC 1
#define HPC 2
#define TARGET 2

#include "stdafx.h"
#include "math.h"
#include "Resource.h"

short int ORIGINX=0;

#define ORIGIN 80
#define CY 16
#define CX 180

#define HEIGHT 320 // was 192
#define HALFHEIGHT 120
#define TOOCLOSE 3
#define HIT 0.75
#define	MAP 6
#define HARDER 2000
#define moon_limit 20

#define WHITERGB (RGB(255,255,255))
#define BLACKRGB (RGB(0,0,0))
#define LTGREYRGB (RGB(190,190,190))
#define DKGREYRGB (RGB(80,80,80))


#define WIDTH 240
#define HALFWIDTH 120

float const rad=3.141592654/180;
float const deg = 57.29577951;

extern bool moveup,movedown,moveleft,moveright;

#define LL 70

short int linex1[2][LL];
short int liney1[2][LL];
short int linex2[2][LL];
short int liney2[2][LL];

short int linecount[2];
short int linemode=0;
short int nlinemode=1;


// hidden bitmap.. or so

CBitmap control_bitmap,control_bitmap2;
CDC pMemDC,pMemDC2;

// Game Variables

short int frame=0;
short int Lives;
short int GameCounter;
short int GameState=0;
short int Score;
short int High;
short int Level;
short int Shots,Hits;
short int Ammo;
bool Sound;
bool size=false;
short int	moon_position=0;
float SaucerSpeed,TankSpeed;
bool Tank1,Tank2,Saucer1,Saucer2;
short int AmmoBonus;
short int EnemyCount;

short int tc=0;

short int tx,ty;

bool Key_left, Key_right, Key_up, Key_fire;

// Prototypes

void ClipAndDrawLine(CDC *pDC, float x0, float y0, float x1, float y1);
void TankShoots(float x,float y,float angle);
void Redraw(CDC *pDC);

#include "RegStuff.h"


// Program pens...

	CString s;
	CRect brect(ORIGIN+WIDTH-160,ORIGIN+10,ORIGIN+WIDTH-10,ORIGIN+30);
	CRect arect(ORIGIN+WIDTH-160,ORIGIN+42,ORIGIN+WIDTH-10,ORIGIN+50);
	CRect crect(ORIGIN+WIDTH-160,ORIGIN+26,ORIGIN+WIDTH-10,ORIGIN+50);
	CRect drect(ORIGIN+WIDTH-160,ORIGIN+26,ORIGIN+WIDTH-10,ORIGIN+50);
	CPen WhitePen,DKGreyPen,BlackPen,ThickPen;

// Data types

struct triple_type {
	float x,y,z;
};

struct float_type {
	float x,y;
};

struct pair_type {
	short int x,y;
};

// Globals

float sd,cd;

#include "data.h"
#include "letterdata.h"
//////// Useful functions /////////

void ResetL()
{
	// set the counter back to zero

	linecount[linemode]=0;
}

void AddL(int x1, int y1, int x2, int y2)
{
	if (linecount[linemode]>LL) return;

	linex1[linemode][linecount[linemode]]=x1;
	liney1[linemode][linecount[linemode]]=y1;
	linex2[linemode][linecount[linemode]]=x2;
	liney2[linemode][linecount[linemode]]=y2;
//	linec[linecount]=c;
	linecount[linemode]++;
}


void DrawL(CDC *pDC)
{
	short int i;
	short int x1,y1,x2,y2,lx,ly;


	lx=-1;ly=-1;

		pDC->SelectObject(&BlackPen);
		//pDC->SelectObject(&WhitePen);


	for (i=0;i<linecount[linemode];i++)
	{
		x1=linex1[linemode][i];
		y1=liney1[linemode][i];
		x2=linex2[linemode][i];
		y2=liney2[linemode][i];
		
		if ((lx==x1) && (ly==y1))
		{
			pDC->LineTo(x2,y2);
		}
		else
		{
			pDC->MoveTo(x1,y1);
			pDC->LineTo(x2,y2);
		}
		lx=x2;
		ly=y2;
	}

	// if last co-ords used were the same, then a
	// move is not needed

}

void EraseL(CDC *pDC)
{
	short int i;
	pDC->SelectObject(&WhitePen);
	//pDC->SelectObject(&BlackPen);
	short int x1,y1,x2,y2,lx,ly;

	lx=-1;ly=-1;

	for (i=0;i<linecount[nlinemode];i++)
	{
		x1=linex1[nlinemode][i];
		y1=liney1[nlinemode][i];
		x2=linex2[nlinemode][i];
		y2=liney2[nlinemode][i];
		
		if ((lx==x1) && (ly==y1))
		{
			pDC->LineTo(x2,y2);
		}
		else
		{
			pDC->MoveTo(x1,y1);
			pDC->LineTo(x2,y2);
		}
		lx=x2;
		ly=y2;
	}
}



void DrawLines(struct pair_type *ptp, int xx, int yy, int c,CDC *pDC)
{
	short int x,y;


	pDC->MoveTo(xx+ORIGINX,yy+ORIGIN);

	for (int i=0;i<c;i++)
	{
		x=tx*(*ptp).x;
		y=ty*(*ptp++).y;

		if ((x<0) || (y<0))
		{
			pDC->MoveTo(xx-x+ORIGINX,yy+y+ORIGIN);
		}
		else
		{
			pDC->LineTo(xx+x+ORIGINX,yy-y+ORIGIN);
		}
	}
}

void PrintLetter(char l, int x, int y,CDC *pDC)
{

	//pDC->SelectObject(&BlackPen);
	pDC->SelectObject(&ThickPen);

	switch (l) {
	case 'A':DrawLines(L_A,x,y,5,pDC);break;
	case 'C':DrawLines(L_C,x,y,4,pDC);break;
	case 'D':DrawLines(L_D,x,y,4,pDC);break;
	case 'E':DrawLines(L_E,x,y,6,pDC);break;	
	case 'F':DrawLines(L_F,x,y,4,pDC);break;	
	case 'G':DrawLines(L_G,x,y,6,pDC);break;
	case 'H':DrawLines(L_H,x,y,5,pDC);break;	
	case 'I':DrawLines(L_I,x,y,5,pDC);break;
	case 'J':DrawLines(L_I,x,y,5,pDC);break;
	case 'K':DrawLines(L_K,x,y,4,pDC);break;	
	case 'L':DrawLines(L_L,x,y,3,pDC);break;
	case 'M':DrawLines(L_M,x,y,4,pDC);break;
	case 'N':DrawLines(L_N,x,y,3,pDC);break;
	case 'O':DrawLines(L_O,x,y,4,pDC);break;
	case 'P':DrawLines(L_P,x,y,4,pDC);break;
	case 'R':DrawLines(L_R,x,y,5,pDC);break;
	case 'S':DrawLines(L_S,x,y,5,pDC);break;
	case 'T':DrawLines(L_T,x,y,4,pDC);break;
	case 'U':DrawLines(L_U,x,y,4,pDC);break;
	case 'V':DrawLines(L_V,x,y,3,pDC);break;
	case 'W':DrawLines(L_W,x,y,5,pDC);break;	
	case 'Y':DrawLines(L_Y,x,y,5,pDC);break;
	case 'Z':DrawLines(L_Z,x,y,4,pDC);break;

	case '0':DrawLines(N_0,x,y,4,pDC);break;
	case '1':DrawLines(N_1,x,y,2,pDC);break;
	case '2':DrawLines(N_2,x,y,6,pDC);break;
	case '3':DrawLines(N_3,x,y,5,pDC);break;
	case '4':DrawLines(N_4,x,y,6,pDC);break;
	case '5':DrawLines(N_5,x,y,5,pDC);break;
	case '6':DrawLines(N_6,x,y,5,pDC);break;
	case '7':DrawLines(N_7,x,y,3,pDC);break;
	case '8':DrawLines(N_8,x,y,6,pDC);break;
	case '9':DrawLines(N_9,x,y,7,pDC);break;

	default:break;
	}
}

void Message1(CDC *pDC)
{
	char message[]="GAME OVER";

	tx=8;ty=6;
	for (int x=0;x<9;x++)
	{
		PrintLetter(message[x],15+12+x*20,40,pDC);
	}

	// print score
	tx=3;ty=4;
	s.Format (L"SCORE %05d HIGH %05d",Score,High);

	for (x=0;x<24;x++)
	{
		PrintLetter(s[x],8+12+x*9,150,pDC);
	}

}

void Message2(CDC *pDC)
{
	char message[]="COLLISION";
	tx=4;ty=4;
	for (int x=0;x<9;x++)
	{
		PrintLetter(message[x],48+x*12,168,pDC);
	}
}

void Message3(CDC *pDC)
{

	s.Format (L"Paused   ");
	pDC->DrawText(s, arect, DT_LEFT | DT_SINGLELINE);

}

void Message4(CDC *pDC)
{
	char message[]="GET READY";
	tx=8;ty=6;
	for (int x=0;x<9;x++)
	{
		PrintLetter(message[x],15+16+x*20,168,pDC);
	}
}

void Message5(CDC *pDC)
{
	char message[]="WARNING SAUCER ATTACK";
	tx=4;ty=4;
	for (int x=0;x<21;x++)
	{
		PrintLetter(message[x],16+x*10,168,pDC);
	}
}


void Message6(CDC *pDC)
{

	s.Format (L"LEVEL %2d",Level);
	tx=8;ty=6;
	for (int x=0;x<8;x++)
	{
//		PrintLetter(s[x],ORIGIN+160+x*20,168,pDC);
		PrintLetter(s[x],20+16+x*20,40,pDC);
	}

}

void Message7(CDC *pDC, int i)
{
	char message[21];
	int l;
	switch(i) {
		case 0:strcpy(message,"    TANKZONE V2.1");l=15;break;
		case 1:strcpy(message,"HERE IS YOUR MISSION");l=20;break;
		case 2:strcpy(message,"SURVIVE ENEMY ATTACK");l=20;break;
		case 3:strcpy(message,"DESTROY ENEMY FORCES");l=20;break;
		case 4:strcpy(message,"REPEL UFO INVASION");l=18;break;
		case 5:strcpy(message,"WARNING AMMO LIMITED");l=20;break;
		case 6:strcpy(message,"USE DEPOTS TO REARM");l=19;break;
		case 7:strcpy(message,"TAP ARROWS TO MOVE");l=18;break;
		case 8:strcpy(message,"CHARITYWARE VERSION");l=19;break;
		case 9:strcpy(message,"   STICKY SOFTWARE");l=18;break;
		case 10:strcpy(message,"   COPYRIGHT 1998");l=17;break;
		case 11:strcpy(message,"   WWW STICKY NET");l=17;break;
	}

	tx=3;ty=5;
	for (int x=0;x<l;x++)
		PrintLetter(message[x],4+(4*(l/2))+9*x,25,pDC);
	
}


/////////////////

float dir(float x,float z)
{
	float a;

	a=deg*atan2(x,z);

	if (x<0) a+=360;

	return a;
}



void PlaySound (int soundnumber)
{

	
	if (!Sound) return;

	switch (soundnumber) {
		
	case 0:	sndPlaySound(L"TZ1", SND_FILENAME|SND_ASYNC);break;
	case 1:	sndPlaySound(L"TZ2", SND_FILENAME|SND_ASYNC);break;
	case 2:	sndPlaySound(L"TZ3", SND_FILENAME|SND_ASYNC);break;
	case 3:	sndPlaySound(L"TZ4", SND_FILENAME|SND_ASYNC);break;
	case 4:	sndPlaySound(L"TZ5", SND_FILENAME|SND_ASYNC);break;
	case 5:	sndPlaySound(L"TZ6", SND_FILENAME|SND_ASYNC);break;
	case 6: sndPlaySound(L"TZ7", SND_FILENAME|SND_ASYNC);break;
	case 7: sndPlaySound(L"TZ8", SND_FILENAME|SND_ASYNC);break;
	case 8: sndPlaySound(L"TZ9", SND_FILENAME|SND_ASYNC);break;
	default:sndPlaySound(L"TZ4", SND_FILENAME|SND_ASYNC);break;
	}

}


///////////////////////////////////


class Windscreen {
	struct pair_type broken_glass[57];
public:
		Windscreen();
		void Draw(CDC *pDC);
};

Windscreen::Windscreen()
{
	for (int i=0;i<57;i++)
	{
		broken_glass[i].x=8*smash[i].x;
		broken_glass[i].y=16+16*smash[i].y;
	}
}

void Windscreen::Draw(CDC *pDC)
{
	bool mode; // true - move, false - draw
	//pDC->SelectObject(&DKGreyPen);
	pDC->SelectObject(&ThickPen);

	int dx;

	if (WIDTH<600) dx=0; else dx=-84;
	if (size) dx=-56;

	for (int i=0;i<57;i++)
	{
		if (broken_glass[i].x==0) 
			mode=true;//move; 
		else 
		{
			if (mode==false)
				pDC->LineTo(broken_glass[i].x-dx,broken_glass[i].y+ORIGIN);
			else
			{
				pDC->MoveTo(broken_glass[i].x-dx,broken_glass[i].y+ORIGIN);
				mode=false;
			}

		}
	}
 }

Windscreen glass;							// Glass shatter



class Horizon {
	struct triple_type mountains[36];	// 36 mountains
public:
		Horizon();
		void Draw(CDC *pDC);
		void Spin(float angle);
};

Horizon::Horizon()
{
	int h=0,dh=1;
	for (int i=0;i<36;i++)
	{
		mountains[i].x=10*sin(rad*i*10);
		mountains[i].z=10*cos(rad*i*10);
		mountains[i].y=-h;
		h=h+dh;
	
		if (Random()&1) dh=-dh;
		if (h>5) dh=-1;
		if (h<0) dh=1;
	}
}

void Horizon::Spin(float angle)
{
	float zz,xx;

	for (int j=0;j<36;j++)	// spin landscape and moon
	{
			xx=(mountains[j].x*cd)-(mountains[j].z*sd);
			zz=(mountains[j].x*sd)+(mountains[j].z*cd); 	
			mountains[j].z=zz;mountains[j].x=xx;
	}
}

void Horizon::Draw(CDC *pDC)
{

	float x1,y1,z1,x2,y2,z2;
	float px1,py1,px2,py2;			// perspective co-ordinates

//	pDC->SelectObject(&DKGreyPen);

	int j=1;
	for (int i=0;i<36;i++)
	{
		x1=mountains[i].x;
		y1=mountains[i].y;
		z1=mountains[i].z;
		x2=mountains[j].x;
		y2=mountains[j].y;
		z2=mountains[j].z;
	
		j++; if (j==36) j=0;

		if ((z1>1) && (z2>1))
		{
			px1=40*(x1);py1=5*(y1);
			px2=40*(x2);py2=5*(y2);
			if (!((px1<-HALFWIDTH) && (px2<-HALFWIDTH)
			||(px1>HALFWIDTH) && (px2>HALFWIDTH)))
			ClipAndDrawLine(pDC,px1,-20+py1,px2,-20+py2);		
		}
	}
	AddL(0,6+ORIGIN+HALFHEIGHT,WIDTH,6+ORIGIN+HALFHEIGHT);		// central line?
}

class Cube {
	struct triple_type position;
	struct triple_type p1[12],p2[12];
	struct triple_type bounding[4];			// bounding box
public:
	Cube();									// Constructor
	void Spin(float angle);				// Spin cube locally
	void Rotate(float angle);				// Alter cube's position globally
	void Move(float distance);				// Alter cube's position globally
	void Draw(CDC *pDC);
	void SetPosition(float x,float y,float z);
	bool TestDistance(float distance);		// Is the cube too close?
	float GetX();
	float GetZ();
};


Cube::Cube()// Constructor
{
	int j=0;
	for (int i=0;i<12;i++)
	{
		p1[i]=cube_lines[j++];
		p2[i]=cube_lines[j++];
	};

	bounding[0].x= 2;bounding[0].y=0;bounding[0].z= 2;
	bounding[1].x= 2;bounding[1].y=0;bounding[1].z=-2;
	bounding[2].x=-2;bounding[2].y=0;bounding[2].z= 2;
	bounding[3].x=-2;bounding[3].y=0;bounding[3].z=-2;
}

float Cube::GetX()
{
	return position.x;
}

float Cube::GetZ()
{
	return position.z;
}


bool Cube::TestDistance(float distance)
{
	// Returns false if unsafe to move

	float d; 
	float x,z;

	for (int i=0;i<4;i++)
	{
		x=bounding[i].x+position.x;
		z=bounding[i].z+position.z-distance;
		d=x*x+z*z;
		if (d<TOOCLOSE) return false;
	}
	return true;
}

void Cube::SetPosition(float x,float y,float z)
{
	position.x=x;
	position.y=y;
	position.z=z;
}

void Cube::Spin(float angle)
{
	// Spin around Y axis

	float zz,xx;

	//angle=-angle;
	sd=sin(angle*rad);
	cd=cos(angle*rad);

	for (int j=0;j<12;j++)
	{
			xx=(p1[j].x*cd)-(p1[j].z*sd);
			zz=(p1[j].x*sd)+(p1[j].z*cd); 	
			p1[j].z=zz;p1[j].x=xx;
			xx=(p2[j].x*cd)-(p2[j].z*sd);
			zz=(p2[j].x*sd)+(p2[j].z*cd); 	
			p2[j].z=zz;p2[j].x=xx;
	}
	for (j=0;j<3;j++)
	{
			xx=(bounding[j].x*cd)-(bounding[j].z*sd);
			zz=(bounding[j].x*sd)+(bounding[j].z*cd); 	
			bounding[j].z=zz;bounding[j].x=xx;	
	}
}

void Cube::Rotate(float angle)
{
	float zz,xx;

	xx=(position.x*cd)-(position.z*sd);
	zz=(position.x*sd)+(position.z*cd); 	
	position.z=zz;position.x=xx;
}

void Cube::Move(float distance)
{
	position.z-=distance;
}

void Cube::Draw(CDC *pDC)
{
	// Draw the Cube in 3D

	pDC->SelectObject(&DKGreyPen);

	float x1,y1,z1,x2,y2,z2;
	float px1,py1,px2,py2;			// perspective co-ordinates

	x1=position.x/2;
	z1=position.z/2;

	if (frame==0) 
		if ((x1*x1+z1*z1)<900) pDC->FillSolidRect(40+x1,40-z1,2,2,DKGREYRGB);

	for (int i=0;i<12;i++)
	{
		x1=p1[i].x+position.x;y1=p1[i].y+position.y;z1=p1[i].z+position.z;
		x2=p2[i].x+position.x;y2=p2[i].y+position.y;z2=p2[i].z+position.z;

		//Plot2D(pDC,x1*MAP,z1*MAP,x2*MAP,z2*MAP);
	
		if ((z1>1) && (z2>1))
		{
			px1=200*(x1/z1);py1=200*(y1/z1);
			px2=200*(x2/z2);py2=200*(y2/z2);
		
			if (!((px1<-HALFWIDTH) && (px2<-HALFWIDTH)
				||(px1>HALFWIDTH) && (px2>HALFWIDTH)))
				ClipAndDrawLine(pDC,px1,py1,px2,py2);
		}
	}
}


Cube box[3];								// Declare Cuboids



class Flag {
	struct triple_type position;
	struct triple_type p1[3],p2[3];
public:
	Flag();
	void Spin(float angle);
	void Rotate(float angle);
	void Move(float distance);
	void Draw(CDC *pDC);
	void Reset();
};

Flag::Flag()
{
	p1[0].x=0;p1[0].y=0;p1[0].z=0;
	p1[1].x=0;p1[1].y=-2;p1[1].z=0;
	p1[2].x=1;p1[2].y=-1.5;p1[2].z=0;
	p1[3].x=0;p1[3].y=-1;p1[3].z=0;
}


void Flag::Reset()
{		// Pick a random location

	int r=Random()&7;
	int x,z;

	switch (r) {
		case 0:x=15;z=10;break;
		case 1:x=10;z=15;break;	
		case 2:x=-10;z=15;break;
		case 3:x=-15;z=10;break;
		case 4:x=-10;z=-15;break;
		case 5:x=-15;z=-10;break;
		case 6:x=15;z=-10;break;
		case 7:x=10;z=-15;break;
	}

	position.x=x+box[0].GetX();
	position.y=1.5;
	position.z=z+box[0].GetZ();;
}



void Flag::Spin(float angle)
{
	// Spin around Y axis

	float zz,xx;

	//angle=-angle;
	sd=sin(angle*rad);
	cd=cos(angle*rad);

	for (int j=0;j<3;j++)
	{
			xx=(p1[j].x*cd)-(p1[j].z*sd);
			zz=(p1[j].x*sd)+(p1[j].z*cd); 	
			p1[j].z=zz;p1[j].x=xx;
	}
}

void Flag::Rotate(float angle)
{
	float zz,xx;

	xx=(position.x*cd)-(position.z*sd);
	zz=(position.x*sd)+(position.z*cd); 	
	position.z=zz;position.x=xx;
}

void Flag::Move(float distance)
{
	position.z-=distance;
	// Test for closeness
	float d;
	d=position.x*position.x+position.z*position.z;
	if (d<TOOCLOSE) 
		{	// Close enough to flag!
			Ammo+=AmmoBonus; // gets less later on, maybe?
			Reset();
			PlaySound(6); // change this!
		}

}

void Flag::Draw(CDC *pDC)
{
	// Draw the Flag in 3D

	pDC->SelectObject(&DKGreyPen);

	float x1,y1,z1;//x2,y2,z2;
	float px1,py1,px2,py2;			// perspective co-ordinates

	x1=position.x/2;
	z1=position.z/2;

	if (frame==0)
		if ((x1*x1+z1*z1)<900) pDC->FillSolidRect(40+x1,40-z1,2,2,DKGREYRGB);



	for (int i=0;i<4;i++)
	{
		x1=p1[i].x+position.x;y1=p1[i].y+position.y;z1=p1[i].z+position.z;
	
	
		if ((z1>1))
		{
			px1=200*(x1/z1);py1=200*(y1/z1);
			
			if (i==0)
			{
				px2=px1;py2=py1;
			}
			else
			{
				if (!((px1<-HALFWIDTH) && (px2<-HALFWIDTH)
					||(px1>HALFWIDTH) && (px2>HALFWIDTH)))
					ClipAndDrawLine(pDC,px1,py1,px2,py2);
					px2=px1;py2=py1;
			}
		}
	}
}

Flag depot;



//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////

#include "TankClass.h"
#include "SaucerClass.h"

///////////////////////////////////////////////////////////////////////////////////


class Shell {
	struct triple_type position;
	struct triple_type p1[12],p2[12];
	float direction;						// angle which shell is facing in
	bool active;							// true if actively flying
	int range;
public:
	Shell();								// Constructor
	void Spin(float angle);				// Spin  locally
	void Rotate(float angle);				// Alter position globally
	void Move(float distance);				// Alter position globally
	void Draw(CDC *pDC);
	bool Think();							// Control shell's movements
	bool ThinkTank();
	void PlayerFire();						// Player hits fire button
	void TankFire(float x,float z,float angle);
	void Stop();							// Stop shell
	bool Firing();							// Is a shell running?
};


Shell::Shell()
{
	range=0;
	direction=0;
	active=false;
	int j=0;
	for (int i=0;i<12;i++)
	{
		p1[i].x=cube_lines[j].x/8;
		p1[i].y=cube_lines[j].y/8;
		p1[i].z=cube_lines[j++].z/8;
		p2[i].x=cube_lines[j].x/8;
		p2[i].y=cube_lines[j].y/8;
		p2[i].z=cube_lines[j++].z/8;
	};
}

void Shell::Stop()
{
	active=false;
}

bool Shell::Firing()
{
	return active;
}

void Shell::Spin(float angle)
{
	// Spin around Y axis

	//if (!active) return;

	float zz,xx;

	for (int j=0;j<12;j++)
	{
			xx=(p1[j].x*cd)-(p1[j].z*sd);
			zz=(p1[j].x*sd)+(p1[j].z*cd); 	
			p1[j].z=zz;p1[j].x=xx;
			xx=(p2[j].x*cd)-(p2[j].z*sd);
			zz=(p2[j].x*sd)+(p2[j].z*cd); 	
			p2[j].z=zz;p2[j].x=xx;
	}

}

void Shell::Rotate(float angle)
{
	//if (!active) return;

	float zz,xx;
	direction-=angle;
	xx=(position.x*cd)-(position.z*sd);
	zz=(position.x*sd)+(position.z*cd); 	
	position.z=zz;position.x=xx;
}

void Shell::Move(float distance)
{
	if (!active) return;

	position.z-=distance;
}

void Shell::Draw(CDC *pDC)
{
	// Draw the Shell in 3D

	if (!active) return;

	pDC->SelectObject(&BlackPen);

	float x1,y1,z1,x2,y2,z2;
	float px1,py1,px2,py2;			// perspective co-ordinates

	x1=position.x/2;
	z1=position.z/2;

	if (frame==0) 
		pDC->Ellipse(40+x1,40-z1,42+x1,42-z1);

	for (int i=0;i<12;i++)
	{
		x1=p1[i].x+position.x;y1=p1[i].y+position.y;z1=p1[i].z+position.z;
		x2=p2[i].x+position.x;y2=p2[i].y+position.y;z2=p2[i].z+position.z;

		//Plot2D(pDC,x1*MAP,z1*MAP,x2*MAP,z2*MAP);
	
		if ((z1>1) && (z2>1))
		{
			px1=200*(x1/z1);py1=200*(y1/z1);
			px2=200*(x2/z2);py2=200*(y2/z2);
		
			if (!((px1<-HALFWIDTH) && (px2<-HALFWIDTH)
				||(px1>HALFWIDTH) && (px2>HALFWIDTH)))
				ClipAndDrawLine(pDC,px1,py1,px2,py2);
		}
	}
}



void Shell::TankFire(float x,float z,float angle)
{
	// A Tank wants to launch a shell

	if (active) return;
	active=true;
	position.x=x;
	position.y=0;
	position.z=z;
	direction=angle;// Fire shell in the same direction as the tank
	range=0;
	PlaySound(2);
}

void Shell::PlayerFire()
{
	// Player wants to launch shell

	if (active) return;
	if (Ammo==0) {
		PlaySound(8);	
		return;
	}
	Ammo--;
	Shots++;
	active=true;
	position.x=0;
	position.y=0;
	position.z=0;
	direction=0;
	range=0;
	PlaySound(0);
}

bool Shell::Think()
{
	// Control the shell
	if (!active) return false;
	float x,z,dx,dz;
	
	// Move..
	position.x+=.8*sin(direction*rad);
	position.z+=.8*cos(direction*rad);


	// Test for cubes

	for (int i=0;i<3;i++)
	{
		x=box[i].GetX();
		z=box[i].GetZ();
		
		dx=position.x-x; if (dx<0) dx=-dx;
		dz=position.z-z; if (dz<0) dz=-dz;

		if ((dx<HIT) && (dz<HIT)) active=false;
	}

	// Test for tanks

		if (panzer.Active())
		{
			x=panzer.GetX();
			z=panzer.GetZ();
			dx=position.x-x; if (dx<0) dx=-dx;
			dz=position.z-z; if (dz<0) dz=-dz;
		
			if ((dx<HIT) && (dz<HIT)) 
			{
				active=false;
				panzer.Kill();
				Score+=range*10;
				Hits++; 
			}
		}

		if (panzer2.Active())
		{
			x=panzer2.GetX();
			z=panzer2.GetZ();
			dx=position.x-x; if (dx<0) dx=-dx;
			dz=position.z-z; if (dz<0) dz=-dz;
			if ((dx<HIT) && (dz<HIT)) 
			{
				active=false;
				panzer2.Kill();
				Hits++;
				Score+=range*10;
			}
		}

		if (martian.Active())
		{
			x=martian.GetX();
			z=martian.GetZ();
			dx=position.x-x; if (dx<0) dx=-dx;
			dz=position.z-z; if (dz<0) dz=-dz;
			if ((dx<HIT) && (dz<HIT)) 
			{
				active=false;
				martian.Kill();
				Hits++;
				Score+=range*20;
			}
		}


	// Range..
	range++;
	if (range<70) return true;
	active=false;

	return true;
}

bool Shell::ThinkTank()
{
	// Control the shell
	if (!active) return false;
	float x,z,dx,dz;
	
	// Move..
	position.x+=.8*sin(direction*rad);
	position.z-=.8*cos(direction*rad);

	// Test for cubes

	for (int i=0;i<3;i++)
	{
		x=box[i].GetX();
		z=box[i].GetZ();
		
		dx=position.x-x; if (dx<0) dx=-dx;
		dz=position.z-z; if (dz<0) dz=-dz;

		if ((dx<HIT) && (dz<HIT)) active=false;
	}

	// Test for hit player

	dx=position.x; if (dx<0) dx=-dx;
	dz=position.z; if (dz<0) dz=-dz;
	
	if ((dx<HIT) && (dz<HIT)) 
	{
		// Hit by enemy shell!
		active=false;
		GameCounter=0;
		GameState=30;
		PlaySound(1);
	}

	// Range..
	range++;
	if (range<70) return true;
	active=false;

	return true;
}

////////////////////////////////////////////////////////////////////////////


// Declare Objects!



Horizon edge;								// Declare Horizon

Shell shell;								// Player's weapon
Shell tank1shell;							// Tank's shell





void TankShoots(float x,float y,float angle)
{
	tank1shell.TankFire(x,y,angle);
}

void Wipe(CDC *pDC)
{
	pDC->SelectObject(&WhitePen);
	pDC->SelectStockObject(WHITE_BRUSH);
	//pDC->FillSolidRect(0,0,WIDTH+2,HEIGHT+28,WHITERGB);
	pDC->FillSolidRect(0,0,WIDTH,HEIGHT,WHITERGB);
	//pDC->FillSolidRect(0,ORIGIN,WIDTH,HEIGHT-ORIGIN,BLACKRGB);
}

void SmallWipe(CDC *pDC)
{
	pDC->SelectObject(&WhitePen);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->FillSolidRect(0,ORIGIN,WIDTH,120,WHITERGB);
	//pDC->FillSolidRect(0,ORIGIN,WIDTH,120,BLACKRGB);
}


inline int FindClipCode(int x, int y)
{
	int code=0;

	if (y>HALFHEIGHT) code|=1;
	else if (y<-HALFHEIGHT) code|=2;
	if (x>HALFWIDTH) code|=4;
	else if (x<-HALFWIDTH) code|=8;
	return code;
}

inline void ClipAndDrawLine(CDC *pDC, float dx0, float dy0, float dx1, float dy1)
{

	int code0, code1, codeout;
	bool accept=false, done=false;

	int x0=(int)dx0;
	int x1=(int)dx1;
	int y0=(int)dy0;
	int y1=(int)dy1;

	code0=FindClipCode(x0,y0);
	code1=FindClipCode(x1,y1);

	do {
		if (!(code0 | code1)) { /* Trival -- both inside */ 
			accept=true;done=true;
		} else if (code0 & code1)	/* Both outside */
			done=true;
		else {
			float x,y;
			codeout=code0 ? code0 : code1;
			if (codeout & 1) {
				x=x0+(x1-x0)*(HALFHEIGHT-y0)/(y1-y0);
				y=HALFHEIGHT;
			} else if (codeout & 2) {
				x=x0+(x1-x0)*(-HALFHEIGHT-y0)/(y1-y0);
				y=-HALFHEIGHT;
			} else if (codeout & 4) {
				y=y0+(y1-y0)*(HALFWIDTH-x0)/(x1-x0);
				x=HALFWIDTH;
			} else {
				y=y0+(y1-y0)*(-HALFWIDTH-x0)/(x1-x0);
				x=-HALFWIDTH;
			}
			if (codeout==code0) {
				x0=(int)x;y0=(int)y;code0=FindClipCode(x0,y0);
			} else {
				x1=(int)x;y1=(int)y;code1=FindClipCode(x1,y1);
			}
		}
	} while (done==false);

	if (accept) {

		AddL(x0+ORIGINX+HALFWIDTH,y0+ORIGIN+HALFHEIGHT,x1+ORIGINX+HALFWIDTH,y1+ORIGIN+HALFHEIGHT);
		//pDC->MoveTo(x0+ORIGINX+HALFWIDTH,y0+ORIGIN+HALFHEIGHT);
		//pDC->LineTo(x1+ORIGINX+HALFWIDTH,y1+ORIGIN+HALFHEIGHT);
	}

}

void DrawMoon(CDC *pDC)
{

	if ((moon_position>moon_limit) || (moon_position<-moon_limit)) return;

	int mx=ORIGINX+HALFWIDTH+moon_position*6; // was 8
	int my=82;

	//	pDC->BitBlt(ORIGINX+HALFWIDTH+x,82,32,32,&dcMem2,0,0,SRCAND);

	AddL(mx+4,my+0,mx+1,my+15);
	AddL(mx+1,my+15,mx+6,my+25);
	AddL(mx+6,my+25,mx+15,my+29);
	AddL(mx+15,my+29,mx+28,my+27);
	AddL(mx+28,my+27,mx+12,my+17);
	AddL(mx+12,my+17,mx+4,my+0);
}

void Explode(CDC *pDC)		// Player hit by shell
{
	GameCounter++;
	if (GameCounter & 1) 
		pDC->SelectStockObject(LTGRAY_BRUSH);
	else
		pDC->SelectStockObject(DKGRAY_BRUSH);

	glass.Draw(pDC);

	if (GameCounter>40) 
	{
		GameCounter=0;
		Lives--;
		if (Lives==0)
		{
			GameState=40;
		}
		else
		{
			GameState=14;
		}
	}

}

void Crashed(CDC *pDC)		// Player hit by tank
{
	GameCounter++;
	if (GameCounter & 1) 
		pDC->SelectStockObject(LTGRAY_BRUSH);
	else
		pDC->SelectStockObject(DKGRAY_BRUSH);

	glass.Draw(pDC);

	Message2(pDC);

	if (GameCounter>40) 
	{
		GameCounter=0;
		Lives--;
		if (Lives==0)
		{
			GameState=40;
		}
		else
		{
			GameState=14;
		}
	}
}

void Attract(CDC *pDC)
{
	// Press any key to play 

	Wipe(pDC);

	GameCounter=0;
	GameState=2;
	Hits=-1;
	ResetL();
	panzer.Reset();
	panzer.Active();
	panzer.SetPosition(0,-1,10);
	tc=0;

	tx=3;ty=4;
	s.Format (L"SCORE %05d HIGH %05d",Score,High);
	for (int x=0;x<24;x++)
	{
		PrintLetter(s[x],8+12+x*9,150,pDC);
	}
	
}


void Attract2(CDC *pDC)
{
	if (linemode==1) nlinemode=0; else nlinemode=1;
	
	ResetL();

	//SmallWipe(pDC);

	Message7(pDC,tc);
	panzer.Draw(pDC);
	panzer.Spin(-4);

	EraseL(pDC);
	DrawL(pDC);

	linemode=nlinemode;


  //Draw Stuff

	GameCounter++;
	if ((GameCounter&31)==0) 
	{
		tc++;
		SmallWipe(pDC);
	}
	if (tc>11) tc=0;
	if (Key_fire) 
	{
		Key_fire=false;
		GameState=10;
	}
}



void GameOver(CDC *pDC)
{

	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkMode(OPAQUE);
	pDC->SetBkColor(LTGREYRGB);

	GameCounter=0;
	GameState=45;
	Hits=-1;
	panzer.Reset();
	panzer.SetPosition(0,-1,10);

	if (Score>High)
	{
		// new high score!
		High=Score;
	}

	SaveInfo(Score);

	PlaySound(5);
	Wipe(pDC);
	Message1(pDC);
}

void GameOver2(CDC *pDC)
{
	// Press any key to play 

	if (linemode==1) nlinemode=0; else nlinemode=1;
	
	ResetL();

	panzer.Draw(pDC);
	panzer.Spin(4);

	EraseL(pDC);
	DrawL(pDC);

	linemode=nlinemode;
	
	
	GameCounter++;


	if (GameCounter>200)
	{
		GameCounter=0;
		GameState=1;
	}

if (Key_fire)
	{	
		GameState=10;
		Key_fire=false;
	}
}



void InitSystem(CDC *pDC)
{

	// we know the width!


	SetRect(brect,WIDTH-160,8,WIDTH-50,24);
	SetRect(crect,WIDTH-160,24,WIDTH-50,40);
	SetRect(arect,WIDTH-160,40,WIDTH-50,56);
	SetRect(drect,WIDTH-160,56,WIDTH-50,72);



	WhitePen.CreatePen(PS_SOLID,1,WHITERGB);
	//LTGreyPen.CreatePen(PS_SOLID,1,LTGREYRGB);
	DKGreyPen.CreatePen(PS_SOLID,1,DKGREYRGB);
	BlackPen.CreatePen(PS_SOLID,1,BLACKRGB);
	ThickPen.CreatePen(PS_SOLID,2,BLACKRGB);
	GameState=1;
	
	for (int i=0;i<GameCounter;i++)
		Random();

	GameCounter=0;

	pMemDC.CreateCompatibleDC(pDC);
	control_bitmap.LoadBitmap(IDB_BITMAP4);
	pMemDC.SelectObject(&control_bitmap);

	pMemDC2.CreateCompatibleDC(pDC);
	control_bitmap2.LoadBitmap(IDB_BITMAP5);
	pMemDC2.SelectObject(&control_bitmap2);

	//pMemDC.FillSolidRect(0,0,240,320,WHITERGB);
	//pMemDC.FillSolidRect(0,0,240,320,BLACKRGB);

}

void InitGame(CDC *pDC)
{

	GameState=12;
	GameCounter=0;
	Lives=3;
	Score=0;
	Shots=0;
	Ammo=5;
	Level=0;
	
}

void InitLevel(CDC *pDC)
{
	Hits=0;
	GameState=13;
	GameCounter=0;
	Level++; 
	
	moveup=false;movedown=false;moveleft=false;moveright=false;

	switch(Level) {
		case 1: EnemyCount=10;Saucer1=false;Tank1=true;Tank2=false;AmmoBonus=4;TankSpeed=.2;break;
		case 2: EnemyCount=2;Saucer1=true;Tank1=false;Tank2=false;AmmoBonus=3;SaucerSpeed=.3;break;
		case 3: EnemyCount=10;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=3;TankSpeed=.2;break;
		case 4: EnemyCount=3;Saucer1=true;Tank1=false;Tank2=false;AmmoBonus=3;SaucerSpeed=.4;break;
		case 5: EnemyCount=10;Saucer1=false;Tank1=true;Tank2=false;AmmoBonus=1;TankSpeed=.4;break;
		case 6: EnemyCount=20;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=3;TankSpeed=.3;break;
		case 7: EnemyCount=4;Saucer1=true;Tank1=false;Tank2=false;AmmoBonus=3;SaucerSpeed=.4;break;
		case 8: EnemyCount=20;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=2;TankSpeed=.3;break;
		case 9: EnemyCount=5;Saucer1=true;Tank1=false;Tank2=false;AmmoBonus=2;SaucerSpeed=.4;break;
		case 10: EnemyCount=20;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=2;TankSpeed=.4;break;
		case 11: EnemyCount=8;Saucer1=true;Tank1=false;Tank2=false;AmmoBonus=2;SaucerSpeed=.4;break;
		case 12: EnemyCount=20;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=2;TankSpeed=.4;break;
		case 13: EnemyCount=20;Saucer1=true;Tank1=true;Tank2=true;AmmoBonus=2;SaucerSpeed=.4;break;
		default: EnemyCount=99;Saucer1=false;Tank1=true;Tank2=true;AmmoBonus=2;SaucerSpeed=.4;TankSpeed=.4;break;
	  }
	PlaySound(4);
}


void DrawRadar(CDC *pDC)
{
	// AND MOON AND SCORE!

	DrawMoon(pDC);

	// Radar circle

	frame++;

	if ((frame<8)) return;
	frame=0;


	// Buttons


	if (shell.Firing())
			pDC->BitBlt(CX,CY,48,48,&pMemDC,0,0,SRCCOPY);
	else
			pDC->BitBlt(CX,CY,48,48,&pMemDC2,0,0,SRCCOPY);

	// Radar part 2


	pDC->SelectObject(&DKGreyPen);
	pDC->SelectStockObject(LTGRAY_BRUSH); 
	pDC->SetBkColor(WHITERGB); // doesn't change circle, only writing
	pDC->Ellipse(8,8,72,72);
	pDC->SelectObject(&DKGreyPen);
	pDC->MoveTo(36,40);
	pDC->LineTo(45,40);
	pDC->MoveTo(40,36);
	pDC->LineTo(40,45);

	pDC->MoveTo(0,78);
	pDC->LineTo(WIDTH,78);

	pDC->SetTextColor(BLACKRGB);
	pDC->SetBkColor(WHITERGB); // doesn't change circle, only writing

	s.Format (L"Score:\t%5d",Score);
	pDC->DrawText(s, brect, DT_NOCLIP | DT_EXPANDTABS |DT_LEFT | DT_SINGLELINE);

	s.Format (L"High:\t%5d",High);
	pDC->DrawText(s, crect, DT_NOCLIP |DT_EXPANDTABS |DT_LEFT | DT_SINGLELINE);

	s.Format (L"Lives:\t%5d ",Lives);
	pDC->DrawText(s, arect, DT_NOCLIP |DT_EXPANDTABS |DT_LEFT | DT_SINGLELINE);


	if (Ammo==0)
		s.Format (L"Ammo:\tNone  ");
	else
		s.Format (L"Ammo:\t%5d   ",Ammo);

	pDC->DrawText(s, drect, DT_NOCLIP |DT_EXPANDTABS | DT_LEFT | DT_SINGLELINE);
}



void NewLevel(CDC *pDC) //13
{
	// New level!

	if (GameCounter<1) Wipe(pDC);
	edge.Draw(pDC);
	Message6(pDC);
	GameCounter++;
	if (GameCounter>30) 
	{
		GameCounter=0;
		GameState=14;
	}

}

void PreGetReady(CDC *pDC)	// 14
{
	Wipe(pDC);
	box[1].SetPosition(-10,0,5);
	box[2].SetPosition(20,0,-25);
	box[0].SetPosition(15,0,20);
	panzer.Reset();
	panzer2.Reset();
	martian.Reset();
	depot.Reset();
	GameCounter=0;
	GameState=15;
	shell.Stop();
	tank1shell.Stop();
	panzer.SetActive(Tank1);
	panzer2.SetActive(Tank2);
	martian.SetActive(Saucer1);
}


void GetReady(CDC *pDC)
{
	// Get Ready!
	// Go here after NewLevel and after being destroyed


	Redraw(pDC);
	pDC->BitBlt(CX,CY,48,48,&pMemDC2,0,0,SRCCOPY);

	if (martian.Active())
		Message5(pDC); 
	else
		Message4(pDC);

	GameCounter++;
	if (GameCounter>30) 
	{
		GameCounter=0;
		GameState=20;
		Wipe(pDC);
		pDC->BitBlt(CX,CY,48,48,&pMemDC2,0,0,SRCCOPY);
	}
}

void SpinPlayer(CDC *pDC, float angle)
{
	// Rotate all object positions
	// Rotate all object local co-ordinates
	// Rotate 4

	if (GameState<20) return;

	sd=sin(angle*rad);
	cd=cos(angle*rad);


	for (int i=0;i<3;i++)
	{
		box[i].Spin(angle);
		box[i].Rotate(angle);
	}

	depot.Spin(angle);
	depot.Rotate(angle);

	sd=sin(angle*rad);cd=cos(angle*rad);

	edge.Spin(angle);

	sd=sin(angle*rad);cd=cos(angle*rad);
	
	if (panzer.Active())
	{
		panzer.Spin(angle);
		panzer.Rotate(angle);
	}

	if (martian.Active())
	{
		martian.Spin(angle,true);
		martian.Rotate(angle);
	}

	if (panzer2.Active())
	{
		panzer2.Spin(angle);
		panzer2.Rotate(angle);
	}
	sd=sin(angle*rad);cd=cos(angle*rad);
	shell.Spin(angle);
	shell.Rotate(angle);
	tank1shell.Spin(-angle);
	tank1shell.Rotate(-angle);	// Moving in opposite direction!
	moon_position-=angle;

	if (moon_position>180) moon_position-=360;
	else if (moon_position<-180) moon_position+=360;

}

void MovePlayer(CDC *pDC, float distance)
{

	if (GameState<20) return;

	// Check for cube collision
	for (int i=0;i<3;i++)
		if (box[i].TestDistance(distance)==false) 
		{
			PlaySound(7);
			return;
		};

	// Move Obstacles
	for (i=0;i<3;i++)
		box[i].Move(distance);

	// Move tanks
	if (panzer.Active()) panzer.Move(distance);
	if (panzer2.Active()) panzer2.Move(distance);
	if (martian.Active()) martian.Move(distance);

	// Move shells
	shell.Move(distance);
	tank1shell.Move(distance);

	depot.Move(distance);

  }




void RedrawNoFlicker(CDC *pDC)
{
	// Redraw the entire screen


	if (linemode==1) nlinemode=0; else nlinemode=1;
	
	ResetL();

	DrawRadar(pDC);

	if (panzer.Active()) panzer.Draw(pDC);
	if (panzer2.Active()) panzer2.Draw(pDC);
	if (martian.Active()) martian.Draw(pDC);

	for (int i=0;i<3;i++)
		box[i].Draw(pDC);

	depot.Draw(pDC);
	shell.Draw(pDC);
	tank1shell.Draw(pDC);
	edge.Draw(pDC);

	// Sites

		if (
		((panzer.GetX()>-1) && (panzer.GetX()<1))
		||
		((panzer2.Active)&&(panzer2.GetX()>-1) && (panzer2.GetX()<1))
		)
		{
			AddL(ORIGINX+HALFWIDTH-15,ORIGIN+HALFHEIGHT-15,ORIGINX+HALFWIDTH-5,ORIGIN+HALFHEIGHT-5);
			AddL(ORIGINX+HALFWIDTH+15,ORIGIN+HALFHEIGHT+15,ORIGINX+HALFWIDTH+5,ORIGIN+HALFHEIGHT+5);
			AddL(ORIGINX+HALFWIDTH+15,ORIGIN+HALFHEIGHT-15,ORIGINX+HALFWIDTH+5,ORIGIN+HALFHEIGHT-5);
			AddL(ORIGINX+HALFWIDTH-15,ORIGIN+HALFHEIGHT+15,ORIGINX+HALFWIDTH-5,ORIGIN+HALFHEIGHT+5);
		}
		else
		{
			AddL(ORIGINX+HALFWIDTH-20,ORIGIN+HALFHEIGHT-20,ORIGINX+HALFWIDTH-15,ORIGIN+HALFHEIGHT-15);
			AddL(ORIGINX+HALFWIDTH+20,ORIGIN+HALFHEIGHT+20,ORIGINX+HALFWIDTH+15,ORIGIN+HALFHEIGHT+15);
			AddL(ORIGINX+HALFWIDTH+20,ORIGIN+HALFHEIGHT-20,ORIGINX+HALFWIDTH+15,ORIGIN+HALFHEIGHT-15);
			AddL(ORIGINX+HALFWIDTH-20,ORIGIN+HALFHEIGHT+20,ORIGINX+HALFWIDTH-15,ORIGIN+HALFHEIGHT+15);
		}
	EraseL(pDC);
	DrawL(pDC);

	linemode=nlinemode;


}

void Redraw(CDC *pDC)
{
	RedrawNoFlicker(pDC);
}



void Shoot()
{
		shell.PlayerFire();
}

void Paused(CDC *pDC)
{
	// Game is paused, but screen still needs
	// redrawing...

	Redraw(pDC);
	Message3(pDC);

}



void Automatic(CDC *pDC)
{
	// This is a standard Tank Level
	// This is called all the time to
	// drive the background action
	

	if (Key_up) MovePlayer(pDC,.2);	
	if ((Key_left) && (!Key_right)) SpinPlayer(pDC,2);
	else if ((Key_right) && (!Key_left)) SpinPlayer(pDC,-2);
	
	if (Key_fire) 
	{	
		Shoot();
		Key_fire=false;
	}

	shell.Think();
	tank1shell.ThinkTank();
	if (panzer.Active()) panzer.Think();
	if (panzer2.Active()) panzer2.Think(); 
	if (martian.Active()) {martian.Think();martian.Spin(5,false);} 
	depot.Spin(10);
	Redraw(pDC);
}



void Game(CDC *pDC)
{
	// This is the core of the game


	switch (GameState) {
	case 20:Automatic(pDC);break;
	case 30:Explode(pDC);break;
	case 35:Crashed(pDC);break;
	case 40:GameOver(pDC);break;
	case 50:Paused(pDC);break;
	case 14:PreGetReady(pDC);break;
	case 15:GetReady(pDC);break;
	case 12:InitLevel(pDC);break;
	case 10:InitGame(pDC);break;
	case 45:GameOver2(pDC);break;
	case 13:NewLevel(pDC);break;
	case 1:Attract(pDC);break;
	case 2:Attract2(pDC);break;
	case 0:InitSystem(pDC);break;
	}

}
