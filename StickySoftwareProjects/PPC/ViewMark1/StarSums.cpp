//
// Star Sums
//
//
// So far, this program can take a date, time and place
// and, given a celstial RA and Dec calculate a local
// RA and Dec but also a physical Alt and Az for plotting.
//
//


// Need to look at Date structure, along with
// function to set it, and so calculate all the
// global values (JD,DJ, Nutat, Obliqe etc etc)

#include "stdafx.h"
#include "math.h"
#include "globalstuff.h"

#define ERRORAMOUNT 1e-6

struct solartype SolarSystem;



// 0=Sun,1=Merc,2=Ven,3=Mars,4=Jup,5=Sat,6=Ura,7=Nep,8=Pl,9=Moon

double Julian=-1;					// Current TIME and DATE
double JD=-1;						// Current Julian Date (integer)
double UT=-1;						// Current Universal Time
double DJ=-1;						// number of days since 1900
double DJINT=-1;					// integer days since 1900
double TimeT;
//double MagicTime;

extern double local_latitude;
extern double local_longitude;
extern double SinLat;
extern double CosLat;

extern double u_ra;
extern double u_dec;
extern double u_rt;
extern double u_st;
extern double u_raz;
extern double u_saz;

extern bool flags[33];

double local_time;
double local_height=10;

 short int local_day;
 short int local_month;
 short int local_year;
 short int local_hour;
 short int local_minute;
 short int local_second;
 short int local_timezone;
 short int local_daylight;
 double Obliquity=-1;						// Obliquity of the Ecliptic
 double	nutation_ecliptic=-1;				// dp
 double	nutation_obliquity=-1;				// d0
 double Greenwich_sidereal_time=-1;
 double Local_sidereal_time=-1;
 double suns_ecliptic_longitude=-1;			// needed for moon phase
 double sun_earth_distance=-1;				// and planet
 double suns_mean_anomaly=-1;				// calculations
 double MOONSPM;


const double pi=3.1415926536;
const double tp=6.283185307;



double R2D (double angle)
{
	// Convert Radians to Degrees
	return (5.729577951e1*angle);
}

double D2R (double angle)
{
	// Convert Degrees to radians
	return (1.745329252e-2*angle);
}


double Integer(double d)
{
	// Return INT(x) value!
	double i;
	
	if (d<0) 
		modf((d-1),&i);
	else 
		modf(d,&i);

	return i;
}

double SInteger(double d)
{
	// A simpler Int function

	double i;
	if (modf(d,&i)>.5) i++;
	return i;
}


double FNU (double angle)
{
	// Restores angle to 0..2pi range

	return (angle-Integer(angle/6.238185308)*6.238185308);
}

double FNS(double angle)
{
	return atan(angle/(sqrt(1-angle*angle)+1e-20));
}

void ResetDate()
{
	JD=-1;UT=-1;DJ=-1;	
	nutation_obliquity=-1;
	nutation_ecliptic=-1;
	Obliquity=-1;
	Greenwich_sidereal_time=-1;
	Local_sidereal_time=-1;
	suns_ecliptic_longitude=-1;
}

void Anomaly(double am, double ec, double *ae, double *at)
{
	// am=mean anomaly
	// ec=eccentric anomaly 

	double m,d,a;

	d=100;	
	
	m=am-tp*Integer(am/tp);
	*ae=m;

	d=*ae-(ec*sin(*ae))-m;
	while (fabs(d)>ERRORAMOUNT)
	{
		d=d/(1.0-(ec*cos(*ae)));
		*ae=*ae-d;
		d=*ae-(ec*sin(*ae))-m;
	}

	a=sqrt((1+ec)/(1-ec))*tan(*ae/2.0);
	*at=2*atan(a);

}





double JulDay (double day, int month, int year)
{
	// Calculate Julian Date (JD) given day,month,year

	int a,b,c,d;

	if (year<1582)
	{
//		printf("Year out of range./n"); 
		return 0;
	}


	if (month<3) 
	{
		month+=12;
		year--;
	}

	a=(year/100);
	b=(2-a+(a/4));
	c=(int)((365.25*year)-694025);
	d=(int)((30.6001*(month+1)));
	return (2415020+b+c+d+day-0.5);

}





double LSTime2(double fd)
{
	// Given fd=day fraction in hours. 0..23.999
	// return the local siderial time.

	double t,t0,tm,gst,tl;
	double r0,r1;
	double d;

	DJ=Julian-2415020;
	d=Integer(DJ-0.5)+0.5;
	t=(d/36525.0)-1;

	r0=((t*5.13366e-2) + (t*t*2.586222e-5) - (t*t*t*1.722e-9));
	r1=6.697374558+(2400.0*(t-((double (local_year)-2000)/100)));
	t0=r0+r1;

	while (t0<0) t0+=24;
	while (t0>24) t0-=24;

	tm=fd;
	//tm=((double(local_second)/60)+double(local_minute))/60+double(local_hour);
	//tm=double(local_hour)+double(local_minute)/60+double(local_second)/3600;

	UT=tm-local_daylight-local_timezone;
	t=t0;

	if (UT<0)  t=t-6.57098244e-2;
	if (UT>24) t=t+6.57098244e-2;

	while (UT<0) UT+=24;
	while (UT>24) UT-=24;
	
	gst=(UT*1.002737908)+t;

	while (gst<0) gst+=24;
	while (gst>24) gst-=24;

	tl=gst+(local_longitude/15.0);

	while (tl<0) tl+=24;
	while (tl>24) tl-=24;

	DJINT=Integer(DJ);

	return tl;//	Local_sidereal_time=tl;
}


