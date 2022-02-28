// ConvertView.h : interface of the CConvertView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONVERTVIEW_H__7B33DF1D_584C_11D2_B639_080000380657__INCLUDED_)
#define AFX_CONVERTVIEW_H__7B33DF1D_584C_11D2_B639_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CConvertView : public CView
{
protected: // create from serialization only
	CConvertView();
	DECLARE_DYNCREATE(CConvertView)

// Attributes
public:
	CConvertDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CConvertView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConvertView)
	afx_msg void OnMenuDoit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ConvertView.cpp
inline CConvertDoc* CConvertView::GetDocument()
   { return (CConvertDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTVIEW_H__7B33DF1D_584C_11D2_B639_080000380657__INCLUDED_)
