// dummyDoc.h : interface of the CDummyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUMMYDOC_H__03FDD21D_4B0B_11D2_93F1_080000380657__INCLUDED_)
#define AFX_DUMMYDOC_H__03FDD21D_4B0B_11D2_93F1_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDummyDoc : public CDocument
{
protected: // create from serialization only
	CDummyDoc();
	DECLARE_DYNCREATE(CDummyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDummyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDummyDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMYDOC_H__03FDD21D_4B0B_11D2_93F1_080000380657__INCLUDED_)
