// ConvertDoc.h : interface of the CConvertDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONVERTDOC_H__7B33DF1B_584C_11D2_B639_080000380657__INCLUDED_)
#define AFX_CONVERTDOC_H__7B33DF1B_584C_11D2_B639_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CConvertDoc : public CDocument
{
protected: // create from serialization only
	CConvertDoc();
	DECLARE_DYNCREATE(CConvertDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CConvertDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConvertDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTDOC_H__7B33DF1B_584C_11D2_B639_080000380657__INCLUDED_)
