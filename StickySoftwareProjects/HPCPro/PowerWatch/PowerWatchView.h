// PowerWatchView.h : interface of the CPowerWatchView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POWERWATCHVIEW_H__71B93ECD_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
#define AFX_POWERWATCHVIEW_H__71B93ECD_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPowerWatchView : public CView
{
protected: // create from serialization only
	CPowerWatchView();
	DECLARE_DYNCREATE(CPowerWatchView)

// Attributes
public:
	CPowerWatchDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerWatchView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPowerWatchView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPowerWatchView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PowerWatchView.cpp
inline CPowerWatchDoc* CPowerWatchView::GetDocument()
   { return (CPowerWatchDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERWATCHVIEW_H__71B93ECD_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
