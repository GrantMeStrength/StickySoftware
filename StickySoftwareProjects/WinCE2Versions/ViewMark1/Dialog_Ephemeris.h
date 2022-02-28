#if !defined(AFX_DIALOG_EPHEMERIS_H__E4DAFD24_E105_11D2_B6F7_00A0C9B5E577__INCLUDED_)
#define AFX_DIALOG_EPHEMERIS_H__E4DAFD24_E105_11D2_B6F7_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_Ephemeris.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Ephemeris dialog

class CDialog_Ephemeris : public CDialog
{
// Construction
public:
	CDialog_Ephemeris(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Ephemeris)
	enum { IDD = IDD_DIALOG_EPHEMERIS };
	CString	m_date;
	CString	m_jupiter;
	CString	m_mars;
	CString	m_mercury;
	CString	m_moon;
	CString	m_neptune;
	CString	m_pluto;
	CString	m_saturn;
	CString	m_sun;
	CString	m_uranus;
	CString	m_user;
	CString	m_venus;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Ephemeris)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Ephemeris)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_EPHEMERIS_H__E4DAFD24_E105_11D2_B6F7_00A0C9B5E577__INCLUDED_)
