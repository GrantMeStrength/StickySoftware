// ZoneCEDoc.cpp : implementation of the CZoneCEDoc class
//

#include "stdafx.h"
#include "ZoneCE.h"

#include "ZoneCEDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZoneCEDoc

IMPLEMENT_DYNCREATE(CZoneCEDoc, CDocument)

BEGIN_MESSAGE_MAP(CZoneCEDoc, CDocument)
	//{{AFX_MSG_MAP(CZoneCEDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZoneCEDoc construction/destruction

CZoneCEDoc::CZoneCEDoc()
{
	// TODO: add one-time construction code here

}

CZoneCEDoc::~CZoneCEDoc()
{
}

BOOL CZoneCEDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CZoneCEDoc serialization

void CZoneCEDoc::Serialize(CArchive& ar)
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
// CZoneCEDoc diagnostics

#ifdef _DEBUG
void CZoneCEDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZoneCEDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZoneCEDoc commands
