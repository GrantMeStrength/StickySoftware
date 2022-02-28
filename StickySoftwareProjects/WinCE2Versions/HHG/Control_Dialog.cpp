// Control_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "HHG.h"
#include "Control_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void DisplayEntry(CDC *pDC,int entry);

/////////////////////////////////////////////////////////////////////////////
// CControl_Dialog dialog


CControl_Dialog::CControl_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CControl_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CControl_Dialog)
	m_list = _T("");
	//}}AFX_DATA_INIT
}


void CControl_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControl_Dialog)
	DDX_LBString(pDX, IDC_ENTRY_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CControl_Dialog, CDialog)
	//{{AFX_MSG_MAP(CControl_Dialog)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControl_Dialog message handlers

BOOL CControl_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CListBox * pBox = (CListBox*)GetDlgItem(IDC_ENTRY_LIST);
	pBox->AddString(L"Vogon Construction Fleet");
	pBox->AddString(L"Babel Fish");
	pBox->AddString(L"Alcohol");
	pBox->AddString(L"Earth");
	pBox->AddString(L"Oolon Coluphid");
	pBox->AddString(L"Eccentrica Galumbits");
	pBox->AddString(L"Zaphod Beeblebrox");
	pBox->AddString(L"Improbability Drive");
	pBox->SetCurSel(0);


	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CControl_Dialog::OnButtonPlay() 
{

	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);


	int which;

	CListBox * pBox = (CListBox*)GetDlgItem(IDC_ENTRY_LIST);
	which=pBox->GetCurSel();
	
	DisplayEntry(&pdc,which);

}


