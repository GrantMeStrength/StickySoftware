// CleanBarney.h : main header file for the CLEANBARNEY application
//

#if !defined(AFX_CLEANBARNEY_H__F18E3B96_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
#define AFX_CLEANBARNEY_H__F18E3B96_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyApp:
// See CleanBarney.cpp for the implementation of this class
//

class CCleanBarneyApp : public CWinApp
{
public:
	CCleanBarneyApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCleanBarneyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCleanBarneyApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEANBARNEY_H__F18E3B96_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
