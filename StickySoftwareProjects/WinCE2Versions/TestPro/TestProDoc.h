// TestProDoc.h : interface of the CTestProDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPRODOC_H__0F791C1B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TESTPRODOC_H__0F791C1B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTestProDoc : public CDocument
{
protected: // create from serialization only
	CTestProDoc();
	DECLARE_DYNCREATE(CTestProDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestProDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestProDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestProDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPRODOC_H__0F791C1B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
