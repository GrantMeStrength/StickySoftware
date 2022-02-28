// dummy2Doc.h : interface of the CDummy2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUMMY2DOC_H__A646E7B3_2494_11D2_93AE_080000380657__INCLUDED_)
#define AFX_DUMMY2DOC_H__A646E7B3_2494_11D2_93AE_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDummy2Doc : public CDocument
{
protected: // create from serialization only
	CDummy2Doc();
	DECLARE_DYNCREATE(CDummy2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDummy2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDummy2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDummy2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMMY2DOC_H__A646E7B3_2494_11D2_93AE_080000380657__INCLUDED_)
