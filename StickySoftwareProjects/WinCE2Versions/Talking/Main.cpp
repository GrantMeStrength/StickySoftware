// Version 2.1
// 15th September 1998
//
// Fixed: midnight bug (I hope)
// Fixes: Can find samples in two locations (I hope)


#include <windows.h>
#include <string.h>
//#include <time.h>
#include <math.h>

//CTime LocalTime;


LPSTR path;
bool samples_in_card=false;
int hour;
int next_hour;
int minute;
int sp1,sp2,sp3;

int rough_minute, fine_minute;


bool FindSamples()
{

	bool test1,test2;

	test1=sndPlaySound(L"Clock\\timeis", SND_FILENAME|SND_SYNC|SND_NODEFAULT);

	if (test1==false)
	{

		test2=sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\timeis", SND_FILENAME|SND_SYNC|SND_NODEFAULT);

		if (test2==false)
			return false;
		else
			samples_in_card=true;
	}
	else
		samples_in_card=false;
	

	return true;
}

void Phrase(int p)
{
	//MessageBox(NULL,L"Phrase",L"",MB_OK);

	if (!samples_in_card)

	switch (p)
	{
	case 1:while (!sndPlaySound(L"Clock\\fivepast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 2:while (!sndPlaySound(L"Clock\\tenpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 3:while (!sndPlaySound(L"Clock\\quartpa", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 4:while (!sndPlaySound(L"Clock\\twenpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 5:while (!sndPlaySound(L"Clock\\tfpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 6:while (!sndPlaySound(L"Clock\\halfpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 7:while (!sndPlaySound(L"Clock\\tfto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 8:while (!sndPlaySound(L"Clock\\twento", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 9:while (!sndPlaySound(L"Clock\\quarto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 10:while (!sndPlaySound(L"Clock\\tento", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 11:while (!sndPlaySound(L"Clock\\fiveto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	}

	else

	switch (p)
	{
	case 1:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\fivepast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 2:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\tenpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 3:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\quartpa", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 4:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\twenpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 5:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\tfpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 6:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\halfpast", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 7:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\tfto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 8:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\twento", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 9:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\quarto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 10:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\tento", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 11:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\fiveto", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	}
}



void Hourwords(int h)
{
	//MessageBox(NULL,L"Hour",L"",MB_OK);

	if (samples_in_card)

	switch (h)
	{
	case 0:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\twelve", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 1:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\one", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 2:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\two", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 3:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\three", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 4:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\four", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 5:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\five", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 6:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\six", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 7:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\seven", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 8:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\eight", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 9:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\nine", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 10:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\ten", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 11:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\eleven", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 12:while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\twelve", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	}

	else

	switch (h)
	{
	case 0:while (!sndPlaySound(L"Clock\\twelve", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 1:while (!sndPlaySound(L"Clock\\one", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 2:while (!sndPlaySound(L"Clock\\two", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 3:while (!sndPlaySound(L"Clock\\three", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 4:while (!sndPlaySound(L"Clock\\four", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 5:while (!sndPlaySound(L"Clock\\five", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 6:while (!sndPlaySound(L"Clock\\six", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 7:while (!sndPlaySound(L"Clock\\seven", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 8:while (!sndPlaySound(L"Clock\\eight", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 9:while (!sndPlaySound(L"Clock\\nine", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 10:while (!sndPlaySound(L"Clock\\ten", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 11:while (!sndPlaySound(L"Clock\\eleven", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	case 12:while (!sndPlaySound(L"Clock\\twelve", SND_FILENAME|SND_SYNC|SND_NOSTOP));break;
	}
}

struct _SYSTEMTIME timedate; 

void Talk()
{

	GetLocalTime(&timedate);

	hour=timedate.wHour;
	minute=timedate.wMinute;

	if (hour>12) 
		hour=hour-12;
	
	next_hour=hour+1;

	if (next_hour>12) 
		next_hour=next_hour-12;

	rough_minute=minute / 5;
	fine_minute=fmod(minute,5);

	if (fine_minute==0) sp2=rough_minute;

	if ((fine_minute==1) || (fine_minute==2))
	{
		sp1=1;
		sp2=rough_minute;
	}
 
	if ((fine_minute==3) || (fine_minute==4))
	{
		sp1=2;
		sp2=rough_minute+1;
	}
  
	if (minute<=32) sp3=hour;
	else sp3=next_hour;

	if (minute==0) sp1=-2;
	
	// Now the talking

	//while (!sndPlaySound(L"Clock\\timeis", SND_FILENAME|SND_SYNC|SND_NOSTOP|SND_NODEFAULT));

	if (!samples_in_card)
	{
	if (sp1==1) while (!sndPlaySound(L"Clock\\after", SND_FILENAME|SND_SYNC|SND_NOSTOP));
    if (sp1==2) while (!sndPlaySound(L"Clock\\before", SND_FILENAME|SND_SYNC|SND_NOSTOP)); 
	}
	else
	{
	if (sp1==1) while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\after", SND_FILENAME|SND_SYNC|SND_NOSTOP));
    if (sp1==2) while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\before", SND_FILENAME|SND_SYNC|SND_NOSTOP)); 
	}

	if (sp2!=-1) Phrase(sp2);
    if (sp3!=-1) Hourwords(sp3);
   
	if (!samples_in_card)
	{
		if ((sp1==-2) || (sp2==-1) || (sp2==0) || (sp2==12)) while (!sndPlaySound(L"Clock\\oclock", SND_FILENAME|SND_SYNC|SND_NOSTOP));
	}
	else
	{
		if ((sp1==-2) || (sp2==-1) || (sp2==0) || (sp2==12)) while (!sndPlaySound(L"\\Storage Card\\Sticky Software Speaking Clock\\oclock", SND_FILENAME|SND_SYNC|SND_NOSTOP));

	}

}




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR szCmdLine, int iCmdShow)
     {

	// Locate samples

	if (FindSamples()==false)
	{
		MessageBox(NULL,L"Cannot find sound samples!",L"",MB_OK);
		return 0;
	}

	//if (samples_in_card)
	//	MessageBox(NULL,L"Samples in card",L"",MB_OK);
	//else
	//	MessageBox(NULL,L"Samples in main",L"",MB_OK);


	Talk();

    return 0;
}