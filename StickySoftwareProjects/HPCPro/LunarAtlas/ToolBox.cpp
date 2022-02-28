// ToolBox.cpp : implementation file
//

#include "stdafx.h"
#include "LunarAtlas.h"
#include "ToolBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern void RefreshDisplay(CDC *pDC);
extern double walt,wazm;
extern bool toolopen;
extern double zoom;
extern bool redraw;

extern int SX,SY;

/////////////////////////////////////////////////////////////////////////////
// CToolBox dialog


CToolBox::CToolBox(CWnd* pParent /*=NULL*/)
	: CDialog(CToolBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToolBox)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CToolBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolBox)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolBox, CDialog)
	//{{AFX_MSG_MAP(CToolBox)
	ON_BN_CLICKED(IDC_BUTTONUP, OnButtonup)
	ON_BN_CLICKED(IDC_BUTTONDOWN, OnButtondown)
	ON_BN_CLICKED(IDC_BUTTONLEFT, OnButtonleft)
	ON_BN_CLICKED(IDC_BUTTONRIGHT, OnButtonright)
	ON_BN_CLICKED(IDC_BUTTONSPINCLOCK, OnButtonspinclock)
	ON_BN_CLICKED(IDC_BUTTONZOOMIN, OnButtonzoomin)
	ON_BN_CLICKED(IDC_BUTTONZOOMOUT, OnButtonzoomout)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTONSPINANTI, OnButtonspinanti)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolBox message handlers

void CToolBox::OnButtonup() 
{

	SY+=10;
	Redraw();
	
}

void CToolBox::OnButtondown() 
{
	SY-=10;
	Redraw();
}

void CToolBox::OnButtonleft() 
{
	SX-=10;
	Redraw();
}

void CToolBox::OnButtonright() 
{
	SX+=10;
	Redraw();
}

void CToolBox::OnButtonspinanti() 
{
	// TODO: Add your control notification handler code here

	wazm+=.01;
	Redraw();
}

void CToolBox::OnButtonspinclock() 
{
	// TODO: Add your control notification handler code here

	wazm-=.01;
	Redraw();
	
}

void CToolBox::OnButtonzoomin() 
{
	zoom*=1.1;
	Redraw();
	
}

void CToolBox::OnButtonzoomout() 
{
	zoom/=1.1;
	Redraw();
}

void CToolBox::PostNcDestroy() 
{
		delete this;
}

void CToolBox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{

	if (nSBCode==TB_ENDTRACK) 
	{
	pSlide=(CSliderCtrl*)pScrollBar;
	zoom=(double(pSlide->GetPos()))/100;
	Redraw();
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CToolBox::OnOK() 
{
	toolopen=false;
	DestroyWindow();
	
	//CDialog::OnOK();
}

BOOL CToolBox::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	pSlide=(CSliderCtrl *)GetDlgItem(IDC_ZOOM_SLIDER);
	pSlide->SetRange(1,400);
	pSlide->SetPageSize(20);
	pSlide->SetPos(int(zoom*100)); //1..12.5
	pSlide->SetTicFreq(20);
	
	buttonup.AutoLoad(IDC_BUTTONUP,this);
	buttondown.AutoLoad(IDC_BUTTONDOWN,this);
	buttonleft.AutoLoad(IDC_BUTTONLEFT,this);
	buttonright.AutoLoad(IDC_BUTTONRIGHT,this);

	buttonspinanti.AutoLoad(IDC_BUTTONSPINANTI,this);
	buttonspinclock.AutoLoad(IDC_BUTTONSPINCLOCK,this);

	buttonzoomin.AutoLoad(IDC_BUTTONZOOMIN,this);
	buttonzoomout.AutoLoad(IDC_BUTTONZOOMOUT,this);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CToolBox::KillDialog()
{
	toolopen=false;
	delete this;
}

void CToolBox::Redraw()
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	redraw=true;
	RefreshDisplay(&pdc);
	phwnd->SetFocus();
}
