// dummyDoc.cpp : implementation of the CDummyDoc class
//

#include "stdafx.h"
#include "dummy.h"

#include "dummyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDummyDoc

IMPLEMENT_DYNCREATE(CDummyDoc, CDocument)

BEGIN_MESSAGE_MAP(CDummyDoc, CDocument)
	//{{AFX_MSG_MAP(CDummyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDummyDoc construction/destruction

CDummyDoc::CDummyDoc()
{
	// TODO: add one-time construction code here

}

CDummyDoc::~CDummyDoc()
{
}

BOOL CDummyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDummyDoc serialization

void CDummyDoc::Serialize(CArchive& ar)
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
// CDummyDoc diagnostics

#ifdef _DEBUG
void CDummyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDummyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDummyDoc commands
