// PicClickView.h : interface of the CPicClickView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICCLICKVIEW_H__C39557BD_B742_11D1_92E8_0080C809CB22__INCLUDED_)
#define AFX_PICCLICKVIEW_H__C39557BD_B742_11D1_92E8_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPicClickView : public CView
{
protected: // create from serialization only
	CPicClickView();
	DECLARE_DYNCREATE(CPicClickView)

// Attributes
public:
	CPicClickDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicClickView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicClickView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicClickView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PicClickView.cpp
inline CPicClickDoc* CPicClickView::GetDocument()
   { return (CPicClickDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICCLICKVIEW_H__C39557BD_B742_11D1_92E8_0080C809CB22__INCLUDED_)
