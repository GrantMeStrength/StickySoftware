// PowerWatchDoc.h : interface of the CPowerWatchDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POWERWATCHDOC_H__71B93ECB_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
#define AFX_POWERWATCHDOC_H__71B93ECB_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPowerWatchDoc : public CDocument
{
protected: // create from serialization only
	CPowerWatchDoc();
	DECLARE_DYNCREATE(CPowerWatchDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerWatchDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPowerWatchDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPowerWatchDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERWATCHDOC_H__71B93ECB_CB14_11D2_B6D6_00A0C9B5E577__INCLUDED_)
