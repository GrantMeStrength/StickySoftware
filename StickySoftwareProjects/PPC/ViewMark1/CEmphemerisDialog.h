#if !defined(AFX_CEMPHEMERISDIALOG_H__33F0C894_838C_11D2_B677_00A0C9B5E577__INCLUDED_)
#define AFX_CEMPHEMERISDIALOG_H__33F0C894_838C_11D2_B677_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CEmphemerisDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCEmphemerisDialog dialog

class CCEmphemerisDialog : public CDialog
{
// Construction
public:
	CCEmphemerisDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCEmphemerisDialog)
	enum { IDD = IDD_EPHEMERIS_DIALOG };
	CString	m_date;
	CString	m_mercury;
	CString	m_jupiter;
	CString	m_mars;
	CString	m_neptune;
	CString	m_pluto;
	CString	m_saturn;
	CString	m_uranus;
	CString	m_venus;
	CString	m_user;
	CString	m_moon;
	CString	m_sun;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCEmphemerisDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCEmphemerisDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEMPHEMERISDIALOG_H__33F0C894_838C_11D2_B677_00A0C9B5E577__INCLUDED_)
