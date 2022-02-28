// GotoAltAzDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "GotoAltAzDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGotoAltAzDialog dialog


CGotoAltAzDialog::CGotoAltAzDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGotoAltAzDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGotoAltAzDialog)
	m_gotoaltdeg = 0;
	m_gotoaltmin = 0;
	m_gotoaltsec = 0;
	m_gotoazdeg = 0;
	m_gotoazmin = 0;
	m_gotoazsec = 0;
	//}}AFX_DATA_INIT
}


void CGotoAltAzDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGotoAltAzDialog)
	DDX_Text(pDX, IDC_GOTO_ALT_DEG, m_gotoaltdeg);
	DDV_MinMaxInt(pDX, m_gotoaltdeg, -89, 89);
	DDX_Text(pDX, IDC_GOTO_ALT_MIN, m_gotoaltmin);
	DDV_MinMaxInt(pDX, m_gotoaltmin, 0, 59);
	DDX_Text(pDX, IDC_GOTO_ALT_SEC, m_gotoaltsec);
	DDV_MinMaxInt(pDX, m_gotoaltsec, 0, 59);
	DDX_Text(pDX, IDC_GOTO_AZ_DEG, m_gotoazdeg);
	DDV_MinMaxInt(pDX, m_gotoazdeg, 0, 359);
	DDX_Text(pDX, IDC_GOTO_AZ_MIN, m_gotoazmin);
	DDV_MinMaxInt(pDX, m_gotoazmin, 0, 59);
	DDX_Text(pDX, IDC_GOTO_AZ_SEC, m_gotoazsec);
	DDV_MinMaxInt(pDX, m_gotoazsec, 0, 59);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGotoAltAzDialog, CDialog)
	//{{AFX_MSG_MAP(CGotoAltAzDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGotoAltAzDialog message handlers

BOOL CGotoAltAzDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_ALT_DEG);
	pSpin->SetRange(-89,89);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_ALT_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_ALT_SEC);
	pSpin->SetRange(0,59);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_AZ_DEG);
	pSpin->SetRange(0,359);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_AZ_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_AZ_SEC);
	pSpin->SetRange(0,59);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
