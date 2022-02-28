#if !defined(AFX_VERTICAL_DIALOG_H__56820594_ECB3_11D1_9346_080000380657__INCLUDED_)
#define AFX_VERTICAL_DIALOG_H__56820594_ECB3_11D1_9346_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Vertical_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVertical_Dialog dialog

class CVertical_Dialog : public CDialog
{
// Construction
public:
	CVertical_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVertical_Dialog)
	enum { IDD = IDD_VERT_SCROLL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVertical_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVertical_Dialog)
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERTICAL_DIALOG_H__56820594_ECB3_11D1_9346_080000380657__INCLUDED_)
