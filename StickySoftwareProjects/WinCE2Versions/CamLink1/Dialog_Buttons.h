#if !defined(AFX_DIALOG_BUTTONS_H__29531293_E962_11D1_9344_080000380657__INCLUDED_)
#define AFX_DIALOG_BUTTONS_H__29531293_E962_11D1_9344_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_Buttons.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Buttons dialog

class CDialog_Buttons : public CDialog
{
// Construction
public:
	CDialog_Buttons(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Buttons)
	enum { IDD = IDD_DIALOG_BUTTONS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Buttons)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Buttons)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BUTTONS_H__29531293_E962_11D1_9344_080000380657__INCLUDED_)
