// PalmUniverse.h : main header file for the PALMUNIVERSE application
//

#if !defined(AFX_PALMUNIVERSE_H__445EBEE7_1FA6_11D2_93A4_080000380657__INCLUDED_)
#define AFX_PALMUNIVERSE_H__445EBEE7_1FA6_11D2_93A4_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseApp:
// See PalmUniverse.cpp for the implementation of this class
//

class CPalmUniverseApp : public CWinApp
{
public:
	CPalmUniverseApp(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalmUniverseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPalmUniverseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALMUNIVERSE_H__445EBEE7_1FA6_11D2_93A4_080000380657__INCLUDED_)
