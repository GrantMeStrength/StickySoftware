// Life2Doc.h : interface of the CLife2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIFE2DOC_H__BF83F28D_1C0B_11D2_9395_080000380657__INCLUDED_)
#define AFX_LIFE2DOC_H__BF83F28D_1C0B_11D2_9395_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CLife2Doc : public CDocument
{
protected: // create from serialization only
	CLife2Doc();
	DECLARE_DYNCREATE(CLife2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLife2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLife2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLife2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIFE2DOC_H__BF83F28D_1C0B_11D2_9395_080000380657__INCLUDED_)