void CalculateJulian()
{
	// Or "Get Julian".
	// Convert date and time into Julian
	// Given a d/m/y, h:m:s calculate Julian

	double t,t0,tm;//,gst,tl;
	double r0,r1;
	double d;

	double fd;

	fd=(((double(local_second)/60)+double(local_minute))/60+double(local_hour))/24;

	JD=JulDay((local_day+fd),local_month,local_year);
	Julian=JD;

	DJ=JD-2415020;
	d=Integer(DJ-0.5)+0.5;
	t=(d/36525.0)-1;

	DJINT=Integer(JD);

	r0=((t*5.13366e-2) + (t*t*2.586222e-5) - (t*t*t*1.722e-9));
	r1=6.697374558+(2400.0*(t-((local_year-2000)/100)));
	t0=r0+r1;
	
	while (t0<0) t0+=24;
	while (t0>24) t0-=24;

	tm=fd*24;

	UT=tm-local_daylight-local_timezone;

	while (UT<0) UT+=24;
	while (UT>24) UT-=24;

	//Julian=JD+(UT/24); // fraction of the day... 
}

 

/*

double Refract(double y)
{
	// Transforms Y into Q (real into apparent)
	// taking into account the local conditions

	double y1,y2,r1,r2,rf,q;

	y1=y;
	y2=y;
	r1=0;
	y+=y1+r1;
	q=y;

	if (y<2.617994e-1)
		if (y<-8.7e-2) rf=0;

	r2=rf;

	if (r2==0) or (r2-r1)<1e-6
	{
		y=y2;
		return y;
	}

}

*/

void Parallax(double x, double y, double hp, double *p, double *q)
{

	double c1,s1,u,c2,s2,rs,rc,tp,rp,a,cx,sy,cy;
	double dx,cp,ht;

	//printf("Calculating Parallax..\n");

	ht=local_height/6378140;

	c1=cos(D2R(local_latitude));
	s1=sin(D2R(local_latitude));
	u=atan(9.96647e-1 * s1/c1);
	c2=cos(u);s2=sin(u);
	rs=(9.96647e-1*s2)+(ht*s1);
	rc=c2+(ht*c1);
	tp=6.283185308;

	rp=1/sin(hp);
	cx=cos(x);sy=sin(y);cy=cos(y);
	a=(rc*sin(x))/((rp*cy)-(rc*cx));
	dx=atan(a);
	*p=x+dx;
	cp=cos(*p);
	while (*p>tp) *p-=tp;
	while (*p<0) *p+=tp;
	*q=atan(cp*(rp*sy-rs)/(rp*cy*cx-rc));
}

void SplitI(double number, int *deg, int *min, int *sec)
{
	short int ng;
	double d,m,s;

	if (number<0) 
	{
		number=-number;
		ng=-1;
	}

	else 
		ng=1;

	modf(number,&d);
	modf((number-d)*60,&m);
	s=3600*(number-(d+(m/60)));
	*deg=(int)d*ng;
	*min=(int)m;
	*sec=(int)s;
}

void Split(double number, short int *deg, short int *min, short int *sec)
{
	short int ng;
	double d,m,s;

	if (number<0) 
	{
		number=-number;
		ng=-1;
	}

	else 
		ng=1;

	modf(number,&d);
	modf((number-d)*60,&m);
	s=3600*(number-(d+(m/60)));
	*deg=(int)d*ng;
	*min=(int)m;
	*sec=(int)s;
}


void CalculateDay()
{
	// The Key time routine

	// Given Julian,
	// Calculate the Local time in d/m/y,h:m:s
	// Also define the JD, UT, and LST

	double d,i,fd,a,b,c,g,mn,dy,yr;

	// Beta restriction
	//if (Julian>2451000) Julian=2450904;
	
	DJ=Julian-2415020;

	d=DJ+0.5;
	i=Integer(d);
	fd=d-i;

	if (fd==1)
	{
		fd=0;
		i++;
	}
	
	if (i> -115860)
	{
		a=Integer((i/36524.25)+9.9835726e-1)+14;
		i=i+1+a-Integer(a/4);
	}
	
	b=Integer((i/365.25)+8.02601e-1);
	c=i-Integer((365.25*b)+7.50001e-1)+416;
	g=Integer(c/30.6001);mn=g-1;
	dy=c-Integer(30.6001*g)+fd;
	yr=b+1899;
	if (g>13.5) mn=g-13;
	if (mn<2.5) yr=b+1900;
	if (yr<1) yr=yr-1;

	local_year=int(yr);
	local_month=int(mn);
	local_day=int(dy);

	fd*=24.0; // Fraction of a day...turn into hours

	Split(fd,&local_hour,&local_minute,&local_second);

	Local_sidereal_time=LSTime2(fd);		// Work out UT and LST

	TimeT=(DJ/36525.0);//+(UT/8.766E5);
}

