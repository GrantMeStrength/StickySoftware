#if !defined(AFX_TRAFFICSIGNALCTL_H__385A1F0A_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_)
#define AFX_TRAFFICSIGNALCTL_H__385A1F0A_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TrafficSignalCtl.h : Declaration of the CTrafficSignalCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl : See TrafficSignalCtl.cpp for implementation.

class CTrafficSignal;


class CTrafficSignalCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTrafficSignalCtrl)

// Constructor
public:
	CTrafficSignalCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrafficSignalCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	CTrafficSignal * m_pSignal;
	~CTrafficSignalCtrl();

	DECLARE_OLECREATE_EX(CTrafficSignalCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTrafficSignalCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTrafficSignalCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTrafficSignalCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTrafficSignalCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTrafficSignalCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTrafficSignalCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTrafficSignalCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAFFICSIGNALCTL_H__385A1F0A_EDB2_11D2_B709_00A0C9B5E577__INCLUDED)
