// TZ2.h : main header file for the TZ2 application
//

#if !defined(AFX_TZ2_H__BA6D2575_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
#define AFX_TZ2_H__BA6D2575_E83C_11D2_B704_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTZ2App:
// See TZ2.cpp for the implementation of this class
//

class CTZ2App : public CWinApp
{
public:
	CTZ2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTZ2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTZ2App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TZ2_H__BA6D2575_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
