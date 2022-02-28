// CamLink1Doc.h : interface of the CCamLink1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMLINK1DOC_H__ED15E45D_E3ED_11D1_9338_080000380657__INCLUDED_)
#define AFX_CAMLINK1DOC_H__ED15E45D_E3ED_11D1_9338_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CCamLink1Doc : public CDocument
{
protected: // create from serialization only
	CCamLink1Doc();
	DECLARE_DYNCREATE(CCamLink1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamLink1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamLink1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamLink1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMLINK1DOC_H__ED15E45D_E3ED_11D1_9338_080000380657__INCLUDED_)
