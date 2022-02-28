// TestPalmDoc.h : interface of the CTestPalmDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPALMDOC_H__AA0C2B9B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
#define AFX_TESTPALMDOC_H__AA0C2B9B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTestPalmDoc : public CDocument
{
protected: // create from serialization only
	CTestPalmDoc();
	DECLARE_DYNCREATE(CTestPalmDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPalmDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestPalmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPalmDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPALMDOC_H__AA0C2B9B_03B2_11D3_B723_00A0C9B5E577__INCLUDED_)
