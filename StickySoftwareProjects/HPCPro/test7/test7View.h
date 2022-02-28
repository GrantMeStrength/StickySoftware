// test7View.h : interface of the CTest7View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST7VIEW_H__DB088761_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_)
#define AFX_TEST7VIEW_H__DB088761_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTest7View : public CView
{
protected: // create from serialization only
	CTest7View();
	DECLARE_DYNCREATE(CTest7View)

// Attributes
public:
	CTest7Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest7View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest7View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test7View.cpp
inline CTest7Doc* CTest7View::GetDocument()
   { return (CTest7Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST7VIEW_H__DB088761_E466_11D2_B6FF_00A0C9B5E577__INCLUDED_)
