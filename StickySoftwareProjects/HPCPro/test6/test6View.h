// test6View.h : interface of the CTest6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST6VIEW_H__3506176E_E504_11D2_B700_00A0C9B5E577__INCLUDED_)
#define AFX_TEST6VIEW_H__3506176E_E504_11D2_B700_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTest6View : public CView
{
protected: // create from serialization only
	CTest6View();
	DECLARE_DYNCREATE(CTest6View)

// Attributes
public:
	CTest6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest6View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test6View.cpp
inline CTest6Doc* CTest6View::GetDocument()
   { return (CTest6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST6VIEW_H__3506176E_E504_11D2_B700_00A0C9B5E577__INCLUDED_)
