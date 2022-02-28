// CamLink1.h : main header file for the CAMLINK1 application
//

#if !defined(AFX_CAMLINK1_H__ED15E457_E3ED_11D1_9338_080000380657__INCLUDED_)
#define AFX_CAMLINK1_H__ED15E457_E3ED_11D1_9338_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCamLink1App:
// See CamLink1.cpp for the implementation of this class
//

class CCamLink1App : public CWinApp
{
public:
	CCamLink1App(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamLink1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCamLink1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMLINK1_H__ED15E457_E3ED_11D1_9338_080000380657__INCLUDED_)
