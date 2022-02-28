// bitmaptesterDoc.cpp : implementation of the CBitmaptesterDoc class
//

#include "stdafx.h"
#include "bitmaptester.h"

#include "bitmaptesterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterDoc

IMPLEMENT_DYNCREATE(CBitmaptesterDoc, CDocument)

BEGIN_MESSAGE_MAP(CBitmaptesterDoc, CDocument)
	//{{AFX_MSG_MAP(CBitmaptesterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterDoc construction/destruction

CBitmaptesterDoc::CBitmaptesterDoc()
{
	// TODO: add one-time construction code here

}

CBitmaptesterDoc::~CBitmaptesterDoc()
{
}

BOOL CBitmaptesterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterDoc serialization

void CBitmaptesterDoc::Serialize(CArchive& ar)
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
// CBitmaptesterDoc diagnostics

#ifdef _DEBUG
void CBitmaptesterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBitmaptesterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmaptesterDoc commands
