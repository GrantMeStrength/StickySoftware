
/*
*
*                  Uni Power v2.1
*
*/



#include <windows.h>
#include <windowsx.h>
#include "resource.h"

#define RX 50
#define RY 30

struct _SYSTEM_POWER_STATUS_EX power;

TCHAR scCmdLine[64];
int rc;
PROCESS_INFORMATION pi;

int power_value=-1;

WCHAR report1[100];
WCHAR report2[100];

int percent[120];
int current=0;

HINSTANCE globalinstance;
HANDLE icon_bitmap[12];
int icon_counter;

bool once=false;
bool timer=false;
bool kill=false;
bool graph=false;

int tm,pv;
int hourleft,minleft;



void DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	POINT cord[2];

	cord[0].x=x1;
	cord[0].y=y1;	
	cord[1].x=x2;	
	cord[1].y=y2;

	Polyline(hdc,cord,2);

}

	HDC hdc,hdcgraph;
	HBITMAP graph_bitmap;
	HPEN BlackPen,RedPen,GreyPen,DarkRedPen;

BOOL CALLBACK PowerDialog(HWND hwnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{

	// IDD_POWER

	

	int x,y,c,l,oy;
	int ac;

	switch (wMsg) 
	{

		case WM_INITDIALOG:
		
			// Allocate bitmap for graph display
		
			hdc=GetDC(hwnd);
			hdcgraph=CreateCompatibleDC(hdc);
			graph_bitmap=CreateCompatibleBitmap(hdc,241,110);//CreateBitmap(32,32,8,0,NULL);
			SelectBitmap(hdcgraph,graph_bitmap);
		
			BlackPen=CreatePen(PS_SOLID,1,RGB(0,0,0));
			RedPen=CreatePen(PS_SOLID,1,RGB(255,0,0));
			DarkRedPen=CreatePen(PS_SOLID,1,RGB(128,0,0));
			GreyPen=CreatePen(PS_SOLID,1,RGB(192,192,192));

			SetDlgItemText(hwnd,IDD_TEXT1,report1);
			SetDlgItemText(hwnd,IDD_TEXT2,report2);
			SetTimer(hwnd,2,1000,NULL);
			return true;

	
		case WM_TIMER:

			if (wParam!=2) return true;

				GetSystemPowerStatusEx(&power,true);
				pv=power.BatteryLifePercent;
				tm=power.BatteryLifeTime;
				ac=power.ACLineStatus;

			if ((tm==0) || (tm<0))
				{
					wsprintf((unsigned short *)report2,L"");
					wsprintf((unsigned short *)report1,L"Percentage Power remaining: %d%%\0",pv);
				}
				else
				{
					hourleft=tm/3600;
					minleft=(tm-(hourleft*3600))/60;
					wsprintf((unsigned short *)report1,L"Estimated Time Remaining: %d Hours %d Minute(s)",hourleft,minleft);
					wsprintf((unsigned short *)report2,L"Percentage Power remaining: %d%%\0",pv);
			}

				if (ac==1) wsprintf((unsigned short *)report1,L"Using Mains Power");

			SetDlgItemText(hwnd,IDD_TEXT1,report1);
			SetDlgItemText(hwnd,IDD_TEXT2,report2);
	
			GetStockObject(LTGRAY_BRUSH);
			SelectObject(hdcgraph,GreyPen);
			Rectangle(hdcgraph,0,0,241,110);

			
			GetStockObject(WHITE_BRUSH);

			for (x=0;x<250;x+=10)
				DrawLine(hdcgraph,x,0,x,110);

			for (y=0;y<110;y+=10)
				DrawLine(hdcgraph,0,y+5,240,y+5);

			//DrawLine(hdcgraph,0,101,240,101);

			GetStockObject(LTGRAY_BRUSH);


			SelectObject(hdcgraph,RedPen);
			l=0;
			c=current-120;
			if (c<0) c+=120;

			oy=percent[c];

			for (x=0;x<238;x+=2)
			{
				c++;
				if (c>=120) c=0;
				y=percent[c];
				DrawLine(hdcgraph,x+1,105-oy,x+3,105-y);
				oy=y;
			//	DrawLine(hdcgraph,x+2,100,x+2,100-y);
			
			}

/*
				for (x=240;x>0;x-=2)
			{
				c--;
				if (c<0) c=119;
				y=percent[c];
				DrawLine(hdcgraph,x+1,100-oy,x+1-2,100-y);
				oy=y;
			}
*/



			BitBlt(hdc,RX,RY,241,110,hdcgraph,0,0,SRCCOPY);
			
		


			return true;



		case WM_COMMAND:
			{
				switch (LOWORD (wParam))
				{
				
					case IDC_BUTTON1: // Memory
					lstrcpy (scCmdLine, TEXT("power.cpl,1,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					return true;

					case IDCANCEL:
						if (IDYES ==MessageBox(hwnd, L"Are you sure?\nYou'll lose previous values...",L"Quit",MB_SETFOREGROUND|MB_YESNO|MB_ICONWARNING))
							kill=true;
						else
							return true;
					case IDOK:
						KillTimer(hwnd,2);
						DeleteObject(BlackPen);
						DeleteObject(RedPen);
						DeleteObject(DarkRedPen);
						DeleteObject(GreyPen);
						ReleaseDC(hwnd,hdc);
						DeleteBitmap(&graph_bitmap);
						ReleaseDC(hwnd,hdcgraph);
						EndDialog(hwnd,0);
						return true;
				}
			}
		}

	return false;
}







LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg,
                         WPARAM wParam, LPARAM lParam)
{
    NOTIFYICONDATA nid;


    switch(uMsg)
    {

    case WM_CREATE:

		// load the bitmaps

		icon_bitmap[0]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON00),IMAGE_ICON, 16,16,0);
		icon_bitmap[1]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON10),IMAGE_ICON, 16,16,0);
		icon_bitmap[2]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON20),IMAGE_ICON, 16,16,0);
		icon_bitmap[3]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON30),IMAGE_ICON, 16,16,0);
		icon_bitmap[4]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON40),IMAGE_ICON, 16,16,0);
		icon_bitmap[5]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON50),IMAGE_ICON, 16,16,0);
		icon_bitmap[6]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON60),IMAGE_ICON, 16,16,0);
		icon_bitmap[7]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON70),IMAGE_ICON, 16,16,0);
		icon_bitmap[8]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON80),IMAGE_ICON, 16,16,0);
		icon_bitmap[9]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON90),IMAGE_ICON, 16,16,0);
		icon_bitmap[10]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON_FULL),IMAGE_ICON, 16,16,0);
		icon_bitmap[11]=LoadImage(globalinstance,MAKEINTRESOURCE(IDI_ICON_DEFAULT),IMAGE_ICON, 16,16,0);

		// Start timer!
		SetTimer(hwnd,1,10,NULL);
		timer=true;
		
		break;

	case WM_TIMER:

		// If this is the first time,
		// set timer with longer delay and
		// make sure it happens the once
		// only

		if (wParam!=1) return true;

		if (timer==true) {
			KillTimer(hwnd,1);
			SetTimer(hwnd,1,1000*60,NULL); //1000*60
			timer=false;
			sndPlaySound(L"WindMax", SND_FILENAME|SND_ASYNC);
		}

		
		GetSystemPowerStatusEx(&power,true);
		pv=power.BatteryLifePercent;
		percent[current]=pv;
		current++;
		if (current>120) current=0;
		//tm=power.BatteryLifeTime;
		
		if (pv==power_value) break;


		// Delete Icon
		nid.cbSize = sizeof(nid);
        nid.hWnd = hwnd;
        nid.uID = 1;
        nid.uFlags = 0;
        Shell_NotifyIcon(NIM_DELETE, &nid);

		// Create Icon

		nid.uFlags = NIF_ICON | NIF_MESSAGE; // | NIF_TIP;
        nid.uCallbackMessage = WM_USER;

		icon_counter=pv/10;

		if (icon_counter<11)
			nid.hIcon=(HICON)icon_bitmap[icon_counter];
		else
			nid.hIcon=(HICON)icon_bitmap[11];
		
		Shell_NotifyIcon(NIM_ADD, &nid);

		break;


	case WM_USER:
		
		if ((UINT)lParam == WM_LBUTTONDOWN)
		{

			

		
			if (once==false)
			{
				once=true;

			

				DialogBox(globalinstance,MAKEINTRESOURCE(IDD_DIALOG),NULL,PowerDialog);

				once=false;


				if (kill) SendMessage(hwnd,WM_CLOSE,0,0);
			}
			
		
		}


        break;


    case WM_DESTROY:
		if (timer)
			{
				timer=false;
				KillTimer(hwnd,1);
			}

		for (icon_counter=0;icon_counter<12;icon_counter++)
							DeleteObject(icon_bitmap[icon_counter]);


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

	if (FindWindow(L"PowerView",NULL)) 
			return false;
	
	
    if (hPrevInstance == NULL)
    {
        memset(&wndClass, 0, sizeof(wndClass));
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = WndProc;
        wndClass.hInstance = hInstance;
        wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wndClass.lpszClassName = L"PowerView";
        if (!RegisterClass(&wndClass)) return FALSE;
    }

    hwnd = CreateWindow(L"PowerView", L"PowerView",
                  NULL,
                  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                  NULL, NULL, hInstance, NULL);



	for (int p=0;p<120;p++) percent[p]=0;
	current=0;


    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return msg.wParam;

}