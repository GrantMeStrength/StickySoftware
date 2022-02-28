// TZProDoc.cpp : implementation of the CTZProDoc class
//

#include "stdafx.h"
#include "TZPro.h"

#include "TZProDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTZProDoc

IMPLEMENT_DYNCREATE(CTZProDoc, CDocument)

BEGIN_MESSAGE_MAP(CTZProDoc, CDocument)
	//{{AFX_MSG_MAP(CTZProDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTZProDoc construction/destruction

CTZProDoc::CTZProDoc()
{
}

CTZProDoc::~CTZProDoc()
{
}

BOOL CTZProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTZProDoc serialization

void CTZProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTZProDoc diagnostics

#ifdef _DEBUG
void CTZProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTZProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTZProDoc commands
