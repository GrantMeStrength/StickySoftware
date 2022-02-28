// LotteryView.h : interface of the CLotteryView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOTTERYVIEW_H__50759CCD_886E_11D2_B67E_00A0C9B5E577__INCLUDED_)
#define AFX_LOTTERYVIEW_H__50759CCD_886E_11D2_B67E_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CLotteryView : public CView
{
protected: // create from serialization only
	CLotteryView();
	DECLARE_DYNCREATE(CLotteryView)

// Attributes
public:
	CLotteryDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLotteryView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLotteryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLotteryView)
	afx_msg void OnCheck();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LotteryView.cpp
inline CLotteryDoc* CLotteryView::GetDocument()
   { return (CLotteryDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTERYVIEW_H__50759CCD_886E_11D2_B67E_00A0C9B5E577__INCLUDED_)
