// CleanBarneyDoc.h : interface of the CCleanBarneyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLEANBARNEYDOC_H__F18E3B9C_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
#define AFX_CLEANBARNEYDOC_H__F18E3B9C_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CCleanBarneyDoc : public CDocument
{
protected: // create from serialization only
	CCleanBarneyDoc();
	DECLARE_DYNCREATE(CCleanBarneyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCleanBarneyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCleanBarneyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCleanBarneyDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEANBARNEYDOC_H__F18E3B9C_DAD2_11D2_B6EF_00A0C9B5E577__INCLUDED_)
