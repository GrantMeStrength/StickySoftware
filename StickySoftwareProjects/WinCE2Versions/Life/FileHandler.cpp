
//
//
// This file contains the functions for all the 
// file handling. I have no idea how most of them
// work, because they are taken from examples on
// the WinCE VC disks, which are, frankly, crap.
//
//
//

#include "stdafx.h"
//#include "FileHandler.h"

extern class LifeGrid first;

HANDLE  hHeap = NULL;
TCHAR szAppName[20] = TEXT("Life Sample");
TCHAR szTitle[20] =  TEXT("Life Sample");
TCHAR szHtmlChild[20] = TEXT("HTMLChild");

LPTSTR      pCurrentDirectory = NULL;

//TCHAR *WINAPI 
LPTSTR OpenCellFile()
{
    BOOL            bSuccess = FALSE;
    TCHAR           szFileName[MAX_PATH] = {0}, szPathName[MAX_PATH] = TEXT("\\windows"), szExtName[100] = {0};
    OPENFILENAME    of;
    TCHAR           szOpen[50] = TEXT("Open Lifeform");
    //LPTSTR          pFileName, pTemp;

    const LPTSTR pszOpenFilter      = TEXT("Lifeform Files(*.lif)\0*.lif\0All Documents (*.*)\0*.*\0\0");

    memset((LPVOID)&of, 0, sizeof(OPENFILENAME));
    of.lStructSize	    = sizeof(OPENFILENAME);
    of.hwndOwner	    = NULL;
    of.lpstrFile	    = szFileName;
    of.lpstrInitialDir  = NULL;
    of.nMaxFile		    = sizeof(szFileName)/sizeof(TCHAR);

    of.lpstrDefExt  = szExtName;
    of.Flags = OFN_HIDEREADONLY |  // Do not display the Read-Only check box.
               OFN_LONGNAMES;      // Display long filenames if possible.

    of.lpfnHook = NULL;
    of.Flags        |= OFN_FILEMUSTEXIST;
    of.lpstrTitle   = szOpen;
    of.lpstrFilter	= pszOpenFilter;
    bSuccess = GetOpenFileName(&of);

	
    if( bSuccess ) return of.lpstrFile; 
	else return NULL;
	
  
	}

//]TCHAR * WINAPI   
LPTSTR CreateCellFile()
{
    BOOL            bSuccess = FALSE;
    TCHAR           szFileName[MAX_PATH] = {0}, szPathName[MAX_PATH] = TEXT("\\windows");
    const LPTSTR    szExtName = TEXT("lif\0");
	OPENFILENAME    of;
    TCHAR           szOpen[50] = TEXT("Save Lifeform");
    //LPTSTR          pFileName, pTemp;

    const LPTSTR pszOpenFilter      = TEXT("Lifeform Files(*.lif)\0*.lif\0All Documents (*.*)\0*.*\0\0");
	//const LPTSTR pszInitFilter      = TEXT("Lifeform Files(*.lif)\0*.lif\0\0");

    memset((LPVOID)&of, 0, sizeof(OPENFILENAME));
    of.lStructSize	    = sizeof(OPENFILENAME);
    of.hwndOwner	    = NULL;
    of.lpstrFile	    = szFileName;
    of.lpstrInitialDir  = NULL;
    of.nMaxFile		    = sizeof(szFileName)/sizeof(TCHAR);

    of.lpstrDefExt  = szExtName;
    of.Flags = OFN_HIDEREADONLY |  // Do not display the Read-Only check box.
               OFN_LONGNAMES;      // Display long filenames if possible.

    of.lpfnHook = NULL;
   // of.Flags        |= OFN_FILEMUSTEXIST;
    of.lpstrTitle   = szOpen;
    of.lpstrFilter	= pszOpenFilter;
	//of.lpstrCustomFilter = pszInitFilter;
    bSuccess = GetSaveFileName(&of);
    if( bSuccess ) return of.lpstrFile;
	else return FALSE;
}


