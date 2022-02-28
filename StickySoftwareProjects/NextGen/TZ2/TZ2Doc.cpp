// TZ2Doc.cpp : implementation of the CTZ2Doc class
//

#include "stdafx.h"
#include "TZ2.h"

#include "TZ2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTZ2Doc

IMPLEMENT_DYNCREATE(CTZ2Doc, CDocument)

BEGIN_MESSAGE_MAP(CTZ2Doc, CDocument)
	//{{AFX_MSG_MAP(CTZ2Doc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTZ2Doc construction/destruction

CTZ2Doc::CTZ2Doc()
{
}

CTZ2Doc::~CTZ2Doc()
{
}

BOOL CTZ2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTZ2Doc serialization

void CTZ2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTZ2Doc diagnostics

#ifdef _DEBUG
void CTZ2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTZ2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTZ2Doc commands
