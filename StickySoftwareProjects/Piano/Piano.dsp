# Microsoft Developer Studio Project File - Name="Piano" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (WCE x86em) Application" 0x0b01
# TARGTYPE "Win32 (WCE MIPS) Application" 0x0a01
# TARGTYPE "Win32 (WCE SH) Application" 0x0901

CFG=Piano - Win32 (WCE MIPS) Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Piano.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Piano.mak" CFG="Piano - Win32 (WCE MIPS) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Piano - Win32 (WCE MIPS) Release" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "Piano - Win32 (WCE MIPS) Debug" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "Piano - Win32 (WCE x86em) Release" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE "Piano - Win32 (WCE x86em) Debug" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE "Piano - Win32 (WCE SH) Release" (based on\
 "Win32 (WCE SH) Application")
!MESSAGE "Piano - Win32 (WCE SH) Debug" (based on "Win32 (WCE SH) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
# PROP WCE_Configuration "H/PC Ver. 2.00"

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WMIPSRel"
# PROP BASE Intermediate_Dir "WMIPSRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WMIPSRel"
# PROP Intermediate_Dir "WMIPSRel"
# PROP Target_Dir ""
CPP=clmips.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /QMRWCE /c
# ADD CPP /nologo /MT /W3 /GX- /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE" /D "UNICODE" /Yu"stdafx.h" /QMRWCE /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "MIPS" /d "_MIPS_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG"
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

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

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

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX- /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386 /windowsce:emulation
EMPFILE=empfile.exe
# ADD BASE EMPFILE -NOSHELL -COPY
# ADD EMPFILE -NOSHELL -COPY

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_WIN32_WCE" /d "UNDER_NT" /d "_WIN32_WCE_EMULATION" /d "UNICODE" /d "_DEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /windowsce:emulation
EMPFILE=empfile.exe
# ADD BASE EMPFILE -NOSHELL -COPY
# ADD EMPFILE -NOSHELL -COPY

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WCESHRel"
# PROP BASE Intermediate_Dir "WCESHRel"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WCESHRel"
# PROP Intermediate_Dir "WCESHRel"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /machine:SH3 /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WCESHDbg"
# PROP BASE Intermediate_Dir "WCESHDbg"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WCESHDbg"
# PROP Intermediate_Dir "WCESHDbg"
# PROP Target_Dir ""
CPP=shcl.exe
# ADD BASE CPP /nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Yu"stdafx.h" /c
RSC=rc.exe
# ADD BASE RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /r /d "SH3" /d "_SH3_" /d "_WIN32_WCE" /d "UNICODE" /d "DEBUG" /d "_AFXDLL"
MTL=midl.exe
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /subsystem:windowsce
# SUBTRACT BASE LINK32 /pdb:none /nodefaultlib
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /debug /machine:SH3 /subsystem:windowsce
# SUBTRACT LINK32 /pdb:none /nodefaultlib
PFILE=pfile.exe
# ADD BASE PFILE COPY
# ADD PFILE COPY

!ENDIF 

# Begin Target

# Name "Piano - Win32 (WCE MIPS) Release"
# Name "Piano - Win32 (WCE MIPS) Debug"
# Name "Piano - Win32 (WCE x86em) Release"
# Name "Piano - Win32 (WCE x86em) Debug"
# Name "Piano - Win32 (WCE SH) Release"
# Name "Piano - Win32 (WCE SH) Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\Piano.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\Piano.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Piano.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_PIANO=\
	".\MainFrm.h"\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\PianoView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_PIANO=\
	".\MainFrm.h"\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\PianoView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Piano.rc

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PianoDoc.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_PIANOD=\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_PIANOD=\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PianoKeys.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_PIANOK=\
	".\Piano.h"\
	".\PianoKeys.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_PIANOK=\
	".\Piano.h"\
	".\PianoKeys.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PianoView.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_PIANOV=\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\PianoKeys.h"\
	".\PianoView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_PIANOV=\
	".\Piano.h"\
	".\PianoDoc.h"\
	".\PianoKeys.h"\
	".\PianoView.h"\
	".\StdAfx.h"\
	

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE MIPS) Debug"

# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE x86em) Debug"

# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Release"

# ADD CPP /Yc"stdafx.h"

!ELSEIF  "$(CFG)" == "Piano - Win32 (WCE SH) Debug"

# ADD CPP /Yc"stdafx.h"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Piano.h
# End Source File
# Begin Source File

SOURCE=.\PianoDoc.h
# End Source File
# Begin Source File

SOURCE=.\PianoKeys.h
# End Source File
# Begin Source File

SOURCE=.\PianoView.h
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

SOURCE=.\res\Cmdbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Piano.ico
# End Source File
# Begin Source File

SOURCE=.\res\Piano.rc2
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
