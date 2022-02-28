/*
*                 demo
*
*/

#include <windows.h>
#include "resource.h"

HINSTANCE globalinstance;


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR szCmdLine, int iCmdShow)
{
 
	// Load the file to get the four user buttons


	globalinstance=hInstance;


	// Launch the correct application!

	PROCESS_INFORMATION pi;
	int rc=0;
	TCHAR scCmdLine[64];

	


	switch (szCmdLine[0])
		{
		case '1':rc=CreateProcess(L"addrbook.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 
		case '2':rc=CreateProcess(L"calc.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
		case '3':rc=CreateProcess(L"calendar.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
		case '4':rc=CreateProcess(L"notetake.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 
		default:break;
	}

	if (rc)
	{
		CloseHandle (pi.hThread);
		CloseHandle (pi.hProcess);
	}


	
	
	return 0;
	
}