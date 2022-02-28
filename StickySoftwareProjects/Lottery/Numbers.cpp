// Numbers.cpp : implementation file
//

#include "stdafx.h"
#include "Lottery.h"
#include "Numbers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int latest_count=0;
int latest[6];


/////////////////////////////////////////////////////////////////////////////
// CNumbers dialog


CNumbers::CNumbers(CWnd* pParent /*=NULL*/)
	: CDialog(CNumbers::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNumbers)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNumbers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNumbers)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNumbers, CDialog)
	//{{AFX_MSG_MAP(CNumbers)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON21, OnButton21)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON33, OnButton33)
	ON_BN_CLICKED(IDC_BUTTON34, OnButton34)
	ON_BN_CLICKED(IDC_BUTTON35, OnButton35)
	ON_BN_CLICKED(IDC_BUTTON36, OnButton36)
	ON_BN_CLICKED(IDC_BUTTON37, OnButton37)
	ON_BN_CLICKED(IDC_BUTTON38, OnButton38)
	ON_BN_CLICKED(IDC_BUTTON39, OnButton39)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON40, OnButton40)
	ON_BN_CLICKED(IDC_BUTTON41, OnButton41)
	ON_BN_CLICKED(IDC_BUTTON42, OnButton42)
	ON_BN_CLICKED(IDC_BUTTON43, OnButton43)
	ON_BN_CLICKED(IDC_BUTTON44, OnButton44)
	ON_BN_CLICKED(IDC_BUTTON45, OnButton45)
	ON_BN_CLICKED(IDC_BUTTON46, OnButton46)
	ON_BN_CLICKED(IDC_BUTTON47, OnButton47)
	ON_BN_CLICKED(IDC_BUTTON48, OnButton48)
	ON_BN_CLICKED(IDC_BUTTON49, OnButton49)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumbers message handlers

CString key;

void Enter(int n)
{
	latest[latest_count]=n;
	latest_count++;
}



void CNumbers::OnButton1() 
{
	if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON1,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON1,L"-");
	Enter(1);
}

void CNumbers::OnButton2() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON2,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON2,L"-");
	Enter(2);
}

void CNumbers::OnButton3() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON3,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON3,L"-");
	Enter(3);	
}

void CNumbers::OnButton4() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON4,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON4,L"-");
	Enter(4);	
}

void CNumbers::OnButton5() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON5,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON5,L"-");
	Enter(5);	
}

void CNumbers::OnButton6() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON6,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON6,L"-");
	Enter(6);	
}

void CNumbers::OnButton7() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON7,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON7,L"-");
	Enter(7);	
}

void CNumbers::OnButton8() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON8,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON8,L"-");
	Enter(8);	
}

void CNumbers::OnButton9() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON9,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON9,L"-");
	Enter(9);	
}


void CNumbers::OnButton10() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON10,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON10,L"-");
	Enter(10);	
}

void CNumbers::OnButton11() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON11,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON11,L"-");
	Enter(11);	
}

void CNumbers::OnButton12() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON12,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON12,L"-");
	Enter(12);	
}

void CNumbers::OnButton13() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON13,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON13,L"-");
	Enter(13);	
}

void CNumbers::OnButton14() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON14,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON14,L"-");
	Enter(14);
}

void CNumbers::OnButton15() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON15,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON15,L"-");
	Enter(15);	
}

void CNumbers::OnButton16() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON16,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON16,L"-");
	Enter(16);	
}

void CNumbers::OnButton17() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON17,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON17,L"-");
	Enter(17);
}

void CNumbers::OnButton18() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON18,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON18,L"-");
	Enter(18);
}

void CNumbers::OnButton19() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON19,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON19,L"-");
	Enter(19);	
}


void CNumbers::OnButton20() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON20,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON20,L"-");
	Enter(20);	
}

void CNumbers::OnButton21() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON21,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON21,L"-");
	Enter(21);	
}

void CNumbers::OnButton22() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON22,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON22,L"-");
	Enter(22);	
}

void CNumbers::OnButton23() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON23,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON23,L"-");
	Enter(23);	
}

void CNumbers::OnButton24() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON24,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON24,L"-");
	Enter(24);	
}

void CNumbers::OnButton25() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON25,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON25,L"-");
	Enter(25);	
}

void CNumbers::OnButton26() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON26,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON26,L"-");
	Enter(26);	
}

void CNumbers::OnButton27() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON27,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON27,L"-");
	Enter(27);	
}

void CNumbers::OnButton28() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON28,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON28,L"-");
	Enter(28);	
}

void CNumbers::OnButton29() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON29,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON29,L"-");
	Enter(29);
}



void CNumbers::OnButton30() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON30,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON30,L"-");
	Enter(30);	
}

void CNumbers::OnButton31() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON31,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON31,L"-");
	Enter(31);	
}

void CNumbers::OnButton32() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON32,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON32,L"-");
	Enter(32);	
}

void CNumbers::OnButton33() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON33,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON33,L"-");
	Enter(33);	
}

void CNumbers::OnButton34() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON34,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON34,L"-");
	Enter(34);	
}

void CNumbers::OnButton35() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON35,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON35,L"-");
	Enter(35);	
}

void CNumbers::OnButton36() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON36,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON36,L"-");
	Enter(36);	
}

void CNumbers::OnButton37() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON37,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON37,L"-");
	Enter(37);	
}

void CNumbers::OnButton38() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON38,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON38,L"-");
	Enter(38);	
}

void CNumbers::OnButton39() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON39,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON39,L"-");
	Enter(39);	
}



void CNumbers::OnButton40() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON40,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON40,L"-");
	Enter(40);	
}

void CNumbers::OnButton41() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON41,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON41,L"-");
	Enter(41);	
}

void CNumbers::OnButton42() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON42,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON42,L"-");
	Enter(42);	
}

void CNumbers::OnButton43() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON43,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON43,L"-");
	Enter(43);	
}

void CNumbers::OnButton44() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON44,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON44,L"-");
	Enter(44);	
}

void CNumbers::OnButton45() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON45,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON45,L"-");
	Enter(45);	
}

void CNumbers::OnButton46() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON46,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON46,L"-");
	Enter(46);	
}

void CNumbers::OnButton47() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON47,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON47,L"-");
	Enter(47);	
}

void CNumbers::OnButton48() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON48,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON48,L"-");
	Enter(48);	
}

void CNumbers::OnButton49() 
{
if (latest_count==6) return; CWnd* phwnd=GetParent();CClientDC dc(this);CClientDC pdc(phwnd);GetDlgItemText(IDC_BUTTON49,key);
	if (key=="-") return;
	SetDlgItemText(IDC_BUTTON49,L"-");
	Enter(49);	
}


BOOL CNumbers::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	latest_count=0;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNumbers::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
