// benchmarkView.h : interface of the CBenchmarkView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENCHMARKVIEW_H__BE40BBE0_22C6_11D2_93AA_080000380657__INCLUDED_)
#define AFX_BENCHMARKVIEW_H__BE40BBE0_22C6_11D2_93AA_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CBenchmarkView : public CView
{
protected: // create from serialization only
	CBenchmarkView();
	DECLARE_DYNCREATE(CBenchmarkView)

// Attributes
public:
	CBenchmarkDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchmarkView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBenchmarkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBenchmarkView)
	afx_msg void OnMenuitemStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in benchmarkView.cpp
inline CBenchmarkDoc* CBenchmarkView::GetDocument()
   { return (CBenchmarkDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHMARKVIEW_H__BE40BBE0_22C6_11D2_93AA_080000380657__INCLUDED_)
