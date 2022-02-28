#if !defined(AFX_TIMEDATEDIALOG_H__E2EF0C64_A840_11D1_92DA_0080C809CB22__INCLUDED_)
#define AFX_TIMEDATEDIALOG_H__E2EF0C64_A840_11D1_92DA_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TimeDateDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeDateDialog dialog

class CTimeDateDialog : public CDialog
{
// Construction
public:
	CTimeDateDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeDateDialog)
	enum { IDD = IDD_WHEN_DIALOG };
	int		m_month;
	int		m_year;
	int		m_day;
	int		m_hour;
	int		m_min;
	int		m_sec;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeDateDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeDateDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckDaylight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEDATEDIALOG_H__E2EF0C64_A840_11D1_92DA_0080C809CB22__INCLUDED_)
