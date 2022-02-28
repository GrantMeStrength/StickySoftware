#ifndef __TEMPLATE_H_
#define __TEMPLATE_H_

TCHAR pszAppName[] = TEXT("TEMPLATE");
TCHAR pszTitle[] = TEXT("Windows CE Application Template");

/* Define the global application HINSTANCE */
HINSTANCE ghInst;

int nWidth;  //Main window width
int nHeight; //Main window height

/* Define the HWNDs used by this application
   hwndMain       -->     Main application window
 */
HWND hwndMain;

/* Define the main application window procedure */
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam);
#endif
