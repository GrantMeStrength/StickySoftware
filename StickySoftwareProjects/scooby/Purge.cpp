//
// Delete all previous Barney Files
//
// Nuke em!

	// Remove all traces of Barney Buttons:
	// Files, registry and database entries

#include "stdafx.h"

CEPROPVAL Looking;
HANDLE dh;
CEOID did=0;
DWORD dwIndex;
	bool failure=false;
	HKEY hKey;
	DWORD dwState=1;
	HRESULT hRes;
	TCHAR value[64];
	DWORD dwDisp;
	TCHAR filename[64];

void CleanFiles()
{
	// Delete all Files

	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but1.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but2.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but3.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but4.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but5.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but6.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but7.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but8.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but9.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butF.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butV.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butP.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butM.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butT.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butX.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butH.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.cdf"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.mcs"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butS.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\userA.bmp"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\userB.bmp"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\userC.bmp"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\userD.bmp"));

	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p1.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p2.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p3.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p4.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p5.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p6.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p7.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p8.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\p9.gif"));


	DeleteFile(TEXT("\\Windows\\stickylaunch.exe"));
	DeleteFile(TEXT("\\Windows\\barney.htp"));




}

void CleanRegistry()
{
	// Delete Registry Keys

	wsprintf(value,TEXT("Software\\Microsoft\\Mobile Channels\\Channels\\Barney\0"));

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE,(LPCTSTR)&value,0,KEY_ALL_ACCESS,&hKey);
	if (hRes==ERROR_SUCCESS) 

	{
	//	MessageBox(NULL,L"Error",L"Barny exists!",MB_OK);
	
		// Delete subkeys

		if (ERROR_SUCCESS!=RegCloseKey(hKey))
		{
			MessageBox(NULL,L"Error",L"Cannot close",MB_OK);
			return;
		}
 
		int plop;
		CString plops;

		plop=RegDeleteKey(HKEY_LOCAL_MACHINE, (LPCTSTR)&value);

		//plop=RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney\0");

		if (ERROR_SUCCESS!=plop)
		{
			plops.Format(L"Error: %d",plop);
			MessageBox(NULL,L"Error",plops,MB_OK);
			return;
		}

		// Urgh. How to delete in the range 0 to X?
		// Let's ASSUME the key is the last in the list

		int i=99;bool carryon=true;
		do
		{
			wsprintf(value,TEXT("Software\\Microsoft\\Active Desktop\\%d\0"),i);
			hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE,(LPCTSTR)&value,0,KEY_ALL_ACCESS,&hKey);
			if ((hRes==ERROR_SUCCESS) || (i<0)) // key exists, so stop..
				carryon=false;
			i--;
		} while (carryon);


		if (i>=0)
		{	
			RegCloseKey(hKey);
			RegDeleteKey(HKEY_LOCAL_MACHINE, (LPCTSTR)&value);
		}
	}
}


void SeekAndDestroy()
{

	CEOID found;

	Looking.propid=MAKELONG(CEVT_LPWSTR,0x42);
	Looking.val.lpwstr=filename;
	Looking.wLenData=0;
	Looking.wFlags=0;

	found=CeSeekDatabase(dh,CEDB_SEEK_VALUEFIRSTEQUAL,(int)&Looking,&dwIndex);
	if (found!=0)
	{
		// Found so delete

		//MessageBox(NULL,filename,L"Found Database",MB_OK);
		CeDeleteRecord(dh,found);
	}
	//else
	//	MessageBox(NULL,filename,L"Not found",MB_OK);

}


void CleanDatabase()
{

	// Clean out Database

	dh=CeOpenDatabase(&did,TEXT("AatpCache"),MAKELONG(CEVT_LPWSTR,0x42),0/*CEDB_AUTOINCREMENT*/,NULL);

	if (dh==INVALID_HANDLE_VALUE)
	{

	// not open
		MessageBox(NULL,L"Open Failure",L"Database",MB_OK);
	}
	else
	{

		// Go to start of database
		CeSeekDatabase(dh,CEDB_SEEK_BEGINNING,0,&dwIndex);

		
		// Start Looking

		wsprintf(filename,TEXT("but1.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but2.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but3.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but4.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but5.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but6.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but7.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but8.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but9.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userA.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userB.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userC.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userD.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butF.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butV.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butP.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butM.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butT.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butX.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butH.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butS.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p1.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p2.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p3.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p4.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p5.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p6.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p7.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p8.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("p9.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.mcs\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.cdf\0"));
		SeekAndDestroy(); 
}

	CloseHandle(dh);

}