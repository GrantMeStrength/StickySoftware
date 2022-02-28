// HangManDoc.h : interface of the CHangManDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANGMANDOC_H__98448DDE_30F2_11D2_93C2_080000380657__INCLUDED_)
#define AFX_HANGMANDOC_H__98448DDE_30F2_11D2_93C2_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CHangManDoc : public CDocument
{
protected: // create from serialization only
	CHangManDoc();
	DECLARE_DYNCREATE(CHangManDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHangManDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHangManDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHangManDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANGMANDOC_H__98448DDE_30F2_11D2_93C2_080000380657__INCLUDED_)
