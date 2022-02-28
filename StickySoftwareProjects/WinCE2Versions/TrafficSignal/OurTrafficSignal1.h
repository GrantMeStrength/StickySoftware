// OurTrafficSignal1.h: interface for the CTrafficSignal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OURTRAFFICSIGNAL1_H__385A1F0E_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_)
#define AFX_OURTRAFFICSIGNAL1_H__385A1F0E_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTrafficSignal;

class CTrafficSignal  
{
public:
	CTrafficSignal();
	virtual ~CTrafficSignal();
	void SetPosition(CPoint ptPosition) {m_ptPosition=ptPosition;}
	void SetHeight(CPoint nHeight) {m_nHeight=nHeight;}
	void SetSignalState(CPoint nSignalState) {m_nSignalState=nSignalState;}
	void Draw(CDC *pDC);
	int NextState();
private:
	CPoint m_ptPosition;
	int m_nHeight;
	int m_nSignalState;


};

#endif // !defined(AFX_OURTRAFFICSIGNAL1_H__385A1F0E_EDB2_11D2_B709_00A0C9B5E577__INCLUDED_)
