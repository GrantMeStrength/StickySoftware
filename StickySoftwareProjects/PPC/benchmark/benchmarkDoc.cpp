// benchmarkDoc.cpp : implementation of the CBenchmarkDoc class
//

#include "stdafx.h"
#include "benchmark.h"

#include "benchmarkDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDoc

IMPLEMENT_DYNCREATE(CBenchmarkDoc, CDocument)

BEGIN_MESSAGE_MAP(CBenchmarkDoc, CDocument)
	//{{AFX_MSG_MAP(CBenchmarkDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDoc construction/destruction

CBenchmarkDoc::CBenchmarkDoc()
{
	// TODO: add one-time construction code here

}

CBenchmarkDoc::~CBenchmarkDoc()
{
}

BOOL CBenchmarkDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDoc serialization

void CBenchmarkDoc::Serialize(CArchive& ar)
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
// CBenchmarkDoc diagnostics

#ifdef _DEBUG
void CBenchmarkDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBenchmarkDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBenchmarkDoc commands
