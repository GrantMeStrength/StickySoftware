// CleanBarneyView.h : interface of the CCleanBarneyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLEANBARNEYVIEW_H__F18E3B9E_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
#define AFX_CLEANBARNEYVIEW_H__F18E3B9E_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CCleanBarneyView : public CView
{
protected: // create from serialization only
	CCleanBarneyView();
	DECLARE_DYNCREATE(CCleanBarneyView)

// Attributes
public:
	CCleanBarneyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCleanBarneyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCleanBarneyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCleanBarneyView)
	afx_msg void OnClean();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CleanBarneyView.cpp
inline CCleanBarneyDoc* CCleanBarneyView::GetDocument()
   { return (CCleanBarneyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEANBARNEYVIEW_H__F18E3B9E_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
