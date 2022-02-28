// scoobyDoc.cpp : implementation of the CScoobyDoc class
//

#include "stdafx.h"
#include "scooby.h"

#include "scoobyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoobyDoc

IMPLEMENT_DYNCREATE(CScoobyDoc, CDocument)

BEGIN_MESSAGE_MAP(CScoobyDoc, CDocument)
	//{{AFX_MSG_MAP(CScoobyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoobyDoc construction/destruction

CScoobyDoc::CScoobyDoc()
{
	// TODO: add one-time construction code here

}

CScoobyDoc::~CScoobyDoc()
{
}

BOOL CScoobyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CScoobyDoc serialization

void CScoobyDoc::Serialize(CArchive& ar)
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
// CScoobyDoc diagnostics

#ifdef _DEBUG
void CScoobyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScoobyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScoobyDoc commands
