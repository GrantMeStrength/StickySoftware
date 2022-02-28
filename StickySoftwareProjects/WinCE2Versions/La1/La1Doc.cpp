// La1Doc.cpp : implementation of the CLa1Doc class
//

#include "stdafx.h"
#include "La1.h"

#include "La1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLa1Doc

IMPLEMENT_DYNCREATE(CLa1Doc, CDocument)

BEGIN_MESSAGE_MAP(CLa1Doc, CDocument)
	//{{AFX_MSG_MAP(CLa1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLa1Doc construction/destruction

CLa1Doc::CLa1Doc()
{
	// TODO: add one-time construction code here

}

CLa1Doc::~CLa1Doc()
{
}

BOOL CLa1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLa1Doc serialization

void CLa1Doc::Serialize(CArchive& ar)
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
// CLa1Doc diagnostics

#ifdef _DEBUG
void CLa1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLa1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLa1Doc commands
