// fROM tRIPLE cLASS

#include "math.h"

class triple {
	int deg;
	int min;
	double sec;
	double all;
	bool flag;		// if flag is true, value has changed so needs recalculating
public:
	triple();
	int get_deg(void);
	int get_min(void);
	double get_sec(void);
	void set_deg(int);
	void set_min(int);
	void set_sec(double);
	double get_all(void);
	void set_all(double);
	void add_deg(int);
};

triple::triple()
{
	deg=0;min=0;sec=0;all=0;flag=false;
}

int triple::get_deg(void)
{
	return deg;
}

int triple::get_min(void)
{
	return min;
}

double triple::get_sec(void)
{
	return sec;
}

void triple::set_deg(int i)
{
	//flag=true;
	deg=i;
	all=(double (deg)+double(min)/60+(sec/3600));
}

void triple::add_deg(int i)
{
	//flag=true;
	deg+=i;
	all=(double (deg)+double(min)/60+(sec/3600));

}

void triple::set_min(int i)
{
	//flag=true;
	min=i;
	all=(double (deg)+double(min)/60+(sec/3600));

}

void triple::set_sec(double i)
{
	//flag=true;
	sec=i;
	all=(double (deg)+double(min)/60+double(sec/3600));

}

double triple::get_all(void)
{
	if (flag==true)
	{
		all=(double (deg)+double(min)/60+double(sec/3600));
		flag=false;
	}

	return all;
}

void triple::set_all(double number)
{
	int ng;
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
	deg=(int)d*ng;
	min=(int)m;
	sec=s;
	
	all=ng*number;
	flag=false;
};
