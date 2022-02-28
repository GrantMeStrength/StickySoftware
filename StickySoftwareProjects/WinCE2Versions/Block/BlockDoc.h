// BlockDoc.h : interface of the CBlockDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOCKDOC_H__9176FE3E_35E7_11D2_93CA_080000380657__INCLUDED_)
#define AFX_BLOCKDOC_H__9176FE3E_35E7_11D2_93CA_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CBlockDoc : public CDocument
{
protected: // create from serialization only
	CBlockDoc();
	DECLARE_DYNCREATE(CBlockDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlockDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBlockDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBlockDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLOCKDOC_H__9176FE3E_35E7_11D2_93CA_080000380657__INCLUDED_)
