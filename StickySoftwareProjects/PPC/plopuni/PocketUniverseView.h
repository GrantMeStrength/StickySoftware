// PocketUniverseView.h : interface of the CPocketUniverseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POCKETUNIVERSEVIEW_H__680D5C5F_24BC_11D2_93AE_080000380657__INCLUDED_)
#define AFX_POCKETUNIVERSEVIEW_H__680D5C5F_24BC_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPocketUniverseView : public CView
{
protected: // create from serialization only
	CPocketUniverseView();
	DECLARE_DYNCREATE(CPocketUniverseView)

// Attributes
public:
	CPocketUniverseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPocketUniverseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPocketUniverseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPocketUniverseView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PocketUniverseView.cpp
inline CPocketUniverseDoc* CPocketUniverseView::GetDocument()
   { return (CPocketUniverseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POCKETUNIVERSEVIEW_H__680D5C5F_24BC_11D2_93AE_080000380657__INCLUDED_)
