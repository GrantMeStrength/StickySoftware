// test9.h : main header file for the TEST9 application
//

#if !defined(AFX_TEST9_H__222E7606_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
#define AFX_TEST9_H__222E7606_E75A_11D2_B703_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest9App:
// See test9.cpp for the implementation of this class
//

class CTest9App : public CWinApp
{
public:
	CTest9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest9App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST9_H__222E7606_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
