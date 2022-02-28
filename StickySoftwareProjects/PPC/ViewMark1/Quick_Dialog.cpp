// Quick_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Quick_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern double window_az,window_alt;


/////////////////////////////////////////////////////////////////////////////
// CQuick_Dialog dialog


CQuick_Dialog::CQuick_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CQuick_Dialog::IDD, pParent)
{
	parent=pParent;
	//{{AFX_DATA_INIT(CQuick_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CQuick_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuick_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuick_Dialog, CDialog)
	//{{AFX_MSG_MAP(CQuick_Dialog)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_QBUTTON_N, OnQbuttonN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuick_Dialog message handlers

void CQuick_Dialog::PostNcDestroy() 
{
	delete this;
}

void CQuick_Dialog::OnButtonOk() 
{
	DestroyWindow();	
}

void CQuick_Dialog::OnQbuttonN() 
{
	// The Look North Button...	
	window_az=0;
	parent->SendMessage(WM_PAINT,0,0);

}
