// testrebarDoc.cpp : implementation of the CTestrebarDoc class
//

#include "stdafx.h"
#include "testrebar.h"

#include "testrebarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestrebarDoc

IMPLEMENT_DYNCREATE(CTestrebarDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestrebarDoc, CDocument)
	//{{AFX_MSG_MAP(CTestrebarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestrebarDoc construction/destruction

CTestrebarDoc::CTestrebarDoc()
{
	// TODO: add one-time construction code here

}

CTestrebarDoc::~CTestrebarDoc()
{
}

BOOL CTestrebarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestrebarDoc serialization

void CTestrebarDoc::Serialize(CArchive& ar)
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
// CTestrebarDoc diagnostics

#ifdef _DEBUG
void CTestrebarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestrebarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestrebarDoc commands
