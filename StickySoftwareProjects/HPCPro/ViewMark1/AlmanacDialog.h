#if !defined(AFX_ALMANACDIALOG_H__80CF3673_B857_11D2_B6BC_00A0C9B5E577__INCLUDED_)
#define AFX_ALMANACDIALOG_H__80CF3673_B857_11D2_B6BC_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AlmanacDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlmanacDialog dialog

class CAlmanacDialog : public CDialog
{
// Construction
public:


	CAlmanacDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlmanacDialog)
	enum { IDD = IDD_DIALOG_ALMANAC };
	CString	m_date;
	CString	m_jupiter;
	CString	m_mars;
	CString	m_moon;
	CString	m_neptune;
	CString	m_pluto;
	CString	m_saturn;
	CString	m_sun;
	CString	m_uranus;
	CString	m_user;
	CString	m_venus;
	CString	m_mercury;
	CString	m_plop;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlmanacDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlmanacDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALMANACDIALOG_H__80CF3673_B857_11D2_B6BC_00A0C9B5E577__INCLUDED_)
