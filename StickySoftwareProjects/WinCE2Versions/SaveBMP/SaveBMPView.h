// SaveBMPView.h : interface of the CSaveBMPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVEBMPVIEW_H__DA5A942F_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_)
#define AFX_SAVEBMPVIEW_H__DA5A942F_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CSaveBMPView : public CView
{
protected: // create from serialization only
	CSaveBMPView();
	DECLARE_DYNCREATE(CSaveBMPView)

// Attributes
public:
	CSaveBMPDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveBMPView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSaveBMPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSaveBMPView)
	afx_msg void OnMenuSavebmp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SaveBMPView.cpp
inline CSaveBMPDoc* CSaveBMPView::GetDocument()
   { return (CSaveBMPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEBMPVIEW_H__DA5A942F_D6CE_11D2_B6EA_00A0C9B5E577__INCLUDED_)
