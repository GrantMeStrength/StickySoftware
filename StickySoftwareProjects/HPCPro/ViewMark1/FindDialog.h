#if !defined(AFX_FINDDIALOG_H__78A92D27_A863_11D1_92DA_0080C809CB22__INCLUDED_)
#define AFX_FINDDIALOG_H__78A92D27_A863_11D1_92DA_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FindDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindDialog dialog

class CFindDialog : public CDialog
{
// Construction
public:
	int m_body;
	CFindDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindDialog)
	enum { IDD = IDD_SEARCH_DIALOG };
	int	m_const;
	int	m_solar;
	int	m_star;
	int		m_messier;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindDialog)
	afx_msg void OnCloseupComboGotoconst();
	afx_msg void OnCloseupComboGotosolar();
	afx_msg void OnCloseupComboGotostar();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDDIALOG_H__78A92D27_A863_11D1_92DA_0080C809CB22__INCLUDED_)
