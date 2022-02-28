// CamLink1Doc.cpp : implementation of the CCamLink1Doc class
//

#include "stdafx.h"
#include "CamLink1.h"

#include "CamLink1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCamLink1Doc

IMPLEMENT_DYNCREATE(CCamLink1Doc, CDocument)

BEGIN_MESSAGE_MAP(CCamLink1Doc, CDocument)
	//{{AFX_MSG_MAP(CCamLink1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamLink1Doc construction/destruction

CCamLink1Doc::CCamLink1Doc()
{
	// TODO: add one-time construction code here

}

CCamLink1Doc::~CCamLink1Doc()
{
}

BOOL CCamLink1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCamLink1Doc serialization

void CCamLink1Doc::Serialize(CArchive& ar)
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
// CCamLink1Doc diagnostics

#ifdef _DEBUG
void CCamLink1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCamLink1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCamLink1Doc commands
