// TrafficSignalCtl.cpp : Implementation of the CTrafficSignalCtrl ActiveX Control class.

#include "stdafx.h"
#include "TrafficSignal.h"
#include "TrafficSignalCtl.h"
#include "TrafficSignalPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTrafficSignalCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_MSG_MAP(CTrafficSignalCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTrafficSignalCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTrafficSignalCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTrafficSignalCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTrafficSignalCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTrafficSignalCtrl, 1)
	PROPPAGEID(CTrafficSignalPropPage::guid)
END_PROPPAGEIDS(CTrafficSignalCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTrafficSignalCtrl, "TRAFFICSIGNAL.TrafficSignalCtrl.1",
	0x385a1efc, 0xedb2, 0x11d2, 0xb7, 0x9, 0, 0xa0, 0xc9, 0xb5, 0xe5, 0x77)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTrafficSignalCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTrafficSignal =
		{ 0x385a1efa, 0xedb2, 0x11d2, { 0xb7, 0x9, 0, 0xa0, 0xc9, 0xb5, 0xe5, 0x77 } };
const IID BASED_CODE IID_DTrafficSignalEvents =
		{ 0x385a1efb, 0xedb2, 0x11d2, { 0xb7, 0x9, 0, 0xa0, 0xc9, 0xb5, 0xe5, 0x77 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTrafficSignalOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTrafficSignalCtrl, IDS_TRAFFICSIGNAL, _dwTrafficSignalOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::CTrafficSignalCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTrafficSignalCtrl

BOOL CTrafficSignalCtrl::CTrafficSignalCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TRAFFICSIGNAL,
			IDB_TRAFFICSIGNAL,
			afxRegApartmentThreading,
			_dwTrafficSignalOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::CTrafficSignalCtrl - Constructor

CTrafficSignalCtrl::CTrafficSignalCtrl()
{
	InitializeIIDs(&IID_DTrafficSignal, &IID_DTrafficSignalEvents);

	// TODO: Initialize your control's instance data here.

	m_pSignal = new CTrafficSignal;
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::~CTrafficSignalCtrl - Destructor

CTrafficSignalCtrl::~CTrafficSignalCtrl()
{
	// TODO: Cleanup your control's instance data here.

	delete m_pSignal;
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::OnDraw - Drawing function

void CTrafficSignalCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::DoPropExchange - Persistence support

void CTrafficSignalCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::OnResetState - Reset control to default state

void CTrafficSignalCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl::AboutBox - Display an "About" box to the user

void CTrafficSignalCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TRAFFICSIGNAL);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTrafficSignalCtrl message handlers
