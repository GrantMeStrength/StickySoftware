// UpdateDialog2.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "UpdateDialog2.h"

extern short int CurrentUnit;
extern short int CurrentTarget;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpdateDialog2 dialog


CUpdateDialog2::CUpdateDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdateDialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdateDialog2)
	m_how = -1;
	m_who = -1;
	m_delayvalue = 0;
	m_jumpvalue = 0;
	//}}AFX_DATA_INIT
}


void CUpdateDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdateDialog2)
	DDX_CBIndex(pDX, IDC_COMBO_HOW, m_how);
	DDX_CBIndex(pDX, IDC_COMBO_WHO, m_who);
	DDX_Text(pDX, IDC_EDIT_DELAY_VALUE, m_delayvalue);
	DDV_MinMaxInt(pDX, m_delayvalue, 1, 100);
	DDX_Text(pDX, IDC_EDIT_JUMP_VALUE, m_jumpvalue);
	DDV_MinMaxInt(pDX, m_jumpvalue, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpdateDialog2, CDialog)
	//{{AFX_MSG_MAP(CUpdateDialog2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpdateDialog2 message handlers



BOOL CUpdateDialog2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Add strings to the combo box
	
	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_HOW);
	pCBox->AddString(L"Second(s)");
	pCBox->AddString(L"Minute(s)");
	pCBox->AddString(L"Hour(s)");
	pCBox->AddString(L"Day(s)");
	pCBox->AddString(L"Month(s)");
	pCBox->AddString(L"Year(s)");
	pCBox->SetCurSel(CurrentUnit);

	CComboBox * qCBox = (CComboBox*)GetDlgItem(IDC_COMBO_WHO);

	qCBox->AddString(L"Sun");
	qCBox->AddString(L"Mercury");
	qCBox->AddString(L"Venus");
	qCBox->AddString(L"Mars");
	qCBox->AddString(L"Jupiter");
	qCBox->AddString(L"Saturn");
	qCBox->AddString(L"Uranus");
	qCBox->AddString(L"Neptune");
	qCBox->AddString(L"Pluto");
	qCBox->AddString(L"Moon");
	qCBox->AddString(L"Nothing");
	qCBox->SetCurSel(CurrentTarget);

	// Set spin values

	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_JUMPVALUE);
	pSpin->SetRange(1,100);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_DELAYVALUE);
	pSpin->SetRange(1,100);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


/*

BOOL CGotoRaDecDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_RA_HOUR);
	pSpin->SetRange(0,23);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_RA_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_RA_SEC);
	pSpin->SetRange(0,59);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_DEC_DEG);
	pSpin->SetRange(-89,89);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_DEC_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GOTO_DEC_SEC);
	pSpin->SetRange(0,59);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


  */
