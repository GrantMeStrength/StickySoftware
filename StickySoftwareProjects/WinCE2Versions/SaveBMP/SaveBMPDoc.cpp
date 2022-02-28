// SaveBMPDoc.cpp : implementation of the CSaveBMPDoc class
//

#include "stdafx.h"
#include "SaveBMP.h"

#include "SaveBMPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveBMPDoc

IMPLEMENT_DYNCREATE(CSaveBMPDoc, CDocument)

BEGIN_MESSAGE_MAP(CSaveBMPDoc, CDocument)
	//{{AFX_MSG_MAP(CSaveBMPDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveBMPDoc construction/destruction

CSaveBMPDoc::CSaveBMPDoc()
{
}

CSaveBMPDoc::~CSaveBMPDoc()
{
}

BOOL CSaveBMPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSaveBMPDoc serialization

void CSaveBMPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSaveBMPDoc diagnostics

#ifdef _DEBUG
void CSaveBMPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSaveBMPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSaveBMPDoc commands
