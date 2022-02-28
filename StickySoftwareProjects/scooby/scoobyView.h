// scoobyView.h : interface of the CScoobyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCOOBYVIEW_H__CD85915F_602B_11D2_B64C_00A0C9B5E577__INCLUDED_)
#define AFX_SCOOBYVIEW_H__CD85915F_602B_11D2_B64C_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CScoobyView : public CView
{
protected: // create from serialization only
	CScoobyView();
	DECLARE_DYNCREATE(CScoobyView)

// Attributes
public:
	CScoobyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoobyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScoobyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScoobyView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in scoobyView.cpp
inline CScoobyDoc* CScoobyView::GetDocument()
   { return (CScoobyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOOBYVIEW_H__CD85915F_602B_11D2_B64C_00A0C9B5E577__INCLUDED_)
