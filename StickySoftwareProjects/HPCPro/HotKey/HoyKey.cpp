
/*
*
*                  Hot Key
*
*/

#include <windows.h>
#include "resource.h"

bool alt=false;

HINSTANCE globalinstance;

//bool once=false;
//bool timer=false;


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
       	nid.uFlags = NIF_ICON | NIF_MESSAGE; 
        nid.uCallbackMessage = WM_USER;
		nid.hIcon=(HICON)LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON),IMAGE_ICON, 16,16,0);
		Shell_NotifyIcon(NIM_ADD, &nid);

	    break;

	case WM_TIMER:

		
		break;


	case WM_USER:
		
		if ((UINT)lParam == WM_LBUTTONDOWN)
		{

			
				MessageBox(NULL,L"Plop",L"Plop",MB_SETFOREGROUND|MB_OK);
			
		
		}

		/*
		if ((UINT)lParam == WM_KEYDOWN)
		{
			if ((UINT)wParam == VK_MENU)
				alt=true;
		}
*/	break;

	case WM_KEYUP :
//WM_SYSCHAR
		//if ((UINT)lParam == VK_MENU)
		//{
				MessageBox(NULL,L"Plop",L"Plop",MB_SETFOREGROUND|MB_OK);
		//		alt=false;
			
		//}


        break;

		case WM_SYSKEYUP :
			MessageBox(NULL,L"Plip",L"Plip",MB_SETFOREGROUND|MB_OK);
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

	if (FindWindow(L"HotKey",NULL)) 
	{
		return false;
	}
	
    if (hPrevInstance == NULL)
    {
        memset(&wndClass, 0, sizeof(wndClass));
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = WndProc;
        wndClass.hInstance = hInstance;
        wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wndClass.lpszClassName = L"HotKey";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"HotKey", L"HotKey",
                  NULL,
                  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                  NULL, NULL, hInstance, NULL);

    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}