// TestPalmView.h : interface of the CTestPalmView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPALMVIEW_H__AA0C2B9D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TESTPALMVIEW_H__AA0C2B9D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTestPalmView : public CView
{
protected: // create from serialization only
	CTestPalmView();
	DECLARE_DYNCREATE(CTestPalmView)

// Attributes
public:
	CTestPalmDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPalmView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestPalmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPalmView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestPalmView.cpp
inline CTestPalmDoc* CTestPalmView::GetDocument()
   { return (CTestPalmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPALMVIEW_H__AA0C2B9D_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
