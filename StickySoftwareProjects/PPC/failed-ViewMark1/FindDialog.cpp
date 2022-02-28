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

/////////////////////////////////////////////////////////////////////////////
// CFindDialog dialog


CFindDialog::CFindDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFindDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDialog, CDialog)
	//{{AFX_MSG_MAP(CFindDialog)
	ON_BN_CLICKED(IDC_RADIO_JUPITER, OnRadioJupiter)
	ON_BN_CLICKED(IDC_RADIO_MARS, OnRadioMars)
	ON_BN_CLICKED(IDC_RADIO_MERCURY, OnRadioMercury)
	ON_BN_CLICKED(IDC_RADIO_MOON, OnRadioMoon)
	ON_BN_CLICKED(IDC_RADIO_NEPTUNE, OnRadioNeptune)
	ON_BN_CLICKED(IDC_RADIO_PLUTO, OnRadioPluto)
	ON_BN_CLICKED(IDC_RADIO_SATURN, OnRadioSaturn)
	ON_BN_CLICKED(IDC_RADIO_SUN, OnRadioSun)
	ON_BN_CLICKED(IDC_RADIO_URANUS, OnRadioUranus)
	ON_BN_CLICKED(IDC_RADIO_VENUS, OnRadioVenus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDialog message handlers

void CFindDialog::OnRadioJupiter() 
{
	m_body=JUPITER;
	
}

void CFindDialog::OnRadioMars() 
{
	m_body=MARS;	
}

void CFindDialog::OnRadioMercury() 
{
	m_body=MERCURY;	
}

void CFindDialog::OnRadioMoon() 
{
	m_body=MOON;
}

void CFindDialog::OnRadioNeptune() 
{
	m_body=NEPTUNE;
}

void CFindDialog::OnRadioPluto() 
{
	m_body=PLUTO;
}

void CFindDialog::OnRadioSaturn() 
{
	m_body=SATURN;
}

void CFindDialog::OnRadioSun() 
{
	m_body=SUN;
}

void CFindDialog::OnRadioUranus() 
{
	m_body=URANUS;
}

void CFindDialog::OnRadioVenus() 
{
	m_body=VENUS;
}
