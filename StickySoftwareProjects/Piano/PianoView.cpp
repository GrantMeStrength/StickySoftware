// PianoView.cpp : implementation of the CPianoView class
//

#include "stdafx.h"
#include "Piano.h"

#include "PianoDoc.h"
#include "PianoView.h"

#include "PianoKeys.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPianoKeys *Keyadlg;

bool once=false;		// Open the dialog

int current_time=0;
bool play=false;
bool record=false;
int speed=200;
extern short int song_count;
short int end_song;


/////////////////////////////////////////////////////////////////////////////
// CPianoView

IMPLEMENT_DYNCREATE(CPianoView, CView)

BEGIN_MESSAGE_MAP(CPianoView, CView)
	//{{AFX_MSG_MAP(CPianoView)
	ON_WM_TIMER()
	ON_COMMAND(IDM_PLAY, OnPlay)
	ON_COMMAND(IDM_RECORD, OnRecord)
	ON_UPDATE_COMMAND_UI(IDM_RECORD, OnUpdateRecord)
	ON_COMMAND(IDM_STOP, OnStop)
	ON_UPDATE_COMMAND_UI(IDM_STOP, OnUpdateStop)
	ON_UPDATE_COMMAND_UI(IDM_PLAY, OnUpdatePlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPianoView construction/destruction

CPianoView::CPianoView()
{
	// TODO: add construction code here

}

CPianoView::~CPianoView()
{
}

BOOL CPianoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPianoView drawing

void CPianoView::OnDraw(CDC* pDC)
{
	CPianoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (once==false)
	{
		once=true;
		Keyadlg =new CPianoKeys;
		Keyadlg->Create(IDD_KEYBOARD_DIALOG,this);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPianoView diagnostics

#ifdef _DEBUG
void CPianoView::AssertValid() const
{
	CView::AssertValid();
}

void CPianoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPianoDoc* CPianoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPianoDoc)));
	return (CPianoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPianoView message handlers


void CPianoView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default


		current_time++;
	
		Keyadlg->Playback();
	
		if (current_time>=end_song)
		{
			play=false;
			KillTimer(1);
		}
		
	CView::OnTimer(nIDEvent);
}

void CPianoView::OnPlay() 
{
	if (play) KillTimer(1);
	if (record) end_song=current_time;
	record=false;
	play=true;
	song_count=0;
	current_time=0;
	SetTimer(1, speed, NULL);
}


void CPianoView::OnRecord() 
{
	if (play) KillTimer(1);
	record=true;
	play=false;
	song_count=0;
	current_time=0;
	end_song=0;
}

void CPianoView::OnUpdateRecord(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(record);
}

void CPianoView::OnStop() 
{
	if (play) {
		KillTimer(1);
		play=false;
	}
	if (record) {
		end_song=current_time;
		record=false;
	}

	SendMessage(TB_SETSTATE,0);
}

void CPianoView::OnUpdateStop(CCmdUI* pCmdUI) 
{
	bool stop=true;
	if ((play)||(record)) stop=false;
	pCmdUI->SetCheck(stop);
}

void CPianoView::OnUpdatePlay(CCmdUI* pCmdUI) 
{
		pCmdUI->SetCheck(play);	
}
/*
TB_SETSTATE
toolbar
sendmessage
*/