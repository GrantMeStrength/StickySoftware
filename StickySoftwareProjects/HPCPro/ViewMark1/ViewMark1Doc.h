// ViewMark1Doc.h : interface of the CViewMark1Doc class
//
/////////////////////////////////////////////////////////////////////////////

class CViewMark1Doc : public CDocument
{
protected: // create from serialization only
	CViewMark1Doc();
	DECLARE_DYNCREATE(CViewMark1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewMark1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	char * fileText;
	virtual ~CViewMark1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewMark1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
