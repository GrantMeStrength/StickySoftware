// PalmUniverseView.h : interface of the CPalmUniverseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PALMUNIVERSEVIEW_H__445EBEEF_1FA6_11D2_93A4_080000380657__INCLUDED_)
#define AFX_PALMUNIVERSEVIEW_H__445EBEEF_1FA6_11D2_93A4_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPalmUniverseView : public CView
{
protected: // create from serialization only
	CPalmUniverseView();
	DECLARE_DYNCREATE(CPalmUniverseView)

// Attributes
public:
	CPalmUniverseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalmUniverseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPalmUniverseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPalmUniverseView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PalmUniverseView.cpp
inline CPalmUniverseDoc* CPalmUniverseView::GetDocument()
   { return (CPalmUniverseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALMUNIVERSEVIEW_H__445EBEEF_1FA6_11D2_93A4_080000380657__INCLUDED_)
