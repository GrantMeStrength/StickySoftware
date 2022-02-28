// LocationDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "LocationDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern bool eastwest;
extern bool northsouth;


/////////////////////////////////////////////////////////////////////////////
// LocationDialog dialog


LocationDialog::LocationDialog(CWnd* pParent /*=NULL*/)
	: CDialog(LocationDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(LocationDialog)
	m_LAT_MIN = 0;
	m_LAT_DEG = 0;
	m_LAT_SEC = 0;
	m_LONG_DEG = 0;
	m_LONG_MIN = 0;
	m_LONG_SEC = 0;
	m_timezone = 0;
	m_where = -1;
	//}}AFX_DATA_INIT
}


void LocationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LocationDialog)
	DDX_Text(pDX, IDC_LAT_BOX_MIN, m_LAT_MIN);
	DDV_MinMaxInt(pDX, m_LAT_MIN, 0, 59);
	DDX_Text(pDX, IDC_LAT_BOX_DEG, m_LAT_DEG);
	DDV_MinMaxInt(pDX, m_LAT_DEG, 0, 89);
	DDX_Text(pDX, IDC_LAT_BOX_SEC, m_LAT_SEC);
	DDV_MinMaxInt(pDX, m_LAT_SEC, 0, 59);
	DDX_Text(pDX, IDC_LONG_BOX_DEG, m_LONG_DEG);
	DDV_MinMaxInt(pDX, m_LONG_DEG, 0, 179);
	DDX_Text(pDX, IDC_LONG_BOX_MIN, m_LONG_MIN);
	DDV_MinMaxInt(pDX, m_LONG_MIN, 0, 59);
	DDX_Text(pDX, IDC_LONG_BOX_SEC, m_LONG_SEC);
	DDV_MinMaxInt(pDX, m_LONG_SEC, 0, 59);
	DDX_Text(pDX, IDC_TIME_TZ, m_timezone);
	DDV_MinMaxInt(pDX, m_timezone, 0, 12);
	DDX_CBIndex(pDX, IDC_COMBO_WHERE, m_where);
	//}}AFX_DATA_MAP
}



BEGIN_MESSAGE_MAP(LocationDialog, CDialog)
	//{{AFX_MSG_MAP(LocationDialog)
	ON_CBN_CLOSEUP(IDC_COMBO_WHERE, OnCloseupComboWhere)
	ON_BN_CLICKED(IDC_BUTTON_NORTH_SOUTH, OnButtonNorthSouth)
	ON_BN_CLICKED(IDC_BUTTON_EAST_WEST, OnButtonEastWest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LocationDialog message handlers

BOOL LocationDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSpinButtonCtrl* pSpin;
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LONG_DEG);
	pSpin->SetRange(0,179);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LONG_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LONG_SEC);
	pSpin->SetRange(0,59);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LAT_DEG);
	pSpin->SetRange(0,89);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LAT_MIN);
	pSpin->SetRange(0,59);
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_LAT_SEC);
	pSpin->SetRange(0,59);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_TZ);
	pSpin->SetRange(0,12);

	
	CComboBox * pCBox = (CComboBox*)GetDlgItem(IDC_COMBO_WHERE);
	pCBox->AddString(L"- Cities -");
	pCBox->AddString(L"London");
	pCBox->AddString(L"New York");
	pCBox->AddString(L"Tokyo");
	pCBox->AddString(L"Bombay");
	pCBox->AddString(L"Sydney");
	pCBox->AddString(L"Hong Kong");
	pCBox->AddString(L"Moscow");
	pCBox->AddString(L"Los Angeles");
	pCBox->AddString(L"Quebec");
	pCBox->AddString(L"Rome");
	pCBox->AddString(L"Mexico City");
	pCBox->AddString(L"Cape Town");
	pCBox->AddString(L"Dublin");
	pCBox->AddString(L"Seoul");
	pCBox->AddString(L"Bangor");
	pCBox->AddString(L"Jerusalem");
	pCBox->SetCurSel(0);

	if (eastwest)
		SetDlgItemText(IDC_BUTTON_EAST_WEST,L"E");
	else
		SetDlgItemText(IDC_BUTTON_EAST_WEST,L"W");

	if (northsouth)
		SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"N");
	else
		SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"S");

	return TRUE; 
}




