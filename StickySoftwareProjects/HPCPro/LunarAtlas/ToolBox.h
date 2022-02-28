#if !defined(AFX_TOOLBOX_H__20B09A23_CD8A_11D2_B6DC_00A0C9B5E577__INCLUDED_)
#define AFX_TOOLBOX_H__20B09A23_CD8A_11D2_B6DC_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ToolBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToolBox dialog

class CToolBox : public CDialog
{
// Construction
public:
	CToolBox(CWnd* pParent = NULL);   // standard constructor
	void KillDialog();
	void Redraw();
	CSliderCtrl* pSlide;
	CBitmapButton buttonup,buttondown,buttonleft,buttonright;
	CBitmapButton buttonspinanti,buttonspinclock,buttonzoomin,buttonzoomout;

// Dialog Data
	//{{AFX_DATA(CToolBox)
	enum { IDD = IDD_TOOLBOX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CToolBox)
	afx_msg void OnButtonup();
	afx_msg void OnButtondown();
	afx_msg void OnButtonleft();
	afx_msg void OnButtonright();
	afx_msg void OnButtonspinclock();
	afx_msg void OnButtonzoomin();
	afx_msg void OnButtonzoomout();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonspinanti();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBOX_H__20B09A23_CD8A_11D2_B6DC_00A0C9B5E577__INCLUDED_)
