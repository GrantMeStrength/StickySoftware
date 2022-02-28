// FileTestView.h : interface of the CFileTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILETESTVIEW_H__91A7A88F_23CE_11D2_93AD_080000380657__INCLUDED_)
#define AFX_FILETESTVIEW_H__91A7A88F_23CE_11D2_93AD_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CFileTestView : public CView
{
protected: // create from serialization only
	CFileTestView();
	DECLARE_DYNCREATE(CFileTestView)

// Attributes
public:
	CFileTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFileTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFileTestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FileTestView.cpp
inline CFileTestDoc* CFileTestView::GetDocument()
   { return (CFileTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETESTVIEW_H__91A7A88F_23CE_11D2_93AD_080000380657__INCLUDED_)
