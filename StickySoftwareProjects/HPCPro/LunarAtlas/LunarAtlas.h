// LunarAtlas.h : main header file for the LUNARATLAS application
//

#if !defined(AFX_LUNARATLAS_H__C2DD5445_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
#define AFX_LUNARATLAS_H__C2DD5445_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasApp:
// See LunarAtlas.cpp for the implementation of this class
//

class CLunarAtlasApp : public CWinApp
{
public:
	CLunarAtlasApp(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLunarAtlasApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLunarAtlasApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUNARATLAS_H__C2DD5445_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
