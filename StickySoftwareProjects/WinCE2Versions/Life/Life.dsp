# Microsoft Developer Studio Project File - Name="Life" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Application" 0x0b01
# TARGTYPE "Win32 (WCE MIPS) Application" 0x0a01
# TARGTYPE "Win32 (WCE SH) Application" 0x0901

CFG=Life - Win32 (WCE MIPS) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Life.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Life.mak" CFG="Life - Win32 (WCE MIPS) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Life - Win32 (WCE MIPS) Release" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "Life - Win32 (WCE MIPS) Debug" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "Life - Win32 (WCE SH) Release" (based on\
 "Win32 (WCE SH) Application")
!MESSAGE "Life - Win32 (WCE x86em) test" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
# PROP WCE_Configuration "H/PC Ver. 2.00"

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRel"
# PROP Intermediate_Dir "WMIPSRel"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:MIPS /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:MIPS /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Life___W"
# PROP BASE Intermediate_Dir "Life___W"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Life___W"
# PROP Intermediate_Dir "Life___W"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:IX86 /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Life___0"
# PROP BASE Intermediate_Dir "Life___0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Life"
# PROP Intermediate_Dir "Life"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MT /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /D "_AFXDLL" /QMRWCE /c
# SUBTRACT CPP /YX /Yc /Yu
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /fo"Life.res" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d "INTLMSG_CODEPAGE" /d "NDEBUG" /d "_AFXDLL"
# SUBTRACT RSC /x
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:IX86 /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /pdb:"Life.pdb" /machine:IX86 /out:"Life.exe" /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib
EMPFILE=empfile.exe
# ADD BASE EMPFILE -COPY
# ADD EMPFILE -COPY

!ENDIF 

# Begin Target

# Name "Life - Win32 (WCE MIPS) Release"
# Name "Life - Win32 (WCE MIPS) Debug"
# Name "Life - Win32 (WCE SH) Release"
# Name "Life - Win32 (WCE x86em) test"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\FileHandler.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
# SUBTRACT BASE CPP /YX /Yc /Yu
# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Game.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

# PROP Exclude_From_Build 1
# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_GAME_=\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GamePlusPlus.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Life.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Life.rc

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LifeDoc.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LifeView.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

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

SOURCE=.\FileHandler.h
# End Source File
# Begin Source File

SOURCE=.\Game.h
# End Source File
# Begin Source File

SOURCE=.\Life.h
# End Source File
# Begin Source File

SOURCE=.\LifeDoc.h
# End Source File
# Begin Source File

SOURCE=.\LifeView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
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

SOURCE=.\res\Cmdbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Life.ico
# End Source File
# Begin Source File

SOURCE=.\res\Life.rc2
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
