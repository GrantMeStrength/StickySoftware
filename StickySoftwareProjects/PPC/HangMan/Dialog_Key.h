#if !defined(AFX_DIALOG_KEY_H__98448DE7_30F2_11D2_93C2_080000380657__INCLUDED_)
#define AFX_DIALOG_KEY_H__98448DE7_30F2_11D2_93C2_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dialog_Key.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog_Key dialog

class CDialog_Key : public CDialog
{
// Construction
public:
	void KillDialog();
	void ResetKeys();
	CDialog_Key(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialog_Key)
	enum { IDD = IDD_DIALOG_KEY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Key)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog_Key)
	afx_msg void OnButtonA();
	afx_msg void OnButtonB();
	afx_msg void OnButtonC();
	afx_msg void OnButtonD();
	afx_msg void OnButtonQ();
	afx_msg void OnButtonP();
	afx_msg void OnButtonO();
	afx_msg void OnButtonN();
	afx_msg void OnButtonM();
	afx_msg void OnButtonL();
	afx_msg void OnButtonK();
	afx_msg void OnButtonJ();
	afx_msg void OnButtonI();
	afx_msg void OnButtonH();
	afx_msg void OnButtonG();
	afx_msg void OnButtonF();
	afx_msg void OnButtonE();
	afx_msg void OnButtonR();
	afx_msg void OnButtonS();
	afx_msg void OnButtonT();
	afx_msg void OnButtonU();
	afx_msg void OnButtonV();
	afx_msg void OnButtonW();
	afx_msg void OnButtonX();
	afx_msg void OnButtonY();
	afx_msg void OnButtonZ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_KEY_H__98448DE7_30F2_11D2_93C2_080000380657__INCLUDED_)
