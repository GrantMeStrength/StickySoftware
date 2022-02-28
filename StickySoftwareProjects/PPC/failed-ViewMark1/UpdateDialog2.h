#if !defined(AFX_UPDATEDIALOG2_H__B7471723_AC46_11D1_92DE_0080C809CB22__INCLUDED_)
#define AFX_UPDATEDIALOG2_H__B7471723_AC46_11D1_92DE_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UpdateDialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUpdateDialog2 dialog

class CUpdateDialog2 : public CDialog
{
// Construction
public:
	CUpdateDialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdateDialog2)
	enum { IDD = IDD_UPDATE_DIALOG };
	int		m_how;
	int		m_who;
	int		m_delayvalue;
	int		m_jumpvalue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpdateDialog2)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEDIALOG2_H__B7471723_AC46_11D1_92DE_0080C809CB22__INCLUDED_)
