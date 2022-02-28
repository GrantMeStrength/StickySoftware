// testrebarDoc.h : interface of the CTestrebarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTREBARDOC_H__A7F7DAEE_206C_11D2_93A5_080000380657__INCLUDED_)
#define AFX_TESTREBARDOC_H__A7F7DAEE_206C_11D2_93A5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTestrebarDoc : public CDocument
{
protected: // create from serialization only
	CTestrebarDoc();
	DECLARE_DYNCREATE(CTestrebarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestrebarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestrebarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestrebarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTREBARDOC_H__A7F7DAEE_206C_11D2_93A5_080000380657__INCLUDED_)
