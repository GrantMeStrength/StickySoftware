// La1View.h : interface of the CLa1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LA1VIEW_H__E7A2743F_338B_11D2_93C5_080000380657__INCLUDED_)
#define AFX_LA1VIEW_H__E7A2743F_338B_11D2_93C5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CLa1View : public CView
{
protected: // create from serialization only
	CLa1View();
	DECLARE_DYNCREATE(CLa1View)

// Attributes
public:
	CLa1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLa1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLa1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLa1View)
	afx_msg void OnMoveDown();
	afx_msg void OnMoveLeft();
	afx_msg void OnMoveRight();
	afx_msg void OnMoveUp();
	afx_msg void OnMoveIn();
	afx_msg void OnMoveOut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in La1View.cpp
inline CLa1Doc* CLa1View::GetDocument()
   { return (CLa1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LA1VIEW_H__E7A2743F_338B_11D2_93C5_080000380657__INCLUDED_)
