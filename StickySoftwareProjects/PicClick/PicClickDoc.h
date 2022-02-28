// PicClickDoc.h : interface of the CPicClickDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICCLICKDOC_H__C39557BB_B742_11D1_92E8_0080C809CB22__INCLUDED_)
#define AFX_PICCLICKDOC_H__C39557BB_B742_11D1_92E8_0080C809CB22__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPicClickDoc : public CDocument
{
protected: // create from serialization only
	CPicClickDoc();
	DECLARE_DYNCREATE(CPicClickDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicClickDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPicClickDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPicClickDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICCLICKDOC_H__C39557BB_B742_11D1_92E8_0080C809CB22__INCLUDED_)
