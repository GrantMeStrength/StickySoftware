// Dialog_Key.cpp : implementation file
//

#include "stdafx.h"
#include "HangMan.h"
#include "Dialog_Key.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CString key;

extern void Test(char key, CDC *pdc);



/////////////////////////////////////////////////////////////////////////////
// CDialog_Key dialog


CDialog_Key::CDialog_Key(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Key::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Key)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialog_Key::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Key)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Key, CDialog)
	//{{AFX_MSG_MAP(CDialog_Key)
	ON_BN_CLICKED(IDC_BUTTON_A, OnButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, OnButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, OnButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, OnButtonD)
	ON_BN_CLICKED(IDC_BUTTON_Q, OnButtonQ)
	ON_BN_CLICKED(IDC_BUTTON_P, OnButtonP)
	ON_BN_CLICKED(IDC_BUTTON_O, OnButtonO)
	ON_BN_CLICKED(IDC_BUTTON_N, OnButtonN)
	ON_BN_CLICKED(IDC_BUTTON_M, OnButtonM)
	ON_BN_CLICKED(IDC_BUTTON_L, OnButtonL)
	ON_BN_CLICKED(IDC_BUTTON_K, OnButtonK)
	ON_BN_CLICKED(IDC_BUTTON_J, OnButtonJ)
	ON_BN_CLICKED(IDC_BUTTON_I, OnButtonI)
	ON_BN_CLICKED(IDC_BUTTON_H, OnButtonH)
	ON_BN_CLICKED(IDC_BUTTON_G, OnButtonG)
	ON_BN_CLICKED(IDC_BUTTON_F, OnButtonF)
	ON_BN_CLICKED(IDC_BUTTON_E, OnButtonE)
	ON_BN_CLICKED(IDC_BUTTON_R, OnButtonR)
	ON_BN_CLICKED(IDC_BUTTON_S, OnButtonS)
	ON_BN_CLICKED(IDC_BUTTON_T, OnButtonT)
	ON_BN_CLICKED(IDC_BUTTON_U, OnButtonU)
	ON_BN_CLICKED(IDC_BUTTON_V, OnButtonV)
	ON_BN_CLICKED(IDC_BUTTON_W, OnButtonW)
	ON_BN_CLICKED(IDC_BUTTON_X, OnButtonX)
	ON_BN_CLICKED(IDC_BUTTON_Y, OnButtonY)
	ON_BN_CLICKED(IDC_BUTTON_Z, OnButtonZ)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Key message handlers


void CDialog_Key::ResetKeys()
{
	SetDlgItemText(IDC_BUTTON_A,L"A");
	SetDlgItemText(IDC_BUTTON_B,L"B");
	SetDlgItemText(IDC_BUTTON_C,L"C");
	SetDlgItemText(IDC_BUTTON_D,L"D");
	SetDlgItemText(IDC_BUTTON_E,L"E");
	SetDlgItemText(IDC_BUTTON_F,L"F");
	SetDlgItemText(IDC_BUTTON_G,L"G");
	SetDlgItemText(IDC_BUTTON_H,L"H");
	SetDlgItemText(IDC_BUTTON_I,L"I");
	SetDlgItemText(IDC_BUTTON_J,L"J");
	SetDlgItemText(IDC_BUTTON_K,L"K");
	SetDlgItemText(IDC_BUTTON_L,L"L");
	SetDlgItemText(IDC_BUTTON_M,L"M");
	SetDlgItemText(IDC_BUTTON_N,L"N");
	SetDlgItemText(IDC_BUTTON_O,L"O");
	SetDlgItemText(IDC_BUTTON_P,L"P");
	SetDlgItemText(IDC_BUTTON_Q,L"Q");
	SetDlgItemText(IDC_BUTTON_R,L"R");
	SetDlgItemText(IDC_BUTTON_S,L"S");
	SetDlgItemText(IDC_BUTTON_T,L"T");
	SetDlgItemText(IDC_BUTTON_U,L"U");
	SetDlgItemText(IDC_BUTTON_V,L"V");
	SetDlgItemText(IDC_BUTTON_W,L"W");
	SetDlgItemText(IDC_BUTTON_X,L"X");
	SetDlgItemText(IDC_BUTTON_Y,L"Y");
	SetDlgItemText(IDC_BUTTON_Z,L"Z");
}

void CDialog_Key::PostNcDestroy() 
{
	delete this;	
	//CDialog::PostNcDestroy();
}

void CDialog_Key::KillDialog()
{
	delete this;
}

void CDialog_Key::OnButtonA() 
{

	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_A,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_A,L"-");
	Test('A',&pdc);
}

void CDialog_Key::OnButtonB() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_B,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_B,L"-");
	Test('B',&pdc);
	
}

void CDialog_Key::OnButtonC() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_C,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_C,L"-");
	Test('C',&pdc);
}

void CDialog_Key::OnButtonD() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_D,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_D,L"-");
	Test('D',&pdc);
}

void CDialog_Key::OnButtonQ() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_Q,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_Q,L"-");
	Test('Q',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonP() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_P,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_P,L"-");
	Test('P',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonO() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_O,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_O,L"-");
	Test('O',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonN() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_N,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_N,L"-");
	Test('N',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonM() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_M,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_M,L"-");
	Test('M',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonL() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_L,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_L,L"-");
	Test('L',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonK() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_K,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_K,L"-");
	Test('K',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonJ() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_J,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_J,L"-");
	Test('J',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonI() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_I,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_I,L"-");
	Test('I',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonH() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_H,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_H,L"-");
	Test('H',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonG() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_G,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_G,L"-");
	Test('G',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonF() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_F,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_F,L"-");
	Test('F',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonE() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_E,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_E,L"-");
	Test('E',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonR() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_R,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_R,L"-");
	Test('R',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonS() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_S,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_S,L"-");
	Test('S',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonT() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_T,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_T,L"-");
	Test('T',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonU() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_U,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_U,L"-");
	Test('U',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonV() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_V,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_V,L"-");
	Test('V',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonW() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_W,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_W,L"-");
	Test('W',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonX() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_X,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_X,L"-");
	Test('X',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonY() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_Y,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_Y,L"-");
	Test('Y',&pdc);
	// TODO: Add your control notification handler code here
	
}

void CDialog_Key::OnButtonZ() 
{
	CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON_Z,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON_Z,L"-");
	Test('Z',&pdc);
	// TODO: Add your control notification handler code here
}
