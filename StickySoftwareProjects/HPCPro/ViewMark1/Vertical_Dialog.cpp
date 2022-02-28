// Vertical_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViewMark1.h"
#include "Vertical_Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class triple {
	int deg;
	int min;
	int sec;
	double all;
	bool flag;
public:
	triple();
	int get_deg(void);
	int get_min(void);
	double get_sec(void);
	void set_deg(int);
	void set_min(int);
	void set_sec(double);
	double get_all(void);
	void set_all(double);
	void add_deg(int);
};


extern void DrawSky(CDC *pDC);
extern class triple win_alt,win_azm;

/////////////////////////////////////////////////////////////////////////////
// CVertical_Dialog dialog


CVertical_Dialog::CVertical_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(CVertical_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVertical_Dialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CVertical_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVertical_Dialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVertical_Dialog, CDialog)
	//{{AFX_MSG_MAP(CVertical_Dialog)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVertical_Dialog message handlers



void CVertical_Dialog::PostNcDestroy() 
{

	delete this;

	//CDialog::PostNcDestroy();
}

/*

  
	


SB_BOTTOM   Scroll to bottom.

SB_ENDSCROLL   End scroll.

SB_LINEDOWN   Scroll one line down.

SB_LINEUP   Scroll one line up.

SB_PAGEDOWN   Scroll one page down.

SB_PAGEUP   Scroll one page up.

SB_THUMBPOSITION   Scroll to the absolute position. The current position is provided in nPos.

SB_THUMBTRACK   Drag scroll box to specified position. The current position is provided in nPos.

SB_TOP   Scroll to top.
*/

void CVertical_Dialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	double alt=win_alt.get_all();
//	switch(nSBCode) {
//	case SB_LINEDOWN: alt--;break;
//	case SB_LINEUP: alt++;break;
//	};
	win_alt.set_all(alt);


	double azm;
	CSliderCtrl* pSlider;
	pSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER);
	azm=pSlider->GetPos();
	win_azm.set_all(azm);


	DrawSky(&pdc);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);

}



void CVertical_Dialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	double azm=win_azm.get_all();
	switch(nSBCode) {
	case SB_LINEDOWN: azm--;break;
	case SB_LINEUP: azm++;break;
	};
	win_azm.set_all(azm);
	DrawSky(&pdc);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

BOOL CVertical_Dialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CSliderCtrl* pSlider;
	pSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER);
	pSlider->SetRange(1,16);
	pSlider->SetPos(8);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CVertical_Dialog::OnLButtonDown(UINT nFlags, CPoint point) 
{

	// The dialog has been clicked, to try and get
	// magnification, in case it's changed.
	
	
	CWnd* phwnd=GetParent();
	CClientDC dc(this);
	CClientDC pdc(phwnd);
	double azm;
	CSliderCtrl* pSlider;
	pSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER);
	azm=12*pSlider->GetPos();
	win_azm.set_all(azm);
	DrawSky(&pdc);

	CDialog::OnLButtonDown(nFlags, point);
}
