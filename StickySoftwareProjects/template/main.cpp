#include <windows.h>
#include "template.h"

int WINAPI WinMain(HINSTANCE hInstance, 
				   HINSTANCE hPrevInstance, 
				   LPTSTR lpCmdLine,
				   int nCmdShow)
{
	MSG msg;
    RECT rc;
	WNDCLASS wndClass;

	/* Save application instance in ghInst for
	   possible use by other functions, such as
	   the main windows's window procedure.
	 */
	ghInst = hInstance;

	/* Register the main window class */
	wndClass.style         = 0;
	wndClass.lpfnWndProc   = WndProc;
	wndClass.cbClsExtra    = 0;
	wndClass.cbWndExtra    = 0;
	wndClass.hInstance     = hInstance;
	wndClass.hIcon         = NULL;
	wndClass.hCursor       = NULL;
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wndClass.lpszMenuName  = NULL;
	wndClass.lpszClassName = pszAppName;
	RegisterClass(&wndClass);

	/* Create the application's main window */
    SystemParametersInfo(SPI_GETWORKAREA,
                         NULL,
                         &rc,
                         NULL);
    nWidth = rc.right;
    nHeight = rc.bottom;

	hwndMain = CreateWindow(pszAppName,
                            pszTitle,
                            WS_VISIBLE|WS_OVERLAPPED,
                            0,0,
                            nWidth,
                            nHeight,
							NULL,
							NULL,
							hInstance,
							NULL);

    while (GetMessage(&msg, NULL, 0, 0) == TRUE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg); 
	}
	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		return (0);
	default:
     return (DefWindowProc(hwnd, message, wParam, lParam));
	}
}


