// PianoDoc.cpp : implementation of the CPianoDoc class
//

#include "stdafx.h"
#include "Piano.h"

#include "PianoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern short int song[258];
extern short int end_song;


/////////////////////////////////////////////////////////////////////////////
// CPianoDoc

IMPLEMENT_DYNCREATE(CPianoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPianoDoc, CDocument)
	//{{AFX_MSG_MAP(CPianoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPianoDoc construction/destruction

CPianoDoc::CPianoDoc()
{
	// TODO: add one-time construction code here

}

CPianoDoc::~CPianoDoc()
{
}

BOOL CPianoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	SetPathName(CString("\\My Documents\\.tun"),false);
//	SetPathName(CString("\\.tun"),false);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CPianoDoc serialization

void CPianoDoc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();

	if (ar.IsStoring())
	{
		song[257]=end_song;
		f->Write(&song[0],sizeof(song));
	}
	else
	{
		f->Read(&song[0],sizeof(song));
		end_song=song[257];
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPianoDoc diagnostics

#ifdef _DEBUG
void CPianoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPianoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPianoDoc commands
