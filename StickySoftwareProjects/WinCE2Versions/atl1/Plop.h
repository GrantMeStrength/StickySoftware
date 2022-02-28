// Plop.h : Declaration of the CPlop

#ifndef __PLOP_H_
#define __PLOP_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlop
class ATL_NO_VTABLE CPlop : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPlop, &CLSID_Plop>,
	public IDispatchImpl<IPlop, &IID_IPlop, &LIBID_ATL1Lib>
{
public:
	CPlop()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PLOP)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPlop)
	COM_INTERFACE_ENTRY(IPlop)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPlop
public:

	HRESULT __stdcall RefreshRate(long HScan,long *retval);
	HRESULT __stdcall GetVRes(long *retval);
	HRESULT __stdcall GetHRes(long *retval);


};

#endif //__PLOP_H_
