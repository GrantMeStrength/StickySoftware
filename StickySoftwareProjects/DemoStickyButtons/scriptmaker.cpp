/*
	demo code

*/


#include "stdafx.h"
//#include "addrstor.h"

int a=2; 


void MoveFiles()
{
	MoveFile(TEXT("\\Windows\\but1.gif"),TEXT("\\Windows\\Temporary Internet Files\\but1.gif"));
	MoveFile(TEXT("\\Windows\\but2.gif"),TEXT("\\Windows\\Temporary Internet Files\\but2.gif"));
	MoveFile(TEXT("\\Windows\\but3.gif"),TEXT("\\Windows\\Temporary Internet Files\\but3.gif"));
	MoveFile(TEXT("\\Windows\\but4.gif"),TEXT("\\Windows\\Temporary Internet Files\\but4.gif"));

	MoveFile(TEXT("\\Windows\\barney.gif"),TEXT("\\Windows\\Temporary Internet Files\\barney.gif"));
	MoveFile(TEXT("\\Windows\\barney.cdf"),TEXT("\\Windows\\Temporary Internet Files\\barney.cdf"));


}

void WriteToDatabase()
{

	HANDLE dh;
	CEOID did=0;

	dh=CeOpenDatabase(&did,TEXT("AatpCache"),0,CEDB_AUTOINCREMENT,NULL);

	if (dh==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,L"Open Failure: no AatpCache.",L"Database",MB_OK);
		return;
	}

	
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



void PokeRegistry()
{
	bool failure=false;
	HKEY hKey;
	DWORD dwState=1;
	HRESULT hRes;
	TCHAR value[64];
	DWORD dwDisp;

	// Test for Barney, if exists return

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney",0,KEY_ALL_ACCESS,&hKey);
	if (hRes==ERROR_SUCCESS) return;

	// Now, Barney isn't installed, so continue..


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
		dwState=0;
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
	MoveFiles();
}


CString l[200];



void SaveScript()
{


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
			l[b]+="\n";
			WriteFile(hFile,l[b],(2*l[b].GetLength()),&dwNumberOfBytesRote,NULL);
		
		}
						
		CloseHandle(hFile);
	}

}



void MakeScript()
{


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
l[a++]="Day= Mid(CurTime,21,3)\r";
l[a++]="FullDay=Day & \", \"\r";
l[a++]="if (Day=\"Mon\") then FullDay=\"Monday, \" end if\r";
l[a++]="if (Day=\"Tue\") then FullDay=\"Tuesday, \" end if\r";
l[a++]="if (Day=\"Wed\") then FullDay=\"Wednesday, \" end if\r";
l[a++]="if (Day=\"Thu\") then FullDay=\"Thursday, \" end if\r";
l[a++]="if (Day=\"Fri\") then FullDay=\"Friday, \" end if\r";
l[a++]="if (Day=\"Sat\") then FullDay=\"Saturday, \" end if\r";
l[a++]="if (Day=\"Sun\") then FullDay=\"Sunday, \" end if\r";



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


//	' Display graphic  


	l[a++]="Response.Write(\"<center>\")\r"; 
    l[a++]="Response.Write(\"<IMG SRC=http://-ram-/barney.gif>\")\r";
	l[a++]="Response.Write(\"</center>\")\r";
	l[a++]="Response.Write(\"<br>\")\r";


// Display Date


    l[a++]="Response.Write(\"<CENTER><B>\" & FullDay & LocDate & \"</B></CENTER><BR>\")\r";



	l[a++]="Response.Write(\"<center>\")\r"; 

//	' Display Buttons


	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?1\" & Q & \"><img src=\" & Q & \"http://-ram-/but1.gif\" & Q & \"></A>\")\r";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?2\" & Q & \"><img src=\" & Q & \"http://-ram-/but2.gif\" & Q & \"></A>\")\r";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?3\" & Q & \"><img src=\" & Q & \"http://-ram-/but3.gif\" & Q & \"></A>\")\r";
	l[a++]="Response.Write(\"<A HREF=\" & Q & \"mcexe://stickylaunch.exe?4\" & Q & \"><img src=\" & Q & \"http://-ram-/but4.gif\" & Q & \"></A>\")\r";
	

l[a++]="%>\r";
l[a++]="</BODY>\r";
l[a++]="\r";

}
  