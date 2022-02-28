// test9Doc.cpp : implementation of the CTest9Doc class
//

#include "stdafx.h"
#include "test9.h"

#include "test9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest9Doc

IMPLEMENT_DYNCREATE(CTest9Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest9Doc, CDocument)
	//{{AFX_MSG_MAP(CTest9Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest9Doc construction/destruction

CTest9Doc::CTest9Doc()
{
	// TODO: add one-time construction code here

}

CTest9Doc::~CTest9Doc()
{
}

BOOL CTest9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest9Doc serialization

void CTest9Doc::Serialize(CArchive& ar)
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
// CTest9Doc diagnostics

#ifdef _DEBUG
void CTest9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest9Doc commands
