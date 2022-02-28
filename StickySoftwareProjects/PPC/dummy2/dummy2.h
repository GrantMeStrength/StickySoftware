// dummy2.h : main header file for the DUMMY2 application
//

#if !defined(AFX_DUMMY2_H__A646E7AB_2494_11D2_93AE_080000380657__INCLUDED_)
#define AFX_DUMMY2_H__A646E7AB_2494_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDummy2App:
// See dummy2.cpp for the implementation of this class
//

class CDummy2App : public CWinApp
{
public:
	CDummy2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummy2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDummy2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMY2_H__A646E7AB_2494_11D2_93AE_080000380657__INCLUDED_)
