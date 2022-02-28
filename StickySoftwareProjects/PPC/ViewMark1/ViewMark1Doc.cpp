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

extern DWORD Core[23]; // the settinga all in one chunk!
extern void ExtractCore(bool withtime);
extern void CreateCore();

//#define DEMO

/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc

IMPLEMENT_DYNCREATE(CViewMark1Doc, CDocument)

BEGIN_MESSAGE_MAP(CViewMark1Doc, CDocument)
	//{{AFX_MSG_MAP(CViewMark1Doc)
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

	SetPathName(CString("\\My Documents\\.uni"),false);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CViewMark1Doc serialization

void CViewMark1Doc::Serialize(CArchive& ar)
{
		CFile *f = ar.GetFile();

#ifndef DEMO

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
#endif
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


/*
BOOL CViewMark1Doc::OnSaveDocument(LPCTSTR lpszPathName) 
{

	CString slash = L"\\";

	if ((*lpszPathName==slash) &&	((*(lpszPathName+1)==slash))) 

	{
		//sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
		lpszPathName++;
	}

	return CDocument::OnSaveDocument(lpszPathName);
}

BOOL CViewMark1Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{

	CString slash = L"\\";

	if ((*lpszPathName==slash) && ((*(lpszPathName+1)==slash))) 

	{
		sndPlaySound(L"\\Question", SND_FILENAME|SND_SYNC);
		lpszPathName++;
	}

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}
*/
