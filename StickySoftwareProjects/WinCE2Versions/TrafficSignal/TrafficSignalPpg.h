#if !defined(AFX_TRAFFICSIGNALPPG_H__385A1F0C_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_)
#define AFX_TRAFFICSIGNALPPG_H__385A1F0C_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TrafficSignalPpg.h : Declaration of the CTrafficSignalPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage : See TrafficSignalPpg.cpp.cpp for implementation.

class CTrafficSignalPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTrafficSignalPropPage)
	DECLARE_OLECREATE_EX(CTrafficSignalPropPage)

// Constructor
public:
	CTrafficSignalPropPage();

// Dialog Data
	//{{AFX_DATA(CTrafficSignalPropPage)
	enum { IDD = IDD_PROPPAGE_TRAFFICSIGNAL };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTrafficSignalPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAFFICSIGNALPPG_H__385A1F0C_EDB2_11D2_B709_00A0C9B5E577__INCLUDED)
