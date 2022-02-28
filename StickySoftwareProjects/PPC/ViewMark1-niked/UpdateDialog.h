#if !defined(AFX_UPDATEDIALOG_H__39EE3103_AC34_11D1_92DE_0080C809CB22__INCLUDED_)
#define AFX_UPDATEDIALOG_H__39EE3103_AC34_11D1_92DE_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UpdateDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUpdateDialog dialog

class CUpdateDialog : public CDialog
{
// Construction
public:
	CUpdateDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdateDialog)
	enum { IDD = IDD_UPDATE_DIALOG };
	int		m_how;
	int		m_who;
	int		m_delayvalue;
	int		m_jumpvalue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpdateDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEDIALOG_H__39EE3103_AC34_11D1_92DE_0080C809CB22__INCLUDED_)
