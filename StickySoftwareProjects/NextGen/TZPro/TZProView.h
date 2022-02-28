// TZProView.h : interface of the CTZProView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TZPROVIEW_H__0DE7456D_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_)
#define AFX_TZPROVIEW_H__0DE7456D_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTZProView : public CView
{
protected: // create from serialization only
	CTZProView();
	DECLARE_DYNCREATE(CTZProView)

// Attributes
public:
	CTZProDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTZProView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTZProView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTZProView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TZProView.cpp
inline CTZProDoc* CTZProView::GetDocument()
   { return (CTZProDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TZPROVIEW_H__0DE7456D_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_)
