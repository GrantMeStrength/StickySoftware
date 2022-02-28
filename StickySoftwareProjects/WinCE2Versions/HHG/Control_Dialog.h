#if !defined(AFX_CONTROL_DIALOG_H__5A0D9D76_3744_11D2_93CE_080000380657__INCLUDED_)
#define AFX_CONTROL_DIALOG_H__5A0D9D76_3744_11D2_93CE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Control_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControl_Dialog dialog

class CControl_Dialog : public CDialog
{
// Construction
public:
	CControl_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CControl_Dialog)
	enum { IDD = IDD_CONTROL_DIALOG };
	CString	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CControl_Dialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL_DIALOG_H__5A0D9D76_3744_11D2_93CE_080000380657__INCLUDED_)
