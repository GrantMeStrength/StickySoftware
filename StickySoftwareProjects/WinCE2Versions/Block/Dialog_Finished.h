#if !defined(AFX_DIALOG_FINISHED_H__9176FE47_35E7_11D2_93CA_080000380657__INCLUDED_)
#define AFX_DIALOG_FINISHED_H__9176FE47_35E7_11D2_93CA_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_Finished.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Finished dialog

class CDialog_Finished : public CDialog
{
// Construction
public:
	CDialog_Finished(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Finished)
	enum { IDD = IDD_DIALOG_FINISHED };
	CString	m_string;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Finished)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Finished)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_FINISHED_H__9176FE47_35E7_11D2_93CA_080000380657__INCLUDED_)
