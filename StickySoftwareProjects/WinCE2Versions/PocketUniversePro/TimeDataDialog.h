#if !defined(AFX_TIMEDATADIALOG_H__1EFCD764_03B4_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TIMEDATADIALOG_H__1EFCD764_03B4_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TimeDataDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeDataDialog dialog

class CTimeDataDialog : public CDialog
{
// Construction
public:
	CTimeDataDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeDataDialog)
	enum { IDD = IDD_WHEN_TIMEDATE };
	BOOL		m_daylight;
	short int	m_day;
	short int	m_hour;
	short int	m_min;
	short int	m_month;
	short int	m_sec;
	short int	m_year;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeDataDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeDataDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEDATADIALOG_H__1EFCD764_03B4_11D3_B723_00A0C9B5E577__INCLUDED_)
