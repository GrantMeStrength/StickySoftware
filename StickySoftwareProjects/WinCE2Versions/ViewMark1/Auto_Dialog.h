#if !defined(AFX_AUTO_DIALOG_H__03B57034_A9E0_11D1_92DC_0080C809CB22__INCLUDED_)
#define AFX_AUTO_DIALOG_H__03B57034_A9E0_11D1_92DC_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Auto_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAuto_Dialog dialog

class CAuto_Dialog : public CDialog
{
// Construction
public:
	CAuto_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAuto_Dialog)
	enum { IDD = IDD_AUTO_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAuto_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAuto_Dialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTO_DIALOG_H__03B57034_A9E0_11D1_92DC_0080C809CB22__INCLUDED_)
