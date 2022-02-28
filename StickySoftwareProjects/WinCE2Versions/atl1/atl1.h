/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Apr 08 14:27:58 1999
 */
/* Compiler settings for atl1.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __atl1_h__
#define __atl1_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPlop_FWD_DEFINED__
#define __IPlop_FWD_DEFINED__
typedef interface IPlop IPlop;
#endif 	/* __IPlop_FWD_DEFINED__ */


#ifndef __Plop_FWD_DEFINED__
#define __Plop_FWD_DEFINED__

#ifdef __cplusplus
typedef class Plop Plop;
#else
typedef struct Plop Plop;
#endif /* __cplusplus */

#endif 	/* __Plop_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IPlop_INTERFACE_DEFINED__
#define __IPlop_INTERFACE_DEFINED__

/* interface IPlop */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPlop;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("385A1EE0-EDB2-11D2-B709-00A0C9B5E577")
    IPlop : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RefreshRate( 
            /* [in] */ long HScan,
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVRes( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHRes( 
            /* [retval][out] */ long __RPC_FAR *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlopVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPlop __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPlop __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPlop __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPlop __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPlop __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPlop __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPlop __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RefreshRate )( 
            IPlop __RPC_FAR * This,
            /* [in] */ long HScan,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVRes )( 
            IPlop __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHRes )( 
            IPlop __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *retval);
        
        END_INTERFACE
    } IPlopVtbl;

    interface IPlop
    {
        CONST_VTBL struct IPlopVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlop_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlop_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlop_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlop_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPlop_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPlop_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPlop_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPlop_RefreshRate(This,HScan,retval)	\
    (This)->lpVtbl -> RefreshRate(This,HScan,retval)

#define IPlop_GetVRes(This,retval)	\
    (This)->lpVtbl -> GetVRes(This,retval)

#define IPlop_GetHRes(This,retval)	\
    (This)->lpVtbl -> GetHRes(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPlop_RefreshRate_Proxy( 
    IPlop __RPC_FAR * This,
    /* [in] */ long HScan,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IPlop_RefreshRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlop_GetVRes_Proxy( 
    IPlop __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IPlop_GetVRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPlop_GetHRes_Proxy( 
    IPlop __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *retval);


void __RPC_STUB IPlop_GetHRes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlop_INTERFACE_DEFINED__ */



#ifndef __ATL1Lib_LIBRARY_DEFINED__
#define __ATL1Lib_LIBRARY_DEFINED__

/* library ATL1Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ATL1Lib;

EXTERN_C const CLSID CLSID_Plop;

#ifdef __cplusplus

class DECLSPEC_UUID("385A1EE1-EDB2-11D2-B709-00A0C9B5E577")
Plop;
#endif
#endif /* __ATL1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
