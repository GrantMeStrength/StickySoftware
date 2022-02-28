// ProjectGView.h : interface of the CProjectGView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTGVIEW_H__FFE8F5C3_F16C_11D1_9350_080000380657__INCLUDED_)
#define AFX_PROJECTGVIEW_H__FFE8F5C3_F16C_11D1_9350_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CProjectGView : public CView
{
protected: // create from serialization only
	CProjectGView();
	DECLARE_DYNCREATE(CProjectGView)

// Attributes
public:
	CProjectGDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectGView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProjectGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProjectGView)
	afx_msg void OnMenuDraw();
	afx_msg void OnMenuAngle1minus();
	afx_msg void OnMenuAngle1plus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ProjectGView.cpp
inline CProjectGDoc* CProjectGView::GetDocument()
   { return (CProjectGDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTGVIEW_H__FFE8F5C3_F16C_11D1_9350_080000380657__INCLUDED_)
