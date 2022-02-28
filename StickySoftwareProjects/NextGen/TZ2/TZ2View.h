// TZ2View.h : interface of the CTZ2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TZ2VIEW_H__BA6D257D_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
#define AFX_TZ2VIEW_H__BA6D257D_E83C_11D2_B704_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTZ2View : public CView
{
protected: // create from serialization only
	CTZ2View();
	DECLARE_DYNCREATE(CTZ2View)

// Attributes
public:
	CTZ2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTZ2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTZ2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTZ2View)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TZ2View.cpp
inline CTZ2Doc* CTZ2View::GetDocument()
   { return (CTZ2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TZ2VIEW_H__BA6D257D_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
