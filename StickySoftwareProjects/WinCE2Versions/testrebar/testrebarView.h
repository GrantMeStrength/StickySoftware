// testrebarView.h : interface of the CTestrebarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTREBARVIEW_H__A7F7DAF0_206C_11D2_93A5_080000380657__INCLUDED_)
#define AFX_TESTREBARVIEW_H__A7F7DAF0_206C_11D2_93A5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTestrebarView : public CView
{
protected: // create from serialization only
	CTestrebarView();
	DECLARE_DYNCREATE(CTestrebarView)

// Attributes
public:
	CTestrebarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestrebarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestrebarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestrebarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testrebarView.cpp
inline CTestrebarDoc* CTestrebarView::GetDocument()
   { return (CTestrebarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTREBARVIEW_H__A7F7DAF0_206C_11D2_93A5_080000380657__INCLUDED_)