inline double HourAngle(double x)
{
		// Given a RA (in degrees) use the time to calculate
		// the Hour Angle (in degrees)

		double p;

		//printf("Calculating hour angle for %f...\n",x);


		//if (Local_sidereal_time==-1)
		//		CalculateDay();
		
		p=Local_sidereal_time-x;
		
		while (p>24) p-=24;
		while (p<0) p+=24;

		//printf("Hour angle is %f\n",p);

		return p;
}


void ConvertAltAztoRaDec(double azm, double alt, double *ra, double *dec)
{
	// Take Azm,Alt (in radians) and convert to Ra,Dec (in degrees)

	double sy,cy,cx,sx,a,q,cq,b,cp,p;
	double x,y,cf,sf;

	cf=CosLat;
	sf=SinLat;

	x=azm; 
	y=alt;
							
	sy=sin(y);	cy=cos(y);
	sx=sin(x);	cx=cos(x);

	a=(sy*sf)+(cy*cf*cx);
	q=asin(a);
	cq=cos(q);
	b=cf*cq;
	if (b<1e-10) b=1e-10;
	cp=(sy-(sf*a))/b;
	if (cp<-1) cp=0;
	if (cp>1) cp=0;
	p=acos(cp);
	if (sx>0) p=tp-p;
	
	p=R2D(p);
	q=R2D(q);

	p=p/15;
	p=HourAngle(p);

	*ra=p;
	*dec=q;
}

void MakeLocal(double RA,double Dec, double *Az, double *Alt)
{
	// Convert Dec,RA of an object
	// into local Az, Alt cords for plotting 

	// Values coming in are in Degrees
	// Values leaving are in Radians

	//RA=LST-RA;

	double sy,cy,cx,sx,a,q,cq,b,cp,p;
	double HR,x,y;

	HR=HourAngle(RA);
	x=D2R(HR)*15;
	y=D2R(Dec);

	sy=sin(y);cy=cos(y);
	sx=sin(x);cx=cos(x);

	a=(sy*SinLat)+(cy*CosLat*cx);
	q=asin(a);
	cq=cos(q);
	b=CosLat*cq;
	//if (b<1e-10) b=1e-10;
	if (b<1e-50) b=1e-50;
	cp=(sy-(SinLat*a))/b;
	p=acos(cp);
	if (sx>0) p=tp-p;

	*Az=(p);
	*Alt=(q);

}


void NUTAT()
{
	// Calculate the Nutation 
	
	double t,t2;
	double a,b,l1,l2,d1,d2,m1,m2,n1,n2,ndp,ndo;


	DJ=Julian-2415020;

	//DJ=JD-2415020;

	t=DJ/36525.0;
	// int upgrade

	//t=DJINT/36525.0;

	t2=t*t;

	a=1.000021358E2*t; b=360.0*(a-Integer(a));
	l1=2.796967E2+3.03E-4*t2+b; l2=2.0*D2R(l1);
	a=1.336855231E3*t ; b=360.0*(a-Integer(a));
	d1=2.704342E2-1.133E-3*t2+b ; d2=2.0*D2R(d1);
	a=9.999736056E1*t ; b=360.0*(a-Integer(a));
	m1=3.584758E2-1.5E-4*t2+b ; m1=D2R(m1);
	a=1.325552359E3*t ; b=360.0*(a-Integer(a));
	m2=2.961046E2+9.192E-3*t2+b ; m2=D2R(m2);
	a=5.372616667*t ; b=360.0*(a-Integer(a));
	n1=2.591833E2+2.078E-3*t2-b; n1=D2R(n1);
	n2=2*n1;

	ndp=(-17.2327-1.737E-2*t)*sin(n1);
	ndp=ndp+(-1.2729-1.3E-4*t)*sin(l2)+2.088E-1*sin(n2);
	ndp=ndp-2.037E-1*sin(d2)+(1.261E-1-3.1E-4*t)*sin(m1);
	ndp=ndp+6.75E-2*sin(m2)-(4.97E-2-1.2E-4*t)*sin(l2+m1);
	ndp=ndp-3.42E-2*sin(d2-n1)-2.61E-2*sin(d2+m2);
	ndp=ndp+2.14E-2*sin(l2-m1)-1.49E-2*sin(l2-d2+m2);
	ndp=ndp+1.24E-2*sin(l2-n1)+1.14E-2*sin(d2-m2);
	
	ndo=(9.21+9.1E-4*t)*cos(n1);
	ndo=ndo+(5.522E-1-2.9E-4*t)*cos(l2)-9.04E-2*cos(n2);
	ndo=ndo+8.84E-2*cos(d2)+2.16E-2*cos(l2+m1);
	ndo=ndo+1.83E-2*cos(d2-n1)+1.13E-2*cos(d2+m2);
	ndo=ndo-9.3E-3*cos(l2-m1)-6.6E-3*cos(l2-n1);

	ndp=ndp/3600.0; ndo=ndo/3600.0;

	nutation_ecliptic=ndp;  // in degrees
	nutation_obliquity=ndo; // in degress

}



