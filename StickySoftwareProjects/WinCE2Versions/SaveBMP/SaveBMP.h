// SaveBMP.h : main header file for the SAVEBMP application
//

#if !defined(AFX_SAVEBMP_H__DA5A9427_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_)
#define AFX_SAVEBMP_H__DA5A9427_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSaveBMPApp:
// See SaveBMP.cpp for the implementation of this class
//

class CSaveBMPApp : public CWinApp
{
public:
	CSaveBMPApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveBMPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSaveBMPApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEBMP_H__DA5A9427_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_)
