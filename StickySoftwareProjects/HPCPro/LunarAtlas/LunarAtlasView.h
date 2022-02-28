// LunarAtlasView.h : interface of the CLunarAtlasView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LUNARATLASVIEW_H__C2DD544D_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
#define AFX_LUNARATLASVIEW_H__C2DD544D_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CLunarAtlasView : public CView
{
protected: // create from serialization only
	CLunarAtlasView();
	DECLARE_DYNCREATE(CLunarAtlasView)

// Attributes
public:
	CLunarAtlasDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLunarAtlasView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLunarAtlasView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLunarAtlasView)
	afx_msg void OnOpenToolbox();
	afx_msg void OnUpdateOpenToolbox(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGoUp();
	afx_msg void OnGoDown();
	afx_msg void OnGoLeft();
	afx_msg void OnGoRight();
	afx_msg void OnMenuImage();
	afx_msg void OnUpdateMenuImage(CCmdUI* pCmdUI);
	afx_msg void OnNameSeas();
	afx_msg void OnUpdateNameSeas(CCmdUI* pCmdUI);
	afx_msg void OnAllCraters();
	afx_msg void OnUpdateAllCraters(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LunarAtlasView.cpp
inline CLunarAtlasDoc* CLunarAtlasView::GetDocument()
   { return (CLunarAtlasDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUNARATLASVIEW_H__C2DD544D_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
