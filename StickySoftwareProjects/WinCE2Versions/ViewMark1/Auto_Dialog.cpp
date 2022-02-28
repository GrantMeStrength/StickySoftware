// Auto_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Auto_Dialog.h"

extern int CurrentUnit;
extern int CurrentTarget;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAuto_Dialog dialog


CAuto_Dialog::CAuto_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAuto_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAuto_Dialog)
	//}}AFX_DATA_INIT
}


void CAuto_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAuto_Dialog)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAuto_Dialog, CDialog)
	//{{AFX_MSG_MAP(CAuto_Dialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAuto_Dialog message handlers


BOOL CAuto_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CListBox * pCombo = (CListBox *)GetDlgItem(IDC_LIST_UNIT);

	pCombo->AddString(L"Second(s)");
	pCombo->AddString(L"Minute(s)");
	pCombo->AddString(L"Hour(s)");
	pCombo->AddString(L"Day(s)");
	pCombo->AddString(L"Month(s)");
	pCombo->AddString(L"Year(s)");
	//pCombo->SetTopIndex(CurrentUnit);
	//pCombo->SetCurSel(0);

	CListBox * tCombo = (CListBox *)GetDlgItem(IDC_LIST_LOCK);

	tCombo->AddString(L"Sun");
	tCombo->AddString(L"Moon");
	tCombo->AddString(L"Mercury");
	tCombo->AddString(L"Mars");
	tCombo->AddString(L"Jupiter");
	tCombo->AddString(L"Saturn");
	tCombo->AddString(L"Uranus");
	tCombo->AddString(L"Neptune");
	tCombo->AddString(L"Pluto");
	tCombo->AddString(L"Nothing");
	tCombo->SetCurSel(CurrentTarget);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


	// This is called when the auto-init dialog
	// appears, and we use it to set the right
	// radio button.

/*
	
	switch (CurrentUnit)
	{
	case 1:CheckDlgButton(IDC_RADIO_SEC,1);break;
	case 2:CheckDlgButton(IDC_RADIO_MIN,1);break;
	case 3:CheckDlgButton(IDC_RADIO_HOUR,1);break;
	case 4:CheckDlgButton(IDC_RADIO_DAY,1);break;
   	case 5:CheckDlgButton(IDC_RADIO_MONTH,1);break;
   	case 6:CheckDlgButton(IDC_RADIO_YEAR,1);break;
	}
	*/
