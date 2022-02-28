// LotteryView.cpp : implementation of the CLotteryView class
//

#include "stdafx.h"
#include "Lottery.h"

#include "LotteryDoc.h"
#include "LotteryView.h"

#include "Numbers.h"

bool once=false;
extern int latest[6];
extern int latest_count;



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLotteryView

IMPLEMENT_DYNCREATE(CLotteryView, CView)

BEGIN_MESSAGE_MAP(CLotteryView, CView)
	//{{AFX_MSG_MAP(CLotteryView)
	ON_COMMAND(IDM_CHECK, OnCheck)
	ON_COMMAND(IDM_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLotteryView construction/destruction

CLotteryView::CLotteryView()
{
	// TODO: add construction code here

}

CLotteryView::~CLotteryView()
{
}

BOOL CLotteryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLotteryView drawing

int ypos;

void PrintText(CDC *pdc,CString text)
{
	CRect brect(10,ypos,240,ypos+16);
	pdc->SetTextColor(RGB(0,0,0));
	pdc->SetBkMode(TRANSPARENT);
	pdc->DrawText(text, brect, DT_LEFT | DT_SINGLELINE);
	ypos+=12;
}

CString line,num;
int l,n,i,j;
int lines[20][6];
int match;

void CLotteryView::OnDraw(CDC* pDC)
{
	CLotteryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	ypos=32;

	PrintText(pDC,L"Your Numbers Are:");

	ypos+=32;

	for (l=0;l<20;l++)
	{
		line="";
		match=0;

		for (i=0;i<6;i++)
			for (j=0;j<6;j++)
				if (latest[i]==lines[l][j]) match++;

		for (n=0;n<6;n++)
		{
			num.Format(L"%02d ",lines[l][n]);
			line+=num;
		}

		if (lines[l][0]!=0)
		{
			if (match>1) {num.Format(L" with %d matches.",match);line+=num;}
			if (match==1) {num.Format(L" with %d match.",match);line+=num;}
			if (match==0) {line+=" with no matches.";}
			PrintText(pDC,line);
		}
	}

/*


	if (once==false)
	{
		once=true;
		CNumbers cDlg;
		if (cDlg.DoModal()==IDOK)
		{
		}
	}
*/
  
}

/////////////////////////////////////////////////////////////////////////////
// CLotteryView diagnostics

#ifdef _DEBUG
void CLotteryView::AssertValid() const
{
	CView::AssertValid();
}

void CLotteryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLotteryDoc* CLotteryView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLotteryDoc)));
	return (CLotteryDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLotteryView message handlers

void CLotteryView::OnCheck() 
{
	// Check new numbers with current ones
	// in memory

	// Get the six new numbers
	
	CNumbers cDlg;
	if (cDlg.DoModal()==IDOK)
	{
		//Redraw()
	
	}
	
}

void CLotteryView::OnChange() 
{
	CNumbers cDlg;

	int l,m;

	for (l=0;l<20;l++)
		for (m=0;m<6;m++)
			lines[l][m]=0;

	for (l=0;l<20;l++)
	{
		if (cDlg.DoModal()==IDOK)
		{
			if (latest_count!=6) break;
			for (m=0;m<6;m++)
				lines[l][m]=latest[m];
		}
	}

	for (m=0;m<6;m++)
		latest[m]=0;

}
