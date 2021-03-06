
/*
*
*                  Flipper Pro v1.3
*
*  Task Management utility for the Palmsize PC
*               (C) 1998,99 John Kennedy
*
*               25th November 1998
*
*    1.2 - 29th, avoid killing Properties applets
*	 1.3 - 7/2/99, no more tap-slide & memory
*    2.0 - 16th March. New dialog, new buttons, sound, autokill!
*	 2.1 - added code to launch apps on Wyvern machines too

*/








#include <windows.h>
#include "resource.h"

extern BOOL CALLBACK TaskDialog(HWND hwnd, UINT wMsg, WPARAM wParam, LPARAM lParam);

bool kill=false;

HANDLE hThread1;
DWORD dwThread1ID=0;
INT nParamater=5;
bool sound=false;
bool autokill=false;

//DWORD WINAPI Thread2(PVOID pArg) 
//{

	//int nParam=(int) pArg;


	// Plan is to make thread wait for a Power On
	// message, then do something. This must be in
	// an endless loop *gulp* so the wait better be
	// right

//	HANDLE hFile;
//	hFile=CreateFile(L"COM2:",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
//	if (!hFile) MessageBox(NULL,L"Error!",L"I'm an error",MB_OK);

//	int x;

//	SetCommMask(hFile,EV_POWER);

//	COMMTIMEOUTS comset;

//	comset.ReadIntervalTimeout=0;
//	comset.ReadTotalTimeoutMultiplier=0;
//	comset.ReadTotalTimeoutConstant=0;
//	comset.WriteTotalTimeoutMultiplier=0;
//	comset.WriteTotalTimeoutConstant=0;
//
//	x=SetCommTimeouts(hFile,&comset);
	
//	if (x==0) MessageBox(NULL,L"SetCom",L"SetCom",MB_OK);

//	
//	WaitCommEvent(hFile,(LPDWORD) EV_POWER,NULL);
//	CloseHandle(hFile);


//	MessageBox(NULL,L"Hello!",L"I'm a thread",MB_OK);
//
//	return 0x15;
//}





HWND next=NULL,find=NULL,top=NULL;
HINSTANCE globalinstance;
// HWND globalwindow;

int click=0;

HWND tasks[20];
char text[20][64];
int textcounter=0;

HMENU taskmenu;

bool once=false;
bool timer=false;


void KillMungoKill(HWND hWnd)
{

	TCHAR name[64];
	TCHAR prop[]=L"Properties";
	TCHAR prog[]=L"Remove Programs";

	LPTSTR pointer=(LPTSTR)&name[0];
	GetWindowText(hWnd,pointer,32);

	if ((wcsstr(name,prop)==NULL) && (wcsstr(name,prog)==NULL))
	{
	//	MessageBox(hWnd,(LPTSTR)name,L"Can kill",MB_OK);
		SendMessage(hWnd,WM_CLOSE,0,0);
		sndPlaySound(L"Close", SND_FILENAME|SND_ASYNC);
	}
//	else
//		MessageBox(hWnd,TEXT("Can't kill Properties!"),TEXT("FP"),MB_OK);
}


 





BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{

	next=hwnd;
	long status;
	int length;
	char name[64];
	LPTSTR pointer=(LPTSTR)&name[0];

	length=GetWindowTextLength(next); // length is not uni, i.e. at least half the true size
	status=GetWindowLong(next,GWL_STYLE);

	if ((status&WS_EX_INK)&&(length!=0))
	{
		if (top==NULL) top=next;	// top is the first window now
		find=next;

		//for (int j=0;j<64;j++) name[j]='\0';

		GetWindowText(next,pointer,32);
		tasks[textcounter]=next;
	
		for (int i=0;i<((length*2)+2);i++)
			text[textcounter][i]=name[i];

		textcounter++;
			if (textcounter>20) textcounter=20;
	}
	return true;
}

