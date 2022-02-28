// TalkingClockDoc.cpp : implementation of the CTalkingClockDoc class
//

#include "stdafx.h"
#include "TalkingClock.h"

#include "TalkingClockDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockDoc

IMPLEMENT_DYNCREATE(CTalkingClockDoc, CDocument)

BEGIN_MESSAGE_MAP(CTalkingClockDoc, CDocument)
	//{{AFX_MSG_MAP(CTalkingClockDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockDoc construction/destruction

CTalkingClockDoc::CTalkingClockDoc()
{
	// TODO: add one-time construction code here

}

CTalkingClockDoc::~CTalkingClockDoc()
{
}

BOOL CTalkingClockDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTalkingClockDoc serialization

void CTalkingClockDoc::Serialize(CArchive& ar)
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
// CTalkingClockDoc diagnostics

#ifdef _DEBUG
void CTalkingClockDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTalkingClockDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTalkingClockDoc commands
