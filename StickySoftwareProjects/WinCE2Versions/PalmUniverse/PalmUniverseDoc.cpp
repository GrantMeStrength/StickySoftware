// PalmUniverseDoc.cpp : implementation of the CPalmUniverseDoc class
//

#include "stdafx.h"
#include "PalmUniverse.h"

#include "PalmUniverseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseDoc

IMPLEMENT_DYNCREATE(CPalmUniverseDoc, CDocument)

BEGIN_MESSAGE_MAP(CPalmUniverseDoc, CDocument)
	//{{AFX_MSG_MAP(CPalmUniverseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseDoc construction/destruction

CPalmUniverseDoc::CPalmUniverseDoc()
{
	// TODO: add one-time construction code here

}

CPalmUniverseDoc::~CPalmUniverseDoc()
{
}

BOOL CPalmUniverseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseDoc serialization

void CPalmUniverseDoc::Serialize(CArchive& ar)
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
// CPalmUniverseDoc diagnostics

#ifdef _DEBUG
void CPalmUniverseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPalmUniverseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPalmUniverseDoc commands
