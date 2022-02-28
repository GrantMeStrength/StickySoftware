
#include <windows.h>


HWND next=NULL,find=NULL,top=NULL;
HWND tasks[20];
char text[20][64];
int textcounter=0;


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

		GetWindowText(next,pointer,32);
		tasks[textcounter]=next;
	
		for (int i=0;i<((length*2)+2);i++)
			text[textcounter][i]=name[i];

		textcounter++;
			if (textcounter>20) textcounter=20;
	}
	return true;
}


void KillMungoKill(HWND hWnd)
{

	TCHAR name[64];
	TCHAR prop[]=L"Properties";
	TCHAR prog[]=L"Remove Programs";

	LPTSTR pointer=(LPTSTR)&name[0];
	GetWindowText(hWnd,pointer,32);

	if ((wcsstr(name,prop)==NULL) && (wcsstr(name,prog)==NULL))
	{
		SendMessage(hWnd,WM_CLOSE,0,0);
		sndPlaySound(L"Close", SND_FILENAME|SND_ASYNC);
	}
}


void KillAllButDesktop()
{
	textcounter=0;
	top=NULL;find=NULL;
	EnumWindows(EnumWindowsProc,NULL);

	for (int i=1;i<textcounter;i++)
		if (tasks[i]!=FindWindow(L"DesktopExplorerWindow",L"Desktop"))
			KillMungoKill(tasks[i]);
}