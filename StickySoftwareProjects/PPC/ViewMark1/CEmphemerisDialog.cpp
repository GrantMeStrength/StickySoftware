// CEmphemerisDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "CEmphemerisDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCEmphemerisDialog dialog


CCEmphemerisDialog::CCEmphemerisDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCEmphemerisDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCEmphemerisDialog)
	m_date = _T("");
	m_mercury = _T("");
	m_jupiter = _T("");
	m_mars = _T("");
	m_neptune = _T("");
	m_pluto = _T("");
	m_saturn = _T("");
	m_uranus = _T("");
	m_venus = _T("");
	m_user = _T("");
	m_moon = _T("");
	m_sun = _T("");
	//}}AFX_DATA_INIT
}


void CCEmphemerisDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCEmphemerisDialog)
	DDX_Text(pDX, IDC_STRING_DATE, m_date);
	DDV_MaxChars(pDX, m_date, 32);
	DDX_Text(pDX, IDC_STRING_MERCURY, m_mercury);
	DDX_Text(pDX, IDC_STRING_JUPITER, m_jupiter);
	DDX_Text(pDX, IDC_STRING_MARS, m_mars);
	DDX_Text(pDX, IDC_STRING_NEPTUNE, m_neptune);
	DDX_Text(pDX, IDC_STRING_PLUTO, m_pluto);
	DDX_Text(pDX, IDC_STRING_SATURN, m_saturn);
	DDX_Text(pDX, IDC_STRING_URANUS, m_uranus);
	DDX_Text(pDX, IDC_STRING_VENUS, m_venus);
	DDX_Text(pDX, IDC_STRING_USER, m_user);
	DDX_Text(pDX, IDC_STRING_MOON, m_moon);
	DDX_Text(pDX, IDC_STRING_SUN, m_sun);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCEmphemerisDialog, CDialog)
	//{{AFX_MSG_MAP(CCEmphemerisDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCEmphemerisDialog message handlers
