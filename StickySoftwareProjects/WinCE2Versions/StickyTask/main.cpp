#include <windows.h>
#include "resource.h"

/*

	Flipper
	Task management utility
	(Effectively FlipperPro Lite)
	25th November 1998
	
	  (1.2 - fixed Properties closing option, 28th Nov 1998)
*/

HWND next=NULL,find=NULL,top=NULL;
HINSTANCE globalinstance;

int click=0;

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
		//KillMungoKill(hWnd);
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

	length=GetWindowTextLength(next);
	status=GetWindowLong(next,GWL_STYLE);

	if ((status&WS_EX_INK)&&(length!=0))
	{
		if (top==NULL) top=next;	// top is the first window now
		
		find=next;
	}
	return true;
}

BOOL CALLBACK EnumWindowsProcNotFussy(HWND hwnd,LPARAM lParam)
{

	next=hwnd;
	long status;
	int length;

	length=GetWindowTextLength(next);
	status=GetWindowLong(next,GWL_STYLE);

	if (top==NULL) top=next;	// top is the first window now
		
	find=next;

	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg,
                         WPARAM wParam, LPARAM lParam)
{
    NOTIFYICONDATA nid;

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
        break;
    case WM_USER:
        if ((UINT)lParam == WM_LBUTTONUP)
		{
			if (click==0)
			{
				// If click-off, release-on then close Flipper app!
				sndPlaySound(L"Close", SND_FILENAME|SND_ASYNC);
				SendMessage(hwnd,WM_DESTROY,0,0);
			}

			if (click==1)
			{
				// If click-on, release-off
				// (could be a double-click though, be careful!
				top=NULL;find=NULL;
				EnumWindows(EnumWindowsProc,NULL);
				if (find!=NULL) SetForegroundWindow(find);
				click=0;
			}
			if (click==3)
			{
				click=0;
			}
	
		}
      

		if ((UINT)lParam == WM_LBUTTONDOWN)
		{
			click=1;
		}

		 if ((UINT)lParam == WM_LBUTTONDBLCLK)
		 {  
			// Kill the top most window
			 if (top!=NULL) 
			 {
				 if (top!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
				 {
					 KillMungoKill(top);
					//SendMessage(top,WM_CLOSE,0,0);
					//sndPlaySound(L"Close", SND_FILENAME|SND_ASYNC);
				 }
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
    case WM_DESTROY:
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

	if (FindWindow(L"flipper",NULL)) 
	{
		// Perform one flip!
		find=NULL;
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
//        wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wndClass.lpszClassName = L"Flipper";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"Flipper", L"Flipper",
                  NULL,//WS_OVERLAPPEDWINDOW,
                       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                       NULL, NULL, hInstance, NULL);
//    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}