void OBLIQ()
{
	// Calculate the Obliquity of the Ecliptic

	double t,a,DJ;
	


	if (nutation_obliquity==-1) 
		NUTAT();

	//nutation_obliquity=0;

	//DJ=JD-2415020;
	DJ=Julian-2415020;

	t=(DJ/36525)-1;
	a=(46.815+(0.0006-0.00181*t)*t)*t;
	a=a/3600;
	Obliquity=23.43929167-a+nutation_obliquity;
	//printf("\nObliq:");printDMS(Obliquity);printf("\n");


}

void EQECL (double x, double y, double *ra, double *dec)
{
	// Convert Geocentric ecliptic long (X)/lat(Y) into
	// ra and dec



	double e,se,ce,cy,sy,ty,s,q,p,a,cx,sx;


	if (Obliquity==-1)
		OBLIQ();

	e=D2R(Obliquity);
	se=sin(e);
	ce=cos(e);
	cy=cos(y);
	sy=sin(y);
	if (fabs(cy)<1e-20) cy=1e-20;
	ty=sy/cy;
	cx=cos(x);
	sx=sin(x);

	s=(sy*ce)+(cy*se*sx);
	q=asin(s);
	a=(sx*ce)-(ty*se);
	p=atan(a/cx);
	if (cx<0) p+=pi;
	while (p>tp) p-=tp;
	while (p<0) p+=tp;
	*ra=p;
	*dec=q;

}



void Sun()
{
	// Calculation the position of the sun
	// Needs JD and UT

	double sra,sdec;
	double sr,rr;
	double t,t2;
	double a,b,l,m1,ec,am,ae,at;
	double a1,b1,c1,d1,e1,h1;
	double d2,d3;
	double al;



//	DJ=JD-2415020;
//	DJ=Julian-2415020;UT=0;

	//t=(DJINT/36525.0)+(UT/8.766E5);

	t=TimeT;

	t2=t*t;
	a=1.000021359E2*t;
	b=360.0*(a-Integer(a));
	l=2.7969668E2+3.025E-4*t2+b;
	a=9.999736042E1*t;
	b=360.0*(a-Integer(a));
	m1=3.5847583E2-(1.5E-4+3.3E-6*t)*t2+b;
	ec=1.675104E-2-4.18E-5*t-1.26E-7*t2;

	am=D2R(m1);

	suns_mean_anomaly=am; // in radians

	Anomaly(am,ec,&ae,&at);

	a=6.255209472E1*t;  b=360.0*(a-Integer(a));
	a1=D2R(153.23+b);
	a=1.251041894E2*t;	b=360.0*(a-Integer(a));
	b1=D2R(216.57+b);
	a=9.156766028E1*t;	b=360.0*(a-Integer(a));
	c1=D2R(312.69+b);
	a=1.236853095E3*t;	b=360.0*(a-Integer(a));
	d1=D2R(350.74-1.44E-3*t2+b);

	e1=D2R(231.19+20.2*t);
	a=1.831353208E2*t;  b=360.0*(a-Integer(a));
	h1=D2R(353.4+b);

	d2=1.34E-3*cos(a1)+1.54E-3*cos(b1)+2E-3*cos(c1);
	d2=d2+1.79E-3*sin(d1)+1.78E-3*sin(e1);
	d3=5.43E-6*sin(a1)+1.575E-5*sin(b1);
	d3=d3+1.627E-5*sin(c1)+3.076E-5*cos(d1);
	d3=d3+9.27E-6*sin(h1);
	sr=at+D2R(l-m1+d2); 
	rr=1.0000002*(1.0-ec*cos(ae))+d3;

	while (sr<0) sr+=tp;
	while (sr>tp) sr-=tp;

	suns_ecliptic_longitude=sr;
	sun_earth_distance=rr;

	EQECL(D2R(200.3185167),D2R(43.787175),&sra,&sdec);

	EQECL(sr,0,&sra,&sdec);

	al=R2D(sr)+nutation_ecliptic-5.69e-3;

	EQECL(D2R(al),0,&sra,&sdec);

	double hp=4.263452e-5/rr;

	if (flags[ParallaxOn]) Parallax(sra,sdec,hp,&sra,&sdec);

	SolarSystem.body[SUN].ra=R2D(sra)/15;
	SolarSystem.body[SUN].dec=R2D(sdec);
	SolarSystem.body[SUN].mag=0;
	SolarSystem.body[SUN].phase=0;
	SolarSystem.body[SUN].size=0;
	SolarSystem.body[SUN].distance=(float)rr;

}


