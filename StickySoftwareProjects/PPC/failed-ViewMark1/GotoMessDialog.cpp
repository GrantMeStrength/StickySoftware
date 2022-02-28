// GotoMessDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "GotoMessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGotoMessDialog dialog


CGotoMessDialog::CGotoMessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGotoMessDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGotoMessDialog)
	m_messnumber = 1;
	//}}AFX_DATA_INIT
}


void CGotoMessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGotoMessDialog)
	DDX_Text(pDX, IDC_MESS_NUMBER, m_messnumber);
	DDV_MinMaxInt(pDX, m_messnumber, 1, 110);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGotoMessDialog, CDialog)
	//{{AFX_MSG_MAP(CGotoMessDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGotoMessDialog message handlers

BOOL CGotoMessDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MESS_NUMBER);
	pSpin->SetRange(1,110);
	//m_messnumber=1;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
