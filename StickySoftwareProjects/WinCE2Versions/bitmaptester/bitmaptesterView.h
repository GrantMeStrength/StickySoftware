// bitmaptesterView.h : interface of the CBitmaptesterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPTESTERVIEW_H__4F8165DD_F189_11D1_9325_080000380657__INCLUDED_)
#define AFX_BITMAPTESTERVIEW_H__4F8165DD_F189_11D1_9325_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CBitmaptesterView : public CView
{
protected: // create from serialization only
	CBitmaptesterView();
	DECLARE_DYNCREATE(CBitmaptesterView)

// Attributes
public:
	CBitmaptesterDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmaptesterView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmaptesterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmaptesterView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in bitmaptesterView.cpp
inline CBitmaptesterDoc* CBitmaptesterView::GetDocument()
   { return (CBitmaptesterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTESTERVIEW_H__4F8165DD_F189_11D1_9325_080000380657__INCLUDED_)