void Moon()
{

	// Does it all from s,m,h


double m1,m2,m3,m4,m5,m6;
double q,g,e,e2,l,t,tp,a,b,c;
double ml,ms,md,me,pm,mf;
double NA,BM,MM;
double s1,s2,s3,s4,w1,w2,t2;
double mJD,mDJ,mut,mtm;
double al,r,f,th,cd,sd,d,i,fm,k;
double mra,mdec;


	mtm=((double(local_second)/60)+double(local_minute))/60+double(local_hour);
	mut=(mtm)-(local_daylight)-(local_timezone);

	mJD=JulDay(local_day,local_month,local_year);
	mDJ=mJD-2415020;
	t=(mDJ/36525.0)+(mut/8.766e5);
	//MagicTime=t;

	t2=t*t;
	m1=2.732158213e1;m2=3.652596407e2;
	m3=2.755455094e1;m4=2.953058868e1;
	m5=2.721222039e1;m6=6.798363307e3;

	q=mDJ+(mut/24.0);

	m1=q/m1;m2=q/m2;
	m3=q/m3;m4=q/m4;
	m5=q/m5;m6=q/m6;

	m1=360*(m1-Integer(m1));
	m2=360*(m2-Integer(m2));
	m3=360*(m3-Integer(m3));
	m4=360*(m4-Integer(m4));
	m5=360*(m5-Integer(m5));
	m6=360*(m6-Integer(m6));

ml=2.70434164e2+m1-(1.133e-3-1.9e-6*t)*t2;
ms=3.58475833e2+m2-(1.5e-4+3.3e-6*t)*t2;
md=2.96104608e2+m3+(9.192e-3+1.44e-5*t)*t2;
me=3.50737486e2+m4-(1.436e-3-1.9e-6*t)*t2;
mf=11.250889+m5-(3.211e-3+3e-7*t)*t2;

NA=2.59183275e2-m6+(2.078e-3+2.2e-6*t)*t2;
 
a=D2R(51.2+20.2*t);
s1=sin(a);
s2=sin(D2R(NA));

b=346.56+(132.87-9.1731e-3*t)*t;
s3=3.964e-3*sin(D2R(b));
c=D2R(NA+275.05-2.3*t);
s4=sin(c);

ml=ml+2.33e-4*s1+s3+1.964e-3*s2;
ms=ms-1.778e-3*s1;
md=md+8.17e-4*s1+s3+2.541e-3*s2;
mf=mf+s3-2.4691e-2*s2-4.328e-3*s4;
me=me+2.011e-3*s1+s3+1.964e-3*s2;
e=1-(2.495e-3+7.52e-6*t)*t;
e2=e*e;

ml=D2R(ml);
ms=D2R(ms);
NA=D2R(NA);
me=D2R(me);
mf=D2R(mf);
md=D2R(md);


l=6.28875*sin(md)+1.274018*sin(2*me-md);
l=l+6.58309e-1*sin(2*me)+2.13616e-1*sin(2*md);
l=l-e*1.85596e-1*sin(ms)-1.14336e-1*sin(2*mf);
l=l+5.8793e-2*sin(2*(me-md));
l=l+5.7212e-2*e*sin(2*me-ms-md)+5.332e-2*sin(2*me+md);
l=l+4.5874e-2*e*sin(2*me-ms)+4.1024e-2*e*sin(md-ms);
l=l-3.4718e-2*sin(me)-e*3.0465e-2*sin(ms+md);
l=l+1.5326e-2*sin(2*(me-mf))-1.2528e-2*sin(2*mf+md);
l=l-1.098e-2*sin(2*mf-md)+1.0674e-2*sin(4*me-md);
l=l+1.0034e-2*sin(3*md)+8.548e-3*sin(4*me-2*md);
l=l-e*7.91e-3*sin(ms-md+2*me)-e*6.783e-3*sin(2*me+ms);
l=l+5.162e-3*sin(md-me)+e*5e-3*sin(ms+me);
l=l+3.862e-3*sin(4*me)+e*4.049e-3*sin(md-ms+2*me);
l=l+3.996e-3*sin(2*(md+me))+3.665e-3*sin(2*me-3*md);
l=l+e*2.695e-3*sin(2*md-ms)+2.602e-3*sin(md-2*(mf+me));
l=l+e*2.396e-3*sin(2*(me-md)-ms)-2.349e-3*sin(md+me);
l=l+e2*2.249e-3*sin(2*(me-ms))-e*2.125e-3*sin(2*md+ms);
l=l-e2*2.079e-3*sin(2*ms)+e2*2.059e-3*sin(2*(me-ms)-md);
l=l-1.773e-3*sin(md+2*(me-mf))-1.595e-3*sin(2*(mf+me));
l=l+e*1.22e-3*sin(4*me-ms-md)-1.11e-3*sin(2*(md+mf));
l=l+8.92e-4*sin(md-3*me)-e*8.11e-4*sin(ms+md+2*me);
l=l+e*7.61e-4*sin(4*me-ms-2*md);
l=l+e2*7.04e-4*sin(md-2*(ms+me));
l=l+e*6.93e-4*sin(ms-2*(md-me));
l=l+e*5.98e-4*sin(2*(me-mf)-ms);
l=l+5.5e-4*sin(md+4*me)+5.38e-4*sin(4*md);
l=l+e*5.21e-4*sin(4*me-ms)+4.86e-4*sin(2*md-me);
l=l+e2*7.17e-4*sin(md-2*ms);
MM=ml+D2R(l);

tp=6.283185308;

while (MM<0) MM+=tp;
while (MM>tp) MM-=tp;




g=5.128189*sin(mf)+2.80606e-1*sin(md+mf);
g=g+2.77693e-1*sin(md-mf)+1.73238e-1*sin(2*me-mf);
g=g+5.5413e-2*sin(2*me+mf-md)+4.6272e-2*sin(2*me-mf-md);
g=g+3.2573e-2*sin(2*me+mf)+1.7198e-2*sin(2*md+mf);
g=g+9.267e-3*sin(2*me+md-mf)+8.823e-3*sin(2*md-mf);
g=g+e*8.247e-3*sin(2*me-ms-mf)+4.323e-3*sin(2*(me-md)-mf);
g=g+4.2e-3*sin(2*me+mf+md)+e*3.372e-3*sin(mf-ms-2*me);
g=g+e*2.472e-3*sin(2*me+mf-ms-md);
g=g+e*2.222e-3*sin(2*me+mf-ms);
g=g+e*2.072e-3*sin(2*me-mf-ms-md);
g=g+e*1.877e-3*sin(mf-ms+md)+1.828e-3*sin(4*me-mf-md);
g=g-e*1.803e-3*sin(mf+ms)-1.75e-3*sin(3*mf);
g=g+e*1.57e-3*sin(md-ms-mf)-1.487e-3*sin(mf+me);
g=g-e*1.481e-3*sin(mf+ms+md)+e*1.417e-3*sin(mf-ms-md);
g=g+e*1.35e-3*sin(mf-ms)+1.33e-3*sin(mf-me);
g=g+1.106e-3*sin(mf+3*md)+1.02e-3*sin(4*me-mf);
g=g+8.33e-4*sin(mf+4*me-md)+7.81e-4*sin(md-3*mf);
g=g+6.7e-4*sin(mf+4*me-2*md)+6.06e-4*sin(2*me-3*mf);
g=g+5.97e-4*sin(2*(me+md)-mf);
g=g+e*4.92e-4*sin(2*me+md-ms-mf)+4.5e-4*sin(2*(md-me)-mf);
g=g+4.39e-4*sin(3*md-mf)+4.23e-4*sin(mf+2*(me+md));
g=g+4.22e-4*sin(2*me-mf-3*md)-e*3.67e-4*sin(ms+mf+2*me-md);
g=g-e*3.53e-4*sin(ms+mf+2*me)+3.31e-4*sin(mf+4*me);
g=g+e*3.17e-4*sin(2*me+mf-ms+md);
g=g+e2*3.06e-4*sin(2*(me-ms)-mf)-2.83e-4*sin(md+3*mf);
w1=4.664e-4*cos(NA);
w2=7.54e-5*cos(c);
BM=D2R(g)*(1.0-w1-w2);

pm=9.50724e-1+5.1818e-2*cos(md)+9.531e-3*cos(2*me-md);
pm=pm+7.843e-3*cos(2*me)+2.824e-3*cos(2*md);
pm=pm+8.57e-4*cos(2*me+md)+e*5.33e-4*cos(2*me-ms);
pm=pm+e*4.01e-4*cos(2*me-md-ms);
pm=pm+e*3.2e-4*cos(md-ms)-2.71e-4*cos(me);
pm=pm-e*2.64e-4*cos(ms+md)-1.98e-4*cos(2*mf-md);
pm=pm+1.73e-4*cos(3*md)+1.67e-4*cos(4*me-md);
pm=pm-e*1.11e-4*cos(ms)+1.03e-4*cos(4*me-2*md);
pm=pm-8.4e-5*cos(2*md-2*me)-e*8.3e-5*cos(2*me+ms);
pm=pm+7.9e-5*cos(2*me+2*md)+7.2e-5*cos(4*me);
pm=pm+e*6.4e-5*cos(2*me-ms+md)-e*6.3e-5*cos(2*me+ms-md);
pm=pm+e*4.1e-5*cos(ms+me)+e*3.5e-5*cos(2*md-ms);
pm=pm-3.3e-5*cos(3*md-2*me)-3e-5*cos(md+me);
pm=pm-2.9e-5*cos(2*(mf-me))-e*2.9e-5*cos(2*md+ms);
pm=pm+e2*2.6e-5*cos(2*(me-ms))-2.3e-5*cos(2*(mf-me)+md);
pm=pm+e*1.9e-5*cos(4*me-ms-md);
pm=D2R(pm);


//if (nutation_ecliptic==-1) 
	NUTAT();

al=R2D(MM)+nutation_ecliptic;

r=6378.14/sin(pm);
f=r/384401.0;
th=5.181e-1/f;


if (suns_ecliptic_longitude==-1)
	Sun();

short int side;
double lead;

lead=MM-suns_ecliptic_longitude;
if (lead<0) lead+=tp;

if (lead<pi)
	side=-1;
else
	side=1;

cd=cos(MM-suns_ecliptic_longitude)*cos(BM);
d=1.570796327-asin(cd);
sd=sin(d);
i=1.468e-1*sd*(1.0-5.49e-2*sin(md));
i=i/(1.0-1.67e-2*sin(ms));
i=3.151592654-d-D2R(i);
k=(1.0+cos(i))/2;
fm=side*Integer(k*1000+0.5)/1000;

EQECL (D2R(al), BM, &mra, &mdec);
if (flags[ParallaxOn])
	{
	mra=mra/3.819718634;
	Parallax(mra,mdec,pm,&mra,&mdec);
	mra=mra*3.819718634;
	}

	SolarSystem.body[MOON].ra=R2D(mra/15);
	SolarSystem.body[MOON].dec=R2D(mdec);
	SolarSystem.body[MOON].mag=0;
	SolarSystem.body[MOON].phase=(float) fm;
	SolarSystem.body[MOON].size=(float) th;
	SolarSystem.body[MOON].distance=(float) r;

	MOONSPM=pm;
}

