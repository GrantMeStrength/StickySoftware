#if !defined(AFX_GOTOALTAZDIALOG_H__527ABC40_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
#define AFX_GOTOALTAZDIALOG_H__527ABC40_A978_11D1_9F52_0000E8CE6806__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GotoAltAzDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGotoAltAzDialog dialog

class CGotoAltAzDialog : public CDialog
{
// Construction
public:
	CGotoAltAzDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGotoAltAzDialog)
	enum { IDD = IDD_GOTO_ALTAZ_DIALOG };
	int		m_gotoaltdeg;
	int		m_gotoaltmin;
	int		m_gotoaltsec;
	int		m_gotoazdeg;
	int		m_gotoazmin;
	int		m_gotoazsec;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGotoAltAzDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGotoAltAzDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOTOALTAZDIALOG_H__527ABC40_A978_11D1_9F52_0000E8CE6806__INCLUDED_)
