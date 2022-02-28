
class Tank {
	struct triple_type position;
	struct triple_type p1[17],p2[17];
	struct triple_type bounding[4];			// bounding box
	double direction;						// angle which tank is facing in
	int	counter;							// time limits explosion
	int movement;							// 0 spin, 1 move, 2 nowt, 3 bang!
	double aimangle;
	double delta;
	bool active;
	bool ultratank;		// if true, it's nastier!
public:
	Tank();									// Constructor
	void Reset();							// Redefine graphics etc
	void Spin(double angle);				// Spin Tank locally
	void Rotate(double angle);				// Alter Tank's position globally
	void Move(double distance);		// Alter Tank's position globally
	void Draw(CDC *pDC);
	void SetPosition(double x,double y,double z);
	//bool TestDistance(double distance);		// Is the tank too close?
	void Drive(double distance);			// Move in the direction
	bool Think();							// Control the tank
	double GetX();
	double GetZ();
	void Kill();							// Tank destroyed
	void Explode();
//	double GetA();
	bool Active();
	void SetActive(bool state);
};


//double Tank::GetA()
//{
//	double r;
//	r=(position.x*position.x+position.z*position.z);
//	return r;//(double)(movement;//aimangle;//direction;
//}

void Tank::SetActive(bool state)
{
	active=state;
	if (state==true) movement=5;
}

bool Tank::Active()
{
	return active;
}



//void Tank::Fix()
//{
		//double dd;
		//aimangle=dir(position.x,position.z);
		//Spin(-direction-aimangle);
		//movement=1;
//}

void Tank::Reset()
{

	int j=0;

	if (Hits==EnemyCount) 
	{
		active=false;
		return;
	}

	counter=0;
	direction=270;//180;
	//Spin((rand() & 15)*24);
	movement=5;

	double x,z;

	do 
	{
		x=(double) (Random() & 63)-32;
		z=(double) (Random() & 63)-32;
	} while ((x*x+z+z)<64);

	SetPosition(x,1,z);

	if ((Random()&3)==0) ultratank=true; else ultratank=false;

	for (int i=0;i<17;i++)
	{
		if (!ultratank)
		{
			p1[i]=tank_lines[j++];
			p2[i]=tank_lines[j++];
		}
		else
		{
			p1[i]=ultra_tank_lines[j++];
			p2[i]=ultra_tank_lines[j++];
		}

		p1[i].y=-p1[i].y;
		p2[i].y=-p2[i].y;
	};
	bounding[0].x= 2;bounding[0].y=0;bounding[0].z= 1.5;
	bounding[1].x= 2;bounding[1].y=0;bounding[1].z=-1.5;
	bounding[2].x=-3;bounding[2].y=0;bounding[2].z= 1.5;
	bounding[3].x=-3;bounding[3].y=0;bounding[3].z=-1.5;
}

Tank::Tank()// Constructor
{
	Reset();
}

void Tank::Kill()
{
	// Tank is destroyed
	PlaySound(3);
	movement=3;
	counter=0;
}


/*
bool Tank::TestDistance(double distance)
{
	// Returns false if unsafe for player to move

	double d; // fnarr fnarr
	double x,z;

	for (int i=0;i<4;i++)
	{
		x=bounding[i].x+position.x;
		z=bounding[i].z+position.z-distance;
		d=x*x+z*z;
		if (d<TOOCLOSE) return false;
	}
	return true;	
}
*/

void Tank::SetPosition(double x,double y,double z)
{
	position.x=x;
	position.y=y;
	position.z=z;
}


double Tank::GetX()
{
	return position.x;
}

double Tank::GetZ()
{
	return position.z;
}

