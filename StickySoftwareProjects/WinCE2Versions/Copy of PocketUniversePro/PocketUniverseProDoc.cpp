// PocketUniverseProDoc.cpp : implementation of the CPocketUniverseProDoc class
//

#include "stdafx.h"
#include "PocketUniversePro.h"

#include "PocketUniverseProDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProDoc

IMPLEMENT_DYNCREATE(CPocketUniverseProDoc, CDocument)

BEGIN_MESSAGE_MAP(CPocketUniverseProDoc, CDocument)
	//{{AFX_MSG_MAP(CPocketUniverseProDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProDoc construction/destruction

CPocketUniverseProDoc::CPocketUniverseProDoc()
{
	// TODO: add one-time construction code here

}

CPocketUniverseProDoc::~CPocketUniverseProDoc()
{
}

BOOL CPocketUniverseProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProDoc serialization

void CPocketUniverseProDoc::Serialize(CArchive& ar)
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
// CPocketUniverseProDoc diagnostics

#ifdef _DEBUG
void CPocketUniverseProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPocketUniverseProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPocketUniverseProDoc commands
