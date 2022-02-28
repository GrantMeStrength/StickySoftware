//
// This code creates, stores, retreives and deletes
// information from the registry.
//
// The information stored includes:
// * The current high score (long int)
// * Various game settings (display etc)
//

#include "stdafx.h"


extern bool Sound;
extern short int speed;



void SaveInfo(int hs)
{
	HKEY hKey;
	DWORD dwDisp,hiscore,dwSpeed,dwSettings;
	HRESULT hRes;

	hiscore=hs;
	dwSpeed=speed;

	dwSettings=0;
	if (Sound) dwSettings=1;

	hRes=RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ",0,NULL,0,KEY_ALL_ACCESS,NULL,&hKey,&dwDisp);

	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"CreateKey failed!",L"",MB_OK);
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
		//MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return -1;
	}

	dwSize=sizeof(DWORD);
	hRes=RegQueryValueEx(hKey,L"Hi",0,&dwType,(LPBYTE)&hiscore,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't read registry 1!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}

	hRes=RegQueryValueEx(hKey,L"Sp",0,&dwType,(LPBYTE)&dwSpeed,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't read registry 2!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}

	hRes=RegQueryValueEx(hKey,L"St",0,&dwType,(LPBYTE)&dwSettings,&dwSize);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't read registry 3!",L"",MB_OK);
		RegCloseKey(hKey);
		return -1;
	}


	RegCloseKey(hKey);

	hs=(int)hiscore;
	speed=(int)dwSpeed;

	if (dwSettings&1) Sound=true;else Sound=false;
	
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
		//MessageBox(NULL,L"Couldn't open registry!",L"",MB_OK);
		return;
	}


	
	hRes=RegDeleteValue(hKey,L"St");
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't delete St!",L"",MB_OK);
		return;
	}

	RegDeleteValue(hKey,L"Sp");
	RegDeleteValue(hKey,L"Hi");

	RegCloseKey(hKey);

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Sticky",0,KEY_ALL_ACCESS,&hKey);
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't open registry2!",L"",MB_OK);
		return;
	}


	hRes=RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Sticky\\TZ");
	if (hRes!=ERROR_SUCCESS)
	{
		//MessageBox(NULL,L"Couldn't delete \\s!",L"",MB_OK);
		//return;
	}


	RegCloseKey(hKey);

	//MessageBox(NULL,L"deleted!",L"",MB_OK);
}