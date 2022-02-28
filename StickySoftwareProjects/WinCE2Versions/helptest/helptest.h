// helptest.h : main header file for the HELPTEST application
//

#if !defined(AFX_HELPTEST_H__A94940F5_EF33_11D1_934D_080000380657__INCLUDED_)
#define AFX_HELPTEST_H__A94940F5_EF33_11D1_934D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHelptestApp:
// See helptest.cpp for the implementation of this class
//

class CHelptestApp : public CWinApp
{
public:
	CHelptestApp(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelptestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHelptestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPTEST_H__A94940F5_EF33_11D1_934D_080000380657__INCLUDED_)