void OpenPopUpMenu(HWND hwnd)
{
	// Open pop-up menu!

	int i;

	// test to see if we can display memory

/*
	
*/



	once=true;
	textcounter=0;
	top=NULL;find=NULL;
	EnumWindows(EnumWindowsProc,NULL);
	
	taskmenu=CreatePopupMenu();
	for (i=0;i<textcounter;i++)
			AppendMenu(taskmenu,MF_STRING|MF_ENABLED,i,(const unsigned short *)&text[i]);
	AppendMenu(taskmenu,MF_SEPARATOR,0,TEXT("dummy"));
	//AppendMenu(taskmenu,MF_STRING|MF_GRAYED,104,(const unsigned short *)report1);
	//if (card==true) AppendMenu(taskmenu,MF_STRING|MF_GRAYED,105,(const unsigned short *)report2);
	//AppendMenu(taskmenu,MF_SEPARATOR,0,TEXT("dummy"));
	AppendMenu(taskmenu,MF_STRING|MF_ENABLED,101,TEXT("Kill current task"));
	AppendMenu(taskmenu,MF_STRING|MF_ENABLED,102,TEXT("Kill all but current"));
	AppendMenu(taskmenu,MF_ENABLED|MF_STRING,103,TEXT("Options..."));
	AppendMenu(taskmenu,MF_ENABLED|MF_STRING,104,TEXT("Run..."));

	/*
	if (sound)
		AppendMenu(taskmenu,MF_CHECKED|MF_STRING|MF_ENABLED,103,TEXT("Startup Sound"));
	else
		AppendMenu(taskmenu,MF_STRING|MF_ENABLED,103,TEXT("Startup Sound"));


	if (autokill)
		AppendMenu(taskmenu,MF_CHECKED|MF_STRING|MF_ENABLED,104,TEXT("Autokill"));
	else
		AppendMenu(taskmenu,MF_STRING|MF_ENABLED,104,TEXT("Autokill"));
	*/


//	AppendMenu(taskmenu,MF_STRING|MF_ENABLED,105,TEXT("Quit Flipper"));
	//AppendMenu(taskmenu,MF_STRING|MF_ENABLED,106,TEXT("pop 1"));
	i=TrackPopupMenu(taskmenu,TPM_NONOTIFY|TPM_RETURNCMD|TPM_LEFTALIGN|TPM_BOTTOMALIGN,240,294,0,hwnd,NULL);
	DestroyMenu(taskmenu);
	once=false;
	if ((i>=0) && (i<100)) // Jump to new window
	{
		if (tasks[i]!=NULL) SetForegroundWindow(tasks[i]);
	}

	if (i==101) // Kill current application
	{
		if (top!=NULL) 
		{
			 if (top!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
					 KillMungoKill(top);
			 else
			{
				 // Can't shut desktop, that's rude!
				SetForegroundWindow(top);
				sndPlaySound(L"Exclam", SND_FILENAME|SND_ASYNC);
			}
		}
	}

	if (i==102) // Kill all but current...
	
		for (i=1;i<textcounter;i++)
			if (tasks[i]!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
				KillMungoKill(tasks[i]);
		// make sure to pop desktop forward
	
	

	if (i==103) // toggle sound on and off
	{
		DialogBox(globalinstance,MAKEINTRESOURCE(IDD_TASK_DIALOG),NULL,TaskDialog);
		//		sound=!sound;
		
		if (autokill) // Start timer
			SetTimer(hwnd,2,3*60*1000,NULL);
		else // Killtimer
			KillTimer(hwnd,2);

		if (kill) KillMungoKill(hwnd);
	}

	if (i==104) // Run
	{

		//SetForegroundWindow(FindWindow(L"DesktopExplorerWindow",L"Desktop"));

		keybd_event(82,NULL,KEYEVENTF_SILENT,0);
		keybd_event(82,NULL,KEYEVENTF_KEYUP|KEYEVENTF_SILENT,0);

		keybd_event(85,NULL,KEYEVENTF_SILENT,0);
		keybd_event(85,NULL,KEYEVENTF_KEYUP|KEYEVENTF_SILENT,0);

		keybd_event(78,NULL,KEYEVENTF_SILENT,0);
		keybd_event(78,NULL,KEYEVENTF_KEYUP|KEYEVENTF_SILENT,0);

		keybd_event(50,NULL,KEYEVENTF_SILENT,0);
		keybd_event(50,NULL,KEYEVENTF_KEYUP|KEYEVENTF_SILENT,0);

		keybd_event(51,NULL,KEYEVENTF_SILENT,0);
		keybd_event(51,NULL,KEYEVENTF_KEYUP|KEYEVENTF_SILENT,0);
	}


//	if (i==105) // Quit
	//	KillMungoKill(hwnd);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg,
                         WPARAM wParam, LPARAM lParam)
{
    NOTIFYICONDATA nid;
	int i;


    switch(uMsg)
    {

    case WM_CREATE:
        nid.cbSize = sizeof(nid);
        nid.hWnd = hwnd;
        nid.uID = 1;
        nid.uFlags = NIF_ICON | NIF_MESSAGE; // | NIF_TIP;
        nid.uCallbackMessage = WM_USER;
		nid.hIcon=(HICON)LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON2),IMAGE_ICON, 16,16,0);
        Shell_NotifyIcon(NIM_ADD, &nid);
		// Start timer!
	//	SetTimer(hwnd,2,60*1000,NULL);
        break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			if (once) break;
		sndPlaySound(L"Question", SND_FILENAME|SND_ASYNC);
		KillTimer(hwnd,1);
		timer=false;
		OpenPopUpMenu(hwnd);
		click=0;
		once=false;
		break;
		
		case 2: // Autokill

			//sndPlaySound(L"asterisk", SND_FILENAME|SND_ASYNC);
			// Kill all but current

			textcounter=0;
			top=NULL;find=NULL;
			EnumWindows(EnumWindowsProc,NULL);
			for (i=1;i<textcounter;i++)
				if (tasks[i]!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
					KillMungoKill(tasks[i]);


			break;
		default:break;
		}
		
    case WM_USER:
        if ((UINT)lParam == WM_LBUTTONUP)
		{
				
			if ((click==1)&& (once==false))
			{
				// If click-on, release-off
				// (could be a double-click though, be careful!
				top=NULL;find=NULL;
				textcounter=0;
				EnumWindows(EnumWindowsProc,NULL);
				if (find!=NULL) SetForegroundWindow(find);
				click=0;
			}

			if (click==3)
			{
				// Just had a double click!
				click=0;
			}

			if (timer)
			{
				timer=false;
				KillTimer(hwnd,1);
			}
		
		}
      

		if ((UINT)lParam == WM_LBUTTONDOWN)
		{
			click=1;
			// Start timer!
			SetTimer(hwnd,1,400,NULL);
			timer=true;


		}

		 if ((UINT)lParam == WM_LBUTTONDBLCLK)
		 {  
			// Kill the top most window
			 if (top!=NULL) 
			 {
				 if (top!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
				 	KillMungoKill(top);
				 
				 else
				 {
					 // Can't shut desktop, that's rude!
					SetForegroundWindow(top);
					sndPlaySound(L"Exclam", SND_FILENAME|SND_ASYNC);
			 	}
			 }
			 click=3;
		 }

        break;

	case 0x219:

		//sndPlaySound(L"Exclam", SND_FILENAME|SND_ASYNC);

		if (sound)
			if (LOWORD(wParam)==0x8000)	sndPlaySound(L"Flipper", SND_FILENAME|SND_ASYNC);

			//MessageBox(NULL,L"Activate!",L"Activate!",MB_OK);
		//if (LOWORD(wParam)==WA_CLICKACTIVE)	MessageBox(NULL,L"Clikvate!",L"Activate!",MB_OK);

		break;

    case WM_DESTROY:
		if (timer)
			{
				timer=false;
				KillTimer(hwnd,1);
			}

		// Add code to killer timer 2 if it exists

		if (autokill) KillTimer(hwnd,2);

        nid.cbSize = sizeof(nid);
        nid.hWnd = hwnd;
        nid.uID = 1;
        nid.uFlags = 0;
        Shell_NotifyIcon(NIM_DELETE, &nid);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
   return 0;
}




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR szCmdLine, int iCmdShow)
     {
 
	MSG msg;
    HWND hwnd;
    WNDCLASS wndClass;
	globalinstance=hInstance;
	
	// Check for previous existance!

	if (FindWindow(L"FlipperPro",NULL)) 
	{
		// Perform one flip!
		find=NULL;
		textcounter=0;
		EnumWindows(EnumWindowsProc,NULL);
		if (find!=NULL) SetForegroundWindow(find);
		return false;
	}
	
    if (hPrevInstance == NULL)
    {
        memset(&wndClass, 0, sizeof(wndClass));
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = WndProc;
        wndClass.hInstance = hInstance;
        wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wndClass.lpszClassName = L"FlipperPro";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"FlipperPro", L"FlipperPro",
                  NULL,//WS_OVERLAPPEDWINDOW,
                       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                       NULL, NULL, hInstance, NULL);

	//globalwindow=hwnd;

//hThread1=CreateThread(NULL,0,Thread2,NULL,0,&dwThread1ID);
//CloseHandle(hThread1);










//    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}