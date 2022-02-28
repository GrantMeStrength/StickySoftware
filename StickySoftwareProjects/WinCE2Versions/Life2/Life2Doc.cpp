// Life2Doc.cpp : implementation of the CLife2Doc class
//

#include "stdafx.h"
#include "Life2.h"

#include "Life2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLife2Doc

IMPLEMENT_DYNCREATE(CLife2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLife2Doc, CDocument)
	//{{AFX_MSG_MAP(CLife2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLife2Doc construction/destruction

CLife2Doc::CLife2Doc()
{
	// TODO: add one-time construction code here

}

CLife2Doc::~CLife2Doc()
{
}

BOOL CLife2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLife2Doc serialization

void CLife2Doc::Serialize(CArchive& ar)
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
// CLife2Doc diagnostics

#ifdef _DEBUG
void CLife2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLife2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLife2Doc commands
