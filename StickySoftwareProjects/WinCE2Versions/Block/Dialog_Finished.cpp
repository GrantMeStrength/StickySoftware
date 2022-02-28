// Dialog_Finished.cpp : implementation file
//

#include "stdafx.h"
#include "Block.h"
#include "Dialog_Finished.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Finished dialog


CDialog_Finished::CDialog_Finished(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Finished::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Finished)
	m_string = _T("");
	//}}AFX_DATA_INIT
}


void CDialog_Finished::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Finished)
	DDX_Text(pDX, IDC_STRING_ONE, m_string);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Finished, CDialog)
	//{{AFX_MSG_MAP(CDialog_Finished)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Finished message handlers
