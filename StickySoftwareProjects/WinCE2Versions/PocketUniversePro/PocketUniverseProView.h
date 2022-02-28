// PocketUniverseProView.h : interface of the CPocketUniverseProView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POCKETUNIVERSEPROVIEW_H__B191AD5E_03B3_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_POCKETUNIVERSEPROVIEW_H__B191AD5E_03B3_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPocketUniverseProView : public CView
{
protected: // create from serialization only
	CPocketUniverseProView();
	DECLARE_DYNCREATE(CPocketUniverseProView)

// Attributes
public:
	CPocketUniverseProDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPocketUniverseProView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPocketUniverseProView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPocketUniverseProView)
	afx_msg void OnMenuSettimedate();
	afx_msg void OnMenuDisplay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PocketUniverseProView.cpp
inline CPocketUniverseProDoc* CPocketUniverseProView::GetDocument()
   { return (CPocketUniverseProDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POCKETUNIVERSEPROVIEW_H__B191AD5E_03B3_11D3_B723_00A0C9B5E577__INCLUDED_)