#include "StarSums2.h"


void ConvertToAltAz()
{
	short int i;
	double az,alt;

	for (i=0;i<10;i++)
	{
		MakeLocal(SolarSystem.body[i].ra,SolarSystem.body[i].dec,&az,&alt);
		SolarSystem.body[i].az=az;
		SolarSystem.body[i].alt=alt;
	}
}





void CalculateSolarSystem()
{

	// Use the current Julian date to
	// find both actual and apparent
	// locations.

	SinLat = sin(D2R(local_latitude));
	CosLat = cos(D2R(local_latitude));
	ResetDate();
	CalculateDay();
	Sun();
	Moon();
    Planets();
	ConvertToAltAz();	// Convert Moon,Sun and planet's Ra/Dec to Alt/Azm
}

double LST2CIV(double lst)
{
	// Convert LST to ordinary time

	double t,sg,tl,ut,x;
	double d,r0,r1,t0;

	DJ=Julian-2415020;
	d=Integer(DJ-0.5)+0.5;
	t=(d/36525.0)-1;

	r0=((t*5.13366e-2) + (t*t*2.586222e-5) - (t*t*t*1.722e-9));
	r1=6.697374558+(2400.0*(t-((double (local_year)-2000)/100)));
	t0=r0+r1;

	while (t0<0) t0+=24;
	while (t0>24) t0-=24;

	t=t0-(local_daylight+local_timezone)*1.002737908;

	while (t<0) t+=24;
	while (t>24) t-=24;

	sg=lst-(local_longitude/15);

	while (sg<0) sg+=24;
	while (sg>24) sg-=24;

	x=sg;

	if (sg<t) x=sg+24;

	tl=(x-t)*9.972695677e-1;

	while (tl<0) tl+=24;
	while (tl>24) tl-=24;

	ut=tl-local_daylight-local_timezone;

	while (ut<0) ut+=24;
	while (ut>24) ut-=24;

	return ut;
}

