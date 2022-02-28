// ViewMark1View.h : interface of the CViewMark1View class
//
/////////////////////////////////////////////////////////////////////////////

class CViewMark1View : public CView
{
protected: // create from serialization only
	CViewMark1View();
	DECLARE_DYNCREATE(CViewMark1View)

// Attributes
public:
	CViewMark1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewMark1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViewMark1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewMark1View)
	afx_msg void OnControlZoomIn();
	afx_msg void OnControlZoomOut();
	afx_msg void OnControlLookDown();
	afx_msg void OnControlLookUp();
	afx_msg void OnControlLookLeft();
	afx_msg void OnControlLookRight();
	afx_msg void OnControlLocation();
	afx_msg void OnWhenDialog();
	afx_msg void OnFindDialog();
	afx_msg void OnHowDialog();
	afx_msg void OnGotoAltazDialog();
	afx_msg void OnGotoRadecDialog();
	afx_msg void OnKeyDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnControlTimeNow();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUpdateDialog();
	afx_msg void OnControlTimeMinus();
	afx_msg void OnControlTimePlus();
	afx_msg void OnQuickDialog();
	afx_msg void OnToolDialog();
	afx_msg void OnTaskInvert();
	afx_msg void OnTaskPlanets();
	afx_msg void OnTaskStars();
	afx_msg void OnTaskAutotime();
	afx_msg void OnTaskOutlines();
	afx_msg void OnCompass();
	afx_msg void OnUpdateCompass(CCmdUI* pCmdUI);
	afx_msg void OnTaskMess();
	afx_msg void OnTaskLabels();
	afx_msg void OnMenuJupiter();
	afx_msg void OnControlLookNorth();
	afx_msg void OnControlLookEast();
	afx_msg void OnControlLookSouth();
	afx_msg void OnControlLookWest();
	afx_msg void OnControlLookZenith();
	afx_msg void OnControlLookHorizon();
	afx_msg void OnKeyDefine();
	afx_msg void OnUpdateToolDialog(CCmdUI* pCmdUI);
	afx_msg void OnUpdateKeyDialog(CCmdUI* pCmdUI);
	afx_msg void OnMenuEphemeris();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ViewMark1View.cpp
inline CViewMark1Doc* CViewMark1View::GetDocument()
   { return (CViewMark1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
