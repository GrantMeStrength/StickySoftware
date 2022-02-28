// TimeDateDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "TimeDateDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern short int local_daylight;

/////////////////////////////////////////////////////////////////////////////
// CTimeDateDialog dialog


CTimeDateDialog::CTimeDateDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeDateDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeDateDialog)
	m_month = 0;
	m_year = 0;
	m_day = 0;
	m_hour = 0;
	m_min = 0;
	m_sec = 0;
	//}}AFX_DATA_INIT
}


void CTimeDateDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeDateDialog)
	DDX_Text(pDX, IDC_MONTH_BOX, m_month);
	DDV_MinMaxInt(pDX, m_month, 1, 12);
	DDX_Text(pDX, IDC_YEAR_BOX, m_year);
	DDV_MinMaxInt(pDX, m_year, 1900, 2100);
	DDX_Text(pDX, IDC_DAY_BOX, m_day);
	DDV_MinMaxInt(pDX, m_day, 1, 31);
	DDX_Text(pDX, IDC_TIME_HOUR, m_hour);
	DDV_MinMaxInt(pDX, m_hour, 0, 23);
	DDX_Text(pDX, IDC_TIME_MIN, m_min);
	DDV_MinMaxInt(pDX, m_min, 0, 59);
	DDX_Text(pDX, IDC_TIME_SEC, m_sec);
	DDV_MinMaxInt(pDX, m_sec, 0, 59);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeDateDialog, CDialog)
	//{{AFX_MSG_MAP(CTimeDateDialog)
	ON_BN_CLICKED(IDC_CHECK_DAYLIGHT, OnCheckDaylight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeDateDialog message handlers

BOOL CTimeDateDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_DAY);
	pSpin->SetRange(1,31);	
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MONTH);
	pSpin->SetRange(1,12);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_YEAR);
	pSpin->SetRange(1900,2000);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HOUR);
	pSpin->SetRange(0,23);	
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_SEC);
	pSpin->SetRange(0,59);

	//pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_DL);
	//pSpin->SetRange(-12,12);	
	//Made daylight saving a switch

	CheckDlgButton(IDC_CHECK_DAYLIGHT,local_daylight);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTimeDateDialog::OnCheckDaylight() 
{
		// Toggle the daylight saving setting on and off
	
	if (local_daylight==1) local_daylight=0; else local_daylight=1;

}
