// TalkingClockView.h : interface of the CTalkingClockView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TALKINGCLOCKVIEW_H__3D95CBF0_43E7_11D2_93E0_080000380657__INCLUDED_)
#define AFX_TALKINGCLOCKVIEW_H__3D95CBF0_43E7_11D2_93E0_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTalkingClockView : public CView
{
protected: // create from serialization only
	CTalkingClockView();
	DECLARE_DYNCREATE(CTalkingClockView)

// Attributes
public:
	CTalkingClockDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalkingClockView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTalkingClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTalkingClockView)
	afx_msg void OnTellMeTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TalkingClockView.cpp
inline CTalkingClockDoc* CTalkingClockView::GetDocument()
   { return (CTalkingClockDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKINGCLOCKVIEW_H__3D95CBF0_43E7_11D2_93E0_080000380657__INCLUDED_)
