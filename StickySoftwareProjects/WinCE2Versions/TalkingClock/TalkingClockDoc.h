// TalkingClockDoc.h : interface of the CTalkingClockDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TALKINGCLOCKDOC_H__3D95CBEE_43E7_11D2_93E0_080000380657__INCLUDED_)
#define AFX_TALKINGCLOCKDOC_H__3D95CBEE_43E7_11D2_93E0_080000380657__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTalkingClockDoc : public CDocument
{
protected: // create from serialization only
	CTalkingClockDoc();
	DECLARE_DYNCREATE(CTalkingClockDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalkingClockDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTalkingClockDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTalkingClockDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKINGCLOCKDOC_H__3D95CBEE_43E7_11D2_93E0_080000380657__INCLUDED_)
