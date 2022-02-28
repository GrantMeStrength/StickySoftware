// Dialog_Ephemeris.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Dialog_Ephemeris.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Ephemeris dialog


CDialog_Ephemeris::CDialog_Ephemeris(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Ephemeris::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Ephemeris)
	m_date = _T("");
	m_jupiter = _T("");
	m_mars = _T("");
	m_mercury = _T("");
	m_moon = _T("");
	m_neptune = _T("");
	m_pluto = _T("");
	m_saturn = _T("");
	m_sun = _T("");
	m_uranus = _T("");
	m_user = _T("");
	m_venus = _T("");
	//}}AFX_DATA_INIT
}


void CDialog_Ephemeris::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Ephemeris)
	DDX_Text(pDX, IDC_STRING_DATE, m_date);
	DDX_Text(pDX, IDC_STRING_JUPITER, m_jupiter);
	DDX_Text(pDX, IDC_STRING_MARS, m_mars);
	DDX_Text(pDX, IDC_STRING_MERCURY, m_mercury);
	DDX_Text(pDX, IDC_STRING_MOON, m_moon);
	DDX_Text(pDX, IDC_STRING_NEPTUNE, m_neptune);
	DDX_Text(pDX, IDC_STRING_PLUTO, m_pluto);
	DDX_Text(pDX, IDC_STRING_SATURN, m_saturn);
	DDX_Text(pDX, IDC_STRING_SUN, m_sun);
	DDX_Text(pDX, IDC_STRING_URANUS, m_uranus);
	DDX_Text(pDX, IDC_STRING_USER, m_user);
	DDX_Text(pDX, IDC_STRING_VENUS, m_venus);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Ephemeris, CDialog)
	//{{AFX_MSG_MAP(CDialog_Ephemeris)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Ephemeris message handlers
