// dummy.h : main header file for the DUMMY application
//

#if !defined(AFX_DUMMY_H__03FDD217_4B0B_11D2_93F1_080000380657__INCLUDED_)
#define AFX_DUMMY_H__03FDD217_4B0B_11D2_93F1_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDummyApp:
// See dummy.cpp for the implementation of this class
//

class CDummyApp : public CWinApp
{
public:
	CDummyApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDummyApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMY_H__03FDD217_4B0B_11D2_93F1_080000380657__INCLUDED_)
