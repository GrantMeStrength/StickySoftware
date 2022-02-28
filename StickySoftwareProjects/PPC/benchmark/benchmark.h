// benchmark.h : main header file for the BENCHMARK application
//

#if !defined(AFX_BENCHMARK_H__BE40BBD8_22C6_11D2_93AA_080000380657__INCLUDED_)
#define AFX_BENCHMARK_H__BE40BBD8_22C6_11D2_93AA_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkApp:
// See benchmark.cpp for the implementation of this class
//

class CBenchmarkApp : public CWinApp
{
public:
	CBenchmarkApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBenchmarkApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARK_H__BE40BBD8_22C6_11D2_93AA_080000380657__INCLUDED_)
