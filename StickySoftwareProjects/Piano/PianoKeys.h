#if !defined(AFX_PIANOKEYS_H__8FD19746_CA0F_11D1_9301_0080C809CB22__INCLUDED_)
#define AFX_PIANOKEYS_H__8FD19746_CA0F_11D1_9301_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PianoKeys.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPianoKeys dialog

class CPianoKeys : public CDialog
{
// Construction
public:
	void Playback();
	CPianoKeys(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPianoKeys)
	enum { IDD = IDD_KEYBOARD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPianoKeys)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPianoKeys)
	afx_msg void OnA1();
	afx_msg void OnA1s();
	afx_msg void OnB1();
	afx_msg void OnC1s();
	afx_msg void OnC2();
	afx_msg void OnD1();
	afx_msg void OnD1s();
	afx_msg void OnE1();
	afx_msg void OnF1();
	afx_msg void OnF1s();
	afx_msg void OnG1();
	afx_msg void OnG1s();
	afx_msg void OnMc();
	afx_msg void OnSpace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIANOKEYS_H__8FD19746_CA0F_11D1_9301_0080C809CB22__INCLUDED_)
