# Microsoft Developer Studio Project File - Name="ViewMark1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE ARM) Application" 0x8501
# TARGTYPE "Win32 (WCE x86em) Application" 0x7f01
# TARGTYPE "Win32 (WCE SH3) Application" 0x8101
# TARGTYPE "Win32 (WCE MIPS) Application" 0x8201

CFG=ViewMark1 - Win32 (WCE x86em) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ViewMark1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ViewMark1.mak" CFG="ViewMark1 - Win32 (WCE x86em) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ViewMark1 - Win32 (WCE x86em) Debug" (based on "Win32 (WCE x86em) Application")
!MESSAGE "ViewMark1 - Win32 (WCE MIPS) Release" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "ViewMark1 - Win32 (WCE SH3) Release" (based on "Win32 (WCE SH3) Application")
!MESSAGE "ViewMark1 - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Application")
!MESSAGE "ViewMark1 - Win32 (WCE ARM) ReleaseARM" (based on "Win32 (WCE ARM) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Pro 2.11"
# PROP WCE_FormatVersion "6.0"

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "x86emDbg"
# PROP BASE Intermediate_Dir "x86emDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "x86emDbg"
# PROP Intermediate_Dir "x86emDbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
EMPFILE=empfile.exe
# ADD BASE EMPFILE NOSHELL COPY
# ADD EMPFILE NOSHELL COPY
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Zm200 /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "_DEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /nodefaultlib:"$(CENoDefaultLib)" /windowsce:emulation

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ViewMark"
# PROP BASE Intermediate_Dir "ViewMark"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ViewMark"
# PROP Intermediate_Dir "ViewMark"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=clmips.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_AFXDLL" /D "_MBCS" /Zm200 /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:IX86 /windowsce:emulation
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /pdb:"WMIPSRel/testmips.pdb" /machine:MIPS /out:"WMIPSRel/PUPro.exe.MIPS" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ViewMar0"
# PROP BASE Intermediate_Dir "ViewMar0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ViewMar0"
# PROP Intermediate_Dir "ViewMar0"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=shcl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /pdb:"WMIPSRel/testmips.pdb" /machine:IX86 /out:"WMIPSRel/testmips.exe" /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /pdb:"WCESHDbg/TESTSH3.pdb" /machine:SH3 /nodefaultlib:"$(CENoDefaultLib)" /out:"PUniverse.exe.SH3" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /incremental:yes /debug /nodefaultlib

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ViewMar2"
# PROP BASE Intermediate_Dir "ViewMar2"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ViewMar2"
# PROP Intermediate_Dir "ViewMar2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
EMPFILE=empfile.exe
# ADD BASE EMPFILE NOSHELL COPY
# ADD EMPFILE NOSHELL COPY
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /Zm200 /c
# SUBTRACT CPP /Fr
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /fo"x86emRel/plop.res" /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /pdb:"WMIPSRel/testmips.pdb" /machine:IX86 /out:"WMIPSRel/testmips.exe" /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /pdb:none /machine:I386 /nodefaultlib:"$(CENoDefaultLib)" /nodefaultlib /out:"x86emRel/plop.exe"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ViewMark1___Win32__WCE_ARM__ReleaseARM"
# PROP BASE Intermediate_Dir "ViewMark1___Win32__WCE_ARM__ReleaseARM"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ViewMark1___Win32__WCE_ARM__ReleaseARM"
# PROP Intermediate_Dir "ViewMark1___Win32__WCE_ARM__ReleaseARM"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=clarm.exe
# ADD BASE CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /YX /Zm200 /c
# ADD CPP /nologo /MC /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "NDEBUG" /D "ARM" /D "_ARM_" /D UNDER_CE=$(CEVersion) /D "UNICODE" /YX /Zm200 /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /fo"x86emRel/plop.res" /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
# ADD RSC /l 0x809 /r /fo"x86emRel/plop.res" /d "ARM" /d "_ARM_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 "E:\Program Files\DevStudio\MyProjects\WinCE2Versions\ViewMark1\ViewMar2\starsums" /nologo /entry:"wWinMainCRTStartup" /machine:ARM /nodefaultlib:"$(CENoDefaultLib)" /out:"x86emRel/plop.exe"
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /pdb:"WCEARMRel/test6.pdb" /machine:ARM /out:"WCEARMRel/PuPro.exe.ARM" /subsystem:$(CESubsystem) /STACK:65536,4096
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "ViewMark1 - Win32 (WCE x86em) Debug"
# Name "ViewMark1 - Win32 (WCE MIPS) Release"
# Name "ViewMark1 - Win32 (WCE SH3) Release"
# Name "ViewMark1 - Win32 (WCE x86em) Release"
# Name "ViewMark1 - Win32 (WCE ARM) ReleaseARM"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AlmanacDialog.cpp
DEP_CPP_ALMAN=\
	".\AlmanacDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CKeyDefineDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CNameRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Ob0
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ConstRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Ob0
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Dialog_Ephemeris.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_DIALO=\
	".\Dialog_Ephemeris.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_DIALO=\
	".\Dialog_Ephemeris.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_DIALO=\
	".\Dialog_Ephemeris.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_DIALO=\
	".\Dialog_Ephemeris.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_DIALO=\
	".\Dialog_Ephemeris.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	
# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\HPCPro\ViewMark1\DrawSky.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\FindDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GotoAltAzDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GotoRaDecDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_JOVIA=\
	"..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	"..\..\WinCE2Versions\ViewMark1\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_JOVIA=\
	"..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	"..\..\WinCE2Versions\ViewMark1\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_JOVIA=\
	"..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	"..\..\WinCE2Versions\ViewMark1\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_JOVIA=\
	"..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	"..\..\WinCE2Versions\ViewMark1\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_JOVIA=\
	"..\..\WinCE2Versions\ViewMark1\Jovian_Dialog.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	"..\..\WinCE2Versions\ViewMark1\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Key_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LocationDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MessRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Ob0
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MoonView.cpp
DEP_CPP_MOONV=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\OldStarsums.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_OLDST=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_OLDST=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RegStuff.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SettingsDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StarRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP Intermediate_Dir "c:\devstudio\myprojects"
DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /O2 /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Intermediate_Dir "c:\devstudio\myprojects"
# PROP Intermediate_Dir "c:\devstudio\myprojects"
DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
# ADD BASE CPP /O2 /Ob0
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /O2 /Ob0
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\WinCE2Versions\ViewMark1\StarSums.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STARS=\
	"..\..\WinCE2Versions\ViewMark1\globalstuff.h"\
	"..\..\WinCE2Versions\ViewMark1\StarSums2.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STARS=\
	"..\..\WinCE2Versions\ViewMark1\globalstuff.h"\
	"..\..\WinCE2Versions\ViewMark1\StarSums2.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_STARS=\
	"..\..\WinCE2Versions\ViewMark1\globalstuff.h"\
	"..\..\WinCE2Versions\ViewMark1\StarSums2.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_STARS=\
	"..\..\WinCE2Versions\ViewMark1\globalstuff.h"\
	"..\..\WinCE2Versions\ViewMark1\StarSums2.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_STARS=\
	"..\..\WinCE2Versions\ViewMark1\globalstuff.h"\
	"..\..\WinCE2Versions\ViewMark1\StarSums2.h"\
	"..\..\WinCE2Versions\ViewMark1\stdafx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TIMED=\
	"..\..\WinCE2Versions\PocketUniversePro\PocketUniversePro.h"\
	"..\..\WinCE2Versions\PocketUniversePro\StdAfx.h"\
	"..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TIMED=\
	"..\..\WinCE2Versions\PocketUniversePro\PocketUniversePro.h"\
	"..\..\WinCE2Versions\PocketUniversePro\StdAfx.h"\
	"..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_TIMED=\
	"..\..\WinCE2Versions\PocketUniversePro\PocketUniversePro.h"\
	"..\..\WinCE2Versions\PocketUniversePro\StdAfx.h"\
	"..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TIMED=\
	"..\..\WinCE2Versions\PocketUniversePro\PocketUniversePro.h"\
	"..\..\WinCE2Versions\PocketUniversePro\StdAfx.h"\
	"..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_TIMED=\
	"..\..\WinCE2Versions\PocketUniversePro\PocketUniversePro.h"\
	"..\..\WinCE2Versions\PocketUniversePro\StdAfx.h"\
	"..\..\WinCE2Versions\PocketUniversePro\TimeDataDialog.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TimeDateDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TIMEDA=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TIMEDA=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_TIMEDA=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TIMEDA=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_TIMEDA=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TimeStuff.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Toolbox_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\UpdateDialog2.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ViewMark1.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ViewMark1.rc

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ViewMark1Doc.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWMA=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWMA=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_VIEWMA=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWMA=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_VIEWMA=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\HPCPro\ViewMark1\ViewMark1View.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWMAR=\
	".\Data_Dialog.h"\
	".\Dialog_Ephemeris.h"\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\GotoAltAzDialog.h"\
	".\GotoRaDecDialog.h"\
	".\Jovian_Dialog.h"\
	".\Key_Dialog.h"\
	".\LocationDialog.h"\
	".\RegStuff.h"\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\Toolbox_Dialog.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWMAR=\
	".\Data_Dialog.h"\
	".\Dialog_Ephemeris.h"\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\GotoAltAzDialog.h"\
	".\GotoRaDecDialog.h"\
	".\Jovian_Dialog.h"\
	".\Key_Dialog.h"\
	".\LocationDialog.h"\
	".\RegStuff.h"\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\Toolbox_Dialog.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

DEP_CPP_VIEWMAR=\
	".\Data_Dialog.h"\
	".\Dialog_Ephemeris.h"\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\GotoAltAzDialog.h"\
	".\GotoRaDecDialog.h"\
	".\Jovian_Dialog.h"\
	".\Key_Dialog.h"\
	".\LocationDialog.h"\
	".\RegStuff.h"\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\Toolbox_Dialog.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWMAR=\
	".\Data_Dialog.h"\
	".\Dialog_Ephemeris.h"\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\GotoAltAzDialog.h"\
	".\GotoRaDecDialog.h"\
	".\Jovian_Dialog.h"\
	".\Key_Dialog.h"\
	".\LocationDialog.h"\
	".\RegStuff.h"\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\Toolbox_Dialog.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

DEP_CPP_VIEWMAR=\
	".\Data_Dialog.h"\
	".\Dialog_Ephemeris.h"\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\GotoAltAzDialog.h"\
	".\GotoRaDecDialog.h"\
	".\Jovian_Dialog.h"\
	".\Key_Dialog.h"\
	".\LocationDialog.h"\
	".\RegStuff.h"\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\Toolbox_Dialog.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AlmanacDialog.h

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CKeyDefineDialog.h
# End Source File
# Begin Source File

SOURCE=.\CNameRoutines.h
# End Source File
# Begin Source File

SOURCE=.\ConstRoutines.h
# End Source File
# Begin Source File

SOURCE=.\Dialog_Ephemeris.h
# End Source File
# Begin Source File

SOURCE=.\FindDialog.h
# End Source File
# Begin Source File

SOURCE=.\fk5data.h

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH3) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE ARM) ReleaseARM"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\globalstuff.h
# End Source File
# Begin Source File

