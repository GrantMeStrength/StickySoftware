// PicClickDoc.cpp : implementation of the CPicClickDoc class
//

#include "stdafx.h"
#include "PicClick.h"

#include "PicClickDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicClickDoc

IMPLEMENT_DYNCREATE(CPicClickDoc, CDocument)

BEGIN_MESSAGE_MAP(CPicClickDoc, CDocument)
	//{{AFX_MSG_MAP(CPicClickDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicClickDoc construction/destruction

CPicClickDoc::CPicClickDoc()
{
	// TODO: add one-time construction code here

}

CPicClickDoc::~CPicClickDoc()
{
}

BOOL CPicClickDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPicClickDoc serialization

void CPicClickDoc::Serialize(CArchive& ar)
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
// CPicClickDoc diagnostics

#ifdef _DEBUG
void CPicClickDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPicClickDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPicClickDoc commands
