// Lottery.h : main header file for the LOTTERY application
//

#if !defined(AFX_LOTTERY_H__50759CC5_886E_11D2_B67E_00A0C9B5E577__INCLUDED_)
#define AFX_LOTTERY_H__50759CC5_886E_11D2_B67E_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLotteryApp:
// See Lottery.cpp for the implementation of this class
//

class CLotteryApp : public CWinApp
{
public:
	CLotteryApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLotteryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLotteryApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTERY_H__50759CC5_886E_11D2_B67E_00A0C9B5E577__INCLUDED_)
