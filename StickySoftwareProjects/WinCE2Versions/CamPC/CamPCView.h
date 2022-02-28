// CamPCView.h : interface of the CCamPCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMPCVIEW_H__77A1AC1F_E4C9_11D1_933D_080000380657__INCLUDED_)
#define AFX_CAMPCVIEW_H__77A1AC1F_E4C9_11D1_933D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CCamPCView : public CView
{
protected: // create from serialization only
	CCamPCView();
	DECLARE_DYNCREATE(CCamPCView)

// Attributes
public:
	CCamPCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamPCView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamPCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamPCView)
	afx_msg void OnMenuClose();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuSnap();
	afx_msg void OnMenuStatus();
	afx_msg void OnMenuOpen192();
	afx_msg void OnMenuOpen384();
	afx_msg void OnMenuThumb();
	afx_msg void OnMenuNext();
	afx_msg void OnMenuPrev();
	afx_msg void OnMenuDraw();
	afx_msg void OnMenuOpen576();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CamPCView.cpp
inline CCamPCDoc* CCamPCView::GetDocument()
   { return (CCamPCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPCVIEW_H__77A1AC1F_E4C9_11D1_933D_080000380657__INCLUDED_)
