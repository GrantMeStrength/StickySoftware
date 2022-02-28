// helptestDoc.cpp : implementation of the CHelptestDoc class
//

#include "stdafx.h"
#include "helptest.h"

#include "helptestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelptestDoc

IMPLEMENT_DYNCREATE(CHelptestDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelptestDoc, CDocument)
	//{{AFX_MSG_MAP(CHelptestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelptestDoc construction/destruction

CHelptestDoc::CHelptestDoc()
{
	// TODO: add one-time construction code here

}

CHelptestDoc::~CHelptestDoc()
{
}

BOOL CHelptestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHelptestDoc serialization

void CHelptestDoc::Serialize(CArchive& ar)
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
// CHelptestDoc diagnostics

#ifdef _DEBUG
void CHelptestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelptestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHelptestDoc commands
