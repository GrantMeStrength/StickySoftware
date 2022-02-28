// TestProView.h : interface of the CTestProView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPROVIEW_H__0F791C1D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TESTPROVIEW_H__0F791C1D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTestProView : public CView
{
protected: // create from serialization only
	CTestProView();
	DECLARE_DYNCREATE(CTestProView)

// Attributes
public:
	CTestProDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestProView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestProView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestProView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestProView.cpp
inline CTestProDoc* CTestProView::GetDocument()
   { return (CTestProDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPROVIEW_H__0F791C1D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
