// PalmUniverseDoc.h : interface of the CPalmUniverseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PALMUNIVERSEDOC_H__445EBEED_1FA6_11D2_93A4_080000380657__INCLUDED_)
#define AFX_PALMUNIVERSEDOC_H__445EBEED_1FA6_11D2_93A4_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPalmUniverseDoc : public CDocument
{
protected: // create from serialization only
	CPalmUniverseDoc();
	DECLARE_DYNCREATE(CPalmUniverseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalmUniverseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPalmUniverseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPalmUniverseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALMUNIVERSEDOC_H__445EBEED_1FA6_11D2_93A4_080000380657__INCLUDED_)
