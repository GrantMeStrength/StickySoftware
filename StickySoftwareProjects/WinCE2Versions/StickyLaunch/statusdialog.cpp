
//
// Status Dialog
//

#include <windows.h>
#include "resource.h"

//struct _SYSTEM_POWER_STATUS_EX power;

#define OFFSET 16
#define L1 65


//extern bool active;

extern HINSTANCE globalinstance;
TCHAR scCmdLine[64];
int rc;
PROCESS_INFORMATION pi;


//int b=0;
int frame_counter=0;

HBITMAP hBitmap_full,hBitmap_low,hBitmap_critical,hBitmap_default;

HDC hdcMem,hdc;
BYTE temp_reading,last_reading=1;


BOOL CALLBACK StatusDialog(HWND hwnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{

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

			//active=true;

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

			hBitmap_full=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATFULL));
			hBitmap_low=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATLOW));
			hBitmap_critical=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATCRITICAL));
			hBitmap_default=LoadBitmap(globalinstance,MAKEINTRESOURCE(IDB_BITMAP_BATDEFAULT));
			
			SetTimer(hwnd,1,300,NULL);

			return true;


		case WM_TIMER:

			hdc=GetDC(hwnd);
			hdcMem=CreateCompatibleDC(hdc);
					
			frame_counter++;if (frame_counter>3) frame_counter=0;
			
			//Rectangle(hdc,60,L1,134,L1+2);
			//Rectangle(hdc,88,180,134,182);

	
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
					case 2:SelectObject(hdcMem,hBitmap_full);break;
					case 1:SelectObject(hdcMem,hBitmap_low);break;
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
		
			BitBlt(hdc,54,131-OFFSET,32,32,hdcMem,0,0,SRCCOPY);
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
			BitBlt(hdc,122,131-OFFSET,32,32,hdcMem,0,0,SRCCOPY);

			DeleteDC(hdcMem);
			ReleaseDC(hwnd,hdc);
			
			return true;



		case WM_COMMAND:
			{
				switch (LOWORD (wParam))
				{
					case IDC_BUTTON1: // Memory
					lstrcpy (scCmdLine, TEXT("system.cpl,1,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					return true;

					case IDC_BUTTON2: // Power
					lstrcpy (scCmdLine, TEXT("power.cpl,1,1"));rc=CreateProcess(L"ctlpnl.exe",scCmdLine,NULL,NULL,false,0,NULL,NULL,NULL,&pi);
					CloseHandle (pi.hThread);
					CloseHandle (pi.hProcess);
					return true;

					case IDOK:
					case IDCANCEL:
					
						KillTimer(hwnd,1);
						//active=false;
						EndDialog(hwnd,0);

						DeleteObject(hBitmap_full);
						DeleteObject(hBitmap_low);
						DeleteObject(hBitmap_critical);
						DeleteObject(hBitmap_default);

						return true;
				}
			}
		}

	return false;
}


