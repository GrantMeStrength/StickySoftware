#if !defined(AFX_DIALOG_GAME_LOST_H__F810F744_31BB_11D2_93C3_080000380657__INCLUDED_)
#define AFX_DIALOG_GAME_LOST_H__F810F744_31BB_11D2_93C3_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_Game_Lost.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Game_Lost dialog

class CDialog_Game_Lost : public CDialog
{
// Construction
public:
	CDialog_Game_Lost(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Game_Lost)
	enum { IDD = IDD_DIALOG_GAME_LOST };
	CString	m_string2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Game_Lost)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Game_Lost)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_GAME_LOST_H__F810F744_31BB_11D2_93C3_080000380657__INCLUDED_)
