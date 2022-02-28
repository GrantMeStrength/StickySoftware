// TrafficSignalPpg.cpp : Implementation of the CTrafficSignalPropPage property page class.

#include "stdafx.h"
#include "TrafficSignal.h"
#include "TrafficSignalPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTrafficSignalPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTrafficSignalPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTrafficSignalPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTrafficSignalPropPage, "TRAFFICSIGNAL.TrafficSignalPropPage.1",
	0x385a1efd, 0xedb2, 0x11d2, 0xb7, 0x9, 0, 0xa0, 0xc9, 0xb5, 0xe5, 0x77)


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::CTrafficSignalPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTrafficSignalPropPage

BOOL CTrafficSignalPropPage::CTrafficSignalPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TRAFFICSIGNAL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::CTrafficSignalPropPage - Constructor

CTrafficSignalPropPage::CTrafficSignalPropPage() :
	COlePropertyPage(IDD, IDS_TRAFFICSIGNAL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTrafficSignalPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage::DoDataExchange - Moves data between page and properties

void CTrafficSignalPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTrafficSignalPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalPropPage message handlers
