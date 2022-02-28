// test9View.h : interface of the CTest9View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST9VIEW_H__222E760E_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
#define AFX_TEST9VIEW_H__222E760E_E75A_11D2_B703_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTest9View : public CView
{
protected: // create from serialization only
	CTest9View();
	DECLARE_DYNCREATE(CTest9View)

// Attributes
public:
	CTest9Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest9View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest9View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test9View.cpp
inline CTest9Doc* CTest9View::GetDocument()
   { return (CTest9Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST9VIEW_H__222E760E_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
