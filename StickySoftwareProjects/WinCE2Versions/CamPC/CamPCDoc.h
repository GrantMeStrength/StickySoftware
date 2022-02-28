// CamPCDoc.h : interface of the CCamPCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMPCDOC_H__77A1AC1D_E4C9_11D1_933D_080000380657__INCLUDED_)
#define AFX_CAMPCDOC_H__77A1AC1D_E4C9_11D1_933D_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CCamPCDoc : public CDocument
{
protected: // create from serialization only
	CCamPCDoc();
	DECLARE_DYNCREATE(CCamPCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamPCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamPCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamPCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPCDOC_H__77A1AC1D_E4C9_11D1_933D_080000380657__INCLUDED_)
