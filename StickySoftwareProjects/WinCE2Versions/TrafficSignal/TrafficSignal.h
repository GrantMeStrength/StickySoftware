#if !defined(AFX_TRAFFICSIGNAL_H__385A1F02_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_)
#define AFX_TRAFFICSIGNAL_H__385A1F02_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TrafficSignal.h : main header file for TRAFFICSIGNAL.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalApp : See TrafficSignal.cpp for implementation.

class CTrafficSignalApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAFFICSIGNAL_H__385A1F02_EDB2_11D2_B709_00A0C9B5E577__INCLUDED)
