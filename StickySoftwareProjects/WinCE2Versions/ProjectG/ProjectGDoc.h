// ProjectGDoc.h : interface of the CProjectGDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTGDOC_H__FFE8F5C1_F16C_11D1_9350_080000380657__INCLUDED_)
#define AFX_PROJECTGDOC_H__FFE8F5C1_F16C_11D1_9350_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CProjectGDoc : public CDocument
{
protected: // create from serialization only
	CProjectGDoc();
	DECLARE_DYNCREATE(CProjectGDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectGDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProjectGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProjectGDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTGDOC_H__FFE8F5C1_F16C_11D1_9350_080000380657__INCLUDED_)
