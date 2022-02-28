# Microsoft Developer Studio Project File - Name="TZ2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE ARM) Application" 0x8501
# TARGTYPE "Win32 (WCE x86em) Application" 0x7f01
# TARGTYPE "Win32 (WCE SH3) Application" 0x8101
# TARGTYPE "Win32 (WCE MIPS) Application" 0x8201

CFG=TZ2 - Win32 (WCE MIPS) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TZ2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TZ2.mak" CFG="TZ2 - Win32 (WCE MIPS) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TZ2 - Win32 (WCE MIPS) Release" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "TZ2 - Win32 (WCE MIPS) Debug" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "TZ2 - Win32 (WCE SH3) Release" (based on "Win32 (WCE SH3) Application")
!MESSAGE "TZ2 - Win32 (WCE SH3) Debug" (based on "Win32 (WCE SH3) Application")
!MESSAGE "TZ2 - Win32 (WCE ARM) Release" (based on "Win32 (WCE ARM) Application")
!MESSAGE "TZ2 - Win32 (WCE ARM) Debug" (based on "Win32 (WCE ARM) Application")
!MESSAGE "TZ2 - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Application")
!MESSAGE "TZ2 - Win32 (WCE x86em) Debug" (based on "Win32 (WCE x86em) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Pro 2.11"
# PROP WCE_FormatVersion "6.0"

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRel"
# PROP Intermediate_Dir "WMIPSRel"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE  /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /QMRWCE   /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WMIPSDbg"
# PROP BASE Intermediate_Dir "WMIPSDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WMIPSDbg"
# PROP Intermediate_Dir "WMIPSDbg"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrtMTDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE  /c
# ADD CPP /nologo /M$(CECrtMTDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /QMRWCE   /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH3Rel"
# PROP BASE Intermediate_Dir "WCESH3Rel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESH3Rel"
# PROP Intermediate_Dir "WCESH3Rel"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtMT) /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCESH3Dbg"
# PROP BASE Intermediate_Dir "WCESH3Dbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCESH3Dbg"
# PROP Intermediate_Dir "WCESH3Dbg"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtMTDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMTDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEARMRel"
# PROP BASE Intermediate_Dir "WCEARMRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEARMRel"
# PROP Intermediate_Dir "WCEARMRel"
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /GX- /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCEARMDbg"
# PROP BASE Intermediate_Dir "WCEARMDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCEARMDbg"
# PROP Intermediate_Dir "WCEARMDbg"
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "x86emRel"
# PROP BASE Intermediate_Dir "x86emRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "x86emRel"
# PROP Intermediate_Dir "x86emRel"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /windowsce:emulation

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "x86emDbg"
# PROP BASE Intermediate_Dir "x86emDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "x86emDbg"
# PROP Intermediate_Dir "x86emDbg"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX- /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX- /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_" /d "_AFXDLL"
# ADD RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_" /d "_AFXDLL"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation

!ENDIF 

# Begin Target

# Name "TZ2 - Win32 (WCE MIPS) Release"
# Name "TZ2 - Win32 (WCE MIPS) Debug"
# Name "TZ2 - Win32 (WCE SH3) Release"
# Name "TZ2 - Win32 (WCE SH3) Debug"
# Name "TZ2 - Win32 (WCE ARM) Release"
# Name "TZ2 - Win32 (WCE ARM) Debug"
# Name "TZ2 - Win32 (WCE x86em) Release"
# Name "TZ2 - Win32 (WCE x86em) Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RegStuff.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ThreeD.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_THREE=\
	".\StdAfx.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	".\RegStuff.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_THREE=\
	".\data.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
NODEP_CPP_THREE=\
	".\letterdata.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TZ2.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_TZ2_C=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TZ2.rc

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TZ2Doc.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_TZ2DO=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TZ2View.cpp

!IF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Release"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE MIPS) Debug"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Release"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE SH3) Debug"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Release"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE ARM) Debug"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Release"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ELSEIF  "$(CFG)" == "TZ2 - Win32 (WCE x86em) Debug"

DEP_CPP_TZ2VI=\
	".\StdAfx.h"\
	".\TZ2.h"\
	".\TZ2Doc.h"\
	".\TZ2View.h"\
	

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\data.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\RegStuff.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SaucerClass.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TankClass.h
# End Source File
# Begin Source File

SOURCE=.\TZ2.h
# End Source File
# Begin Source File

SOURCE=.\TZ2Doc.h
# End Source File
# Begin Source File

SOURCE=.\TZ2View.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\tankzone4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TZ2.ico
# End Source File
# Begin Source File

SOURCE=.\res\TZ2.rc2
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Target
# End Project
