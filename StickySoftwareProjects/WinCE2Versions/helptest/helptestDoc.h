// helptestDoc.h : interface of the CHelptestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HELPTESTDOC_H__A94940FB_EF33_11D1_934D_080000380657__INCLUDED_)
#define AFX_HELPTESTDOC_H__A94940FB_EF33_11D1_934D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CHelptestDoc : public CDocument
{
protected: // create from serialization only
	CHelptestDoc();
	DECLARE_DYNCREATE(CHelptestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelptestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHelptestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHelptestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPTESTDOC_H__A94940FB_EF33_11D1_934D_080000380657__INCLUDED_)
