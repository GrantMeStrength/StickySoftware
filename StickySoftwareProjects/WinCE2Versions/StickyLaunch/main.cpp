/*
*                  Sticky Launch Plus

			Launch Utility for StickyButtons

		         	"I am a HERO!"

*
*/

#include <windows.h>
#include "resource.h"

HINSTANCE globalinstance;

PROCESS_INFORMATION pi;
int rc=0;
TCHAR scCmdLine[64];

extern void KillAllButDesktop();

void ControlMemory()
{
	rc=CreateProcess(L"ctlpnl.exe",L"system.cpl,1,1",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
	rc=CreateProcess(L"ctlpnl.exe",L"systemg.cpl,0,1",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
}


void ControlPower()
{
	rc=CreateProcess(L"ctlpnl.exe",L"power.cpl",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
	rc=CreateProcess(L"ctlpnl.exe",L"powerg.cpl",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
}

void ControlVolume()
{
	rc=CreateProcess(L"ctlpnl.exe",L"sounds.cpl",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
	rc=CreateProcess(L"ctlpnl.exe",L"soundsg.cpl",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
}

void ControlTasks()
{
	rc=CreateProcess(L"ctlpnl.exe",L"system.cpl,1,2",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
	rc=CreateProcess(L"ctlpnl.exe",L"systemg.cpl,0,2",NULL,NULL,false,0,NULL,NULL,NULL,&pi);
}


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR szCmdLine, int iCmdShow)
{
 
	// Load the file to get the four user buttons

	globalinstance=hInstance;

	// Launch the correct application!


	
	TCHAR DecodeLink[256];
	TCHAR test[256];
	//lstrcpy (scCmdLine, TEXT(""));
	int i,j;

	//MessageBox(NULL,(LPCTSTR)&program[0],L"Program String",MB_OK);
	//MessageBox(NULL,(L"plop"),(LPCTSTR)&program[0],MB_OK);

	for (i=0;i<256;i++) test[i]='\0';
	lstrcpy (test, &szCmdLine[0]);

	//MessageBox(NULL,(LPCTSTR)&test,L"Program String",MB_OK);
	//for (i=0;i<256;i++) if (szCmdLine[i]=='_') szCmdLine[i]='\\';
	//MessageBox(NULL,(LPCTSTR)&szCmdLine[0],L"Stripped String",MB_OK);


	if (SHGetShortcutTarget((LPCTSTR)&test,DecodeLink,sizeof(DecodeLink)))
		 {
		//	 MessageBox(NULL,(LPCTSTR)&szCmdLine[0],(LPCTSTR)DecodeLink,MB_OK);
		for (j=0,i=0;i<256;i++) if (DecodeLink[i]!='\"') test[j++]=DecodeLink[i];
		//	MessageBox(NULL,(LPCTSTR)&szCmdLine[0],(LPCTSTR)DecodeLink,MB_OK);
			 rc=CreateProcess(test,NULL,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
		 }
	else 
		
		//MessageBox(NULL,(LPCTSTR)&szCmdLine[0],L"SmegHead",MB_OK);

	{

			
		switch (szCmdLine[0])
			{
			case '1':rc=CreateProcess(L"addrbook.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 
			case '2':rc=CreateProcess(L"calc.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case '3':rc=CreateProcess(L"calendar.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case '4':rc=CreateProcess(L"notetake.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 
			case '5':rc=CreateProcess(L"pmail.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case '6':rc=CreateProcess(L"tasks.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case '7':rc=CreateProcess(L"voicstub.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 
			case '8':rc=CreateProcess(L"aaview.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break; 

			// Extra commands

			case 'M':ControlMemory();break;
			case 'P':ControlPower();break;
			case 'V':ControlVolume();break;
			case 'T':ControlTasks();break;
			case 'F':rc=CreateProcess(L"shfind.exe",L"",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case 'H':rc=CreateProcess(L"peghelp.exe",L"barney.htp",NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
			case 'X':KillAllButDesktop();break;
			}
			
			

		if (rc)
		{
			CloseHandle (pi.hThread);
			CloseHandle (pi.hProcess);
		}

	}

	
	
	return 0;
	
}