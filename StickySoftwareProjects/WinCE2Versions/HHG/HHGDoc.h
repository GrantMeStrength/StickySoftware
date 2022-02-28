// HHGDoc.h : interface of the CHHGDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HHGDOC_H__5A0D9D6E_3744_11D2_93CE_080000380657__INCLUDED_)
#define AFX_HHGDOC_H__5A0D9D6E_3744_11D2_93CE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CHHGDoc : public CDocument
{
protected: // create from serialization only
	CHHGDoc();
	DECLARE_DYNCREATE(CHHGDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHHGDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHHGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHHGDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HHGDOC_H__5A0D9D6E_3744_11D2_93CE_080000380657__INCLUDED_)
