// CleanBarneyView.cpp : implementation of the CCleanBarneyView class
//

#include "stdafx.h"
#include "CleanBarney.h"

#include "CleanBarneyDoc.h"
#include "CleanBarneyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyView

IMPLEMENT_DYNCREATE(CCleanBarneyView, CView)

BEGIN_MESSAGE_MAP(CCleanBarneyView, CView)
	//{{AFX_MSG_MAP(CCleanBarneyView)
	ON_COMMAND(IDM_CLEAN, OnClean)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyView construction/destruction

CCleanBarneyView::CCleanBarneyView()
{
}

CCleanBarneyView::~CCleanBarneyView()
{
}

BOOL CCleanBarneyView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyView drawing

void CCleanBarneyView::OnDraw(CDC* pDC)
{
	CCleanBarneyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyView diagnostics

#ifdef _DEBUG
void CCleanBarneyView::AssertValid() const
{
	CView::AssertValid();
}

void CCleanBarneyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCleanBarneyDoc* CCleanBarneyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCleanBarneyDoc)));
	return (CCleanBarneyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyView message handlers


//***************************************//

// Nuke em!

	// Remove all traces of Barney Buttons:
	// Files, registry and database entries


CEPROPVAL Looking;
HANDLE dh;
CEOID did=0;
DWORD dwIndex;
	bool failure=false;
	HKEY hKey;
	DWORD dwState=1;
	HRESULT hRes;
	TCHAR value[64];
	DWORD dwDisp;
	TCHAR filename[64];

void CleanFiles()
{
	// Delete all Files

	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but1.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but2.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but3.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but4.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but5.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but6.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but7.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but8.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\but9.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butF.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butV.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butP.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butM.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butT.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butX.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butH.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.gif"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.cdf"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\barney.mcs"));
	DeleteFile(TEXT("\\Windows\\Temporary Internet Files\\butS.gif"));

	DeleteFile(TEXT("\\Windows\\stickylaunch.exe"));
	DeleteFile(TEXT("\\Windows\\barney.htp"));




}

void CleanRegistry()
{
	// Delete Registry Keys

	hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney",0,KEY_ALL_ACCESS,&hKey);
	if (hRes==ERROR_SUCCESS) 

	{
		RegCloseKey(hKey);
		RegDeleteKey(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Mobile Channels\\Channels\\Barney");

		// Urgh. How to delete in the range 0 to X?
		// Let's ASSUME the key is the last in the list

		int i=99;bool carryon=true;
		do
		{
			wsprintf(value,TEXT("Software\\Microsoft\\Active Desktop\\%d\0"),i);
			hRes=RegOpenKeyEx(HKEY_LOCAL_MACHINE,(LPCTSTR)&value,0,KEY_ALL_ACCESS,&hKey);
			if ((hRes==ERROR_SUCCESS) || (i<0)) // key exists, so stop..
				carryon=false;
			i--;
		} while (carryon);


		if (i>=0)
		{	
			RegCloseKey(hKey);
			RegDeleteKey(HKEY_LOCAL_MACHINE, (LPCTSTR)&value);
		}
	}
}


void SeekAndDestroy()
{

	CEOID found;

	Looking.propid=MAKELONG(CEVT_LPWSTR,0x42);
	Looking.val.lpwstr=filename;
	Looking.wLenData=0;
	Looking.wFlags=0;

	found=CeSeekDatabase(dh,CEDB_SEEK_VALUEFIRSTEQUAL,(int)&Looking,&dwIndex);
	if (found!=0)
	{
		// Found so delete

		//MessageBox(NULL,filename,L"Found Database",MB_OK);
		CeDeleteRecord(dh,found);
	}
	//else
	//	MessageBox(NULL,filename,L"Not found",MB_OK);

}


void CleanDatabase()
{

	// Clean out Database

	dh=CeOpenDatabase(&did,TEXT("AatpCache"),MAKELONG(CEVT_LPWSTR,0x42),0/*CEDB_AUTOINCREMENT*/,NULL);

	if (dh==INVALID_HANDLE_VALUE)
	{

	// not open
		MessageBox(NULL,L"Open Failure",L"Database",MB_OK);
	}
	else
	{

		// Go to start of database
		CeSeekDatabase(dh,CEDB_SEEK_BEGINNING,0,&dwIndex);

		
		// Start Looking

		wsprintf(filename,TEXT("but1.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but2.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but3.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but4.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but5.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but6.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but7.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but8.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("but9.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userA.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userB.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userC.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("userD.bmp\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butF.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butV.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butP.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butM.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butT.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butX.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butH.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("butS.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.gif\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.mcs\0"));
		SeekAndDestroy();
		wsprintf(filename,TEXT("barney.cdf\0"));
		SeekAndDestroy(); 
}

	CloseHandle(dh);

}




//***************************************//

void CCleanBarneyView::OnClean() 
{

	// Clean out after Barney

	CleanFiles();
	CleanRegistry();
	for (int i=1;i<5;i++)
		CleanDatabase();
	MessageBox(L"Finished!",L"All done!");
}
