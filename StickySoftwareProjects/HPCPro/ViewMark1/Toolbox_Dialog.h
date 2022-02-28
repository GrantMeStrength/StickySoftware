#if !defined(AFX_TOOLBOX_DIALOG_H__D7986453_F793_11D1_932F_080000380657__INCLUDED_)
#define AFX_TOOLBOX_DIALOG_H__D7986453_F793_11D1_932F_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Toolbox_Dialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToolbox_Dialog dialog

class CToolbox_Dialog : public CDialog
{
// Construction
public:
	void UpdateSlider();
	void KillDialog();
	CSliderCtrl* pSlide;
	CBitmapButton buttonup,buttondown,buttonleft,buttonright;
	CBitmapButton buttonnorth,buttonsouth,buttoneast,buttonwest;
	CBitmapButton buttontimeplus,buttontimeminus,buttonzoomin,buttonzoomout;
	void Redraw();
	CToolbox_Dialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CToolbox_Dialog)
	enum { IDD = IDD_TOOLBOX_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolbox_Dialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CToolbox_Dialog)
	virtual void OnOK();
	afx_msg void OnButtonEast();
	afx_msg void OnButtonNorth();
	afx_msg void OnButtonSouth();
	afx_msg void OnButtonTimeminus();
	afx_msg void OnButtonTimeplus();
	afx_msg void OnButtonWest();
	afx_msg void OnButtonZoomin();
	afx_msg void OnButtonZoomout();
	afx_msg void OnButtondown();
	afx_msg void OnButtonleft();
	afx_msg void OnButtonright();
	afx_msg void OnButtonup();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBOX_DIALOG_H__D7986453_F793_11D1_932F_080000380657__INCLUDED_)
