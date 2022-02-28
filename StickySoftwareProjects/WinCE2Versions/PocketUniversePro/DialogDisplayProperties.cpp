// DialogDisplayProperties.cpp : implementation file
//

#include "stdafx.h"
#include "PocketUniversePro.h"
#include "DialogDisplayProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogDisplayProperties dialog


CDialogDisplayProperties::CDialogDisplayProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogDisplayProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogDisplayProperties)
	m_details = FALSE;
	m_ecliptic = FALSE;
	m_grid = FALSE;
	m_hide = FALSE;
	m_horizon = FALSE;
	m_hourglass = FALSE;
	m_invert = FALSE;
	m_labels = FALSE;
	m_markers = FALSE;
	m_mess = FALSE;
	m_moongfx = FALSE;
	m_outline = FALSE;
	m_parallax = FALSE;
	m_planets = FALSE;
	m_realsize = FALSE;
	m_sites = FALSE;
	m_sm = FALSE;
	m_stars = FALSE;
	m_mag = -1;
	//}}AFX_DATA_INIT
}


void CDialogDisplayProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogDisplayProperties)
	DDX_Check(pDX, IDC_CHECK_DETAILS, m_details);
	DDX_Check(pDX, IDC_CHECK_ECLIPTIC, m_ecliptic);
	DDX_Check(pDX, IDC_CHECK_GRID, m_grid);
	DDX_Check(pDX, IDC_CHECK_HIDE, m_hide);
	DDX_Check(pDX, IDC_CHECK_HORIZON, m_horizon);
	DDX_Check(pDX, IDC_CHECK_HOURGLASS, m_hourglass);
	DDX_Check(pDX, IDC_CHECK_INVERT, m_invert);
	DDX_Check(pDX, IDC_CHECK_LABELS, m_labels);
	DDX_Check(pDX, IDC_CHECK_MARKERS, m_markers);
	DDX_Check(pDX, IDC_CHECK_MESS, m_mess);
	DDX_Check(pDX, IDC_CHECK_MOONGFX, m_moongfx);
	DDX_Check(pDX, IDC_CHECK_OUTLINE, m_outline);
	DDX_Check(pDX, IDC_CHECK_PARALLAX, m_parallax);
	DDX_Check(pDX, IDC_CHECK_PLANETS, m_planets);
	DDX_Check(pDX, IDC_CHECK_REALSIZE, m_realsize);
	DDX_Check(pDX, IDC_CHECK_SITES, m_sites);
	DDX_Check(pDX, IDC_CHECK_SM, m_sm);
	DDX_Check(pDX, IDC_CHECK_STARS, m_stars);
	DDX_CBIndex(pDX, IDC_COMBO_MAGNITUDES, m_mag);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogDisplayProperties, CDialog)
	//{{AFX_MSG_MAP(CDialogDisplayProperties)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogDisplayProperties message handlers
