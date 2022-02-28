// PocketUniverseDoc.h : interface of the CPocketUniverseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POCKETUNIVERSEDOC_H__680D5C5D_24BC_11D2_93AE_080000380657__INCLUDED_)
#define AFX_POCKETUNIVERSEDOC_H__680D5C5D_24BC_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPocketUniverseDoc : public CDocument
{
protected: // create from serialization only
	CPocketUniverseDoc();
	DECLARE_DYNCREATE(CPocketUniverseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPocketUniverseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPocketUniverseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPocketUniverseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POCKETUNIVERSEDOC_H__680D5C5D_24BC_11D2_93AE_080000380657__INCLUDED_)
