// BlockView.h : interface of the CBlockView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOCKVIEW_H__9176FE40_35E7_11D2_93CA_080000380657__INCLUDED_)
#define AFX_BLOCKVIEW_H__9176FE40_35E7_11D2_93CA_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CBlockView : public CView
{
protected: // create from serialization only
	CBlockView();
	DECLARE_DYNCREATE(CBlockView)

// Attributes
public:
	CBlockDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlockView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBlockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBlockView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGamePattern1();
	afx_msg void OnGamePattern2();
	afx_msg void OnGamePattern3();
	afx_msg void OnGamePattern4();
	afx_msg void OnGamePattern5();
	afx_msg void OnGamePattern6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BlockView.cpp
inline CBlockDoc* CBlockView::GetDocument()
   { return (CBlockDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLOCKVIEW_H__9176FE40_35E7_11D2_93CA_080000380657__INCLUDED_)
