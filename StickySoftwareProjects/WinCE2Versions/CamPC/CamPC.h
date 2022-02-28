// CamPC.h : main header file for the CAMPC application
//

#if !defined(AFX_CAMPC_H__77A1AC17_E4C9_11D1_933D_080000380657__INCLUDED_)
#define AFX_CAMPC_H__77A1AC17_E4C9_11D1_933D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCamPCApp:
// See CamPC.cpp for the implementation of this class
//

class CCamPCApp : public CWinApp
{
public:
	CCamPCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamPCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCamPCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPC_H__77A1AC17_E4C9_11D1_933D_080000380657__INCLUDED_)
