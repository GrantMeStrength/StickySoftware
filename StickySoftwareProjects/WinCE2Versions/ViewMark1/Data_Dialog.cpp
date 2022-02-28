// Data_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Data_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CData_Dialog dialog


CData_Dialog::CData_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CData_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CData_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CData_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CData_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CData_Dialog, CDialog)
	//{{AFX_MSG_MAP(CData_Dialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CData_Dialog message handlers
