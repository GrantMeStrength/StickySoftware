//
// This code creates, stores, retreives and deletes
// information from the registry.
//
// The information stored includes:
// * The current location (lat/long)
// * Various display settings 
//

#include "stdafx.h"
#include "globalstuff.h"
#include "math.h"

//#define DEMO

extern bool eastwest;
extern bool northsouth;
extern double local_longitude;
extern double local_latitude;
extern short int display_mode;


extern bool flags[33];

// Settings used by the auto update feature

extern int CurrentDelay; 
extern int CurrentJump;  
extern int CurrentUnit;
extern int CurrentTarget;
extern int CurrentMags;	

extern short int local_day;
extern short int local_month;
extern short int local_year;
extern short int local_hour;
extern short int local_minute;
extern short int local_second;
extern short int local_timezone;
extern bool local_daylight;

extern int g_win_alt_deg,g_win_alt_min;
extern int g_win_azm_deg,g_win_azm_min;


// Location lat,long, tz, dy

DWORD Core[22];

DWORD dwLat1,dwLat2,dwLong1,dwLong2;
DWORD dwSettings,dwSettings2;


void CreateCore()
{
	long int *lip;
	DWORD dw1,dw2;


	lip=(long int *)&local_longitude;
	dw1=*lip++;
	dw2=*lip;
	dwLong1=dw1;dwLong2=dw2;

	lip=(long int *)&local_latitude;
	dw1=*lip++;
	dw2=*lip;
	dwLat1=dw1;dwLat2=dw2;

	switch (display_mode)
	{
	case 0:flags[Display1]=0;flags[Display2]=0;break;
	case 1:flags[Display1]=0;flags[Display2]=1;break;
	case 2:flags[Display1]=1;flags[Display2]=1;break;
	}

	flags[NorthNess]=northsouth;
	flags[EastNess]=eastwest;

	dwSettings=0;
	for (int i=0;i<16;i++)
		if (flags[i]) dwSettings+=1<<i;

	dwSettings2=0;
	for (i=0;i<16;i++)
		if (flags[i+16]) dwSettings2+=1<<i;

	// Assign Core

	Core[0]=local_daylight;
	Core[1]=local_timezone;
	Core[2]=dwLong1;
	Core[3]=dwLong2;
	Core[4]=dwLat1;
	Core[5]=dwLat2;
	Core[6]=CurrentDelay;
	Core[7]=CurrentJump;
	Core[8]=CurrentUnit;
	Core[9]=CurrentTarget;
	Core[10]=CurrentMags;
	Core[11]=dwSettings;
	Core[12]=dwSettings2;
	Core[13]=local_day;
	Core[14]=local_month;
	Core[15]=local_year;
	Core[16]=local_minute;
	Core[17]=local_hour;
	Core[18]=g_win_alt_deg;
	Core[19]=g_win_azm_deg;
	Core[20]=g_win_alt_min;
	Core[21]=g_win_azm_min;
}

void ExtractCore(bool withtime)
{

	long int *lip;
	DWORD dw1,dw2;

	local_daylight=Core[0];
	local_timezone=Core[1];
	dwLong1=Core[2];
	dwLong2=Core[3];
	dwLat1=Core[4];
	dwLat2=Core[5];
	CurrentDelay=Core[6];
	CurrentJump=Core[7];
	CurrentUnit=Core[8];
	CurrentTarget=Core[9];
	CurrentMags=Core[10];
	dwSettings=Core[11];
	dwSettings2=Core[12];

	dw1=dwLong1;dw2=dwLong2;
	lip=(long int *) &local_longitude;
	*lip++=dw1;
	*lip=dw2;

	dw1=dwLat1;dw2=dwLat2;
	lip=(long int *) &local_latitude;
	*lip++=dw1;
	*lip=dw2;

	if (withtime)
	{
		local_day=Core[13];
		local_month=Core[14];
		local_year=Core[15];
		local_minute=Core[16];
		local_hour=Core[17];
		g_win_alt_deg=Core[18];
		g_win_azm_deg=Core[19];
		g_win_alt_min=Core[20];
		g_win_azm_min=Core[21];
	}


	for (int i=0;i<16;i++)
		if (dwSettings&(1<<i)) flags[i]=true; else flags[i]=false;

	for (i=0;i<16;i++)
		if (dwSettings2&(1<<i)) flags[i+16]=true; else flags[i+16]=false;

	northsouth=flags[NorthNess];
	eastwest=flags[EastNess];

	display_mode=flags[Display1]+flags[Display2];

}

void SaveInfo()
{
	// Save Settings in Registry

	HKEY hKey;
	DWORD dwDisp;
	HRESULT hRes;

	CreateCore();

	hRes=RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\PU1",0,NULL,0,KEY_ALL_ACCESS,NULL,&hKey,&dwDisp);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"CreateKey failed!",L"",MB_OK);
		return;
	}
	hRes=RegSetValueEx(hKey,L"Settings",0,REG_BINARY,(LPBYTE)&Core,sizeof(Core));
	RegCloseKey(hKey);
}






bool RealLoadInfo()
{
	// Load settings from Registry

	HKEY hKey;
	DWORD dwSize,dwType;
	HRESULT hRes;

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\PU1",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return false;
	}

	 dwSize=sizeof(Core);
	 hRes=RegQueryValueEx(hKey,L"Settings",0,&dwType,(LPBYTE)&Core,&dwSize);

	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't read settings registry!",L"",MB_OK);
		RegCloseKey(hKey);
		return false;
	}


	RegCloseKey(hKey);
	ExtractCore(false);
	return true;
}


void DeleteInfo()
// Remove the key
{
	HKEY hKey;
	HRESULT hRes;

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\PU1",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return;
	}
	RegCloseKey(hKey);

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't open registry2!",L"",MB_OK);
		return;
	}


	hRes=RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\PU1");
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't delete \\s!",L"",MB_OK);
		return;
	}


	RegCloseKey(hKey);

	//MessageBox(NULL,L"deleted!",L"",MB_OK);
}


void LoadInfo()
{

	g_win_alt_deg=6;
	g_win_azm_deg=0;
	g_win_alt_min=0;
	g_win_azm_min=0;


#ifndef DEMO

	if (RealLoadInfo()==true) return;

#endif

	// The registry setting isn't here, so set all the
	// default values!

flags[GridOn] = false;
flags[HorizonOn] = true;
flags[StarsOn] = true;
flags[PlanetsOn] = true;
flags[SitesOn] = true;
flags[MarkersOn] = true;
flags[LabelsOn] = true;
flags[InvertOn] = false;
flags[TextOn] = true;
flags[MessOn] = false;
flags[ParallaxOn] = false;
flags[HideOn] = true;
flags[SunMoonOn] = true;
flags[OutlineOn] = false;
flags[RealSizeOn] = false;
flags[CompassOn] = false;
flags[TipsOn] = true;
flags[ToolOn] = false;
flags[ToolOpen] = false;

flags[NorthNess]= true;
flags[EastNess]= false;
flags[HourGlassOn] = true;
flags[GfxMoon] = true;
flags[EclipticOn]=false;

	local_longitude=5.5; // has to be something to start with...
	local_latitude=54.3;
	local_timezone=0;
	local_daylight=0;

	flags[KeyLook]=true;
	flags[KeyZoom]=false;
	flags[KeyTime]=false;

	eastwest=false;
	northsouth=true;
}