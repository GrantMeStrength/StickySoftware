#if !defined(AFX_QUICK_DIALOG_H__06023DE3_B356_11D1_92E5_0080C809CB22__INCLUDED_)
#define AFX_QUICK_DIALOG_H__06023DE3_B356_11D1_92E5_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Quick_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuick_Dialog dialog

class CQuick_Dialog : public CDialog
{
// Construction
public:
	CWnd* parent;
	CQuick_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuick_Dialog)
	enum { IDD = IDD_QUICK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuick_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuick_Dialog)
	afx_msg void OnButtonOk();
	afx_msg void OnQbuttonN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUICK_DIALOG_H__06023DE3_B356_11D1_92E5_0080C809CB22__INCLUDED_)
