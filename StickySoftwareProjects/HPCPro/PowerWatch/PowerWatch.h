// PowerWatch.h : main header file for the POWERWATCH application
//

#if !defined(AFX_POWERWATCH_H__71B93EC5_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
#define AFX_POWERWATCH_H__71B93EC5_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchApp:
// See PowerWatch.cpp for the implementation of this class
//

class CPowerWatchApp : public CWinApp
{
public:
	CPowerWatchApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerWatchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPowerWatchApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERWATCH_H__71B93EC5_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
