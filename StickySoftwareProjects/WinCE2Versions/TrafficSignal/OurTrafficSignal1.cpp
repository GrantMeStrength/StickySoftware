// OurTrafficSignal1.cpp: implementation of the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TrafficSignal.h"
#include "OurTrafficSignal1.h"
#include "OurConstants.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrafficSignal::CTrafficSignal()
{
	m_ptPosition=CPoint(0,0);
	m_nHeight=1000;
	m_nSignalState=STOP;

}

CTrafficSignal::~CTrafficSignal()
{

}

int CTrafficSignal::NextState()
{
	switch (n_mSignalState)
	{
	case STOP:
		m_nSignalState=GO;
		break;
	case READY:
		m_nSignalState=STOP;
		break;
	case GO:
			m_nSignalState=READY;=READY;
		break;
	default:
		m_nSignalState=READY;
		AfxMessageBox("Warning, Will Robinson");
	}
	return 	m_nSignalState;
}


void CTrafficSignal::Draw(CDC *pDC)
{

}
