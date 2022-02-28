// ZoneCEView.h : interface of the CZoneCEView class
//
/////////////////////////////////////////////////////////////////////////////

class CZoneCEView : public CView
{
protected: // create from serialization only
	CZoneCEView();
	DECLARE_DYNCREATE(CZoneCEView)

// Attributes
public:
	CZoneCEDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZoneCEView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CZoneCEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZoneCEView)
	afx_msg void OnSpinAnticlockwise();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuVfast();
	afx_msg void OnUpdateMenuVfast(CCmdUI* pCmdUI);
	afx_msg void OnMenuFast();
	afx_msg void OnUpdateMenuFast(CCmdUI* pCmdUI);
	afx_msg void OnMenuMedium();
	afx_msg void OnMenuSlow();
	afx_msg void OnUpdateMenuMedium(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMenuSlow(CCmdUI* pCmdUI);
	afx_msg void OnMenuSound();
	afx_msg void OnUpdateMenuSound(CCmdUI* pCmdUI);
	afx_msg void OnStartGame();
	afx_msg void OnMenuLandscape();
	afx_msg void OnUpdateMenuLandscape(CCmdUI* pCmdUI);
	afx_msg void OnMenuShading();
	afx_msg void OnUpdateMenuShading(CCmdUI* pCmdUI);
	afx_msg void OnGamePause();
	afx_msg void OnUpdateGamePause(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStartGame(CCmdUI* pCmdUI);
	afx_msg void OnMenuFlicker();
	afx_msg void OnUpdateMenuFlicker(CCmdUI* pCmdUI);
	afx_msg void OnDeleteInfo();
	afx_msg void OnMenuFill();
	afx_msg void OnUpdateMenuFill(CCmdUI* pCmdUI);
	afx_msg void OnMenuSize();
	afx_msg void OnUpdateMenuSize(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ZoneCEView.cpp
inline CZoneCEDoc* CZoneCEView::GetDocument()
   { return (CZoneCEDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
