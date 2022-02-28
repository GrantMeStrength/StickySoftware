// HHGDoc.cpp : implementation of the CHHGDoc class
//

#include "stdafx.h"
#include "HHG.h"

#include "HHGDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHHGDoc

IMPLEMENT_DYNCREATE(CHHGDoc, CDocument)

BEGIN_MESSAGE_MAP(CHHGDoc, CDocument)
	//{{AFX_MSG_MAP(CHHGDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHHGDoc construction/destruction

CHHGDoc::CHHGDoc()
{
	// TODO: add one-time construction code here

}

CHHGDoc::~CHHGDoc()
{
}

BOOL CHHGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHHGDoc serialization

void CHHGDoc::Serialize(CArchive& ar)
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
// CHHGDoc diagnostics

#ifdef _DEBUG
void CHHGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHHGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHHGDoc commands
