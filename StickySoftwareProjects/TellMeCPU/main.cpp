#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

SYSTEM_INFO info;
TCHAR msg[30];

memset(&info, 0, sizeof(SYSTEM_INFO));
GetSystemInfo(&info);
wsprintf(msg, TEXT("Type ID = %lu"), info.dwProcessorType);

MessageBox(NULL, msg, TEXT("Processor"), 0);

return 0;

}
