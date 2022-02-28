#if !defined(AFX_SETTINGSDIALOG_H__78A92D26_A863_11D1_92DA_0080C809CB22__INCLUDED_)
#define AFX_SETTINGSDIALOG_H__78A92D26_A863_11D1_92DA_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SettingsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog

class CSettingsDialog : public CDialog
{
// Construction
public:
	CSettingsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingsDialog)
	enum { IDD = IDD_SETTINGS_DIALOG };
	BOOL	m_horizon;
	BOOL	m_planets;
	BOOL	m_stars;
	BOOL	m_sites;
	BOOL	m_markers;
	BOOL	m_labels;
	BOOL	m_invert;
	int		m_visible_mags;
	BOOL	m_text;
	BOOL	m_mess;
	BOOL	m_parallax;
	BOOL	m_hide;
	BOOL	m_outline;
	BOOL	m_sunmoon;
	BOOL	m_realsize;
	BOOL	m_grid;
	BOOL	m_hourglass;
	BOOL	m_ecliptic;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingsDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGSDIALOG_H__78A92D26_A863_11D1_92DA_0080C809CB22__INCLUDED_)
