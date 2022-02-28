// CamLink1View.h : interface of the CCamLink1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMLINK1VIEW_H__ED15E45F_E3ED_11D1_9338_080000380657__INCLUDED_)
#define AFX_CAMLINK1VIEW_H__ED15E45F_E3ED_11D1_9338_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CCamLink1View : public CView
{
protected: // create from serialization only
	CCamLink1View();
	DECLARE_DYNCREATE(CCamLink1View)

// Attributes
public:
	CCamLink1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamLink1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamLink1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamLink1View)
	afx_msg void OnMenuClose();
	afx_msg void OnMenuSnap();
	afx_msg void OnMenuOpen96();
	afx_msg void OnUpdateMenuOpen96(CCmdUI* pCmdUI);
	afx_msg void OnMenuDownall();
	afx_msg void OnMenuDownload();
	afx_msg void OnMenuErase();
	afx_msg void OnMenuNext();
	afx_msg void OnMenuOpen115();
	afx_msg void OnMenuOpen192();
	afx_msg void OnMenuOpen384();
	afx_msg void OnMenuOpen576();
	afx_msg void OnUpdateMenuOpen115(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuOpen192(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuOpen384(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuOpen576(CCmdUI* pCmdUI);
	afx_msg void OnMenuPrev();
	afx_msg void OnMenuResolution();
	afx_msg void OnUpdateMenuResolution(CCmdUI* pCmdUI);
	afx_msg void OnMenuThumb();
	afx_msg void OnToolbarNext();
	afx_msg void OnToolbarPrev();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CamLink1View.cpp
inline CCamLink1Doc* CCamLink1View::GetDocument()
   { return (CCamLink1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMLINK1VIEW_H__ED15E45F_E3ED_11D1_9338_080000380657__INCLUDED_)
