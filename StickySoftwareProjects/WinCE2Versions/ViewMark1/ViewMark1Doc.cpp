// ViewMark1Doc.cpp : implementation of the CViewMark1Doc class
//

#include "stdafx.h"
#include "ViewMark1.h"

#include "ViewMark1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern DWORD Core[22]; // the settinga all in one chunk!
extern void ExtractCore(bool withtime);
extern void CreateCore();


/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc

IMPLEMENT_DYNCREATE(CViewMark1Doc, CDocument)

BEGIN_MESSAGE_MAP(CViewMark1Doc, CDocument)
	//{{AFX_MSG_MAP(CViewMark1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc construction/destruction

CViewMark1Doc::CViewMark1Doc()
{
	// TODO: add one-time construction code here

}

CViewMark1Doc::~CViewMark1Doc()
{
}

BOOL CViewMark1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc serialization

void CViewMark1Doc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();

	if (ar.IsStoring())
	{
		CreateCore();
		f->Write(&Core[0],sizeof(Core));
	}
	else
	{
		f->Read(&Core[0],sizeof(Core));
		ExtractCore(true);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc diagnostics

#ifdef _DEBUG
void CViewMark1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViewMark1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc commands
