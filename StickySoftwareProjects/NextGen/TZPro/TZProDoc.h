// TZProDoc.h : interface of the CTZProDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TZPRODOC_H__0DE7456B_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_)
#define AFX_TZPRODOC_H__0DE7456B_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTZProDoc : public CDocument
{
protected: // create from serialization only
	CTZProDoc();
	DECLARE_DYNCREATE(CTZProDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTZProDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTZProDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTZProDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TZPRODOC_H__0DE7456B_E8D8_11D2_B705_00A0C9B5E577__INCLUDED_)
