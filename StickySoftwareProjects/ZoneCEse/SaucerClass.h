
class Saucer {
	struct triple_type position;
	struct triple_type p1[8],p2[8];
	struct triple_type bounding[4];			// bounding box
	double direction;						// angle which Saucer is facing in
	int	counter;							// time limits explosion
	int movement;							// 0 spin, 1 move, 2 nowt, 3 bang!
	double delta;
	bool active;
	double aimangle;
public:
	Saucer();									// Constructor
	void Reset();							// Redefine graphics etc
	void Spin(double angle, bool move);				// Spin Saucer locally
	void Rotate(double angle);				// Alter Saucer's position globally
	void Move(double distance);		// Alter Saucer's position globally
	void Draw(CDC *pDC);
	void SetPosition(double x,double y,double z);
	void Drive(double distance);			// Move in the direction
	bool Think();							// Control the Saucer
	void Kill();							// Saucer destroyed
	void Explode();
	bool Active();
	void SetActive(bool state);
	double GetX();
	double GetZ();
};


void Saucer::SetActive(bool state)
{
	active=state;
}

bool Saucer::Active()
{
	return active;
}


void Saucer::Reset()
{

	int j=0;

	if (Hits==EnemyCount) 
	{
		active=false;
		return;
	}

	counter=0;
	direction=270;//180;
	movement=1;

	double x,z;

	do 
	{
		x=(double) (Random() & 63)-32;
		z=(double) (Random() & 63)-32;
	} while ((x*x+z+z)<120);

	SetPosition(x,0,z);

	for (int i=0;i<8;i++)
	{
		p1[i]=saucer_lines[j++];
		p2[i]=saucer_lines[j++];
		p1[i].y=-p1[i].y;
		p2[i].y=-p2[i].y;
	};
	bounding[0].x= 2;bounding[0].y=0;bounding[0].z= 2;
	bounding[1].x= 2;bounding[1].y=0;bounding[1].z=-2;
	bounding[2].x=-2;bounding[2].y=0;bounding[2].z= 2;
	bounding[3].x=-2;bounding[3].y=0;bounding[3].z=-2;
}

Saucer::Saucer()// Constructor
{
	Reset();
}

void Saucer::Kill()
{
	// Saucer is destroyed
	PlaySound(3);
	movement=3;
	counter=0;
}


void Saucer::SetPosition(double x,double y,double z)
{
	position.x=x;
	position.y=y;
	position.z=z;
}


double Saucer::GetX()
{
	return position.x;
}

double Saucer::GetZ()
{
	return position.z;
}

void Saucer::Spin(double angle, bool move)
{
	// Spin around Y axis
	// If move=true, then alter the direction of
	// movement too!

	double zz,xx;

	sd=sin(angle*rad);
	cd=cos(angle*rad);

	if (move)
	{
		direction+=angle;
		if (direction<0) direction+=360;
		else if (direction>360) direction-=360;
	}

	for (int j=0;j<8;j++)
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

void Saucer::Rotate(double angle)
{
	double zz,xx;

	sd=sin(angle*rad);
	cd=cos(angle*rad);

	xx=(position.x*cd)-(position.z*sd);
	zz=(position.x*sd)+(position.z*cd); 	
	position.z=zz;position.x=xx;
}

void Saucer::Move(double distance)
{
	position.z-=distance;
}

void Saucer::Explode()
{
	for (int j=0;j<8;j++)
		{
			p1[j].z=p1[j].z*1.1;p1[j].x=p1[j].x*1.1;p1[j].y=p1[j].y*0.9;
			p2[j].z=p2[j].z*0.9;p2[j].x=p2[j].x*0.9;p2[j].y=p2[j].y*1.1;
		}
}

void Saucer::Draw(CDC *pDC)
{
	// Draw the Saucer in 3D

	
	double x1,y1,z1,x2,y2,z2;
	double px1,py1,px2,py2;			// perspective co-ordinates

	pDC->SelectObject(&BlackPen);

	x1=position.x/2;
	z1=position.z/2;

	if (GameState!=2) pDC->Rectangle(ORIGIN+x1+39,ORIGIN-z1+39,ORIGIN+x1+42,ORIGIN-z1+42);

	pDC->SelectObject(&BlackPen);


	for (int i=0;i<8;i++)
	{
		x1=p1[i].x+position.x;y1=p1[i].y+position.y;z1=p1[i].z+position.z;
		x2=p2[i].x+position.x;y2=p2[i].y+position.y;z2=p2[i].z+position.z;
		

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

void Saucer::Drive (double distance)
{
	// Move the Saucer in the direction it is
	// facing by 'distance' number of units

	position.x+=distance*sin(direction*rad);
	position.z-=distance*cos(direction*rad);

}

bool Saucer::Think()
{

	// Control the movement of the Saucer

	// First, check if Saucer has crashed into player
		double d;
		d=position.x*position.x+position.z*position.z;
		if (d<TOOCLOSE) 
		{	// Too close!
			//movement=3;
			GameState=35;
			PlaySound(3);
		}

	if (movement==3) // Exploding
	{
	
		Explode();
		counter++;
		if (counter==20) 
		{
			// Create new Saucer
			if (Hits==EnemyCount) GameState=12;
			Reset();
		}
		return true;
	}

	if (movement==1)		// move 
	{
		counter++;
		Drive(.4);			// Speed of moving saucer
		if (counter>30) 
				movement=2;
		return true;
	}

	if (movement==2)		// find direction of player
	{

		counter=0;
		aimangle=dir(position.x,position.z);

		if (aimangle==0) // can't find way..
		{
			movement=1;
			return true;
			
		}

		//aimangle=(-direction-aimangle);
		if (aimangle>180) aimangle-=360;
		else if (aimangle<-180) aimangle+=360;
		int r=(Random()&3);
	
		if (r==0) direction=-aimangle+45;
		else if (r==1) direction=-aimangle-45;
		else direction=-aimangle;

		movement=1;
		return true;
	}

	return true;
}

Saucer martian;							// Enemy hardware
