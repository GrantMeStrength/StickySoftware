// dummy2Doc.cpp : implementation of the CDummy2Doc class
//

#include "stdafx.h"
#include "dummy2.h"

#include "dummy2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDummy2Doc

IMPLEMENT_DYNCREATE(CDummy2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDummy2Doc, CDocument)
	//{{AFX_MSG_MAP(CDummy2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDummy2Doc construction/destruction

CDummy2Doc::CDummy2Doc()
{
	// TODO: add one-time construction code here

}

CDummy2Doc::~CDummy2Doc()
{
}

BOOL CDummy2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDummy2Doc serialization

void CDummy2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDummy2Doc diagnostics

#ifdef _DEBUG
void CDummy2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDummy2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDummy2Doc commands
