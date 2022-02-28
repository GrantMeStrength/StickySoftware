// test1View.h : interface of the CTest1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1VIEW_H__7CB9E2B3_E45E_11D2_B6FE_00A0C9B5E577__INCLUDED_)
#define AFX_TEST1VIEW_H__7CB9E2B3_E45E_11D2_B6FE_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTest1View : public CView
{
protected: // create from serialization only
	CTest1View();
	DECLARE_DYNCREATE(CTest1View)

// Attributes
public:
	CTest1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test1View.cpp
inline CTest1Doc* CTest1View::GetDocument()
   { return (CTest1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1VIEW_H__7CB9E2B3_E45E_11D2_B6FE_00A0C9B5E577__INCLUDED_)
