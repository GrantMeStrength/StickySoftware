// LifeDoc.cpp : implementation of the CLifeDoc class
//

#include "stdafx.h"
#include "Life.h"

#include "LifeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern class LifeGrid first;

extern  void StopTimer();

extern class LifeGrid {
	short int grid[30+2][32+2];
public:
	LifeGrid();									// Constructor
	void ClearGrid();
	void WriteGrid(int x, int y,short int value);
	short int ReadGrid(int x, int y);
	int Size();
	short int *Where();
	void LoadGrid();
	void SaveGrid();
} first;

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc

IMPLEMENT_DYNCREATE(CLifeDoc, CDocument)

BEGIN_MESSAGE_MAP(CLifeDoc, CDocument)
	//{{AFX_MSG_MAP(CLifeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc construction/destruction

CLifeDoc::CLifeDoc()
{
	// TODO: add one-time construction code here

}

CLifeDoc::~CLifeDoc()
{
}

BOOL CLifeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CLifeDoc serialization

void CLifeDoc::Serialize(CArchive& ar)
{
	CFile *f = ar.GetFile();


	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//StopTimer();
		f->Write(first.Where(),first.Size());
	}
	else
	{
		// TODO: add loading code here
		//StopTimer();
		f->Read(first.Where(),first.Size());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc diagnostics

#ifdef _DEBUG
void CLifeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLifeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLifeDoc commands
