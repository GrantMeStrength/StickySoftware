// Dialog_Game_Lost.cpp : implementation file
//

#include "stdafx.h"
#include "HangMan.h"
#include "Dialog_Game_Lost.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Game_Lost dialog


CDialog_Game_Lost::CDialog_Game_Lost(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Game_Lost::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Game_Lost)
	m_string2 = _T("");
	//}}AFX_DATA_INIT
}


void CDialog_Game_Lost::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Game_Lost)
	DDX_Text(pDX, IDC_STRING_TWO, m_string2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Game_Lost, CDialog)
	//{{AFX_MSG_MAP(CDialog_Game_Lost)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Game_Lost message handlers
