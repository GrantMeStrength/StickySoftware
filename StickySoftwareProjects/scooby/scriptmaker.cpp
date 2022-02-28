/*
	Code for creating the script,
	WHich is actually some code which
	creates an HTML file.

	Accesses the Contacts Database to
	trigger a refresh, which - excuse
	the language - is fucking clever.

	25th November 1998

	v1.0

	Waiting to be unleashed on an 
	unknowing world.

	10th March

	v1.1

	Wow, it's taken this long to get it working.
	Extra features will poke details into Registry,
	Object Store, and copy files from Windows/ to
	Windows/Temp...

  
	23rd

	First bug report :-(

	Hangs. Probably when putting together list of files,
	probably when there are quite a few..



*/


#include "stdafx.h"
#include "addrstor.h"

extern bool settings[16];
extern CString userprogname[4];
extern int buttons[8];

#define GRAPHIC 0
#define TASKS 1
#define VOICE 2
#define CHANNELS 3
#define NOTES 4
#define INBOX 5
#define CALCULATOR 6
#define CONTACTS 7
#define CALENDAR 8
#define USER1 9
#define USER2 10
#define USER3 11
#define USER4 12
#define DATE 13
#define UTILITIES 14
#define PILOT 15

int a=2; 

extern CString trim (CString name);


void MoveFiles()
{
	MoveFile(TEXT("\\Windows\\but1.gif"),TEXT("\\Windows\\Temporary Internet Files\\but1.gif"));
	MoveFile(TEXT("\\Windows\\but2.gif"),TEXT("\\Windows\\Temporary Internet Files\\but2.gif"));
	MoveFile(TEXT("\\Windows\\but3.gif"),TEXT("\\Windows\\Temporary Internet Files\\but3.gif"));
	MoveFile(TEXT("\\Windows\\but4.gif"),TEXT("\\Windows\\Temporary Internet Files\\but4.gif"));
	MoveFile(TEXT("\\Windows\\but5.gif"),TEXT("\\Windows\\Temporary Internet Files\\but5.gif"));
	MoveFile(TEXT("\\Windows\\but6.gif"),TEXT("\\Windows\\Temporary Internet Files\\but6.gif"));
	MoveFile(TEXT("\\Windows\\but7.gif"),TEXT("\\Windows\\Temporary Internet Files\\but7.gif"));
	MoveFile(TEXT("\\Windows\\but8.gif"),TEXT("\\Windows\\Temporary Internet Files\\but8.gif"));
	MoveFile(TEXT("\\Windows\\but9.gif"),TEXT("\\Windows\\Temporary Internet Files\\but9.gif"));

	MoveFile(TEXT("\\Windows\\butF.gif"),TEXT("\\Windows\\Temporary Internet Files\\butF.gif"));
	MoveFile(TEXT("\\Windows\\butV.gif"),TEXT("\\Windows\\Temporary Internet Files\\butV.gif"));
	MoveFile(TEXT("\\Windows\\butP.gif"),TEXT("\\Windows\\Temporary Internet Files\\butP.gif"));
	MoveFile(TEXT("\\Windows\\butM.gif"),TEXT("\\Windows\\Temporary Internet Files\\butM.gif"));
	MoveFile(TEXT("\\Windows\\butT.gif"),TEXT("\\Windows\\Temporary Internet Files\\butT.gif"));
	MoveFile(TEXT("\\Windows\\butX.gif"),TEXT("\\Windows\\Temporary Internet Files\\butX.gif"));
	MoveFile(TEXT("\\Windows\\butH.gif"),TEXT("\\Windows\\Temporary Internet Files\\butH.gif"));

	/*
	MoveFile(TEXT("\\Windows\\p1.gif"),TEXT("\\Windows\\Temporary Internet Files\\p1.gif"));
	MoveFile(TEXT("\\Windows\\p2.gif"),TEXT("\\Windows\\Temporary Internet Files\\p2.gif"));
	MoveFile(TEXT("\\Windows\\p3.gif"),TEXT("\\Windows\\Temporary Internet Files\\p3.gif"));
	MoveFile(TEXT("\\Windows\\p4.gif"),TEXT("\\Windows\\Temporary Internet Files\\p4.gif"));
	MoveFile(TEXT("\\Windows\\p5.gif"),TEXT("\\Windows\\Temporary Internet Files\\p5.gif"));
	MoveFile(TEXT("\\Windows\\p6.gif"),TEXT("\\Windows\\Temporary Internet Files\\p6.gif"));
	MoveFile(TEXT("\\Windows\\p7.gif"),TEXT("\\Windows\\Temporary Internet Files\\p7.gif"));
	MoveFile(TEXT("\\Windows\\p8.gif"),TEXT("\\Windows\\Temporary Internet Files\\p8.gif"));
	MoveFile(TEXT("\\Windows\\p9.gif"),TEXT("\\Windows\\Temporary Internet Files\\p9.gif"));
	*/

	MoveFile(TEXT("\\Windows\\barney.gif"),TEXT("\\Windows\\Temporary Internet Files\\barney.gif"));
	MoveFile(TEXT("\\Windows\\barney.cdf"),TEXT("\\Windows\\Temporary Internet Files\\barney.cdf"));


}

