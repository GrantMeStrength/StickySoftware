// HangMan.h : main header file for the HANGMAN application
//

#if !defined(AFX_HANGMAN_H__98448DD8_30F2_11D2_93C2_080000380657__INCLUDED_)
#define AFX_HANGMAN_H__98448DD8_30F2_11D2_93C2_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHangManApp:
// See HangMan.cpp for the implementation of this class
//

class CHangManApp : public CWinApp
{
public:
	CHangManApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHangManApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHangManApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANGMAN_H__98448DD8_30F2_11D2_93C2_080000380657__INCLUDED_)
