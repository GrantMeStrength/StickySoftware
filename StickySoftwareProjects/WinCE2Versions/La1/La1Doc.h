// La1Doc.h : interface of the CLa1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LA1DOC_H__E7A2743D_338B_11D2_93C5_080000380657__INCLUDED_)
#define AFX_LA1DOC_H__E7A2743D_338B_11D2_93C5_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CLa1Doc : public CDocument
{
protected: // create from serialization only
	CLa1Doc();
	DECLARE_DYNCREATE(CLa1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLa1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLa1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLa1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LA1DOC_H__E7A2743D_338B_11D2_93C5_080000380657__INCLUDED_)
