// TankView.h : interface of the CTankView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKVIEW_H__DF07AE7D_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_)
#define AFX_TANKVIEW_H__DF07AE7D_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTankView : public CView
{
protected: // create from serialization only
	CTankView();
	DECLARE_DYNCREATE(CTankView)

// Attributes
public:
	CTankDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTankView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuEndgame();
	afx_msg void OnMenuPause();
	afx_msg void OnUpdateMenuPause(CCmdUI* pCmdUI);
	afx_msg void OnMenuSounds();
	afx_msg void OnUpdateMenuSounds(CCmdUI* pCmdUI);
	afx_msg void OnMenuSpeedFast();
	afx_msg void OnUpdateMenuSpeedFast(CCmdUI* pCmdUI);
	afx_msg void OnMenuSpeedMedium();
	afx_msg void OnUpdateMenuSpeedMedium(CCmdUI* pCmdUI);
	afx_msg void OnMenuSpeedSlow();
	afx_msg void OnUpdateMenuSpeedSlow(CCmdUI* pCmdUI);
	afx_msg void OnMenuSpeedVfast();
	afx_msg void OnUpdateMenuSpeedVfast(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuEndgame(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TankView.cpp
inline CTankDoc* CTankView::GetDocument()
   { return (CTankDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKVIEW_H__DF07AE7D_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_)
