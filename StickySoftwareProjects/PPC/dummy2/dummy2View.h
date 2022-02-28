// dummy2View.h : interface of the CDummy2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUMMY2VIEW_H__A646E7B5_2494_11D2_93AE_080000380657__INCLUDED_)
#define AFX_DUMMY2VIEW_H__A646E7B5_2494_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDummy2View : public CView
{
protected: // create from serialization only
	CDummy2View();
	DECLARE_DYNCREATE(CDummy2View)

// Attributes
public:
	CDummy2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummy2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDummy2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDummy2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dummy2View.cpp
inline CDummy2Doc* CDummy2View::GetDocument()
   { return (CDummy2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMY2VIEW_H__A646E7B5_2494_11D2_93AE_080000380657__INCLUDED_)
