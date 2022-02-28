// dummyView.h : interface of the CDummyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUMMYVIEW_H__A646E7A0_2494_11D2_93AE_080000380657__INCLUDED_)
#define AFX_DUMMYVIEW_H__A646E7A0_2494_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDummyView : public CView
{
protected: // create from serialization only
	CDummyView();
	DECLARE_DYNCREATE(CDummyView)

// Attributes
public:
	CDummyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDummyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDummyView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dummyView.cpp
inline CDummyDoc* CDummyView::GetDocument()
   { return (CDummyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMYVIEW_H__A646E7A0_2494_11D2_93AE_080000380657__INCLUDED_)
