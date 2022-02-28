// Life2View.h : interface of the CLife2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIFE2VIEW_H__BF83F28F_1C0B_11D2_9395_080000380657__INCLUDED_)
#define AFX_LIFE2VIEW_H__BF83F28F_1C0B_11D2_9395_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CLife2View : public CView
{
protected: // create from serialization only
	CLife2View();
	DECLARE_DYNCREATE(CLife2View)

// Attributes
public:
	CLife2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLife2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLife2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLife2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Life2View.cpp
inline CLife2Doc* CLife2View::GetDocument()
   { return (CLife2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFE2VIEW_H__BF83F28F_1C0B_11D2_9395_080000380657__INCLUDED_)
