// TankDoc.h : interface of the CTankDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKDOC_H__DF07AE7B_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_)
#define AFX_TANKDOC_H__DF07AE7B_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTankDoc : public CDocument
{
protected: // create from serialization only
	CTankDoc();
	DECLARE_DYNCREATE(CTankDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTankDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKDOC_H__DF07AE7B_E8DA_11D2_B705_00A0C9B5E577__INCLUDED_)
