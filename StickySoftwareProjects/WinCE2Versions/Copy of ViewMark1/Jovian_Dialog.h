#if !defined(AFX_JOVIAN_DIALOG_H__1FD9BCC3_F179_11D1_9350_080000380657__INCLUDED_)
#define AFX_JOVIAN_DIALOG_H__1FD9BCC3_F179_11D1_9350_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Jovian_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJovian_Dialog dialog

class CJovian_Dialog : public CDialog
{
// Construction
public:
	CJovian_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJovian_Dialog)
	enum { IDD = IDD_DIALOG_JOVIAN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJovian_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJovian_Dialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOVIAN_DIALOG_H__1FD9BCC3_F179_11D1_9350_080000380657__INCLUDED_)
