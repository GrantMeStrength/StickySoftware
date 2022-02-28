
//
// Task Dialog
//

#include <windows.h>
#include "resource.h"

struct _SYSTEM_POWER_STATUS_EX power;

extern bool once;
extern bool kill;
extern HINSTANCE globalinstance;
extern bool sound;
extern bool autokill;
TCHAR scCmdLine[64];
int rc;
PROCESS_INFORMATION pi;

//int b=0;

//BYTE laststatus=1;
//SetDialogBkColor(RGB(255,0,0),RGB(0,0,0));

//HBITMAP hBitmap;
HBITMAP hBitmap_full,hBitmap_low,hBitmap_critical,hBitmap_default;
HBITMAP frame[6];

HDC hdcMem,hdc;
int frame_counter=0;
BYTE temp_reading,last_reading=1;

COLORREF colours[2];
int elements[2];



BOOL CALLBACK TaskDialog(HWND hwnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{


//	HPEN BlackPen,RedPen,GreyPen,DarkRedPen;
//	HDC hdc;
//	int x,y,c,l;

	bool card;
	WCHAR report1[100],report2[100];
	ULARGE_INTEGER FreeBytesAvailable;
	ULARGE_INTEGER TotalNumberOfBytes;
	ULARGE_INTEGER TotalNumberOfFreeBytes;
	double f1,f2;
	BYTE bat1,bat2;

	switch (wMsg) 
	{

		

		case WM_INITDIALOG:

			once=true;

			colours[0]=RGB(255,255,255);
			elements[0]=COLOR_STATIC;

			colours[1]=GetSysColor(elements[0]);
			SetSysColors(1,&elements[0],&colours[0]);
			

			// Get memory stats
			::GetDiskFreeSpaceEx(_T("\\"),&FreeBytesAvailable,&TotalNumberOfBytes,&TotalNumberOfFreeBytes);
			f1=FreeBytesAvailable.LowPart;
			f2=TotalNumberOfBytes.LowPart;
			wsprintf((unsigned short *)report1,L"Memory free: %d%%\0",int(((f1/f2)*100)));
			card=::GetDiskFreeSpaceEx(_T("\\Storage Card\\"),&FreeBytesAvailable,&TotalNumberOfBytes,&TotalNumberOfFreeBytes);
			f1=FreeBytesAvailable.LowPart;
			f2=TotalNumberOfBytes.LowPart;
			if (card) wsprintf((unsigned short *)report1,L"%s Card free: %d%%\0",report1,int(((f1/f2)*100)));
			SetDlgItemText(hwnd,IDD_TEXT1,report1);

			// Set check boxes
		 
			SendMessage(GetDlgItem(hwnd,IDC_STARTUP),BM_SETCHECK,sound,0);
			SendMessage(GetDlgItem(hwnd,IDC_AUTOKILL),BM_SETCHECK,autokill,0);
			
			hBitmap_full=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATFULL));
			hBitmap_low=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATLOW));
			hBitmap_critical=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATCRITICAL));
			hBitmap_default=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATDEFAULT));
			
			frame[0]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP1));
			frame[1]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP2));
			frame[2]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP3));
			frame[3]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP4));
			frame[4]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP5));
			frame[5]=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP6));

		//	if (frame[0]==NULL)
		//	{
		//		MessageBox(NULL,L"frame!",L"frame!",MB_OK);
		//	}


			SetTimer(hwnd,3,300,NULL);

			return true;
			break;


		case WM_TIMER:

			if (wParam!=3) return true;
	
			hdc=GetDC(hwnd);
			hdcMem=CreateCompatibleDC(hdc);
			SelectObject(hdcMem,frame[frame_counter]);
				
			frame_counter++;if (frame_counter>5) frame_counter=0;
			Rectangle(hdc,93,9,127,42);
			BitBlt(hdc,94,10,32,32,hdcMem,0,0,SRCCOPY);
		
			//Rectangle(hdc,88,90,134,92);
			Rectangle(hdc,88,180,134,182);

	
			// Battery..
			GetSystemPowerStatusEx(&power,true);
			bat1=power.BatteryFlag;
			bat2=power.BackupBatteryFlag;


			// Check for double battery missing

			temp_reading=bat1;
			if ((bat1==128) && (last_reading!=128))
					bat1=last_reading;
			last_reading=temp_reading;
		

			switch (bat1) 
			{
			case 1:
				wsprintf((unsigned short *)report2,L"High\0");
				SelectObject(hdcMem,hBitmap_full);
				break;
			case 2:
				wsprintf((unsigned short *)report2,L"Low\0");
				SelectObject(hdcMem,hBitmap_low);
				break;
			case 4:
				wsprintf((unsigned short *)report2,L"Critical\0");
				SelectObject(hdcMem,hBitmap_critical);
				break;
			case 8:
				wsprintf((unsigned short *)report2,L"Charging\0");
				switch(frame_counter) {
					case 5:SelectObject(hdcMem,hBitmap_full);break;
					case 3:SelectObject(hdcMem,hBitmap_low);break;
					case 1:SelectObject(hdcMem,hBitmap_critical);break;
					case 4:SelectObject(hdcMem,hBitmap_full);break;
					case 2:SelectObject(hdcMem,hBitmap_low);break;
					case 0:SelectObject(hdcMem,hBitmap_critical);break;
					default:SelectObject(hdcMem,hBitmap_full);break;
					};
				break;
			case 128:
				wsprintf((unsigned short *)report2,L"External\0");
				SelectObject(hdcMem,hBitmap_default);
				break;
			default:
				wsprintf((unsigned short *)report2,L"Unknown\0");
				SelectObject(hdcMem,hBitmap_default);
				break;
			}
		
			BitBlt(hdc,54,131,32,32,hdcMem,0,0,SRCCOPY);
			SetDlgItemText(hwnd,IDD_TEXT2,report2);
		

			switch (bat2) 
			{
			case BATTERY_FLAG_HIGH:
				wsprintf((unsigned short *)report2,L"High\0");
				SelectObject(hdcMem,hBitmap_full);
				break;
			case BATTERY_FLAG_LOW:
				wsprintf((unsigned short *)report2,L"Low\0");
				SelectObject(hdcMem,hBitmap_low);
				break;
			case BATTERY_FLAG_CRITICAL:
				wsprintf((unsigned short *)report2,L"Critical\0");
				SelectObject(hdcMem,hBitmap_critical);
				break;
			case BATTERY_FLAG_CHARGING:
				wsprintf((unsigned short *)report2,L"Charging\0");
				switch(frame_counter) {
					case 5:SelectObject(hdcMem,hBitmap_full);break;
					case 3:SelectObject(hdcMem,hBitmap_low);break;
					case 1:SelectObject(hdcMem,hBitmap_critical);break;
					case 4:SelectObject(hdcMem,hBitmap_full);break;
					case 2:SelectObject(hdcMem,hBitmap_low);break;
					case 0:SelectObject(hdcMem,hBitmap_critical);break;
					default:SelectObject(hdcMem,hBitmap_full);break;
					};
				break;
			case BATTERY_FLAG_NO_BATTERY:
				wsprintf((unsigned short *)report2,L"Missing!\0");
				SelectObject(hdcMem,hBitmap_default);
				break;
			default:
				wsprintf((unsigned short *)report2,L"Unknown\0");
				SelectObject(hdcMem,hBitmap_default);
				break;
			}
		
		
			SetDlgItemText(hwnd,IDD_TEXT3,report2);
			BitBlt(hdc,144,131,32,32,hdcMem,0,0,SRCCOPY);

			DeleteDC(hdcMem);
			ReleaseDC(hwnd,hdc);
			
			return true;
			break;



		case WM_COMMAND:
			{
				switch (LOWORD (wParam))
				{

					case IDC_BUTTON1: // Memory
					lstrcpy (scCmdLine, TEXT("system.cpl,1,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					lstrcpy (scCmdLine, TEXT("systemg.cpl,0,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					return true;

					case IDC_BUTTON2: // Power
					lstrcpy (scCmdLine, TEXT("power.cpl,1,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					lstrcpy (scCmdLine, TEXT("powerg.cpl"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					return true;


					case IDOK:
						autokill=SendMessage(GetDlgItem(hwnd,IDC_AUTOKILL),BM_GETCHECK,0,0);
						sound=SendMessage(GetDlgItem(hwnd,IDC_STARTUP),BM_GETCHECK,0,0);
						KillTimer(hwnd,2);
						once=false;
						EndDialog(hwnd,0);

						for (frame_counter=0;frame_counter<6;frame_counter++)
							DeleteObject(frame[frame_counter]);
						DeleteObject(hBitmap_full);
						DeleteObject(hBitmap_low);
						DeleteObject(hBitmap_critical);
						DeleteObject(hBitmap_default);

			
						SetSysColors(1,&elements[0],&colours[1]);
						//MessageBox(NULL,L"plop",L"plop",MB_OK);

						return true;

					case IDCANCEL2:
						kill=true;
					case IDCANCEL:
						KillTimer(hwnd,2);
						once=false;
						EndDialog(hwnd,0);

						for (frame_counter=0;frame_counter<6;frame_counter++)
							DeleteObject(frame[frame_counter]);
						DeleteObject(hBitmap_full);
						DeleteObject(hBitmap_low);
						DeleteObject(hBitmap_critical);
						DeleteObject(hBitmap_default);
						
						SetSysColors(1,&elements[0],&colours[1]);
						return true;
				}
			}
		}

	return false;
}


