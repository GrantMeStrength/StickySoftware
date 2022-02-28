// TestProDoc.cpp : implementation of the CTestProDoc class
//

#include "stdafx.h"
#include "TestPro.h"

#include "TestProDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestProDoc

IMPLEMENT_DYNCREATE(CTestProDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestProDoc, CDocument)
	//{{AFX_MSG_MAP(CTestProDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestProDoc construction/destruction

CTestProDoc::CTestProDoc()
{
}

CTestProDoc::~CTestProDoc()
{
}

BOOL CTestProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestProDoc serialization

void CTestProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestProDoc diagnostics

#ifdef _DEBUG
void CTestProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestProDoc commands
