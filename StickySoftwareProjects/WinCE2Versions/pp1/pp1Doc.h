// pp1Doc.h : interface of the CPp1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PP1DOC_H__76CF065B_0471_11D2_937B_080000380657__INCLUDED_)
#define AFX_PP1DOC_H__76CF065B_0471_11D2_937B_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPp1Doc : public CDocument
{
protected: // create from serialization only
	CPp1Doc();
	DECLARE_DYNCREATE(CPp1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPp1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPp1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPp1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PP1DOC_H__76CF065B_0471_11D2_937B_080000380657__INCLUDED_)
