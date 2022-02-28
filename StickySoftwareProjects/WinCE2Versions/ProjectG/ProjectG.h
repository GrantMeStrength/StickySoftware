// ProjectG.h : main header file for the PROJECTG application
//

#if !defined(AFX_PROJECTG_H__FFE8F5BB_F16C_11D1_9350_080000380657__INCLUDED_)
#define AFX_PROJECTG_H__FFE8F5BB_F16C_11D1_9350_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProjectGApp:
// See ProjectG.cpp for the implementation of this class
//

class CProjectGApp : public CWinApp
{
public:
	CProjectGApp(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProjectGApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTG_H__FFE8F5BB_F16C_11D1_9350_080000380657__INCLUDED_)