SOURCE=.\GotoAltAzDialog.h
# End Source File
# Begin Source File

SOURCE=.\GotoMessDialog.h
# End Source File
# Begin Source File

SOURCE=.\GotoRaDecDialog.h
# End Source File
# Begin Source File

SOURCE=.\Jovian_Dialog.h
# End Source File
# Begin Source File

SOURCE=.\Key_Dialog.h
# End Source File
# Begin Source File

SOURCE=.\LocationDialog.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\newfk5data.h
# End Source File
# Begin Source File

SOURCE=.\RegStuff.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SettingsDialog.h
# End Source File
# Begin Source File

SOURCE=.\StarRountines.h
# End Source File
# Begin Source File

SOURCE=.\StarSums2.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TimeDateDialog.h
# End Source File
# Begin Source File

SOURCE=.\Toolbox_Dialog.h
# End Source File
# Begin Source File

SOURCE=.\TripleClass.h
# End Source File
# Begin Source File

SOURCE=.\UpdateDialog2.h
# End Source File
# Begin Source File

SOURCE=.\ViewMark1.h
# End Source File
# Begin Source File

SOURCE=.\ViewMark1Doc.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\appicon.ico
# End Source File
# Begin Source File

SOURCE=.\bigmoon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_s.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00012.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button_d.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button_r.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button_u.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttondo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonno.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonri.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonti.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonup.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buttonzo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\littlemoon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\newlogo2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ViewMark1.ico
# End Source File
# Begin Source File

SOURCE=.\res\ViewMark1.rc2
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=".\link settings.txt"
# End Source File
# Begin Source File

SOURCE=.\NewStarCatalog.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\ToDo.txt
# End Source File
# Begin Source File

SOURCE=".\What's new!.txt"
# End Source File
# End Target
# End Project
