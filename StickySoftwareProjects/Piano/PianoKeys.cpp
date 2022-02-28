// PianoKeys.cpp : implementation file
//

#include "stdafx.h"
#include "Piano.h"
#include "PianoKeys.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int current_time;
extern bool play;
extern bool record;

short int song[258];
short int song_count=0;


/////////////////////////////////////////////////////////////////////////////
// CPianoKeys dialog


CPianoKeys::CPianoKeys(CWnd* pParent /*=NULL*/)
	: CDialog(CPianoKeys::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPianoKeys)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPianoKeys::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPianoKeys)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPianoKeys, CDialog)
	//{{AFX_MSG_MAP(CPianoKeys)
	ON_BN_CLICKED(IDC_A1, OnA1)
	ON_BN_CLICKED(IDC_A1S, OnA1s)
	ON_BN_CLICKED(IDC_B1, OnB1)
	ON_BN_CLICKED(IDC_C1S, OnC1s)
	ON_BN_CLICKED(IDC_C2, OnC2)
	ON_BN_CLICKED(IDC_D1, OnD1)
	ON_BN_CLICKED(IDC_D1S, OnD1s)
	ON_BN_CLICKED(IDC_E1, OnE1)
	ON_BN_CLICKED(IDC_F1, OnF1)
	ON_BN_CLICKED(IDC_F1S, OnF1s)
	ON_BN_CLICKED(IDC_G1, OnG1)
	ON_BN_CLICKED(IDC_G1S, OnG1s)
	ON_BN_CLICKED(IDC_MC, OnMc)
	ON_BN_CLICKED(IDC_SPACE, OnSpace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPianoKeys message handlers


void Play(int note)
{
	switch (note)
	{
	case 0:	sndPlaySound(L"\\Piano\\C1", SND_FILENAME|SND_ASYNC);break;
	case 1:	sndPlaySound(L"\\Piano\\C1s", SND_FILENAME|SND_ASYNC);break;
	case 2:	sndPlaySound(L"\\Piano\\D1", SND_FILENAME|SND_ASYNC);break;
	case 3:	sndPlaySound(L"\\Piano\\D1s", SND_FILENAME|SND_ASYNC);break;
	case 4:	sndPlaySound(L"\\Piano\\E1", SND_FILENAME|SND_ASYNC);break;
	case 5:	sndPlaySound(L"\\Piano\\F1", SND_FILENAME|SND_ASYNC);break;
	case 6:	sndPlaySound(L"\\Piano\\F1s", SND_FILENAME|SND_ASYNC);break;
	case 7:	sndPlaySound(L"\\Piano\\G1", SND_FILENAME|SND_ASYNC);break;
	case 8:	sndPlaySound(L"\\Piano\\G1s", SND_FILENAME|SND_ASYNC);break;
	case 9:	sndPlaySound(L"\\Piano\\A1", SND_FILENAME|SND_ASYNC);break;
	case 10:sndPlaySound(L"\\Piano\\A1s", SND_FILENAME|SND_ASYNC);break;
	case 11:sndPlaySound(L"\\Piano\\B1", SND_FILENAME|SND_ASYNC);break;
	case 12:sndPlaySound(L"\\Piano\\C2", SND_FILENAME|SND_ASYNC);break;
	default:break;
	}
}

void Record(int note)
{
	if (!record) return;
	song[song_count++]=note;
	if (song_count>255) song_count=255;
	current_time++;
}

void CPianoKeys::OnA1() 
{
	Play(9);
	Record(9);	
}

void CPianoKeys::OnA1s() 
{
	Play(10);
	Record(10);
}

void CPianoKeys::OnB1() 
{
	Play(11);
	Record(11);	
}

void CPianoKeys::OnC1s() 
{
	Play(1);
	Record(1);	
}

void CPianoKeys::OnC2() 
{
	Play(12);
	Record(12);	
}

void CPianoKeys::OnD1() 
{
	Play(2);
	Record(2);	
}

void CPianoKeys::OnD1s() 
{
	Play(3);
	Record(3);	
}

void CPianoKeys::OnE1() 
{
	Play(4);
	Record(4);	
}

void CPianoKeys::OnF1() 
{
	Play(5);
	Record(5);	
}

void CPianoKeys::OnF1s() 
{
	Play(6);
	Record(6);	
}

void CPianoKeys::OnG1() 
{
	Play(7);
	Record(7);	
}

void CPianoKeys::OnG1s() 
{
	Play(8);
	Record(8);	
}

void CPianoKeys::OnMc() 
{
	Play(0);
	Record(0);	
}

void CPianoKeys::Playback()
{
	Play(song[song_count]);
	song_count++;
	if (song_count>256) song_count=0;
}

void CPianoKeys::OnSpace() 
{
	Record(44);	
}
	

