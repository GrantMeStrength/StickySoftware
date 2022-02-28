#include <windows.h>
#include "resource.h"

/*

	Use to be Flipper
	Launch Word Count Utility
*/

HWND next=NULL,find=NULL,top=NULL;
HINSTANCE globalinstance;

PROCESS_INFORMATION pi;
int rc=0;
TCHAR scCmdLine[64];

int click=0;


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
        

		if ((UINT)lParam == WM_LBUTTONDOWN)
		{
			rc=CreateProcess(L"wordcount.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);break;
				if (rc)
				{	
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
				}
		}

		 if ((UINT)lParam == WM_LBUTTONDBLCLK)
		 {  
			sndPlaySound(L"Close", SND_FILENAME|SND_ASYNC);
			SendMessage(hwnd,WM_DESTROY,0,0);
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

	if (FindWindow(L"LaunchCount",NULL)) 
	{
		// Perform one flip!
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
        wndClass.lpszClassName = L"LaunchCount";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"LaunchCount", L"LaunchCount",
                  NULL,//WS_OVERLAPPEDWINDOW,
                       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                       NULL, NULL, hInstance, NULL);
//    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}