// ProjectGDoc.cpp : implementation of the CProjectGDoc class
//

#include "stdafx.h"
#include "ProjectG.h"

#include "ProjectGDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjectGDoc

IMPLEMENT_DYNCREATE(CProjectGDoc, CDocument)

BEGIN_MESSAGE_MAP(CProjectGDoc, CDocument)
	//{{AFX_MSG_MAP(CProjectGDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjectGDoc construction/destruction

CProjectGDoc::CProjectGDoc()
{
	// TODO: add one-time construction code here

}

CProjectGDoc::~CProjectGDoc()
{
}

BOOL CProjectGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProjectGDoc serialization

void CProjectGDoc::Serialize(CArchive& ar)
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
// CProjectGDoc diagnostics

#ifdef _DEBUG
void CProjectGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProjectGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProjectGDoc commands
