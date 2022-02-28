// Plop.cpp : Implementation of CPlop
#include "stdafx.h"
#include "Atl1.h"
#include "Plop.h"

/////////////////////////////////////////////////////////////////////////////
// CPlop

HRESULT __stdcall CPlop::RefreshRate(long HScan, long*retval)
{
	*retval=42;
	return S_OK;
}

HRESULT __stdcall CPlop::GetVRes(long*retval)
{
	*retval=42;
	return S_OK;
}

HRESULT __stdcall CPlop::GetHRes(long*retval)
{
	*retval=42;
	return S_OK;
}
