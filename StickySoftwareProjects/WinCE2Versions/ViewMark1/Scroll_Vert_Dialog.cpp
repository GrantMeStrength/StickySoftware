// Scroll_Vert_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Scroll_Vert_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScroll_Vert_Dialog dialog


CScroll_Vert_Dialog::CScroll_Vert_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CScroll_Vert_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScroll_Vert_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScroll_Vert_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScroll_Vert_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScroll_Vert_Dialog, CDialog)
	//{{AFX_MSG_MAP(CScroll_Vert_Dialog)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScroll_Vert_Dialog message handlers

void CScroll_Vert_Dialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{

	switch (nSBCode) {


	};

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