void WriteToDatabase()
{

	HANDLE dh;
	//DWORD er;
	CEOID did=0;

	dh=CeOpenDatabase(&did,TEXT("AatpCache"),0,CEDB_AUTOINCREMENT,NULL);

	if (dh==INVALID_HANDLE_VALUE)
	{

	// not open
		MessageBox(NULL,L"Open Failure",L"Database",MB_OK);
		/*
		er=GetLastError();
		if (er==ERROR_INVALID_PARAMETER )
			MessageBox(NULL,L"Not found",L"Database",MB_OK);
		if (er==ERROR_FILE_NOT_FOUND)
			MessageBox(NULL,L"Invalid Param",L"Database",MB_OK);
		if (er==ERROR_NOT_ENOUGH_MEMORY)
			MessageBox(NULL,L"NO RAM",L"Database",MB_OK);
		MessageBox(NULL,L"Aliens",L"Database",MB_OK);

			//ERROR_FILE_NOT_FOUND 
		*/
		return;
	}

	
	//	MessageBox(NULL,L"Open OK",L"Database",MB_OK);


	// Add new record to database

	//CEVALUNION 

	
	FILETIME date;
	SYSTEMTIME sysdate;
	CEPROPVAL newobject[8];

	GetSystemTime(&sysdate);
	SystemTimeToFileTime(&sysdate,&date);

	#define CREATEOBJECT newobject[0].propid=MAKELONG(CEVT_LPWSTR,0x41);newobject[0].val.lpwstr=url;newobject[1].propid=MAKELONG(CEVT_LPWSTR,0x42);newobject[1].val.lpwstr=filename;newobject[2].propid=MAKELONG(CEVT_FILETIME,0x43);newobject[2].val.filetime=date;newobject[3].propid=MAKELONG(CEVT_UI4,0x45);newobject[3].val.lVal=0x70000;

	TCHAR url[64];
	TCHAR filename[64];

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but1.gif\0"));
	wsprintf(filename,TEXT("but1.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but2.gif\0"));
	wsprintf(filename,TEXT("but2.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but3.gif\0"));
	wsprintf(filename,TEXT("but3.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but4.gif\0"));
	wsprintf(filename,TEXT("but4.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but5.gif\0"));
	wsprintf(filename,TEXT("but5.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but6.gif\0"));
	wsprintf(filename,TEXT("but6.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but7.gif\0"));
	wsprintf(filename,TEXT("but7.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but8.gif\0"));
	wsprintf(filename,TEXT("but8.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/but9.gif\0"));
	wsprintf(filename,TEXT("but9.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	/*

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p1.gif\0"));
	wsprintf(filename,TEXT("p1.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p2.gif\0"));
	wsprintf(filename,TEXT("p2.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p3.gif\0"));
	wsprintf(filename,TEXT("p3.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p4.gif\0"));
	wsprintf(filename,TEXT("p4.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p5.gif\0"));
	wsprintf(filename,TEXT("p5.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p6.gif\0"));
	wsprintf(filename,TEXT("p6.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p7.gif\0"));
	wsprintf(filename,TEXT("p7.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p8.gif\0"));
	wsprintf(filename,TEXT("p8.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/p9.gif\0"));
	wsprintf(filename,TEXT("p9.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	*/
	
	// User defined buttons 	userA.bmp

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/userA.bmp\0"));
	wsprintf(filename,TEXT("userA.bmp\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/userB.bmp\0"));
	wsprintf(filename,TEXT("userB.bmp\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/userC.bmp\0"));
	wsprintf(filename,TEXT("userC.bmp\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/userD.bmp\0"));
	wsprintf(filename,TEXT("userD.bmp\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);



	// Utilities V, F, M, P, T, X, H

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butP.gif\0"));
	wsprintf(filename,TEXT("butP.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butH.gif\0"));
	wsprintf(filename,TEXT("butH.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butT.gif\0"));
	wsprintf(filename,TEXT("butT.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butM.gif\0"));
	wsprintf(filename,TEXT("butM.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butX.gif\0"));
	wsprintf(filename,TEXT("butX.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butF.gif\0"));
	wsprintf(filename,TEXT("butF.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/butV.gif\0"));
	wsprintf(filename,TEXT("butV.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	// Logo and script

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/barney.gif\0"));
	wsprintf(filename,TEXT("barney.gif\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/barney.cdf\0"));
	wsprintf(filename,TEXT("barney.cdf\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);

	memset(&newobject,0,sizeof(CEPROPVAL)*4);
	wsprintf(url,TEXT("http://-ram-/barney.mcs\0"));
	wsprintf(filename,TEXT("barney.mcs\0"));
	CREATEOBJECT
	CeWriteRecordProps(dh,0,4,newobject);
	

	CloseHandle(dh);

}

void Trigger()
// Trigger refresh by writing to Contacts Database
{
	AddressCard myAC;
	PEGOID myAC_oid;
	int myAC_posIndex;

	if (!OpenAddressBook(HWND_BROADCAST,0)) return;
	
	memset(&myAC,0,sizeof(myAC));
	myAC.pszGivenName=L"DUMMY DUMMY";
	SetMask(&myAC,HHPR_FIRST_LAST_NAME);
	AddAddressCard(&myAC,&myAC_oid,&myAC_posIndex);
	DeleteAddressCard(myAC_oid);
	CloseAddressBook();
}


void PokeRegistry()
{
	bool failure=false;
	HKEY hKey;
	DWORD dwState=1;
	HRESULT hRes;
	TCHAR value[64];
	DWORD dwDisp;


	// Move files anyway, just in case this is an upgrade

	MoveFiles();

	// Test for Barney, if exists return

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney",0,KEY_ALL_ACCESS,&hKey);
	if (hRes==ERROR_SUCCESS) {RegCloseKey(hKey);return;}

	// Now, Barney isn't installed, so continue..

	MessageBox(NULL,L"Welcome to Sticky Buttons!\nAfter running this configuration program, you must go to Settings/Display and switch on Display Active Desktop. Now close this dialog, change settings if required and tap OK.",L"Welcome!",MB_OK);
	

	// Add the Launch Program
	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Components",0,KEY_ALL_ACCESS,&hKey);
	if (hRes==ERROR_SUCCESS)
	{
		RegSetValueEx(hKey,L"stickylaunch.exe",0,REG_DWORD,(LPBYTE)&dwState,sizeof(DWORD));
		RegCloseKey(hKey);
	}
	else
	{
	//	MessageBox(NULL,L"Failure",L"reg1",MB_OK);
		failure=true;
	}


	// Add Mobile Channel part 1
	hRes=RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney",0,NULL,0,KEY_ALL_ACCESS,NULL,&hKey,&dwDisp);
	if (hRes==ERROR_SUCCESS)
	{
		dwState=-1;
		RegSetValueEx(hKey,L"+HomePos",0,REG_DWORD,(LPBYTE)&dwState,sizeof(DWORD));
		dwState=5;
		RegSetValueEx(hKey,L"Barney",0,REG_DWORD,(LPBYTE)&dwState,sizeof(DWORD));

		wsprintf(value,TEXT("MobileDesktopComponent\0"));
		RegSetValueEx(hKey,L"+Usage",0,REG_SZ,(const BYTE *)&value,46);

		wsprintf(value,TEXT("Buttons\0"));
		RegSetValueEx(hKey,L"+Abstract",0,REG_SZ,(const BYTE *)&value,16);
		
		wsprintf(value,TEXT("Buttons\0"));
		RegSetValueEx(hKey,L"+Title",0,REG_SZ,(const BYTE *)&value,16);
	
		wsprintf(value,TEXT("http://-ram-/barney.cdf\0"));
		RegSetValueEx(hKey,L"+CdfUrl",0,REG_SZ,(const BYTE *)&value,48);

		RegCloseKey(hKey);
	}
	else
	{
	//	MessageBox(NULL,L"Failure",L"reg2",MB_OK);
		failure=true;
	}

	// Add Mobile Channel part 2

	// first find next slot, starting at 5
	int i=0;bool carryon=true;
	do
	{
		wsprintf(value,TEXT("Software\\Microsoft\\Active Desktop\\%d\0"),i);
		hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE,(LPCTSTR)&value,0,KEY_ALL_ACCESS,&hKey);
		if (hRes==ERROR_SUCCESS) // key exists, so move on..
			RegCloseKey(hKey);
		else // key doesn't exist, stop and use it!
			carryon=false;
		i++;
	} while (carryon);

	//if (i==0) MessageBox(NULL,L"Failure",L"reg3",MB_OK);

	// second, create keys
	hRes=RegCreateKeyEx(HKEY_LOCAL_MACHINE,(LPCTSTR)&value,0,NULL,0,KEY_ALL_ACCESS,NULL,&hKey,&dwDisp);
	if (hRes==ERROR_SUCCESS)
	{
		dwState=1;
		RegSetValueEx(hKey,L"OnDesktop",0,REG_DWORD,(LPBYTE)&dwState,sizeof(DWORD));
		
		wsprintf(value,TEXT("mctp://Barney\0"));
		RegSetValueEx(hKey,L"URL",0,REG_SZ,(const BYTE *)&value,28);

		wsprintf(value,TEXT("Sticky Buttons\0"));
		RegSetValueEx(hKey,L"Title",0,REG_SZ,(const BYTE *)&value,30);
		
		RegCloseKey(hKey);
	}
	else
	{
	//	MessageBox(NULL,L"Failure",L"reg3",MB_OK);
		failure=true;
	}


	//if (failure==true) StripRegistry();


	WriteToDatabase();
	
}


CString l[200];

void LoadScript()
{

	// Open file, if present, to set initial
	// values

	TCHAR rawkey[130];
	HANDLE hFile;
	DWORD   dwNumberOfBytesRead;
	int p;  

	hFile = CreateFile(	L"\\Windows\\Temporary Internet Files\\barney.mcs", GENERIC_READ,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL );
	
	if ( hFile!=INVALID_HANDLE_VALUE )
    {	// It's there, so open it.
		
		ReadFile(hFile,&rawkey[0],2,&dwNumberOfBytesRead,NULL); // unicode header
		ReadFile(hFile,&rawkey[0],44,&dwNumberOfBytesRead,NULL);

		if (rawkey[5]=='G') settings[GRAPHIC]=true; else settings[GRAPHIC]=false;
		if (rawkey[6]=='P') settings[DATE]=true; else settings[DATE]=false;
		if (rawkey[7]=='C') settings[CONTACTS]=true; else settings[CONTACTS]=false;
		if (rawkey[8]=='A') settings[CALCULATOR]=true; else settings[CALCULATOR]=false;
		if (rawkey[9]=='D') settings[CALENDAR]=true; else settings[CALENDAR]=false;
		if (rawkey[10]=='N') settings[NOTES]=true; else settings[NOTES]=false;
		if (rawkey[11]=='I') settings[INBOX]=true; else settings[INBOX]=false;
		if (rawkey[12]=='T') settings[TASKS]=true; else settings[TASKS]=false;
		if (rawkey[13]=='V') settings[VOICE]=true; else settings[VOICE]=false;
		if (rawkey[14]=='W') settings[CHANNELS]=true; else settings[CHANNELS]=false;
		if (rawkey[15]=='X') settings[USER1]=true; else settings[USER1]=false;
		if (rawkey[16]=='X') settings[USER2]=true; else settings[USER2]=false;
		if (rawkey[17]=='X') settings[USER3]=true; else settings[USER3]=false;
		if (rawkey[18]=='X') settings[USER4]=true; else settings[USER4]=false;
		if (rawkey[19]=='I') settings[PILOT]=true; else settings[PILOT]=false;
		if (rawkey[20]=='U') settings[UTILITIES]=true; else settings[UTILITIES]=false;

		ReadFile(hFile,&rawkey[0],20,&dwNumberOfBytesRead,NULL);
		for (p=0;p<4;p++)
		{
			ReadFile(hFile,&rawkey[0],128,&dwNumberOfBytesRead,NULL);
			for (int q=0;q<64;q++)//=2)
				userprogname[p]+=rawkey[q];
			userprogname[p].TrimRight();
			if (userprogname[p].GetAt(userprogname[p].GetLength()-1)=='!') 
				userprogname[p]=userprogname[p].Left(userprogname[p].GetLength()-1);
			//userprogname[p].TrimRight();
			ReadFile(hFile,&rawkey[0],2,&dwNumberOfBytesRead,NULL);

			if (settings[USER1+p]==true) buttons[p]=1; else {buttons[p]=0;userprogname[p]="\\Windows\\Solitaire.lnk";}

		}

		CloseHandle(hFile);
	}
	else
	{
		for (p=0;p<4;p++) {userprogname[p]="World Clock.lnk";buttons[p]=0;}
		settings[GRAPHIC]=true;
		settings[CONTACTS]=true;
		settings[CALCULATOR]=true;
		settings[CALENDAR]=true;
		settings[VOICE]=true;
		settings[NOTES]=true;
		settings[INBOX]=true;
		settings[TASKS]=true;
		settings[CHANNELS]=true;
		settings[USER1]=false;
		settings[USER2]=false;
		settings[USER3]=false;
		settings[USER4]=false;
		settings[UTILITIES]=true;
		settings[DATE]=true;
		settings[PILOT]=false;
	}
}


void SaveScript()
{

	// 1. Open file
	// 2. Write l[0]..l[a-1]
	// 3. Close file

	int b=0;
	HANDLE hFile;
	char q[2];
	q[0]=char(255);
	q[1]=char(254);

	
    DWORD   dwNumberOfBytesRote;
    hFile = CreateFile(	L"\\Windows\\Temporary Internet Files\\barney.mcs", GENERIC_WRITE,0,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL );
    if ( hFile )
    {
	
		WriteFile(hFile,&q[0],2,&dwNumberOfBytesRote,NULL);

	
		for (b=0;b<a;b++)
		{
			/*
			l[b]+="\n";
			char *pbuff = new char[l[b].GetLength()];
			dwToRite=wcstombs(pbuff,l[b],l[b].GetLength());
			WriteFile(hFile,pbuff,dwToRite,&dwNumberOfBytesRote,NULL);
			delete [] pbuff;
			*/

			l[b]+="\n";
			WriteFile(hFile,l[b],(2*l[b].GetLength()),&dwNumberOfBytesRote,NULL);


			
		}
		
		
		
		CloseHandle(hFile);
	}

}



void MakeScriptStandard()
{

	CString key="<!-- ";
	CString proglist="<!-- ";

l[a++]=L"<%\r";
l[a++]=L"Set MC = Server.CreateObject(\"MobileChannels.Utilities\")\r";
l[a++]=L"Q = Chr(34)\r";
l[a++]=L"%>\r";

l[a++]="<HTML>\r";
l[a++]=L"<%\r";


l[a++]="CurTime=Now\r";
l[a++]="Hours=Mid(CurTime,12,2)\r";
l[a++]="Mins=Mid(CurTime,15,2)\r";
l[a++]="Secs=Mid(CurTime,18,2)\r";
l[a++]="Secs=Secs+(Mins*60)+(Hours*3600)\r";
l[a++]="Secs=86400-Secs\r";
/*
l[a++]="Day= Mid(CurTime,21,3)\r";
l[a++]="FullDay=\"\"\r";
//l[a++]="FullDay=Day & \", \"\r";
l[a++]="if (Day=\"Mon\") then FullDay=\"Monday, \" end if\r";
l[a++]="if (Day=\"Tue\") then FullDay=\"Tuesday, \" end if\r";
l[a++]="if (Day=\"Wed\") then FullDay=\"Wednesday, \" end if\r";
l[a++]="if (Day=\"Thu\") then FullDay=\"Thursday, \" end if\r";
l[a++]="if (Day=\"Fri\") then FullDay=\"Friday, \" end if\r";
l[a++]="if (Day=\"Sat\") then FullDay=\"Saturday, \" end if\r";
l[a++]="if (Day=\"Sun\") then FullDay=\"Sunday, \" end if\r";

*/

l[a++]="Database = MC.ReadRegistry(\"HKEY_LOCAL_MACHINE\", \"Explorer\\\\Database\", \"ContactsDatabase\")\r";
l[a++]="Refresh	= \";URL=mctp://barney\"\r";
l[a++]="Notify = Q & \"DBUPDATE=\" & Database & Refresh & Q\r";
l[a++]="Response.Write(\"<META HTTP-EQUIV=NOTIFY content=\" & Notify & \">\")\r";


l[a++]="Refresh	= Q & Secs & \";URL=mctp://barney\" & Q\r";
l[a++]="Response.Write(\"<META HTTP-EQUIV=REFRESH content=\" & Refresh & \">\")\r";


l[a++]=L"%>\r";

l[a++]="<HEAD>\r";
l[a++]="<META HTTP-EQUIV=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\r";
l[a++]="<TITLE></TITLE>\r";
l[a++]="</HEAD>\r";
l[a++]="<BODY>\r";



l[a++]="<%\r";

l[a++]="Response.Write(\"<META HTTP-EQUIV=AUTOSIZE CONTENT=OFF>\")\r";

//	' Display graphic  

if (settings[GRAPHIC])
{
//	m[mc++]="Yes";
	key+="G";
	l[a++]="Response.Write(\"<center>\")\r"; 
    l[a++]="Response.Write(\"<IMG SRC=\" & Q & \"http://-ram-/
		\" & Q & \" HEIGHT=54 WIDTH=200>\")\r";
	l[a++]="Response.Write(\"</center>\")\r";
	l[a++]="Response.Write(\"<br>\")\r";
}
else
{
//	m[mc++]="No";
	key+="*";
}

// Display Date

if (settings[DATE])
{
	key+="P";

  //  l[a++]="Response.Write(\"<CENTER><B>\" & FullDay & LocDate & \"</B></CENTER><BR>\")\r";
	l[a++]="Response.Write(\"<CENTER><B>\" & LocDate & \"</B></CENTER><BR>\")\r";

}
else
	key+="*";



// Beta message

//	l[a++]="Response.Write(\"<center>BETA 10 NOT FOR REDISTRIBUTION\")\r"; 
//	l[a++]="Response.Write(\"</center>\")\r";
//	l[a++]="Response.Write(\"<br>\")\r";

	l[a++]="Response.Write(\"<center>\")\r"; 

//	' Display Buttons

if (settings[CONTACTS])
{
//	m[mc++]="Yes";
	key+="C";
		l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?1\" & Q & \"><img src=\" & Q & \"http://-ram-/but1.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
		//row++;

}
else
{
//	m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[CALCULATOR])
{
//	m[mc++]="Yes";
	key+="A";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?2\" & Q & \"><img src=\" & Q & \"http://-ram-/but2.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
//	m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[CALENDAR])
{
	//m[mc++]="Yes";
	key+="D";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?3\" & Q & \"><img src=\" & Q & \"http://-ram-/but3.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[NOTES])
{
	//m[mc++]="Yes";
	key+="N";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?4\" & Q & \"><img src=\" & Q & \"http://-ram-/but4.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}

if (settings[INBOX])
{
	//m[mc++]="Yes";
	key+="I";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?5\" & Q & \"><img src=\" & Q & \"http://-ram-/but5.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[TASKS])
{
	//m[mc++]="Yes";
	key+="T";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?6\" & Q & \"><img src=\" & Q & \"http://-ram-/but6.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[VOICE])
{
	//m[mc++]="Yes";
	key+="V";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?7\" & Q & \"><img src=\" & Q & \"http://-ram-/but7.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}

//if (row==4) TakeABreak();

if (settings[CHANNELS])
{
	//m[mc++]="Yes";
	key+="W";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?8\" & Q & \"><img src=\" & Q & \"http://-ram-/but8.gif\" & Q & \" HEIGHT=50 WIDTH=50></A>\")\r";
	//row++;
}
else
{
	//m[mc++]="No";
	key+="*";
}


l[a++]="Response.Write(\"<table border=\" & Q & \"0\" & Q & \">\")\r";

CString st2,st3;
int sc; 

l[a++]="Response.Write(\"<tr>\")\r";


	for (int r=0;r<4;r++)
	{
		st2="";

		if (settings[PILOT])
			st3.Format(L"user%C.bmp",r+65);
		else
			st3.Format(L"but9.gif");


		if (settings[USER1+r])
		{
			key+="X";

		
		
			for (sc=0;sc<(userprogname[r].GetLength());sc++)
			{
				st2+=userprogname[r].GetAt(sc);
				if (userprogname[r].GetAt(sc)=='\\') st2+="\\";
			}

			l[a++]="Response.Write(\"<td align=\" & Q & \"center\" & Q & \"><A HREF=\" & Q & \"mcexe://stickylaunch.exe?"+st2+"\" & Q & \"><img src=\" & Q & \"http://-ram-/"+st3+"\" & Q & \" HEIGHT=32 WIDTH=32></A></td>\")\r";
		}
		else key+="*";
	}

	
	if (settings[PILOT])
		key+="I";
	else
		key+="-"; // i.e. no Pilot mode

l[a++]="Response.Write(\"</tr><tr>\")\r";

CString name;


for (int m=0;m<4;m++)
{
	if (settings[USER1+m])
	{
		name=userprogname[m];
		name.TrimRight();
		name=trim(name);
		l[a++]="Response.Write(\"<td align=\" & Q & \"center\" & Q & \">"+name+"</td>\")\r";
	}
}

l[a++]="Response.Write(\"</tr></table>\")\r";

l[a++]="Response.Write(\"</center>\")\r";


// Utilities

if (settings[UTILITIES])
{
	key+="U";
	l[a++]="Response.Write(\"<hr><center>\")\r"; 

l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?F\" & Q & \"> <img src=\" & Q & \"http://-ram-/butF.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?V\" & Q & \"> <img src=\" & Q & \"http://-ram-/butV.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?P\" & Q & \"> <img src=\" & Q & \"http://-ram-/butP.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?M\" & Q & \"> <img src=\" & Q & \"http://-ram-/butM.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?T\" & Q & \"> <img src=\" & Q & \"http://-ram-/butT.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?X\" & Q & \"> <img src=\" & Q & \"http://-ram-/butX.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?H\" & Q & \"> <img src=\" & Q & \"http://-ram-/butH.gif\" & Q & \" HEIGHT=22 WIDTH=26></A>\")\r";

	l[a++]="Response.Write(\"</center>\")\r";
	l[a++]="Response.Write(\"<br>\")\r";
}
else
	key+="+";


l[a++]="%>\r";
l[a++]="</BODY></HTML>\r";
l[a++]="\r";

key+=" -->\r";
l[0]=key;



	for (int j=0;j<4;j++)
	{
		userprogname[j]+="!";
		while(userprogname[j].GetLength()<64) userprogname[j]+=" ";
		proglist+=userprogname[j]+" ";
	}

	proglist+="-->\r";

l[1]=proglist;


}

/*
void MakeScriptPilot()
{

	CString key="<!-- ";
	CString proglist="<!-- ";

l[a++]=L"<%\r";
l[a++]=L"Set MC = Server.CreateObject(\"MobileChannels.Utilities\")\r";
l[a++]=L"Q = Chr(34)\r";
l[a++]=L"%>\r";

l[a++]="<HTML>\r";
l[a++]=L"<%\r";


l[a++]="Database = MC.ReadRegistry(\"HKEY_LOCAL_MACHINE\", \"Explorer\\\\Database\", \"ContactsDatabase\")\r";
l[a++]="Refresh	= \";URL=mctp://barney\"\r";
l[a++]="Notify = Q & \"DBUPDATE=\" & Database & Refresh & Q\r";
l[a++]="Response.Write(\"<META HTTP-EQUIV=NOTIFY content=\" & Notify & \">\")\r";


l[a++]=L"%>\r";

l[a++]="<HEAD>\r";
l[a++]="<META HTTP-EQUIV=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\r";
l[a++]="<TITLE></TITLE>\r";
l[a++]="</HEAD>\r";
l[a++]="<BODY>\r";


l[a++]="<%\r";

l[a++]="Response.Write(\"<META HTTP-EQUIV=AUTOSIZE CONTENT=OFF>\")\r";


	key+="*"; // graphic
	key+="*"; // date
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*";
	key+="*"; // utilities
	key+="I"; // Pilot mode!


//	Pilot Buttons

l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?1\" & Q & \"><img src=\" & Q & \"http://-ram-/p1.gif\" & Q & \" HEIGHT=74 WIDTH=88></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?1\" & Q & \"><img src=\" & Q & \"http://-ram-/p2.gif\" & Q & \" HEIGHT=74 WIDTH=66></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?4\" & Q & \"><img src=\" & Q & \"http://-ram-/p3.gif\" & Q & \" HEIGHT=74 WIDTH=86></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?5\" & Q & \"><img src=\" & Q & \"http://-ram-/p4.gif\" & Q & \" HEIGHT=63 WIDTH=83></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?6\" & Q & \"><img src=\" & Q & \"http://-ram-/p5.gif\" & Q & \" HEIGHT=63 WIDTH=66></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?3\" & Q & \"><img src=\" & Q & \"http://-ram-/p6.gif\" & Q & \" HEIGHT=63 WIDTH=91></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?7\" & Q & \"><img src=\" & Q & \"http://-ram-/p7.gif\" & Q & \" HEIGHT=72 WIDTH=75></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?8\" & Q & \"><img src=\" & Q & \"http://-ram-/p8.gif\" & Q & \" HEIGHT=72 WIDTH=86></A>\")\r";
l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?F\" & Q & \"><img src=\" & Q & \"http://-ram-/p9.gif\" & Q & \" HEIGHT=72 WIDTH=79></A>\")\r";

l[a++]="%>\r";
l[a++]="</BODY>\r";
l[a++]="\r";

key+=" -->\r";
l[0]=key;



	for (int j=0;j<4;j++)
	{
		userprogname[j]+="!";
		while(userprogname[j].GetLength()<64) userprogname[j]+=" ";
		proglist+=userprogname[j]+" ";
	}

	proglist+="-->\r";

l[1]=proglist;

}
  
*/
void MakeScript()
{
//	if (settings[PILOT])
//		MakeScriptPilot();
//	else
		MakeScriptStandard();
}
		