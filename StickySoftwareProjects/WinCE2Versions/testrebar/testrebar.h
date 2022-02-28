// testrebar.h : main header file for the TESTREBAR application
//

#if !defined(AFX_TESTREBAR_H__A7F7DAE8_206C_11D2_93A5_080000380657__INCLUDED_)
#define AFX_TESTREBAR_H__A7F7DAE8_206C_11D2_93A5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestrebarApp:
// See testrebar.cpp for the implementation of this class
//

class CTestrebarApp : public CWinApp
{
public:
	CTestrebarApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestrebarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestrebarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTREBAR_H__A7F7DAE8_206C_11D2_93A5_080000380657__INCLUDED_)
