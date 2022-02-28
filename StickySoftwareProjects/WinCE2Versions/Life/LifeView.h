// LifeView.h : interface of the CLifeView class
//
/////////////////////////////////////////////////////////////////////////////

class CLifeView : public CScrollView
{
protected: // create from serialization only
	CLifeView();
	DECLARE_DYNCREATE(CLifeView)

// Attributes
public:
	CLifeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLifeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLifeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLifeView)
	afx_msg void OnLifeStart();
	afx_msg void OnLifeClear();
	afx_msg void OnLifeStop();
	afx_msg void OnLifeRandom();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLifeOnce();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLifeFast();
	afx_msg void OnLifeSlow();
	afx_msg void OnLifePrevious();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LifeView.cpp
inline CLifeDoc* CLifeView::GetDocument()
   { return (CLifeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