void LocationDialog::OnCloseupComboWhere() 
{

	UpdateData(true); 
	
	// Default settings
	northsouth=true;
	SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"N");
	eastwest=false;
	SetDlgItemText(IDC_BUTTON_EAST_WEST,L"W");
	
	m_LAT_SEC=0;
	m_LONG_SEC=0;

	switch (m_where) {
	case 1: // London
		{
			m_LAT_DEG=51;m_LAT_MIN=30;
			m_LONG_DEG=0;m_LONG_MIN=10;
			m_timezone=0;
			break;
		}
	case 2: // New York
		{
			m_LAT_DEG=40;m_LAT_MIN=43;
			m_LONG_DEG=74;m_LONG_MIN=1;
			m_timezone=5;
			break;
		}
	 case 3: // tokyo
		{
			m_LAT_DEG=35;m_LAT_MIN=40;
			m_LONG_DEG=-139;m_LONG_MIN=45;
			m_timezone=9;
			break;
		}
	case 4: // Bombay
		{
			m_LAT_DEG=18;m_LAT_MIN=56;
			m_LONG_DEG=-72;m_LONG_MIN=51;
			m_timezone=5;
			break;
		}
	case 5: // Sydney
		{
			m_LAT_DEG=-33;m_LAT_MIN=55;
			m_LONG_DEG=-151;m_LONG_MIN=10;
			m_timezone=10;
			break;
		}
	case 6: // Hong Kong
		{
			m_LAT_DEG=22;m_LAT_MIN=15;
			m_LONG_DEG=-114;m_LONG_MIN=11;
			m_timezone=8;
			break;
		}
	case 7: // Moscow
		{
			m_LAT_DEG=55;m_LAT_MIN=45;
			m_LONG_DEG=-37;m_LONG_MIN=42;
			m_timezone=3;
			break;
		}
	case 8: // los ang
		{
			m_LAT_DEG=34;m_LAT_MIN=0;
			m_LONG_DEG=118;m_LONG_MIN=15;
			m_timezone=8;
			break;
		}
	case 9: // quebec
		{
			m_LAT_DEG=46;m_LAT_MIN=50;
			m_LONG_DEG=71;m_LONG_MIN=15;
			m_timezone=5;
			break;
		}
	case 10: // rome
		{
			m_LAT_DEG=41;m_LAT_MIN=53;
			m_LONG_DEG=-12;m_LONG_MIN=30;
			m_timezone=1;
			break;
		}
	case 11: // mexico
		{
			m_LAT_DEG=19;m_LAT_MIN=25;
			m_LONG_DEG=99;m_LONG_MIN=10;
			m_timezone=6;
			break;
		}
	case 12: // cape town
		{
			m_LAT_DEG=-33;m_LAT_MIN=56;
			m_LONG_DEG=18;m_LONG_MIN=28;
			m_timezone=2;
			break;
		}

	case 13: // Dublin
		{
			m_LAT_DEG=53;m_LAT_MIN=20;
			m_LONG_DEG=6;m_LONG_MIN=15;
			m_timezone=0;
			break;
		}
	case 14: // Seoul
		{
			m_LAT_DEG=37;m_LAT_MIN=30;
			m_LONG_DEG=-127;m_LONG_MIN=0;
			m_timezone=9;
			break;
		}
	case 15: // Bangor
		{
			m_LAT_DEG=54;m_LAT_MIN=36;
			m_LONG_DEG=5;m_LONG_MIN=55;
			m_timezone=0;
			break;
		}
	case 16: // jerusalem
		{
			m_LAT_DEG=31;m_LAT_MIN=47;
			m_LONG_DEG=35;m_LONG_MIN=13;
			m_timezone=2;
			break;
		}


	}


	if (m_LAT_DEG<0)
	{
		m_LAT_DEG=-m_LAT_DEG;
		northsouth=false;
		SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"S");
	}

	if (m_LONG_DEG<0)
	{
		m_LONG_DEG=-m_LONG_DEG;
		eastwest=true;
		SetDlgItemText(IDC_BUTTON_EAST_WEST,L"E");
	}

	UpdateData(false); 	
}

void LocationDialog::OnButtonNorthSouth() 
{
	if (northsouth)
	{
		SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"S");
		northsouth=false;
	}
	else
	{
		SetDlgItemText(IDC_BUTTON_NORTH_SOUTH,L"N");
		northsouth=true;
	}
}

void LocationDialog::OnButtonEastWest() 
{

	if (eastwest)
	{
		SetDlgItemText(IDC_BUTTON_EAST_WEST,L"W");
		eastwest=false;
	}
	else
	{
		SetDlgItemText(IDC_BUTTON_EAST_WEST,L"E");
		eastwest=true;
	}

}


