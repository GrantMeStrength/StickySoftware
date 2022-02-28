// scoobyView.cpp : implementation of the CScoobyView class
//

#include "stdafx.h"
#include "scooby.h"
#include "scoobyDoc.h"
#include "scoobyView.h"


bool once=false;
CScooby *cDlg;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern bool settings[16];
extern CString userprogname[4];
extern int buttons[4];

extern CString appnames[100];
extern CString fullappnames[100];

extern void SaveBMP(CDC *dc, CString filename,int index);


#define GRAPHIC 0
#define TASKS 1
#define VOICE 2
#define CHANNELS 3
#define NOTES 4
#define INBOX 5
#define CALCULATOR 6
#define CONTACTS 7
#define CALENDAR 8
#define USER1 9
#define USER2 10
#define USER3 11
#define USER4 12
#define DATE 13
#define UTILITIES 14
#define PILOT 15

extern void PokeRegistry();
extern void MakeScript();
extern void SaveScript();
extern void LoadScript();
extern void Trigger();

/////////////////////////////////////////////////////////////////////////////
// CScoobyView

IMPLEMENT_DYNCREATE(CScoobyView, CView)

BEGIN_MESSAGE_MAP(CScoobyView, CView)
	//{{AFX_MSG_MAP(CScoobyView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoobyView construction/destruction

CScoobyView::CScoobyView()
{
	// TODO: add construction code here

}

CScoobyView::~CScoobyView()
{
}

BOOL CScoobyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CScoobyView drawing

void CScoobyView::OnDraw(CDC* pDC)
{
	CScoobyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (once==false)
	{
		once=true;
	//	MessageBox(L"Opening window!",L"Plop",MB_OK);
		CScooby cDlg;
		

		LoadScript();
		PokeRegistry();

		cDlg.m_calculator = settings[CALCULATOR];
		cDlg.m_calendar = settings[CALENDAR];
		cDlg.m_channels = settings[CHANNELS];
		cDlg.m_contacts = settings[CONTACTS];
		cDlg.m_inbox = settings[INBOX];
		cDlg.m_notes = settings[NOTES];
		cDlg.m_tasks = settings[TASKS];
		cDlg.m_voice = settings[VOICE];
		cDlg.m_graphic = settings[GRAPHIC];
	//	cDlg.m_user1 = settings[USER1];
	//	cDlg.m_user2 = settings[USER2];
	//	cDlg.m_user3 = settings[USER3];
	//	cDlg.m_user4 = settings[USER4];
		cDlg.m_utilities = settings[UTILITIES];
		cDlg.m_date = settings[DATE];
		cDlg.m_pilot = settings[PILOT];

		//WriteToDatabase();
		
		if (cDlg.DoModal()==IDOK)
		{

			settings[CALCULATOR]=cDlg.m_calculator;
			settings[CALENDAR]=cDlg.m_calendar;
			settings[CHANNELS]=cDlg.m_channels;
			settings[CONTACTS]=cDlg.m_contacts;
			settings[INBOX]=cDlg.m_inbox;
			settings[NOTES]=cDlg.m_notes;
			settings[TASKS]=cDlg.m_tasks;
			settings[VOICE]=cDlg.m_voice;
			settings[GRAPHIC]=cDlg.m_graphic;
			settings[UTILITIES]=cDlg.m_utilities;
			settings[DATE]=cDlg.m_date;
			settings[PILOT]=cDlg.m_pilot;
		//if (cDlg.m_dropuser1!=0) {userprogname[0]=fullappnames[cDlg.m_dropuser1-1];SaveBMP(pDC,userprogname[0],0);}
		//	if (cDlg.m_dropuser2!=0) {userprogname[1]=fullappnames[cDlg.m_dropuser2-1];SaveBMP(pDC,userprogname[1],1);}
		//	if (cDlg.m_dropuser3!=0) {userprogname[2]=fullappnames[cDlg.m_dropuser3-1];SaveBMP(pDC,userprogname[2],2);}
		//	if (cDlg.m_dropuser4!=0) {userprogname[3]=fullappnames[cDlg.m_dropuser4-1];SaveBMP(pDC,userprogname[3],3);}

			for (int p=0;p<4;p++)
			{
				if (buttons[p]==0) 
				{
					settings[USER1+p]=false;
					userprogname[p]=L"Barney";
				}
				if (buttons[p]==1)
				{
					settings[USER1+p]=true;
					//SaveBMP(pDC,userprogname[p],0);
					//userprogname[p] remains the same
				}
				if (buttons[p]>1)
				{
					settings[USER1+p]=true;
					userprogname[p]=fullappnames[buttons[p]-2];
					if (settings[PILOT]) SaveBMP(pDC,userprogname[p],p);
				}
			}

			
			MakeScript();
			SaveScript();	
			Trigger();
		}

  

	//MessageBox(L"Closing window!",L"Plop",MB_OK);
	PostQuitMessage(0);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CScoobyView diagnostics

#ifdef _DEBUG
void CScoobyView::AssertValid() const
{
	CView::AssertValid();
}

void CScoobyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CScoobyDoc* CScoobyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScoobyDoc)));
	return (CScoobyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScoobyView message handlers

