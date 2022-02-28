
/*
*
*                  HAL 9000

*/








#include <windows.h>
#include "resource.h"


bool kill=false;


INT nParamater=5;
bool sound=true;



HINSTANCE globalinstance;
// HWND globalwindow;

int click=0;




bool once=false;
bool timer=false;





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
		nid.hIcon=(HICON)LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON),IMAGE_ICON, 16,16,0);
        Shell_NotifyIcon(NIM_ADD, &nid);
	
        break;

		
    case WM_USER:
        if ((UINT)lParam == WM_LBUTTONUP)
		{
				
			SendMessage(hwnd,WM_CLOSE,0,0);
		}
        break;

	case 0x219:

		//sndPlaySound(L"Exclam", SND_FILENAME|SND_ASYNC);

		if (sound)
			if (LOWORD(wParam)==0x8000)	sndPlaySound(L"Hal", SND_FILENAME|SND_ASYNC);

		
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

		
    if (hPrevInstance == NULL)
    {
        memset(&wndClass, 0, sizeof(wndClass));
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = WndProc;
        wndClass.hInstance = hInstance;
        wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wndClass.lpszClassName = L"HAL";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"HAL", L"HAL",
                  NULL,//WS_OVERLAPPEDWINDOW,
                       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                       NULL, NULL, hInstance, NULL);

	
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}