// Life2.h : main header file for the LIFE2 application
//

#if !defined(AFX_LIFE2_H__BF83F287_1C0B_11D2_9395_080000380657__INCLUDED_)
#define AFX_LIFE2_H__BF83F287_1C0B_11D2_9395_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLife2App:
// See Life2.cpp for the implementation of this class
//

class CLife2App : public CWinApp
{
public:
	CLife2App(LPCTSTR lpszAppName, LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLife2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLife2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFE2_H__BF83F287_1C0B_11D2_9395_080000380657__INCLUDED_)
