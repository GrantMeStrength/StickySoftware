//
// This code creates, stores, retreives and deletes
// information from the registry.
//
// The information stored includes:
// * The current high score (long int)
// * Various game settings (display etc)
//

#include "stdafx.h"


extern bool Sound,Flicker;
extern bool Landscape,Shaded;
extern int speed;



void SaveInfo(int hs)
{
	HKEY hKey;
	DWORD dwDisp,hiscore,dwSpeed,dwSettings;
	HRESULT hRes;

	hiscore=hs;
	dwSpeed=speed;

	dwSettings=0;
	if (Sound) dwSettings=1;
	if (Flicker) dwSettings+=2;
	if (Landscape) dwSettings+=4;
	if (Shaded) dwSettings+=8;

	hRes=RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ",0,NULL,0,KEY_ALL_ACCESS,NULL,&hKey,&dwDisp);

	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"CreateKey failed!",L"",MB_OK);
		return;
	}

	hRes=RegSetValueEx(hKey,L"Hi",0,REG_DWORD,(LPBYTE)&hiscore,sizeof(DWORD));
	hRes=RegSetValueEx(hKey,L"Sp",0,REG_DWORD,(LPBYTE)&dwSpeed,sizeof(DWORD));
	hRes=RegSetValueEx(hKey,L"St",0,REG_DWORD,(LPBYTE)&dwSettings,sizeof(DWORD));

	RegCloseKey(hKey);

}

int LoadInfo()
{
	HKEY hKey;
	DWORD hiscore,dwSize,dwType,dwSettings,dwSpeed;
	HRESULT hRes;
	int hs;

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return -1;
	}

	dwSize=sizeof(DWORD);
	hRes=RegQueryValueEx(hKey,L"Hi",0,&dwType,(LPBYTE)&hiscore,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"Couldn't read registry 1!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}

	hRes=RegQueryValueEx(hKey,L"Sp",0,&dwType,(LPBYTE)&dwSpeed,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"Couldn't read registry 2!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}

	hRes=RegQueryValueEx(hKey,L"St",0,&dwType,(LPBYTE)&dwSettings,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"Couldn't read registry 3!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}


	RegCloseKey(hKey);

	hs=(int)hiscore;
	speed=(int)dwSpeed;

	if (dwSettings&1) Sound=true;else Sound=false;
	if (dwSettings&2) Flicker=true;else Flicker=false;
	if (dwSettings&4) Landscape=true; else Landscape=false;
	if (dwSettings&8) Shaded=true;else Shaded=false;

	return hs;
}


void DeleteInfo()
// Remove the key
{
	HKEY hKey;
	HRESULT hRes;

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return;
	}

	RegDeleteValue(hKey,L"Sp");
	RegDeleteValue(hKey,L"St");
	RegDeleteValue(hKey,L"Hi");
		
	RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ");
}