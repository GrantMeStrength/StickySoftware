// FileTestDoc.h : interface of the CFileTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILETESTDOC_H__91A7A88D_23CE_11D2_93AD_080000380657__INCLUDED_)
#define AFX_FILETESTDOC_H__91A7A88D_23CE_11D2_93AD_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CFileTestDoc : public CDocument
{
protected: // create from serialization only
	CFileTestDoc();
	DECLARE_DYNCREATE(CFileTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	char * fileText;
	virtual ~CFileTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFileTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETESTDOC_H__91A7A88D_23CE_11D2_93AD_080000380657__INCLUDED_)
