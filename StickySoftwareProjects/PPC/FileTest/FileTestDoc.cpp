// FileTestDoc.cpp : implementation of the CFileTestDoc class
//

#include "stdafx.h"
#include "FileTest.h"

#include "FileTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileTestDoc

IMPLEMENT_DYNCREATE(CFileTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileTestDoc, CDocument)
	//{{AFX_MSG_MAP(CFileTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileTestDoc construction/destruction

CFileTestDoc::CFileTestDoc()
{
	// TODO: add one-time construction code here

}

CFileTestDoc::~CFileTestDoc()
{
}

BOOL CFileTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFileTestDoc serialization

void CFileTestDoc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();

	if (ar.IsStoring())
	{
		// TODO: add storing code here

		if (fileText)
		{
			delete[] fileText;
			fileText=0;
		}

		fileText=(char *) new char[100];
		f->Write(fileText,100);

	}
	else
	{
		// TODO: add loading code here
		if (fileText)
		{
			delete[] fileText;
			fileText=0;
		}

		fileText=(char *) new char[100];
		f->Read(fileText,100);

	}
}

/////////////////////////////////////////////////////////////////////////////
// CFileTestDoc diagnostics

#ifdef _DEBUG
void CFileTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileTestDoc commands
