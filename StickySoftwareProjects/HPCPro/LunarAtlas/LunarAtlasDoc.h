// LunarAtlasDoc.h : interface of the CLunarAtlasDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LUNARATLASDOC_H__C2DD544B_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
#define AFX_LUNARATLASDOC_H__C2DD544B_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CLunarAtlasDoc : public CDocument
{
protected: // create from serialization only
	CLunarAtlasDoc();
	DECLARE_DYNCREATE(CLunarAtlasDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLunarAtlasDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLunarAtlasDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLunarAtlasDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUNARATLASDOC_H__C2DD544B_CD5B_11D2_B6DB_00A0C9B5E577__INCLUDED_)
