// PocketUniverseDoc.cpp : implementation of the CPocketUniverseDoc class
//

#include "stdafx.h"
#include "PocketUniverse.h"

#include "PocketUniverseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseDoc

IMPLEMENT_DYNCREATE(CPocketUniverseDoc, CDocument)

BEGIN_MESSAGE_MAP(CPocketUniverseDoc, CDocument)
	//{{AFX_MSG_MAP(CPocketUniverseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseDoc construction/destruction

CPocketUniverseDoc::CPocketUniverseDoc()
{
	// TODO: add one-time construction code here

}

CPocketUniverseDoc::~CPocketUniverseDoc()
{
}

BOOL CPocketUniverseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseDoc serialization

void CPocketUniverseDoc::Serialize(CArchive& ar)
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
// CPocketUniverseDoc diagnostics

#ifdef _DEBUG
void CPocketUniverseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPocketUniverseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseDoc commands
