// GotoRaDecDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "GotoRaDecDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGotoRaDecDialog dialog


CGotoRaDecDialog::CGotoRaDecDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGotoRaDecDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGotoRaDecDialog)
	m_gotodecmin = 0;
	m_gotoramin = 0;
	m_gotodecdeg = 0;
	m_gotorahour = 0;
	m_gotodecsec = 0;
	m_gotorasec = 0;
	//}}AFX_DATA_INIT
}


void CGotoRaDecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGotoRaDecDialog)
	DDX_Text(pDX, IDC_GOTO_DEC_MIN, m_gotodecmin);
	DDV_MinMaxInt(pDX, m_gotodecmin, 0, 59);
	DDX_Text(pDX, IDC_GOTO_RA_MIN, m_gotoramin);
	DDV_MinMaxInt(pDX, m_gotoramin, 0, 59);
	DDX_Text(pDX, IDC_GOTO_DEC_DEG, m_gotodecdeg);
	DDV_MinMaxInt(pDX, m_gotodecdeg, -89, 89);
	DDX_Text(pDX, IDC_GOTO_RA_HOUR, m_gotorahour);
	DDV_MinMaxInt(pDX, m_gotorahour, 0, 23);
	DDX_Text(pDX, IDC_GOTO_DEC_SEC, m_gotodecsec);
	DDV_MinMaxInt(pDX, m_gotodecsec, 0, 59);
	DDX_Text(pDX, IDC_GOTO_RA_SEC, m_gotorasec);
	DDV_MinMaxInt(pDX, m_gotorasec, 0, 59);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGotoRaDecDialog, CDialog)
	//{{AFX_MSG_MAP(CGotoRaDecDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGotoRaDecDialog message handlers

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
