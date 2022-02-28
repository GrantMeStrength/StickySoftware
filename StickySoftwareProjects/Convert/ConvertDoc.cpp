// ConvertDoc.cpp : implementation of the CConvertDoc class
//

#include "stdafx.h"
#include "Convert.h"

#include "ConvertDoc.h"

#define CAMERA_HEADER_SIZE 512
#define LINES 243
#define COLUMNS 512

#define RES_LINES   375
#define UINT8 unsigned char

extern UINT8 *ccd[RES_LINES];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConvertDoc

IMPLEMENT_DYNCREATE(CConvertDoc, CDocument)

BEGIN_MESSAGE_MAP(CConvertDoc, CDocument)
	//{{AFX_MSG_MAP(CConvertDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertDoc construction/destruction

CConvertDoc::CConvertDoc()
{
	// TODO: add one-time construction code here

}

CConvertDoc::~CConvertDoc()
{
}

BOOL CConvertDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CConvertDoc serialization

void CConvertDoc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();

	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// Loading..

		// First skip past header
		f->Seek(CAMERA_HEADER_SIZE, CFile::begin);

		// Now load the data into the ccd array
		for (int line= 0; line < LINES; line++)
			f->Read(&ccd[line],COLUMNS);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CConvertDoc diagnostics

#ifdef _DEBUG
void CConvertDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CConvertDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConvertDoc commands
