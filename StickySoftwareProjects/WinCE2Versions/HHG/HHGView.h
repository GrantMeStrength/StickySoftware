// HHGView.h : interface of the CHHGView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HHGVIEW_H__5A0D9D70_3744_11D2_93CE_080000380657__INCLUDED_)
#define AFX_HHGVIEW_H__5A0D9D70_3744_11D2_93CE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CHHGView : public CView
{
protected: // create from serialization only
	CHHGView();
	DECLARE_DYNCREATE(CHHGView)

// Attributes
public:
	CHHGDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHHGView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHHGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHHGView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HHGView.cpp
inline CHHGDoc* CHHGView::GetDocument()
   { return (CHHGDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HHGVIEW_H__5A0D9D70_3744_11D2_93CE_080000380657__INCLUDED_)
