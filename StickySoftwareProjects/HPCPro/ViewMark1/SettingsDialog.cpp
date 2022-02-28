// SettingsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "SettingsDialog.h"

extern int CurrentMags;
extern short int display_mode;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog dialog


CSettingsDialog::CSettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingsDialog)
	m_horizon = FALSE;
	m_planets = FALSE;
	m_stars = FALSE;
	m_sites = FALSE;
	m_markers = FALSE;
	m_labels = FALSE;
	m_invert = FALSE;
	m_visible_mags = -1;
	m_text = FALSE;
	m_mess = FALSE;
	m_parallax = FALSE;
	m_hide = FALSE;
	m_outline = FALSE;
	m_sunmoon = FALSE;
	m_realsize = FALSE;
	m_grid = FALSE;
	m_hourglass = FALSE;
	m_moongfx = FALSE;
	m_ecliptic = FALSE;
	//}}AFX_DATA_INIT
}


void CSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingsDialog)
	DDX_Check(pDX, IDC_CHECK_HORIZON, m_horizon);
	DDX_Check(pDX, IDC_CHECK_PLANETS, m_planets);
	DDX_Check(pDX, IDC_CHECK_STARS, m_stars);
	DDX_Check(pDX, IDC_CHECK_SITES, m_sites);
	DDX_Check(pDX, IDC_CHECK_MARKERS, m_markers);
	DDX_Check(pDX, IDC_CHECK_LABELS, m_labels);
	DDX_Check(pDX, IDC_CHECK_INVERT, m_invert);
	DDX_CBIndex(pDX, IDC_COMBO_MAGNITUDES, m_visible_mags);
	DDX_Check(pDX, IDC_CHECK_DETAILS, m_text);
	DDX_Check(pDX, IDC_CHECK_MESS, m_mess);
	DDX_Check(pDX, IDC_CHECK_PARALLAX, m_parallax);
	DDX_Check(pDX, IDC_CHECK_HIDE, m_hide);
	DDX_Check(pDX, IDC_CHECK_OUTLINE, m_outline);
	DDX_Check(pDX, IDC_CHECK_SM, m_sunmoon);
	DDX_Check(pDX, IDC_CHECK_REALSIZE, m_realsize);
	DDX_Check(pDX, IDC_CHECK_GRID, m_grid);
	DDX_Check(pDX, IDC_CHECK_HOURGLASS, m_hourglass);
	DDX_Check(pDX, IDC_CHECK_MOONGFX, m_moongfx);
	DDX_Check(pDX, IDC_CHECK_ECLIPTIC, m_ecliptic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
	//{{AFX_MSG_MAP(CSettingsDialog)
	ON_BN_CLICKED(IDC_RADIO_CONTRAST, OnRadioContrast)
	ON_BN_CLICKED(IDC_RADIO_RED, OnRadioRed)
	ON_BN_CLICKED(IDC_RADIO_STANDARD, OnRadioStandard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingsDialog message handlers

BOOL CSettingsDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_MAGNITUDES);
	pCBox->AddString(L"1st magnitude");
	pCBox->AddString(L"2nd magnitude");
	pCBox->AddString(L"3rd magnitude");
	pCBox->AddString(L"4th magnitude");
	pCBox->AddString(L"5th magnitude");
	pCBox->AddString(L"6th magnitude");
	pCBox->AddString(L"7th magnitude");
//	pCBox->AddString(L"8th magnitude");
//	pCBox->AddString(L"9th magnitude");
	pCBox->SetCurSel(CurrentMags);


	// Ah, but if I could switch off the CComboBox that
	// would be nice.

	switch (display_mode) {
	 case 0:CheckDlgButton(IDC_RADIO_STANDARD,1);break;
	 case 1:CheckDlgButton(IDC_RADIO_CONTRAST,1);break;
	 case 2:CheckDlgButton(IDC_RADIO_RED,1);break;
	 }


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingsDialog::OnRadioContrast() 
{
	display_mode=1;	
	
}

void CSettingsDialog::OnRadioRed() 
{
	display_mode=2;	
	
}

void CSettingsDialog::OnRadioStandard() 
{
	display_mode=0;	
}
