// FindDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "FindDialog.h"

#include "globalstuff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



#define CNUMNAMES 55

struct cname_type {
	 char name[15];
	float ra,dec;
};

extern struct cname_type cname[CNUMNAMES];
//extern struct cname_type cncords[CNUMNAMES];



/////////////////////////////////////////////////////////////////////////////
// CFindDialog dialog


CFindDialog::CFindDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDialog)
	m_const = 0;
	m_solar = 0;
	m_star = 0;
	m_messier = 0;
	//}}AFX_DATA_INIT
}


void CFindDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDialog)
	DDX_CBIndex(pDX, IDC_COMBO_GOTOCONST, m_const);
	DDX_CBIndex(pDX, IDC_COMBO_GOTOSOLAR, m_solar);
	DDX_CBIndex(pDX, IDC_COMBO_GOTOSTAR, m_star);
	DDX_Text(pDX, IDC_MESS_NUMBER, m_messier);
	DDV_MinMaxInt(pDX, m_messier, 0, 110);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDialog, CDialog)
	//{{AFX_MSG_MAP(CFindDialog)
	ON_CBN_CLOSEUP(IDC_COMBO_GOTOCONST, OnCloseupComboGotoconst)
	ON_CBN_CLOSEUP(IDC_COMBO_GOTOSOLAR, OnCloseupComboGotosolar)
	ON_CBN_CLOSEUP(IDC_COMBO_GOTOSTAR, OnCloseupComboGotostar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDialog message handlers



BOOL CFindDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString plop;

	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_MESS_NUMBER);
	pSpin->SetRange(1,110);

	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSOLAR);
	pCBox->AddString(L"- Solar System -");
	pCBox->AddString(L"Sun");
	pCBox->AddString(L"Mercury");
	pCBox->AddString(L"Venus");
	pCBox->AddString(L"Mars");
	pCBox->AddString(L"Jupiter");
	pCBox->AddString(L"Saturn");
	pCBox->AddString(L"Uranus");
	pCBox->AddString(L"Neptune");
	pCBox->AddString(L"Pluto");
	pCBox->AddString(L"Moon");
	pCBox->SetCurSel(0);
	

	CComboBox * pSBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOCONST);
	pSBox->AddString(L"- Constellations -");
	for (int i=0;i<32;i++)
	{
		plop=cname[i].name;
		pSBox->AddString(plop);
	}
	pSBox->SetCurSel(0);
	
	CComboBox * pABox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSTAR);
	pABox->AddString(L"- Stars -");
	for (i=32;i<CNUMNAMES;i++)
	{
		plop=cname[i].name;
		pABox->AddString(plop);
	}
	
	pABox->SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFindDialog::OnCloseupComboGotoconst() 
{
	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSOLAR);
	pCBox->SetCurSel(0);
	CComboBox * pABox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSTAR);
	pABox->SetCurSel(0);
	m_messier=0;
}

void CFindDialog::OnCloseupComboGotosolar() 
{
	CComboBox * pSBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOCONST);
	pSBox->SetCurSel(0);
	CComboBox * pABox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSTAR);
	pABox->SetCurSel(0);
	m_messier=0;

}

void CFindDialog::OnCloseupComboGotostar() 
{
	CComboBox * pSBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOCONST);
	pSBox->SetCurSel(0);
	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_GOTOSOLAR);
	pCBox->SetCurSel(0);
	m_messier=0;

}
