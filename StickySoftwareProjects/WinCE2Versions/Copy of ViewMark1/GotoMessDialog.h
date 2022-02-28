#if !defined(AFX_GOTOMESSDIALOG_H__CEE2BF74_2DE6_11D2_93BD_080000380657__INCLUDED_)
#define AFX_GOTOMESSDIALOG_H__CEE2BF74_2DE6_11D2_93BD_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GotoMessDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGotoMessDialog dialog

class CGotoMessDialog : public CDialog
{
// Construction
public:
	CGotoMessDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGotoMessDialog)
	enum { IDD = IDD_GOTO_MESS };
	short	m_messnumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGotoMessDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGotoMessDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOTOMESSDIALOG_H__CEE2BF74_2DE6_11D2_93BD_080000380657__INCLUDED_)
