#if !defined(AFX_KEY_DIALOG_H__527ABC42_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
#define AFX_KEY_DIALOG_H__527ABC42_A978_11D1_9F52_0000E8CE6806__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Key_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKey_Dialog dialog

class CKey_Dialog : public CDialog
{
// Construction
public:
	void KillDialog();
	CKey_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKey_Dialog)
	enum { IDD = IDD_KEY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKey_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKey_Dialog)
	afx_msg void OnPaint();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEY_DIALOG_H__527ABC42_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
