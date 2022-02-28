// Dialog_Buttons.cpp : implementation file
//

#include "stdafx.h"
#include "CamLink1.h"
#include "Dialog_Buttons.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int current_picture;	// Pic to be displayed, downloaded etc


/////////////////////////////////////////////////////////////////////////////
// CDialog_Buttons dialog


CDialog_Buttons::CDialog_Buttons(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Buttons::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Buttons)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Buttons::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Buttons)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Buttons, CDialog)
	//{{AFX_MSG_MAP(CDialog_Buttons)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Buttons message handlers

void CDialog_Buttons::PostNcDestroy() 
{
	delete this;
	//CDialog::PostNcDestroy();	
}

void CDialog_Buttons::OnButtonPrev() 
{
		// Move to previous button
		current_picture--;
	
}

void CDialog_Buttons::OnButtonNext() 
{
		// Move to next button..	
		current_picture++;
}

void CDialog_Buttons::OnButtonFetch() 
{
		// Download current picture
	
}
