// HangManDoc.cpp : implementation of the CHangManDoc class
//

#include "stdafx.h"
#include "HangMan.h"

#include "HangManDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHangManDoc

IMPLEMENT_DYNCREATE(CHangManDoc, CDocument)

BEGIN_MESSAGE_MAP(CHangManDoc, CDocument)
	//{{AFX_MSG_MAP(CHangManDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHangManDoc construction/destruction

CHangManDoc::CHangManDoc()
{
	// TODO: add one-time construction code here

}

CHangManDoc::~CHangManDoc()
{
}

BOOL CHangManDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHangManDoc serialization

void CHangManDoc::Serialize(CArchive& ar)
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
// CHangManDoc diagnostics

#ifdef _DEBUG
void CHangManDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHangManDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHangManDoc commands
