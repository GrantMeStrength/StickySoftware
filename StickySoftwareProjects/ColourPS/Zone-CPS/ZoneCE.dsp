# Microsoft Developer Studio Project File - Name="ZoneCE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Application" 0x7f01
# TARGTYPE "Win32 (WCE SH3) Application" 0x8101
# TARGTYPE "Win32 (WCE MIPS) Application" 0x8201

CFG=ZONECE - WIN32 (WCE MIPS) RELEASE
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ZoneCE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ZoneCE.mak" CFG="ZONECE - WIN32 (WCE MIPS) RELEASE"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ZoneCE - Win32 (WCE MIPS) Release" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "ZoneCE - Win32 (WCE SH3) Release" (based on "Win32 (WCE SH3) Application")
!MESSAGE "ZoneCE - Win32 (WCE x86em) Release" (based on "Win32 (WCE x86em) Application")
!MESSAGE "ZoneCE - Win32 (WCE MIPS) ReleaseInc" (based on "Win32 (WCE MIPS) Application")
!MESSAGE "ZoneCE - Win32 (WCE SH3) ReleaseInc" (based on "Win32 (WCE SH3) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath "H/PC Ver. 2.00"
# PROP WCE_FormatVersion "6.0"

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "TankMIPS"
# PROP Intermediate_Dir "WMIPSRel"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=clmips.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /Yu"stdafx.h" /QMRWCE  /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /nodefaultlib:"$(CENoDefaultLib)" /out:"WMIPSRel/tzp.exe.mips" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ZoneCE_0"
# PROP BASE Intermediate_Dir "ZoneCE_0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "TankSH3"
# PROP Intermediate_Dir "ZoneCE_0"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=shcl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE  /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:IX86 /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /nodefaultlib:"$(CENoDefaultLib)" /out:"TankSH3/tzp.exe.sh3" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ZoneCE_1"
# PROP BASE Intermediate_Dir "ZoneCE_1"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ZoneCE_1"
# PROP Intermediate_Dir "ZoneCE_1"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
EMPFILE=empfile.exe
# ADD BASE EMPFILE NOSHELL COPY
# ADD EMPFILE NOSHELL COPY
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /fo"x86emRel/plop.res" /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:IX86 /out:"WMIPSRel/TankZone.exe" /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /pdb:"x86emRel/plop.pdb" /machine:I386 /nodefaultlib:"$(CENoDefaultLib)" /out:"x86emRel/PalmZone2.exe" /windowsce:emulation /windowsce:convert
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ZoneCE_2"
# PROP BASE Intermediate_Dir "ZoneCE_2"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "TankMIPS_inc"
# PROP Intermediate_Dir "ZoneCE_2"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=clmips.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /Yu"stdafx.h" /QMRWCE  /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /out:"WMIPSRel/TankZone.exe" /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /nodefaultlib:"$(CENoDefaultLib)" /out:"WMIPSRel/PZ2MIPS.exe" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ZoneCE_3"
# PROP BASE Intermediate_Dir "ZoneCE_3"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "TankSH3_inc"
# PROP Intermediate_Dir "ZoneCE_3"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY
CPP=shcl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /M$(CECrtMT) /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /Yu"stdafx.h" /QMRWCE  /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /out:"TankSH3/TankSH3.exe" /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /nodefaultlib:"$(CENoDefaultLib)" /out:"TankSH3/TankSH3.exe" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ENDIF 

# Begin Target

# Name "ZoneCE - Win32 (WCE MIPS) Release"
# Name "ZoneCE - Win32 (WCE SH3) Release"
# Name "ZoneCE - Win32 (WCE x86em) Release"
# Name "ZoneCE - Win32 (WCE MIPS) ReleaseInc"
# Name "ZoneCE - Win32 (WCE SH3) ReleaseInc"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BackupThreeD.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RegStuff.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_REGST=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ThreeD.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_THREE=\
	".\data.h"\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_THREE=\
	".\data.h"\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_THREE=\
	".\data.h"\
	".\letterdata.h"\
	".\RegStuff.h"\
	".\SaucerClass.h"\
	".\StdAfx.h"\
	".\TankClass.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ZoneCE.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_ZONEC=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_ZONEC=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_ZONEC=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_ZONEC=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_ZONEC=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ZoneCE.rc

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ZoneCEDoc.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_ZONECE=\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_ZONECE=\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_ZONECE=\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_ZONECE=\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_ZONECE=\
	".\StdAfx.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ZoneCEView.cpp

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

DEP_CPP_ZONECEV=\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ThreeD.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

DEP_CPP_ZONECEV=\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ThreeD.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

DEP_CPP_ZONECEV=\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ThreeD.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

DEP_CPP_ZONECEV=\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ThreeD.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

DEP_CPP_ZONECEV=\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ThreeD.h"\
	".\ZoneCE.h"\
	".\ZoneCEDoc.h"\
	".\ZoneCEView.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BackupThreeD.h

!IF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) Release"

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE x86em) Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE MIPS) ReleaseInc"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ZoneCE - Win32 (WCE SH3) ReleaseInc"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\data.h
# End Source File
# Begin Source File

SOURCE=.\letterdata.h
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

SOURCE=.\ThreeD.h
# End Source File
# Begin Source File

SOURCE=.\ZoneCE.h
# End Source File
# Begin Source File

SOURCE=.\ZoneCEDoc.h
# End Source File
# Begin Source File

SOURCE=.\ZoneCEView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Cmdbar.bmp
# End Source File
# Begin Source File

SOURCE=".\pocket-tank2-flat.bmp"
# End Source File
# Begin Source File

SOURCE=.\tankzone2.bmp
# End Source File
# Begin Source File

SOURCE=.\tankzone3.bmp
# End Source File
# Begin Source File

SOURCE=.\tankzone4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoneCE.ico
# End Source File
# Begin Source File

SOURCE=.\res\ZoneCE.rc2
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\temp.txt
# End Source File
# Begin Source File

SOURCE=.\Tune1.wav
# End Source File
# End Target
# End Project