void Riset(double ra,double dec,
		   double *risetime,double *settime,
		   double *riseaz, double *setaz, double DI)
{
	// Calculates the rising/setting of a given body

	double cf,sf,sy,cy,sd,cd,ch,ca,h,au,b,a,lu,ld,ad,d;

	cf=cos(D2R(local_latitude));
	sf=sin(D2R(local_latitude));
	sy=sin(dec);cy=cos(dec);
	sd=sin(DI);cd=cos(DI);
	ch=-(sd+(sf*sy))/(cf*cy);

	if (ch<-1) {*risetime=0;return;};	// circumpolar
	if (ch>1) {*risetime=-1;return;};	// never rises

	ca=(sy+(sd*sf))/(cd*cf);
	h=acos(ch);au=acos(ca);
	b=R2D(h)/15.0;a=R2D(ra)/15;
	lu=24+a-b; ld=a+b; ad=tp-au;
	d=24;

	while (lu<0) lu+=d;
	while (lu>d) lu-=d;
	
	while (ld<0) ld+=d;
	while (ld>d) ld-=d;
	
	d=tp;
	while (au<0) au+=d;
	while (au>d) au-=d;
	
	while (ad<0) ad+=d;
	while (ad>d) ad-=d;

	*risetime=LST2CIV(lu);
	*riseaz=R2D(au);
	*settime=LST2CIV(ld);
	*setaz=R2D(ad);
}

