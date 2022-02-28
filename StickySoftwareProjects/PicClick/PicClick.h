// PicClick.h : main header file for the PICCLICK application
//

#if !defined(AFX_PICCLICK_H__C39557B5_B742_11D1_92E8_0080C809CB22__INCLUDED_)
#define AFX_PICCLICK_H__C39557B5_B742_11D1_92E8_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicClickApp:
// See PicClick.cpp for the implementation of this class
//

class CPicClickApp : public CWinApp
{
public:
	CPicClickApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicClickApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPicClickApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICCLICK_H__C39557B5_B742_11D1_92E8_0080C809CB22__INCLUDED_)
