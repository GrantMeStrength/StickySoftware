// TestPro.h : main header file for the TESTPRO application
//

#if !defined(AFX_TESTPRO_H__0F791C15_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TESTPRO_H__0F791C15_03B2_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestProApp:
// See TestPro.cpp for the implementation of this class
//

class CTestProApp : public CWinApp
{
public:
	CTestProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestProApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPRO_H__0F791C15_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
