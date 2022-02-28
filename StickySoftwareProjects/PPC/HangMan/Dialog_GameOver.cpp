// Dialog_GameOver.cpp : implementation file
//

#include "stdafx.h"
#include "HangMan.h"
#include "Resource.h"
#include "Dialog_GameOver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_GameOver dialog


CDialog_GameOver::CDialog_GameOver(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_GameOver::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_GameOver)
	m_string2 = _T("");
	//}}AFX_DATA_INIT
}


void CDialog_GameOver::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_GameOver)
	DDX_Text(pDX, IDC_STRING_TWO, m_string2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_GameOver, CDialog)
	//{{AFX_MSG_MAP(CDialog_GameOver)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_GameOver message handlers
