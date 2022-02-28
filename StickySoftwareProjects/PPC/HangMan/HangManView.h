// HangManView.h : interface of the CHangManView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANGMANVIEW_H__98448DE0_30F2_11D2_93C2_080000380657__INCLUDED_)
#define AFX_HANGMANVIEW_H__98448DE0_30F2_11D2_93C2_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CHangManView : public CView
{
protected: // create from serialization only
	CHangManView();
	DECLARE_DYNCREATE(CHangManView)

// Attributes
public:
	CHangManDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHangManView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateEverything();
	virtual ~CHangManView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHangManView)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HangManView.cpp
inline CHangManDoc* CHangManView::GetDocument()
   { return (CHangManDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANGMANVIEW_H__98448DE0_30F2_11D2_93C2_080000380657__INCLUDED_)
