// pp1View.h : interface of the CPp1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PP1VIEW_H__76CF065D_0471_11D2_937B_080000380657__INCLUDED_)
#define AFX_PP1VIEW_H__76CF065D_0471_11D2_937B_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPp1View : public CView
{
protected: // create from serialization only
	CPp1View();
	DECLARE_DYNCREATE(CPp1View)

// Attributes
public:
	CPp1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPp1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPp1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPp1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pp1View.cpp
inline CPp1Doc* CPp1View::GetDocument()
   { return (CPp1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PP1VIEW_H__76CF065D_0471_11D2_937B_080000380657__INCLUDED_)
