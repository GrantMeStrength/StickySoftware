// bitmaptesterDoc.h : interface of the CBitmaptesterDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPTESTERDOC_H__4F8165DB_F189_11D1_9325_080000380657__INCLUDED_)
#define AFX_BITMAPTESTERDOC_H__4F8165DB_F189_11D1_9325_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CBitmaptesterDoc : public CDocument
{
protected: // create from serialization only
	CBitmaptesterDoc();
	DECLARE_DYNCREATE(CBitmaptesterDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmaptesterDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmaptesterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmaptesterDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTESTERDOC_H__4F8165DB_F189_11D1_9325_080000380657__INCLUDED_)
