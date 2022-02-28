// BlockDoc.cpp : implementation of the CBlockDoc class
//

#include "stdafx.h"
#include "Block.h"

#include "BlockDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlockDoc

IMPLEMENT_DYNCREATE(CBlockDoc, CDocument)

BEGIN_MESSAGE_MAP(CBlockDoc, CDocument)
	//{{AFX_MSG_MAP(CBlockDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlockDoc construction/destruction

CBlockDoc::CBlockDoc()
{
	// TODO: add one-time construction code here

}

CBlockDoc::~CBlockDoc()
{
}

BOOL CBlockDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBlockDoc serialization

void CBlockDoc::Serialize(CArchive& ar)
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
// CBlockDoc diagnostics

#ifdef _DEBUG
void CBlockDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBlockDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBlockDoc commands
