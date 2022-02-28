// helptestView.h : interface of the CHelptestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HELPTESTVIEW_H__A94940FD_EF33_11D1_934D_080000380657__INCLUDED_)
#define AFX_HELPTESTVIEW_H__A94940FD_EF33_11D1_934D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CHelptestView : public CView
{
protected: // create from serialization only
	CHelptestView();
	DECLARE_DYNCREATE(CHelptestView)

// Attributes
public:
	CHelptestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelptestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHelptestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHelptestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in helptestView.cpp
inline CHelptestDoc* CHelptestView::GetDocument()
   { return (CHelptestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPTESTVIEW_H__A94940FD_EF33_11D1_934D_080000380657__INCLUDED_)
