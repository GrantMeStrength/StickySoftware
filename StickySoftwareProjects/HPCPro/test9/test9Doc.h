// test9Doc.h : interface of the CTest9Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST9DOC_H__222E760C_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
#define AFX_TEST9DOC_H__222E760C_E75A_11D2_B703_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTest9Doc : public CDocument
{
protected: // create from serialization only
	CTest9Doc();
	DECLARE_DYNCREATE(CTest9Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest9Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest9Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest9Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST9DOC_H__222E760C_E75A_11D2_B703_00A0C9B5E577__INCLUDED_)
