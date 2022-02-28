// PocketUniversePro.h : main header file for the POCKETUNIVERSEPRO application
//

#if !defined(AFX_POCKETUNIVERSEPRO_H__B191AD56_03B3_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_POCKETUNIVERSEPRO_H__B191AD56_03B3_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProApp:
// See PocketUniversePro.cpp for the implementation of this class
//

class CPocketUniverseProApp : public CWinApp
{
public:
	CPocketUniverseProApp(LPCTSTR lpszHelpName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPocketUniverseProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPocketUniverseProApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POCKETUNIVERSEPRO_H__B191AD56_03B3_11D3_B723_00A0C9B5E577__INCLUDED_)
