// CamPCDoc.cpp : implementation of the CCamPCDoc class
//

#include "stdafx.h"
#include "CamPC.h"

#include "CamPCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCamPCDoc

IMPLEMENT_DYNCREATE(CCamPCDoc, CDocument)

BEGIN_MESSAGE_MAP(CCamPCDoc, CDocument)
	//{{AFX_MSG_MAP(CCamPCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamPCDoc construction/destruction

CCamPCDoc::CCamPCDoc()
{
	// TODO: add one-time construction code here

}

CCamPCDoc::~CCamPCDoc()
{
}

BOOL CCamPCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCamPCDoc serialization

void CCamPCDoc::Serialize(CArchive& ar)
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
// CCamPCDoc diagnostics

#ifdef _DEBUG
void CCamPCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCamPCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCamPCDoc commands
