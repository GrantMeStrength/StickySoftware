#if !defined(AFX_LOCATIONDIALOG_H__E2EF0C63_A840_11D1_92DA_0080C809CB22__INCLUDED_)
#define AFX_LOCATIONDIALOG_H__E2EF0C63_A840_11D1_92DA_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// LocationDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LocationDialog dialog

class LocationDialog : public CDialog
{
// Construction
public:
	
	LocationDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LocationDialog)
	enum { IDD = IDD_WHERE_DIALOG };
	int		m_LAT_MIN;
	int		m_LAT_DEG;
	int		m_LAT_SEC;
	int		m_LONG_DEG;
	int		m_LONG_MIN;
	int		m_LONG_SEC;
	int		m_timezone;
	int		m_where;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LocationDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LocationDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnCloseupComboWhere();
	afx_msg void OnButtonNorthSouth();
	afx_msg void OnButtonEastWest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOCATIONDIALOG_H__E2EF0C63_A840_11D1_92DA_0080C809CB22__INCLUDED_)
