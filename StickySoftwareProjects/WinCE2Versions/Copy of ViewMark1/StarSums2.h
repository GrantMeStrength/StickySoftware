
void Planets()
{

	// Needs JD and UT

	double t;
	double C,B;
	int i,j,k;
	double A0,A1,A2,A3,AA;

	//double sra,sdec;

	int ip;

	double pv,ec,re,lg,ms;

	double x,f,m;


	double LI;
	double 	qa,qb,qc,qd,qe,qf,qg,a,ae,at;
	double	sa,ca,ll,l1,l2,in,ci,co,sp,so,ps,pd,bp;
	double am,lp,om,lo,y,rd,rh,vo,po,ep;

	double b,c,p,q,d,e;
	double elong,elat;

	double j1,j2,j3,j4,j5,j6,j7,j8,j9,ja,jb,jc;
	double u1,u2,u3,u4,u5,u6,u7,u8,u9,ua,ub,uc,ud,ue,uf,ug,ui,uj,uk,UL,un,uo,up,uq,ur,uu,uv,uw,ux,uy,uz;
	double vk,vh,vi,vj,va,vb,vc,vd,ve,vf,vg;
	double ob,oa;


	double AP[9];

	struct pelment_type {
		double element[10];
	};

	struct system {
		struct pelment_type planet[9];
	} Solar_system;



	 double planet_data[184] ={

// Mercury
		178.179078,415.2057519,3.011E-4,0,
		75.899697,1.5554889,2.947E-4,0,
		2.0561421E-1,2.046E-5,-3e-8,0,
		7.002881,1.8608E-3,-1.83E-5,0,
		47.145944,1.1852083,1.739E-4,0,
		3.870986E-1,6.74,-0.42,
// Venus
		342.767053,162.5533664,3.097E-4,0,
		130.163833,1.4080361,-9.764E-4,0,
		6.82069E-3,-4.774E-5,9.1E-8,0,
		3.393631,1.0058E-3,-1E-6,0,
		75.779647,8.9985E-1,4.1E-4,0,
		7.233316E-1,16.92,-4.4,
// Mars
		293.737334,53.17137642,3.107E-4,0,
		3.34218203E2,1.8407584,1.299E-4,-1.19E-6,
		9.33129E-2,9.2064E-5,-7.7E-8,0,
		1.850333,-6.75E-4,1.26E-5,0,
		48.786442,7.709917E-1,-1.4E-6,-5.33E-6,
		1.5236883,9.36,-1.52,
// Jupiter
		238.049257,8.434172183,3.347E-4,
		-1.65E-6,
		1.2720972E1,1.6099617,1.05627E-3,
		-3.43E-6,
		4.833475E-2,1.6418E-4,-4.676E-7,
		-1.7E-9,
		1.308736,-5.6961E-3,3.9E-6,0,
		99.443414,1.01053,3.5222E-4,-8.51E-6,
		5.202561,196.74,-9.4,
// Saturn
		266.564377,3.398638567,3.245E-4,
		-5.8E-6,
		9.1098214E1,1.9584158,8.2636E-4,
		4.61E-6,
		5.589232E-2,-3.455E-4,-7.28E-7,
		7.4E-10,
		2.492519,-3.9189E-3,-1.549E-5,4E-8,
		112.790414,8.731951E-1,-1.5218E-4,
		-5.31E-6,
		9.554747,165.6,-8.88,
// Uranus
		244.19747,1.194065406,3.16E-4,-6E-7,
		1.71548692E2,1.4844328,2.372E-4,
		-6.1E-7,
		4.63444E-2,-2.658E-5,7.7E-8,0,
		7.72464E-1,6.253E-4,3.95E-5,0,
		73.477111,4.986678E-1,1.3117E-3,0,
		19.21814,65.8,-7.19,
// Neptune
		84.457994,6.107942056E-1,3.205E-4,
		-6E-7,
		4.6727364E1,1.4245744,3.9082E-4,
		-6.05E-7,
		8.99704E-3,6.33E-6,-2E-9,0,
		1.779242,-9.5436E-3,-9.1E-6,0,
		130.681389,1.098935,2.4987E-4,
		-4.718E-6,
		30.10957,62.2,-6.87,
// pluto
		95.3113544,3.980332167E-1,0,0,224.017,0,0,0,
		2.5515E-1,0,0,0,
		17.1329,0,0,0,
		110.191,0,0,0,
		39.8151,8.2,-1.0
	};

//	DJ=JD-2415020;
	// DJ=Julian-2415020;UT=0;

	//t=(DJINT/36525.0)+(UT/8.766e5); 
	t=TimeT;

	j=0; // Counter in planet data array

	for (i=1;i<9;i++)
	{
		A0=planet_data[j++];
		A1=planet_data[j++];
		A2=planet_data[j++];
		A3=planet_data[j++];
		AA=A1*t;
		B=360.0*(AA-Integer(AA));
		C=A0+B+(A3*t+A2)*t*t;

		while (C>360) C-=360;
		while (C<0) C+=360;

		Solar_system.planet[i].element[1]=C;

		Solar_system.planet[i].element[2]=(A1*9.856263E-3)+(A2+A3)/36525.0;

		for (k=3;k<7;k++)
		{
			A0=planet_data[j++];
			A1=planet_data[j++];
			A2=planet_data[j++];
			A3=planet_data[j++];
			Solar_system.planet[i].element[k]=((A3*t+A2)*t+A1)*t+A0;
		}

		Solar_system.planet[i].element[7]=planet_data[j++];
		Solar_system.planet[i].element[8]=planet_data[j++];
		Solar_system.planet[i].element[9]=planet_data[j++];
	}



	if (suns_ecliptic_longitude==-1)
		Sun();

	LI=0;
	ms=suns_mean_anomaly;
	re=sun_earth_distance;
	lg=suns_ecliptic_longitude+pi;

for (ip=1;ip<9;ip++)
{

	for (k=1;k<3;k++)
	{

		for (j=1;j<9;j++)
			AP[j]=D2R(Solar_system.planet[j].element[1]-Solar_system.planet[j].element[3]-LI*Solar_system.planet[j].element[2]);


		qa=0;qb=0;qc=0;qd=0;qe=0;qf=0;qg=0;



		switch (ip) {
		case 1:
			{
				qa=2.04E-3*cos(5*AP[2]-2*AP[1]+2.1328E-1);
				qa=qa+1.03E-3*cos(2*AP[2]-AP[1]-2.8046);
				qa=qa+9.1E-4*cos(2*AP[4]-AP[1]-6.4582E-1);
				qa=qa+7.8E-4*cos(5*AP[2]-3*AP[1]+1.7692E-1);

				qb=7.525E-6*cos(2*AP[4]-AP[1]+9.25251E-1);
				qb=qb+6.802E-6*cos(5*AP[2]-3*AP[1]-4.53642);
				qb=qb+5.457E-6*cos(2*AP[2]-2*AP[1]-1.24246);
				qb=qb+3.569E-6*cos(5*AP[2]-AP[1]-1.35699);
				break;
			}
		case 2: // Venus
			{
				qc=7.7E-4*sin(4.1406+t*2.6227);
				qc=D2R(qc);
				qe=qc;
				qa=3.13E-3*cos(2*ms-2*AP[2]-2.587);
				qa=qa+1.98E-3*cos(3*ms-3*AP[2]+4.4768E-2);
				qa=qa+1.36E-3*cos(ms-AP[2]-2.0788);
				qa=qa+9.6E-4*cos(3*ms-2*AP[2]-2.3721);
				qa=qa+8.2E-4*cos(AP[4]-AP[2]-3.6318);
				qb=2.2501E-5*cos(2*ms-2*AP[2]-1.01592);
				qb=qb+1.9045E-5*cos(3*ms-3*AP[2]+1.61577);
				qb=qb+6.887E-6*cos(AP[4]-AP[2]-2.06106);
				qb=qb+5.172E-6*cos(ms-AP[2]-5.08065E-1);
				qb=qb+3.62E-6*cos(5*ms-4*AP[2]-1.81877);
				qb=qb+3.283E-6*cos(4*ms-4*AP[2]+1.10851);
				qb=qb+3.074E-6*cos(2*AP[4]-2*AP[2]-9.62846E-1);
				break;
			}
		case 3: // Mars	
			{
				a=3*AP[4]-8*AP[3]+4*ms;
				sa=sin(a);ca=cos(a);
				qc=-(1.133E-2*sa+9.33E-3*ca);
				qc=D2R(qc);
				qe=qc;
				qa=7.05E-3*cos(AP[4]-AP[3]-8.5448E-1);
				qa=qa+6.07E-3*cos(2*AP[4]-AP[3]-3.2873);
				qa=qa+4.45E-3*cos(2*AP[4]-2*AP[3]-3.3492);
				qa=qa+3.88E-3*cos(ms-2*AP[3]+3.5771E-1);
				qa=qa+2.38E-3*cos(ms-AP[3]+6.1256E-1);
				qa=qa+2.04E-3*cos(2*ms-3*AP[3]+2.7688);
				qa=qa+1.77E-3*cos(3*AP[3]-AP[2]-1.0053);
				qa=qa+1.36E-3*cos(2*ms-4*AP[3]+2.6894);
				qa=qa+1.04E-3*cos(AP[4]+3.0749E-1);

				qb=5.3227E-5*cos(AP[4]-AP[3]+7.17864E-1);
				qb=qb+5.0989E-5*cos(2*AP[4]-2*AP[3]-1.77997);
				qb=qb+3.8278E-5*cos(2*AP[4]-AP[3]-1.71617);
				qb=qb+1.5996E-5*cos(ms-AP[3]-9.69618E-1);
				qb=qb+1.4764E-5*cos(2*ms-3*AP[3]+1.19768);
				qb=qb+8.966E-6*cos(AP[4]-2*AP[3]+7.61225E-1);
				qb=qb+7.914E-6*cos(3*AP[4]-2*AP[3]-2.43887);
				qb=qb+7.004E-6*cos(2*AP[4]-3*AP[3]-1.79573);
				qb=qb+6.62E-6*cos(ms-2*AP[3]+1.97575);
				qb=qb+4.93E-6*cos(3*AP[4]-3*AP[3]-1.33069);
				qb=qb+4.693E-6*cos(3*ms-5*AP[3]+3.32665);
				qb=qb+4.571E-6*cos(2*ms-4*AP[3]+4.27086);
				qb=qb+4.409E-6*cos(3*AP[4]-AP[3]-2.02158);
				break;
			}

		case 4: // Jupiter
			{
				j1=t/5.0+0.1;					j2=FNU(4.14473+5.29691E1*t);
				j3=FNU(4.641118+2.132991E1*t);	j4=FNU(4.250177+7.478172*t);
				j5=5.0*j3-2.0*j2;				j6=2.0*j2-6.0*j3+3.0*j4;
				j7=j3-j2;

				u1=sin(j3);			u2=cos(j3);
				u3=sin(2.0*j3);		u4=cos(2.0*j3);
				u5=sin(j5);			u6=cos(j5);
				u7=sin(2.0*j5);		u8=sin(j6);
				u9=sin(j7);

				ua=cos(j7);ub=sin(2.0*j7);
				uc=cos(2.0*j7);ud=sin(3.0*j7);
				ue=cos(3.0*j7);uf=sin(4.0*j7);
				ug=cos(4.0*j7);vh=cos(5.0*j7);

				qc=(3.31364E-1-(1.0281E-2+4.692E-3*j1)*j1)*u5;
				qc=qc+(3.228E-3-(6.4436E-2-2.075E-3*j1)*j1)*u6;
				qc=qc-(3.083E-3+(2.75E-4-4.89E-4*j1)*j1)*u7;
				qc=qc+2.472E-3*u8+1.3619E-2*u9+1.8472E-2*ub;
				qc=qc+6.717E-3*ud+2.775E-3*uf+6.417E-3*ub*u1;
				qc=qc+(7.275E-3-1.253E-3*j1)*u9*u1+2.439E-3*ud*u1;
				qc=qc-(3.5681E-2+1.208E-3*j1)*u9*u2-3.767E-3*uc*u1;
				qc=qc-(3.3839E-2+1.125E-3*j1)*ua*u1-4.261E-3*ub*u2;
				qc=qc+(1.161E-3*j1-6.333E-3)*ua*u2+2.178E-3*u2;
				qc=qc-6.675E-3*uc*u2-2.664E-3*ue*u2-2.572E-3*u9*u3;
				qc=qc-3.567E-3*ub*u3+2.094E-3*ua*u4+3.342E-3*uc*u4;
				qc=D2R(qc);

				qd=(3606+(130-43*j1)*j1)*u5+(1289-580*j1)*u6;
				qd=qd-6764*u9*u1-1110*ub*u1-224*ud*u1-204*u1;
				qd=qd+(1284+116*j1)*ua*u1+188*uc*u1;
				qd=qd+(1460+130*j1)*u9*u2+224*ub*u2-817*u2;
				qd=qd+6074*u2*ua+992*uc*u2+508*ue*u2+230*ug*u2;
				qd=qd+108*vh*u2-(956+73*j1)*u9*u3+448*ub*u3;
				qd=qd+137*ud*u3+(108*j1-997)*ua*u3+480*uc*u3;
				qd=qd+148*ue*u3+(99*j1-956)*u9*u4+490*ub*u4;
				qd=qd+158*ud*u4+179*u4+(1024+75*j1)*ua*u4;
				qd=qd-437*uc*u4-132*ue*u4;
				qd=qd*1E-7;

				vk=(7.192E-3-3.147E-3*j1)*u5-4.344E-3*u1;
				vk=vk+(j1*(1.97E-4*j1-6.75E-4)-2.0428E-2)*u6;
				vk=vk+3.4036E-2*ua*u1+(7.269E-3+6.72E-4*j1)*u9*u1;
				vk=vk+5.614E-3*uc*u1+2.964E-3*ue*u1+3.7761E-2*u9*u2;
				vk=vk+6.158E-3*ub*u2-6.603E-3*ua*u2-5.356E-3*u9*u3;
				vk=vk+2.722E-3*ub*u3+4.483E-3*ua*u3;
				vk=vk-2.642E-3*uc*u3+4.403E-3*u9*u4;
				vk=vk-2.536E-3*ub*u4+5.547E-3*ua*u4-2.689E-3*uc*u4;

				qe=qc-(D2R(vk)/Solar_system.planet[ip].element[4]);
				qf=205*ua-263*u6+693*uc+312*ue+147*ug+299*u9*u1;
				qf=qf+181*uc*u1+204*ub*u2+111*ud*u2-337*ua*u2;
				qf=qf-111*uc*u2;
				qf=qf*1E-6;
				break;

			}
		
		case 5: // Saturn
			{

				j1=t/5.0+0.1;					j2=FNU(4.14473+5.29691E1*t);
				j3=FNU(4.641118+2.132991E1*t);	j4=FNU(4.250177+7.478172*t);
				j5=5.0*j3-2.0*j2;				j6=2.0*j2-6.0*j3+3.0*j4;
			
				
				j7=j3-j2;
				u1=sin(j3);			u2=cos(j3);
				u3=sin(2.0*j3);		u4=cos(2.0*j3);
				u5=sin(j5);			u6=cos(j5);
				u7=sin(2.0*j5);		u8=sin(j6);
				u9=sin(j7);

				ua=cos(j7);ub=sin(2.0*j7);
				uc=cos(2.0*j7);ud=sin(3.0*j7);
				ue=cos(3.0*j7);uf=sin(4.0*j7);
				ug=cos(4.0*j7);vh=cos(5.0*j7);

				// Checked OK!!! //////
				ui=sin(3*j3);
				uj=cos(3*j3);uk=sin(4*j3);
				UL=cos(4*j3);vi=cos(2*j5);
				un=sin(5*j7);j8=j4-j3;
				uo=sin(2*j8);up=cos(2*j8);
				uq=sin(3*j8);ur=cos(3*j8);

				qc=7.581E-3*u7-7.986E-3*u8-1.48811E-1*u9;
				qc=qc-(8.14181E-1-(1.815E-2-1.6714E-2*j1)*j1)*u5;
				qc=qc-(1.0497E-2-(1.60906E-1-4.1E-3*j1)*j1)*u6;
				qc=qc-1.5208E-2*ud-6.339E-3*uf-6.244E-3*u1;
				qc=qc-1.65E-2*ub*u1-4.0786E-2*ub;
				qc=qc+(8.931E-3+2.728E-3*j1)*u9*u1-5.775E-3*ud*u1;
				qc=qc+(8.1344E-2+3.206E-3*j1)*ua*u1+1.5019E-2*uc*u1;
				qc=qc+(8.5581E-2+2.494E-3*j1)*u9*u2+1.4394E-2*uc*u2;
				qc=qc+(2.5328E-2-3.117E-3*j1)*ua*u2+6.319E-3*ue*u2;
				qc=qc+6.369E-3*u9*u3+9.156E-3*ub*u3+7.525E-3*uq*u3;
				qc=qc-5.236E-3*ua*u4-7.736E-3*uc*u4-7.528E-3*ur*u4;
				qc=D2R(qc);

				qd=(-7927+(2548+9l*j1)*j1)*u5;
				qd=qd+(13381+(1226-253*j1)*j1)*u6+(248-121*j1)*u7;
				qd=qd-(305+91*j1)*vi+412*ub+12415*u1;
				qd=qd+(390-617*j1)*u9*u1+(165-204*j1)*ub*u1;
				qd=qd+26599*ua*u1-4687*uc*u1-1870*ue*u1-821*ug*u1;
				qd=qd-377*vh*u1+497*up*u1+(163-611*j1)*u2;
				qd=qd-12696*u9*u2-4200*ub*u2-1503*ud*u2-619*uf*u2;
				qd=qd-268*un*u2-(282+1306*j1)*ua*u2;
				qd=qd+(-86+230*j1)*uc*u2+461*uo*u2-350*u3;
				qd=qd+(2211-286*j1)*u9*u3-2208*ub*u3-568*ud*u3;
				qd=qd-346*uf*u3-(2780+222*j1)*ua*u3;
				qd=qd+(2022+263*j1)*uc*u3+248*ue*u3+242*uq*u3;
				qd=qd+467*ur*u3-490*u4-(2842+279*j1)*u9*u4;
				qd=qd+(128+226*j1)*ub*u4+224*ud*u4;
				qd=qd+(-1594+282*j1)*ua*u4+(2162-207*j1)*uc*u4;
				qd=qd+561*ue*u4+343*ug*u4+469*uq*u4-242*ur*u4;
				qd=qd-205*u9*ui+262*ud*ui+208*ua*uj-271*ue*uj;
				qd=qd-382*ue*uk-376*ud*UL;
				qd=qd*1E-7;

				vk=(7.7108E-2+(7.186E-3-1.533E-3*j1)*j1)*u5;
				vk=vk-7.075E-3*u9;
				vk=vk+(4.5803E-2-(1.4766E-2+5.36E-4*j1)*j1)*u6;
				vk=vk-7.2586E-2*u2-7.5825E-2*u9*u1-2.4839E-2*ub*u1;
				vk=vk-8.631E-3*ud*u1-1.50383E-1*ua*u2;
				vk=vk+2.6897E-2*uc*u2+1.0053E-2*ue*u2;
				vk=vk-(1.3597E-2+1.719E-3*j1)*u9*u3+1.1981E-2*ub*u4;
				vk=vk-(7.742E-3-1.517E-3*j1)*ua*u3;
				vk=vk+(1.3586E-2-1.375E-3*j1)*uc*u3;
				vk=vk-(1.3667E-2-1.239E-3*j1)*u9*u4;
				vk=vk+(1.4861E-2+1.136E-3*j1)*ua*u4;
				vk=vk-(1.3064E-2+1.628E-3*j1)*uc*u4;
				qe=qc-(D2R(vk)/Solar_system.planet[ip].element[4]);

				qf=572*u5-1590*ub*u2+2933*u6-647*ud*u2;
				qf=qf+33629*ua-344*uf*u2-3081*uc+2885*ua*u2;
				qf=qf-1423*ue+(2172+102*j1)*uc*u2-671*ug;
				qf=qf+296*ue*u2-320*vh-267*ub*u3+1098*u1;
				qf=qf-778*ua*u3-2812*u9*u1+495*uc*u3+688*ub*u1;
				qf=qf+250*ue*u3-393*ud*u1-856*u9*u4-228*uf*u1;
				qf=qf+441*ub*u4+2138*ua*u1+296*uc*u4-999*uc*u1;
				qf=qf+211*ue*u4-642*ue*u1-427*u9*ui-325*ug*u1;
				qf=qf+398*ud*ui-890*u2+344*ua*uj+2206*u9*u2;
				qf=qf-427*ue*uj;
				qf=qf*1E-6;

				qg=7.47E-4*ua*u1+1.069E-3*ua*u2+2.108E-3*ub*u3;
				qg=qg+1.261E-3*uc*u3+1.236E-3*ub*u4-2.075E-3*uc*u4;
				qg=D2R(qg);
				break;


			}

		case 6: // Urananus

			{

				j1=t/5.0+0.1;					j2=FNU(4.14473+5.29691E1*t);
				j3=FNU(4.641118+2.132991E1*t);	j4=FNU(4.250177+7.478172*t);
				j5=5.0*j3-2.0*j2;				j6=2.0*j2-6.0*j3+3.0*j4;

				j8=FNU(1.46205+3.81337*t);
				j9=2*j8-j4;vj=sin(j9);uu=cos(j9);uv=sin(2*j9);uw=cos(2*j9);

				ja=j4-j2;jb=j4-j3;
				jc=j8-j4;
				qc=(8.64319e-1-1.583e-3*j1)*vj;
				qc=qc+(8.2222e-2-6.833e-3*j1)*uu+3.6017e-2*uv;
				qc=qc-3.019e-3*uw+8.122e-3*sin(j6);
				qc=D2R(qc);

				vk=1.20303e-1*vj+6.197e-3*uv;
				vk=vk+(1.9472e-2-9.47e-4*j1)*uu;
				qe=qc-(D2R(vk)/Solar_system.planet[ip].element[4]);

				qd=(163*j1-3349)*vj+20981*uu+1311*uw;
				qd=qd*1e-7;qf=-3.825e-3-uu;

				qa=(-3.8581e-2+(2.031e-3-1.91e-3*j1)*j1)*cos(j4+jb);
				qa=qa+(1.0122e-2-9.88e-4*j1)*sin(j4+jb);
				a=(3.4964e-2-(1.038e-3-8.68e-4*j1)*j1)*cos(2*j4+jb);
				qa=a+qa+5.594e-3*sin(j4+3*jc)-1.4808e-2*sin(ja);
				qa=qa-5.794e-3*sin(jb)+2.347e-3*cos(jb);
				oa=qa+9.872e-3*sin(jc)+8.803e-3*sin(2*jc);
				qa=qa-4.308e-3*sin(3*jc);

				ux=sin(jb);uy=cos(jb);uz=sin(j4);va=cos(j4);
				vb=sin(2*j4);vc=cos(2*j4);
				qg=(4.58e-4*ux-6.42e-4*uy-5.17e-4*cos(4*jc))*uz;
				qg=qg-(3.47e-4*ux+8.53e-4*uy+5.17e-4*sin(4*jb))*va;
				qg=qg+4.03e-4*(cos(2*jc)*vb+sin(2*jc)*vc);
				qg=D2R(qg);

				qb=-25948+4985*cos(ja)-1230*va+3354*uy;
				qb=qb+904*cos(2*jc)+894*(cos(jc)-cos(3*jc));
				ob=qb+(5795*va-1165*uz+1388*vc)*ux;
				qb=qb+(1351*va+5702*uz+1388*vb)*uy;
				qb=qb*1e-6;
				break;

			}

		case 7: // Neptune

			{

				j1=t/5.0+0.1;					j2=FNU(4.14473+5.29691E1*t);
				j3=FNU(4.641118+2.132991E1*t);	j4=FNU(4.250177+7.478172*t);
				j5=5.0*j3-2.0*j2;				j6=2.0*j2-6.0*j3+3.0*j4;

				j8=FNU(1.46205+3.81337*t);
				j9=2*j8-j4;vj=sin(j9);uu=cos(j9);uv=sin(2*j9);uw=cos(2*j9);

				ja=j8-j2;jb=j8-j3;jc=j8-j4;

				qc=(1.089e-3*j1-5.89833e-1)*vj;
				qc=qc+(4.658e-3*j1-5.6094e-2)*uu-2.4286e-2*uv;
				qc=D2R(qc);

				vk=2.4039e-2*vj-2.5303e-2*uu+6.206e-3*uv;
				vk=vk-5.992e-3*uw;
				qe=qc-(D2R(vk)/Solar_system.planet[ip].element[4]);

				qd=4389*vj+1129*uv+4262*uu+1089*uw;
				qd=qd*1e-7;
				qf=8189*uu-817*vj+781*uw;
				qf=qf*1e-6;

				vd=sin(2*jc);ve=cos(2*jc);
				vf=sin(j8);vg=cos(j8);

				qa=-9.556e-3*sin(ja)-5.178e-3*sin(jb);
				qa=qa+2.572e-3*vd-2.972e-3*ve*vf-2.833e-3*vd*vg;
				qg=3.36e-4*ve*vf+3.64e-4*vd*vg;
				qg=D2R(qg);

				qb=-40596+4992*cos(ja)+2744*cos(jb);
				qb=qb+2044*cos(jc)+1051*ve;
				qb=qb*1e-6;
				break;
	}

		case 8: // Pluto

			{
				break;
			}

		}

			
		ec=Solar_system.planet[ip].element[4]+qd;
		am=AP[ip]+qe;
		Anomaly((am),(ec),&ae,&at);
		pv=(Solar_system.planet[ip].element[7]+qf)*(1.0-ec*ec)/(1.0+ec*cos(at));
		lp=R2D(at)+Solar_system.planet[ip].element[3]+R2D(qc-qe);
		lp=D2R(lp);
		om=D2R(Solar_system.planet[ip].element[6]);
		lo=lp-om;
		so=sin(lo);
		co=cos(lo);
		in=D2R(Solar_system.planet[ip].element[5]);
		pv=pv+qb;
		sp=so*sin(in);
		y=so*cos(in);
		ps=asin(sp)+qg;
		//ps=FNS(sp)+qg;
		sp=sin(ps);
		pd=atan(y/co)+om+D2R(qa);
		if (co<0) pd=pd+pi;
		if (pd>tp) pd=pd-tp;
		ci=cos(ps);
		rd=pv*ci;
		ll=pd-lg;
		rh=re*re+pv*pv-2.0*re*pv*ci*cos(ll);
		rh=sqrt(rh);
		LI=rh*5.775518e-3;

		if (k==1)
		{
			lo=pd;
			vo=rh;
			so=ps;
			po=pv;
		};

	}

	l1=sin(ll);l2=cos(ll);

	if (ip<3)
			ep=atan(-1.0*rd*l1/(re-rd*l2))+lg+pi;
	else
			ep=atan(re*l1/(rd-re*l2))+pd;
	

	while (ep<0) ep=ep+tp;
	while (ep>tp) ep=ep-tp;

	bp=atan(rd*sp*sin(ep-pd)/(ci*re*l1));

	//

	if (nutation_ecliptic==-1) NUTAT();


	elong=ep;
	elat=bp;
	
	//bp=bp+D2R(nutation_obliquity);
	ep=ep+D2R(nutation_ecliptic);
	a=lg+pi-ep;
	b=cos(a);
	c=sin(a);
	ep=ep-(9.9387e-5*b/cos(bp));
	bp=bp-(9.9387e-5*c*sin(bp));

	EQECL (ep, bp, &p,&q);

	p=R2D(p)/15;
	q=R2D(q);

	d=-cos(bp)*cos(ep-lg);
	e=R2D(acos(d));

	e=Integer(1e3*e+0.5)/1e3;

	a=Integer((10*Solar_system.planet[ip].element[8]/rh)+0.5)/10;
	f=0.5*(1.0+cos(ep-pd));
	x=log(pv*rh/sqrt(f));
	m=5.0*x/log(10.0)+Solar_system.planet[ip].element[9];

	
SolarSystem.body[ip].ra=p;
SolarSystem.body[ip].dec=q;
SolarSystem.body[ip].mag=(float)m;
SolarSystem.body[ip].size=(float)a;
SolarSystem.body[ip].phase=(float)f;
SolarSystem.body[ip].distance=(float)vo;

}

}