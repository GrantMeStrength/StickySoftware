// CKeyDefineDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "CKeyDefineDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CCKeyDefineDialog dialog


CCKeyDefineDialog::CCKeyDefineDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCKeyDefineDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCKeyDefineDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCKeyDefineDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCKeyDefineDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCKeyDefineDialog, CDialog)
	//{{AFX_MSG_MAP(CCKeyDefineDialog)
	ON_BN_CLICKED(IDC_RADIO_LOOK, OnRadioLook)
	ON_BN_CLICKED(IDC_RADIO_TIME, OnRadioTime)
	ON_BN_CLICKED(IDC_RADIO_ZOOM, OnRadioZoom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCKeyDefineDialog message handlers

BOOL CCKeyDefineDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	switch (keymode)
	{
		case 1:CheckDlgButton(IDC_RADIO_LOOK,1);break;
		case 2:CheckDlgButton(IDC_RADIO_ZOOM,1);break;
		case 3:CheckDlgButton(IDC_RADIO_TIME,1);break;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCKeyDefineDialog::OnRadioLook() 
{
	keymode=1;
}

void CCKeyDefineDialog::OnRadioZoom() 
{
	keymode=2;
}

void CCKeyDefineDialog::OnRadioTime() 
{
	keymode=3;
}


