// LunarAtlasDoc.cpp : implementation of the CLunarAtlasDoc class
//

#include "stdafx.h"
#include "LunarAtlas.h"

#include "LunarAtlasDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasDoc

IMPLEMENT_DYNCREATE(CLunarAtlasDoc, CDocument)

BEGIN_MESSAGE_MAP(CLunarAtlasDoc, CDocument)
	//{{AFX_MSG_MAP(CLunarAtlasDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasDoc construction/destruction

CLunarAtlasDoc::CLunarAtlasDoc()
{
	// TODO: add one-time construction code here

}

CLunarAtlasDoc::~CLunarAtlasDoc()
{
}

BOOL CLunarAtlasDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasDoc serialization

void CLunarAtlasDoc::Serialize(CArchive& ar)
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
// CLunarAtlasDoc diagnostics

#ifdef _DEBUG
void CLunarAtlasDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLunarAtlasDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLunarAtlasDoc commands
