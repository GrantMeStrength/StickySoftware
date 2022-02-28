// LotteryDoc.cpp : implementation of the CLotteryDoc class
//

#include "stdafx.h"
#include "Lottery.h"

#include "LotteryDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int lines[20][6];

/////////////////////////////////////////////////////////////////////////////
// CLotteryDoc

IMPLEMENT_DYNCREATE(CLotteryDoc, CDocument)

BEGIN_MESSAGE_MAP(CLotteryDoc, CDocument)
	//{{AFX_MSG_MAP(CLotteryDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLotteryDoc construction/destruction

CLotteryDoc::CLotteryDoc()
{
	// TODO: add one-time construction code here

}

CLotteryDoc::~CLotteryDoc()
{
}

BOOL CLotteryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	SetPathName(CString("\\My Documents\\.lot"),false);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLotteryDoc serialization

void CLotteryDoc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();

	if (ar.IsStoring())
	{
		f->Write(&lines[0],sizeof(lines));
	}
	else
	{
		f->Read(&lines[0],sizeof(lines));
	}
}


/////////////////////////////////////////////////////////////////////////////
// CLotteryDoc diagnostics

#ifdef _DEBUG
void CLotteryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLotteryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLotteryDoc commands
