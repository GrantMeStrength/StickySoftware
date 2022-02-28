#if !defined(AFX_GOTORADECDIALOG_H__527ABC41_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
#define AFX_GOTORADECDIALOG_H__527ABC41_A978_11D1_9F52_0000E8CE6806__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GotoRaDecDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGotoRaDecDialog dialog

class CGotoRaDecDialog : public CDialog
{
// Construction
public:
	CGotoRaDecDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGotoRaDecDialog)
	enum { IDD = IDD_GOTO_RADEC_DIALOG };
	int		m_gotodecmin;
	int		m_gotoramin;
	int		m_gotodecdeg;
	int		m_gotorahour;
	int		m_gotodecsec;
	int		m_gotorasec;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGotoRaDecDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGotoRaDecDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOTORADECDIALOG_H__527ABC41_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
