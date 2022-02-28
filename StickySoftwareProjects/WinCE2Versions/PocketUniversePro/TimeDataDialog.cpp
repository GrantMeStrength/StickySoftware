// TimeDataDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PocketUniversePro.h"
#include "TimeDataDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeDataDialog dialog


CTimeDataDialog::CTimeDataDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeDataDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeDataDialog)
	m_daylight = FALSE;
	m_day = 9;
	m_hour = 9;
	m_min = 9;
	m_month = 9;
	m_sec = 9;
	m_year = 1999;
	//}}AFX_DATA_INIT
}


void CTimeDataDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeDataDialog)
	DDX_Check(pDX, IDC_TIME_DAYLIGHT, m_daylight);
	DDX_Text(pDX, IDC_TIME_DAY, m_day);
	DDV_MinMaxInt(pDX, m_day, 1, 31);
	DDX_Text(pDX, IDC_TIME_HOUR, m_hour);
	DDV_MinMaxInt(pDX, m_hour, 0, 23);
	DDX_Text(pDX, IDC_TIME_MIN, m_min);
	DDV_MinMaxInt(pDX, m_min, 0, 59);
	DDX_Text(pDX, IDC_TIME_MONTH, m_month);
	DDV_MinMaxInt(pDX, m_month, 1, 12);
	DDX_Text(pDX, IDC_TIME_SEC, m_sec);
	DDV_MinMaxInt(pDX, m_sec, 0, 59);
	DDX_Text(pDX, IDC_TIME_YEAR, m_year);
	DDV_MinMaxInt(pDX, m_year, 1900, 2100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeDataDialog, CDialog)
	//{{AFX_MSG_MAP(CTimeDataDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeDataDialog message handlers

BOOL CTimeDataDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	/*
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_DAY2);
	pSpin->SetRange(1,31);	
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MONTH2);
	pSpin->SetRange(1,12);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_YEAR2);
	pSpin->SetRange(1900,2100);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HOUR2);
	pSpin->SetRange(0,23);	
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MIN2);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_SEC2);
	pSpin->SetRange(0,59);	
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
