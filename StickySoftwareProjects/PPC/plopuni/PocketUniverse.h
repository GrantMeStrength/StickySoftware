// PocketUniverse.h : main header file for the POCKETUNIVERSE application
//

#if !defined(AFX_POCKETUNIVERSE_H__680D5C57_24BC_11D2_93AE_080000380657__INCLUDED_)
#define AFX_POCKETUNIVERSE_H__680D5C57_24BC_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseApp:
// See PocketUniverse.cpp for the implementation of this class
//

class CPocketUniverseApp : public CWinApp
{
public:
	CPocketUniverseApp(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPocketUniverseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPocketUniverseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POCKETUNIVERSE_H__680D5C57_24BC_11D2_93AE_080000380657__INCLUDED_)
