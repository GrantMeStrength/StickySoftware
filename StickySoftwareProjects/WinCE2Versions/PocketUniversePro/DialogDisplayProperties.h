#if !defined(AFX_DIALOGDISPLAYPROPERTIES_H__3593A8C2_0456_11D3_B724_00A0C9B5E577__INCLUDED_)
#define AFX_DIALOGDISPLAYPROPERTIES_H__3593A8C2_0456_11D3_B724_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogDisplayProperties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogDisplayProperties dialog

class CDialogDisplayProperties : public CDialog
{
// Construction
public:
	CDialogDisplayProperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogDisplayProperties)
	enum { IDD = IDD_SETTINGS_DIALOG };
	BOOL	m_details;
	BOOL	m_ecliptic;
	BOOL	m_grid;
	BOOL	m_hide;
	BOOL	m_horizon;
	BOOL	m_hourglass;
	BOOL	m_invert;
	BOOL	m_labels;
	BOOL	m_markers;
	BOOL	m_mess;
	BOOL	m_moongfx;
	BOOL	m_outline;
	BOOL	m_parallax;
	BOOL	m_planets;
	BOOL	m_realsize;
	BOOL	m_sites;
	BOOL	m_sm;
	BOOL	m_stars;
	int		m_mag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogDisplayProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogDisplayProperties)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGDISPLAYPROPERTIES_H__3593A8C2_0456_11D3_B724_00A0C9B5E577__INCLUDED_)