void Tank::Spin(double angle)
{
	// Spin around Y axis

	double zz,xx;

	sd=sin(angle*rad);
	cd=cos(angle*rad);

	direction+=angle;
	if (direction<0) direction+=360;
	else if (direction>360) direction-=360;

	//if (direction<-180) direction+=360;
	//else if (direction>180) direction-=360;

	for (int j=0;j<17;j++)
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

void Tank::Rotate(double angle)
{
	double zz,xx;

	sd=sin(angle*rad);
	cd=cos(angle*rad);

	xx=(position.x*cd)-(position.z*sd);
	zz=(position.x*sd)+(position.z*cd); 	
	position.z=zz;position.x=xx;
}

void Tank::Move(double distance)
{
	position.z-=distance;
}

void Tank::Explode()
{
	for (int j=0;j<17;j++)
		{
			p1[j].z=p1[j].z*1.1;p1[j].x=p1[j].x*1.1;p1[j].y=p1[j].y*0.9;
			p2[j].z=p2[j].z*0.9;p2[j].x=p2[j].x*0.9;p2[j].y=p2[j].y*1.1;
		}
}

void Tank::Draw(CDC *pDC)
{
	// Draw the Tank in 3D

	
	double x1,y1,z1,x2,y2,z2;
	double px1,py1,px2,py2;			// perspective co-ordinates

//	pDC->SelectObject(&BlackPen);

	x1=position.x/2;
	z1=position.z/2;

	if (frame==0) 
		if (((x1*x1+z1*z1)<900) && (GameState==20)) pDC->FillSolidRect(RX+x1,RY-z1,3,3,BRIGHTRED);

//	pDC->SelectObject(&BlackPen);


	for (int i=0;i<17;i++)
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
			ClipAndDrawLine(pDC,px1,py1,px2,py2,0);
		}
	}
}

void Tank::Drive (double distance)
{
	// Move the tank in the direction it is
	// facing by 'distance' number of units

	position.x+=distance*sin(direction*rad);
	position.z-=distance*cos(direction*rad);

}

bool Tank::Think()
{

	int ultraspeed=0;

	// Control the movement of the tank

	// First, check if tank has crashed into player
		double d;
		d=position.x*position.x+position.z*position.z;
		if (d<TOOCLOSE) 
		{	// Too close!
			movement=3;
			GameState=35;
			PlaySound(3);
		}

	if (movement==3) // Exploding
	{
	
		Explode();
		counter++;
		if (counter==20) 
		{
			// Create new tank
			if (Hits==EnemyCount) GameState=12;
			Reset();
		}
		return true;
	}

	if (movement==1)		// move 
	{
		counter++;
		ultraspeed=TankSpeed;
		if (ultratank==true) ultraspeed*=2;
		Drive(TankSpeed);
		if (counter>40) 
		{
			//if ((cenx*cenx+cenz*cenz)>1200)
			//{
			//	movement=6;// move towards centre
			//}
			movement=5;
		}
		return true;
	}

	if (movement==0)		// spin
	{
		counter++;
		if (counter>20) 
		{
			counter=0;
			movement=1;
		}

		Spin(3);
		return true;
	}

	if (movement==2)		// init spin towards player
	{
		aimangle=dir(position.x,position.z);

		if (aimangle==0) 
		{
			movement=1;
			return true;
		}

		aimangle=(-direction-aimangle);
		if (aimangle>180) aimangle-=360;
		else if (aimangle<-180) aimangle+=360;

		aimangle=aimangle/3;

		if (aimangle<0)
		{
			aimangle=-aimangle;
			delta=-3;
		}
		else
		{
			delta=3;
	
		}
		counter=0;
		movement=4;
		return true;
	}

	if (movement==4)
	{
		
		Spin(delta);
		counter++;
	
		if (counter>=aimangle)
		{
			// Lined up -- fire?

			if ((position.x*position.x+position.z*position.z)>1200)
			{
				// too far to fire, but move closer!
				counter=0;
				movement=1;
			}
			else
			{
				if (Random()&1)
				{	double ang;
					ang=direction;//-90;
					if (ang<0) ang+=360;
					TankShoots(position.x,position.z,ang);
					counter=0;
					movement=1;
				}
			}
		}
		return true;
	}

	

	if (movement==5)
	{
		// Pick something to do!
		// 0,1,2

		movement=(Random() & 3);
		if (movement==3) movement=1;

		counter=0;
		
		return true;
	}
	return true;
}

Tank panzer,panzer2;							// Enemy hardware
