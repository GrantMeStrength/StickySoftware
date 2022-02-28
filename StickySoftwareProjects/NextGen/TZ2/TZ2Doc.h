// TZ2Doc.h : interface of the CTZ2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TZ2DOC_H__BA6D257B_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
#define AFX_TZ2DOC_H__BA6D257B_E83C_11D2_B704_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTZ2Doc : public CDocument
{
protected: // create from serialization only
	CTZ2Doc();
	DECLARE_DYNCREATE(CTZ2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTZ2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTZ2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTZ2Doc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TZ2DOC_H__BA6D257B_E83C_11D2_B704_00A0C9B5E577__INCLUDED_)
