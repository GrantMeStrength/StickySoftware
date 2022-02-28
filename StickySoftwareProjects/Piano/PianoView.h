// PianoView.h : interface of the CPianoView class
//
/////////////////////////////////////////////////////////////////////////////

class CPianoView : public CView
{
protected: // create from serialization only
	CPianoView();
	DECLARE_DYNCREATE(CPianoView)

// Attributes
public:
	CPianoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPianoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPianoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPianoView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPlay();
	afx_msg void OnRecord();
	afx_msg void OnUpdateRecord(CCmdUI* pCmdUI);
	afx_msg void OnStop();
	afx_msg void OnUpdateStop(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePlay(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PianoView.cpp
inline CPianoDoc* CPianoView::GetDocument()
   { return (CPianoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
