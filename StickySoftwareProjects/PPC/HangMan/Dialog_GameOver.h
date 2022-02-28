#if !defined(AFX_DIALOG_GAMEOVER_H__98448DE8_30F2_11D2_93C2_080000380657__INCLUDED_)
#define AFX_DIALOG_GAMEOVER_H__98448DE8_30F2_11D2_93C2_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_GameOver.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_GameOver dialog

class CDialog_GameOver : public CDialog
{
// Construction
public:
	CDialog_GameOver(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_GameOver)
	enum { IDD = IDD_DIALOG_GAME };
	CString	m_string2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_GameOver)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_GameOver)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_GAMEOVER_H__98448DE8_30F2_11D2_93C2_080000380657__INCLUDED_)
