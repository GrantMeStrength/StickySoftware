// pp1Doc.cpp : implementation of the CPp1Doc class
//

#include "stdafx.h"
#include "pp1.h"

#include "pp1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPp1Doc

IMPLEMENT_DYNCREATE(CPp1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPp1Doc, CDocument)
	//{{AFX_MSG_MAP(CPp1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPp1Doc construction/destruction

CPp1Doc::CPp1Doc()
{
	// TODO: add one-time construction code here

}

CPp1Doc::~CPp1Doc()
{
}

BOOL CPp1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPp1Doc serialization

void CPp1Doc::Serialize(CArchive& ar)
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
// CPp1Doc diagnostics

#ifdef _DEBUG
void CPp1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPp1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPp1Doc commands
