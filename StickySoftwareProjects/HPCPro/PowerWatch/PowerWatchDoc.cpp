// PowerWatchDoc.cpp : implementation of the CPowerWatchDoc class
//

#include "stdafx.h"
#include "PowerWatch.h"

#include "PowerWatchDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchDoc

IMPLEMENT_DYNCREATE(CPowerWatchDoc, CDocument)

BEGIN_MESSAGE_MAP(CPowerWatchDoc, CDocument)
	//{{AFX_MSG_MAP(CPowerWatchDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchDoc construction/destruction

CPowerWatchDoc::CPowerWatchDoc()
{
	// TODO: add one-time construction code here

}

CPowerWatchDoc::~CPowerWatchDoc()
{
}

BOOL CPowerWatchDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPowerWatchDoc serialization

void CPowerWatchDoc::Serialize(CArchive& ar)
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
// CPowerWatchDoc diagnostics

#ifdef _DEBUG
void CPowerWatchDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPowerWatchDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPowerWatchDoc commands
