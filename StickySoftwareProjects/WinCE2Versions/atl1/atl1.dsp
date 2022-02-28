# Microsoft Developer Studio Project File - Name="atl1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Dynamic-Link Library" 0x7f02
# TARGTYPE "Win32 (WCE SH3) Dynamic-Link Library" 0x8102
# TARGTYPE "Win32 (WCE ARM) Dynamic-Link Library" 0x8502
# TARGTYPE "Win32 (WCE MIPS) Dynamic-Link Library" 0x8202

CFG=atl1 - Win32 (WCE x86em) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "atl1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atl1.mak" CFG="atl1 - Win32 (WCE x86em) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "atl1 - Win32 (WCE MIPS) Debug" (based on "Win32 (WCE MIPS) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE SH3) Debug" (based on "Win32 (WCE SH3) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE ARM) Debug" (based on "Win32 (WCE ARM) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE x86em) Debug" (based on "Win32 (WCE x86em) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE ARM) Release MinSize" (based on "Win32 (WCE ARM) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE ARM) Release MinDependency" (based on "Win32 (WCE ARM) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE MIPS) Release MinSize" (based on "Win32 (WCE MIPS) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE MIPS) Release MinDependency" (based on "Win32 (WCE MIPS) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE SH3) Release MinSize" (based on "Win32 (WCE SH3) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE SH3) Release MinDependency" (based on "Win32 (WCE SH3) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE x86em) Release MinSize" (based on "Win32 (WCE x86em) Dynamic-Link Library")
!MESSAGE "atl1 - Win32 (WCE x86em) Release MinDependency" (based on "Win32 (WCE x86em) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Ver. 2.00"
# PROP WCE_FormatVersion "6.0"

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WMIPSDbg"
# PROP BASE Intermediate_Dir "WMIPSDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WMIPSDbg"
# PROP Intermediate_Dir "WMIPSDbg"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrtDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /QMRWCE     /c
# ADD CPP /nologo /M$(CECrtDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /QMRWCE     /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /debug /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCESH3Dbg"
# PROP BASE Intermediate_Dir "WCESH3Dbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCESH3Dbg"
# PROP Intermediate_Dir "WCESH3Dbg"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrtDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtDebug) /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
# ADD RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /debug /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /debug /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCEARMDbg"
# PROP BASE Intermediate_Dir "WCEARMDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCEARMDbg"
# PROP Intermediate_Dir "WCEARMDbg"
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /GX- /Zi /Od /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "DEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
# ADD RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "DEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 coredll.lib commctrl.lib /nologo /dll /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 coredll.lib commctrl.lib /nologo /dll /debug /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "x86emDbg"
# PROP BASE Intermediate_Dir "x86emDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "x86emDbg"
# PROP Intermediate_Dir "x86emDbg"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MLd /W3 /Gm /GX- /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /Gm /GX- /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_"
# ADD RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_"
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /debug /machine:I386 /windowsce:emulation
# ADD LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /debug /machine:I386 /windowsce:emulation

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEARMRelMinSize"
# PROP BASE Intermediate_Dir "WCEARMRelMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEARMRelMinSize"
# PROP Intermediate_Dir "WCEARMRelMinSize"
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 coredll.lib commctrl.lib /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 coredll.lib commctrl.lib /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCEARMRelMinDependency"
# PROP BASE Intermediate_Dir "WCEARMRelMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCEARMRelMinDependency"
# PROP Intermediate_Dir "WCEARMRelMinDependency"
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /MC /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 coredll.lib commctrl.lib /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 coredll.lib commctrl.lib /nologo /dll /machine:ARM /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRelMinSize"
# PROP BASE Intermediate_Dir "WMIPSRelMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRelMinSize"
# PROP Intermediate_Dir "WMIPSRelMinSize"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /QMRWCE       /c
# ADD CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /QMRWCE       /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRelMinDependency"
# PROP BASE Intermediate_Dir "WMIPSRelMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRelMinDependency"
# PROP Intermediate_Dir "WMIPSRelMinDependency"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /QMRWCE       /c
# ADD CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /QMRWCE       /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /machine:MIPS /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH3RelMinSize"
# PROP BASE Intermediate_Dir "WCESH3RelMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESH3RelMinSize"
# PROP Intermediate_Dir "WCESH3RelMinSize"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESH3RelMinDependency"
# PROP BASE Intermediate_Dir "WCESH3RelMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESH3RelMinDependency"
# PROP Intermediate_Dir "WCESH3RelMinDependency"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrt) /W3 /GX- /O1 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /d "SHx" /d "SH3" /d "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 commctrl.lib coredll.lib /nologo /dll /machine:SH3 /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "x86emRelMinSize"
# PROP BASE Intermediate_Dir "x86emRelMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "x86emRelMinSize"
# PROP Intermediate_Dir "x86emRelMinSize"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /ML /W3 /GX- /O1 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX- /O1 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG"
# ADD RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /windowsce:emulation
# ADD LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /windowsce:emulation

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "x86emRelMinDependency"
# PROP BASE Intermediate_Dir "x86emRelMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "x86emRelMinDependency"
# PROP Intermediate_Dir "x86emRelMinDependency"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /ML /W3 /GX- /O1 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX- /O1 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG"
# ADD RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /windowsce:emulation
# ADD LINK32 commctrl.lib coredll.lib /nologo /stack:0x10000,0x1000 /subsystem:windows /dll /machine:I386 /windowsce:emulation

!ENDIF 

# Begin Target

# Name "atl1 - Win32 (WCE MIPS) Debug"
# Name "atl1 - Win32 (WCE SH3) Debug"
# Name "atl1 - Win32 (WCE ARM) Debug"
# Name "atl1 - Win32 (WCE x86em) Debug"
# Name "atl1 - Win32 (WCE ARM) Release MinSize"
# Name "atl1 - Win32 (WCE ARM) Release MinDependency"
# Name "atl1 - Win32 (WCE MIPS) Release MinSize"
# Name "atl1 - Win32 (WCE MIPS) Release MinDependency"
# Name "atl1 - Win32 (WCE SH3) Release MinSize"
# Name "atl1 - Win32 (WCE SH3) Release MinDependency"
# Name "atl1 - Win32 (WCE x86em) Release MinSize"
# Name "atl1 - Win32 (WCE x86em) Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\atl1.cpp

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\atl1_i.c"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

DEP_CPP_ATL1_=\
	".\atl1.h"\
	".\StdAfx.h"\
	
NODEP_CPP_ATL1_=\
	".\atl1_i.c"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\atl1.def
# End Source File
# Begin Source File

SOURCE=.\atl1.idl

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Performing MIDL step
InputPath=.\atl1.idl

BuildCmds= \
	midl /Oicf /h "atl1.h" /iid "atl1_i.c" "atl1.idl"

".\atl1.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\atl1_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\atl1.rc

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Plop.cpp

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

DEP_CPP_PLOP_=\
	".\atl1.h"\
	".\Plop.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinSize"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE ARM) Release MinDependency"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinSize"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE MIPS) Release MinDependency"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinSize"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE SH3) Release MinDependency"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinSize"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "atl1 - Win32 (WCE x86em) Release MinDependency"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Plop.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Plop.rgs
# End Source File
# End Group
# End Target
# End Project
