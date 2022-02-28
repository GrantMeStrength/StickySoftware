// CleanBarneyDoc.cpp : implementation of the CCleanBarneyDoc class
//

#include "stdafx.h"
#include "CleanBarney.h"

#include "CleanBarneyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyDoc

IMPLEMENT_DYNCREATE(CCleanBarneyDoc, CDocument)

BEGIN_MESSAGE_MAP(CCleanBarneyDoc, CDocument)
	//{{AFX_MSG_MAP(CCleanBarneyDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyDoc construction/destruction

CCleanBarneyDoc::CCleanBarneyDoc()
{
}

CCleanBarneyDoc::~CCleanBarneyDoc()
{
}

BOOL CCleanBarneyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyDoc serialization

void CCleanBarneyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyDoc diagnostics

#ifdef _DEBUG
void CCleanBarneyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCleanBarneyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCleanBarneyDoc commands
