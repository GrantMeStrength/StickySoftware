// TankDoc.cpp : implementation of the CTankDoc class
//

#include "stdafx.h"
#include "Tank.h"

#include "TankDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankDoc

IMPLEMENT_DYNCREATE(CTankDoc, CDocument)

BEGIN_MESSAGE_MAP(CTankDoc, CDocument)
	//{{AFX_MSG_MAP(CTankDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankDoc construction/destruction

CTankDoc::CTankDoc()
{
}

CTankDoc::~CTankDoc()
{
}

BOOL CTankDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTankDoc serialization

void CTankDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTankDoc diagnostics

#ifdef _DEBUG
void CTankDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTankDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankDoc commands
