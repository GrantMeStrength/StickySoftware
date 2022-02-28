#if !defined(AFX_SCROLL_VERT_DIALOG_H__56820593_ECB3_11D1_9346_080000380657__INCLUDED_)
#define AFX_SCROLL_VERT_DIALOG_H__56820593_ECB3_11D1_9346_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Scroll_Vert_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScroll_Vert_Dialog dialog

class CScroll_Vert_Dialog : public CDialog
{
// Construction
public:
	CScroll_Vert_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScroll_Vert_Dialog)
	enum { IDD = IDD_SCROLL_VERT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScroll_Vert_Dialog)
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScroll_Vert_Dialog)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLL_VERT_DIALOG_H__56820593_ECB3_11D1_9346_080000380657__INCLUDED_)
