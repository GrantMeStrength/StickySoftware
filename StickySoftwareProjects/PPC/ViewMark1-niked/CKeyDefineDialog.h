#if !defined(AFX_CKEYDEFINEDIALOG_H__A7F7DAF7_206C_11D2_93A5_080000380657__INCLUDED_)
#define AFX_CKEYDEFINEDIALOG_H__A7F7DAF7_206C_11D2_93A5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CKeyDefineDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCKeyDefineDialog dialog

class CCKeyDefineDialog : public CDialog
{
// Construction
public:
	short int keymode;
	CCKeyDefineDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCKeyDefineDialog)
	enum { IDD = IDD_KEY_DEFINE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCKeyDefineDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCKeyDefineDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioLook();
	afx_msg void OnRadioTime();
	afx_msg void OnRadioZoom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CKEYDEFINEDIALOG_H__A7F7DAF7_206C_11D2_93A5_080000380657__INCLUDED_)
