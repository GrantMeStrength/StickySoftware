#include "stdafx.h"
#include "math.h"

CTime LocalTime;


int hour;
int next_hour;
int minute;
int sp1,sp2,sp3;

int rough_minute, fine_minute;

void Phrase(int p)
{
	switch (p)
	{
	case 1:sndPlaySound(L"\\Storage Card\\Clock\\fivepast", SND_FILENAME|SND_SYNC);break;
	case 2:sndPlaySound(L"\\Storage Card\\Clock\\tenpast", SND_FILENAME|SND_SYNC);break;
	case 3:sndPlaySound(L"\\Storage Card\\Clock\\quartpa", SND_FILENAME|SND_SYNC);break;
	case 4:sndPlaySound(L"\\Storage Card\\Clock\\twenpast", SND_FILENAME|SND_SYNC);break;
	case 5:sndPlaySound(L"\\Storage Card\\Clock\\tfpast", SND_FILENAME|SND_SYNC);break;
	case 6:sndPlaySound(L"\\Storage Card\\Clock\\halfpast", SND_FILENAME|SND_SYNC);break;
	case 7:sndPlaySound(L"\\Storage Card\\Clock\\tfto", SND_FILENAME|SND_SYNC);break;
	case 8:sndPlaySound(L"\\Storage Card\\Clock\\twento", SND_FILENAME|SND_SYNC);break;
	case 9:sndPlaySound(L"\\Storage Card\\Clock\\quarto", SND_FILENAME|SND_SYNC);break;
	case 10:sndPlaySound(L"\\Storage Card\\Clock\\tento", SND_FILENAME|SND_SYNC);break;
	case 11:sndPlaySound(L"\\Storage Card\\Clock\\fiveto", SND_FILENAME|SND_SYNC);break;
	}
}



void Hourwords(int h)
{
	switch (h)
	{
	case 1:sndPlaySound(L"\\Storage Card\\Clock\\one", SND_FILENAME|SND_SYNC);break;
	case 2:sndPlaySound(L"\\Storage Card\\Clock\\two", SND_FILENAME|SND_SYNC);break;
	case 3:sndPlaySound(L"\\Storage Card\\Clock\\three", SND_FILENAME|SND_SYNC);break;
	case 4:sndPlaySound(L"\\Storage Card\\Clock\\four", SND_FILENAME|SND_SYNC);break;
	case 5:sndPlaySound(L"\\Storage Card\\Clock\\five", SND_FILENAME|SND_SYNC);break;
	case 6:sndPlaySound(L"\\Storage Card\\Clock\\six", SND_FILENAME|SND_SYNC);break;
	case 7:sndPlaySound(L"\\Storage Card\\Clock\\seven", SND_FILENAME|SND_SYNC);break;
	case 8:sndPlaySound(L"\\Storage Card\\Clock\\eight", SND_FILENAME|SND_SYNC);break;
	case 9:sndPlaySound(L"\\Storage Card\\Clock\\nine", SND_FILENAME|SND_SYNC);break;
	case 10:sndPlaySound(L"\\Storage Card\\Clock\\ten", SND_FILENAME|SND_SYNC);break;
	case 11:sndPlaySound(L"\\Storage Card\\Clock\\eleven", SND_FILENAME|SND_SYNC);break;
	case 12:sndPlaySound(L"\\Storage Card\\Clock\\twelve", SND_FILENAME|SND_SYNC);break;
	}
}

void Talk()
{

	LocalTime = CTime::GetCurrentTime();
	hour=LocalTime.GetHour();
	minute=LocalTime.GetMinute();


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
 
	if ((fine_minute==3) || (fine_minute=+4))
	{
		sp1=2;
		sp2=rough_minute+1;
	}
  
	if (minute<=30) sp3=hour;
	else sp3=next_hour;

	if (minute==0) sp1=-2;
	
	// Now the talking

	sndPlaySound(L"\\Storage Card\\Clock\\timeis", SND_FILENAME|SND_SYNC);
	if (sp1==1) sndPlaySound(L"\\Storage Card\\Clock\\after", SND_FILENAME|SND_SYNC);
    if (sp1==2) sndPlaySound(L"\\Storage Card\\Clock\\before", SND_FILENAME|SND_SYNC); 
    if (sp2!=-1) Phrase(sp2);
    if (sp3!=-1) Hourwords(sp3);
   	if ((sp1==-2) || (sp2==-1) || (sp2==0) || (sp2==12)) sndPlaySound(L"\\Storage Card\\Clock\\oclock", SND_FILENAME|SND_SYNC);

}