void Ephemeris_Planets()
{
	// Calculate the rise/set times and locations
	// of the planets

	// Do user as well

	Riset((15*D2R(u_ra)),D2R(u_dec),&u_rt,&u_st,&u_raz,&u_saz,1.454441e-2);

	for (int p=1;p<10;p++)
		Riset(	(15*D2R(SolarSystem.body[p].ra)),
				D2R(SolarSystem.body[p].dec),
				&SolarSystem.body[p].risetime,
				&SolarSystem.body[p].settime,
				&SolarSystem.body[p].riseaz,
				&SolarSystem.body[p].setaz,
				1.454441e-2);
}

void Ephemeris_Sun()
{
	int temph=local_hour;
	int tempm=local_minute;
	int temps=local_second;

	double la,lb;

	local_hour=12;
	local_minute=0;
	local_second=0;

	ResetDate();
	CalculateJulian();
	CalculateDay();

	// Now it's midday

	Sun();

	Riset(	(15*D2R(SolarSystem.body[SUN].ra)),
				D2R(SolarSystem.body[SUN].dec),
				&la,
				&lb,
				&SolarSystem.body[SUN].riseaz,
				&SolarSystem.body[SUN].setaz,
				1.454441e-2);

	Split(la,&local_hour,&local_minute,&local_second);

	ResetDate();
	CalculateJulian();
	CalculateDay();
	Sun();
	Riset(	(15*D2R(SolarSystem.body[SUN].ra)),
				D2R(SolarSystem.body[SUN].dec),
				&SolarSystem.body[SUN].risetime,
				&SolarSystem.body[SUN].settime,
				&SolarSystem.body[SUN].riseaz,
				&SolarSystem.body[SUN].setaz,
				1.454441e-2);

	Split(lb,&local_hour,&local_minute,&local_second);
	CalculateJulian();
	CalculateDay();
	Sun();
	Riset(	(15*D2R(SolarSystem.body[SUN].ra)),
				D2R(SolarSystem.body[SUN].dec),
				&la,
				&SolarSystem.body[SUN].settime,
				&SolarSystem.body[SUN].riseaz,
				&SolarSystem.body[SUN].setaz,
				1.454441e-2);

	// Restore values and finish up
	local_hour=temph;
	local_minute=tempm;
	local_second=temps;

	ResetDate();
	CalculateJulian();
	CalculateDay();
}


void Ephemeris_Moon()
{

	double la,lb;


	int temph=local_hour;
	int tempm=local_minute;
	int temps=local_second;

	double di,th;

	local_hour=12;
	local_minute=0;
	local_second=0;

	ResetDate();
	CalculateJulian();
	CalculateDay();

	Moon();

	th=2.7249e-1*sin(MOONSPM);di=th+9.8902e-3-MOONSPM;

	Riset((15*D2R(SolarSystem.body[MOON].ra)),D2R(SolarSystem.body[MOON].dec),
				&la,&lb,&SolarSystem.body[MOON].riseaz,&SolarSystem.body[MOON].setaz,di);


	// Find rise time

	for (int p=1;p<4;p++)
	{
		Split(la,&local_hour,&local_minute,&local_second);
		ResetDate();
		CalculateJulian();
		CalculateDay();
		Moon();
		th=2.7249e-1*sin(MOONSPM);di=th+9.8902e-3-MOONSPM;
		Riset((15*D2R(SolarSystem.body[MOON].ra)),D2R(SolarSystem.body[MOON].dec),
				&la,&lb,&SolarSystem.body[MOON].riseaz,&SolarSystem.body[MOON].setaz,di);
	}
	SolarSystem.body[MOON].risetime=la;

	// Find set time

	for (p=1;p<4;p++)
	{
		Split(lb,&local_hour,&local_minute,&local_second);
		ResetDate();
		CalculateJulian();
		CalculateDay();
		Moon();
		th=2.7249e-1*sin(MOONSPM);di=th+9.8902e-3-MOONSPM;
		Riset((15*D2R(SolarSystem.body[MOON].ra)),D2R(SolarSystem.body[MOON].dec),
				&la,&lb,&SolarSystem.body[MOON].riseaz,&SolarSystem.body[MOON].setaz,di);
	}
	SolarSystem.body[MOON].settime=lb;


	// Restore values and finish up
	local_hour=temph;
	local_minute=tempm;
	local_second=temps;

	CalculateJulian();
	CalculateDay();

}





void Ephemeris()
{
	Ephemeris_Planets();
	Ephemeris_Sun();
	Ephemeris_Moon();

}


/*

1. Convert D/m/y, h/m/s -> Julian :: CalculateJulian();

	This is required twice: once when starting the program
	when the system clock is read, and once when the User 
	enters a date and time into the When dialog.

2. Convert Julian -> d/m/y, h/m/s :: CalculateDay();

	This is required so that the corrent time and date
	can be displayed on-screen.

3. Convert Julian -> LST :: CalculateDay();

	This is required for all Alz.Az calculations

4. Convert Julian -> JD and UT :: :: CalculateDay();

	This is required as Moon(), Sun() and Planets()
	all require JD and UT.


  Therefore Julian is the format which is used to store
  the time. When other units are required, they are taken
  from Julian. However, Julian is only set directly by
  condition (1). Any time-steps are differences in the 
  value of Julian.

*/
