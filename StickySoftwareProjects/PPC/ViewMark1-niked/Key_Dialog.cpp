// Key_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Key_Dialog.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern bool KeyOn;

extern void DrawKey(CDC *pDC);

/////////////////////////////////////////////////////////////////////////////
// CKey_Dialog dialog


CKey_Dialog::CKey_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CKey_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKey_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CKey_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKey_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKey_Dialog, CDialog)
	//{{AFX_MSG_MAP(CKey_Dialog)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKey_Dialog message handlers

void CKey_Dialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// Now the key dialog window is open, we can
	// draw on it!

	DrawKey(&dc);

	// Do not call CDialog::OnPaint() for painting messages
}

void CKey_Dialog::OnOK() 
{
	// TODO: Add extra validation here
	
	DestroyWindow();

	KeyOn=false;
	//CDialog::OnOK();
}

void CKey_Dialog::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;
	//CDialog::PostNcDestroy();
}

void CKey_Dialog::KillDialog()
{
	KeyOn=false;
	DestroyWindow();
	delete this;
}
