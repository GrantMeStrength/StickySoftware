// TestPalmDoc.cpp : implementation of the CTestPalmDoc class
//

#include "stdafx.h"
#include "TestPalm.h"

#include "TestPalmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPalmDoc

IMPLEMENT_DYNCREATE(CTestPalmDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestPalmDoc, CDocument)
	//{{AFX_MSG_MAP(CTestPalmDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPalmDoc construction/destruction

CTestPalmDoc::CTestPalmDoc()
{
}

CTestPalmDoc::~CTestPalmDoc()
{
}

BOOL CTestPalmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestPalmDoc serialization

void CTestPalmDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestPalmDoc diagnostics

#ifdef _DEBUG
void CTestPalmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestPalmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPalmDoc commands
