// test5View.h : interface of the CTest5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST5VIEW_H__DB08874E_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_)
#define AFX_TEST5VIEW_H__DB08874E_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTest5View : public CView
{
protected: // create from serialization only
	CTest5View();
	DECLARE_DYNCREATE(CTest5View)

// Attributes
public:
	CTest5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest5View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest5View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test5View.cpp
inline CTest5Doc* CTest5View::GetDocument()
   { return (CTest5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST5VIEW_H__DB08874E_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_)
