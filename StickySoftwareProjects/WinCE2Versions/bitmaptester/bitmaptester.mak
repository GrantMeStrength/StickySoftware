# Microsoft Developer Studio Generated NMAKE File, Based on bitmaptester.dsp
!IF "$(CFG)" == ""
CFG=bitmaptester - Win32 (WCE MIPS) Debug
!MESSAGE No configuration specified. Defaulting to bitmaptester - Win32 (WCE\
 MIPS) Debug.
!ENDIF 

!IF "$(CESubsystem)" == ""
CESubsystem=windowsce,2.0
!MESSAGE Variable CESubsystem not specified. Defaulting to windowsce,2.0
!ENDIF 

!IF "$(CEVersion)" == ""
CEVersion=200
!MESSAGE Variable CEVersion not specified. Defaulting to 200
!ENDIF 

!IF "$(CEConfigName)" == ""
CEConfigName=H/PC Ver. 2.00
!MESSAGE Variable CEConfigName not specified.  Defaulting to H/PC Ver. 2.00
!ENDIF 

!IF "$(CFG)" != "bitmaptester - Win32 (WCE MIPS) Release" && "$(CFG)" !=\
 "bitmaptester - Win32 (WCE MIPS) Debug" && "$(CFG)" !=\
 "bitmaptester - Win32 (WCE x86em) Release" && "$(CFG)" !=\
 "bitmaptester - Win32 (WCE x86em) Debug" && "$(CFG)" !=\
 "bitmaptester - Win32 (WCE SH) Release" && "$(CFG)" !=\
 "bitmaptester - Win32 (WCE SH) Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "bitmaptester.mak"\
 CFG="bitmaptester - Win32 (WCE MIPS) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "bitmaptester - Win32 (WCE MIPS) Release" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "bitmaptester - Win32 (WCE MIPS) Debug" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "bitmaptester - Win32 (WCE x86em) Release" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE "bitmaptester - Win32 (WCE x86em) Debug" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE "bitmaptester - Win32 (WCE SH) Release" (based on\
 "Win32 (WCE SH) Application")
!MESSAGE "bitmaptester - Win32 (WCE SH) Debug" (based on\
 "Win32 (WCE SH) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

OUTDIR=.\WMIPSRel
INTDIR=.\WMIPSRel
# Begin Custom Macros
OutDir=.\WMIPSRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=clmips.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D\
 "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D "UNICODE"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /QMRWCE /c 
CPP_OBJS=.\WMIPSRel/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\bitmaptester.res" /d "MIPS" /d "_MIPS_" /d\
 UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d\
 "UNICODE" /d "NDEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"$(OUTDIR)\bitmaptester.pdb" /machine:MIPS\
 /out:"$(OUTDIR)\bitmaptester.exe" /subsystem:$(CESubsystem) 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSRel\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSRel\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

OUTDIR=.\WMIPSDbg
INTDIR=.\WMIPSDbg
# Begin Custom Macros
OutDir=.\WMIPSDbg
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.ilk"
	-@erase "$(OUTDIR)\bitmaptester.pdb"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=clmips.exe
CPP_PROJ=/nologo /MTd /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D\
 "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /QMRWCE /c 
CPP_OBJS=.\WMIPSDbg/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\bitmaptester.res" /d "MIPS" /d "_MIPS_" /d\
 UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d "$(CEConfigName)" /d\
 "UNICODE" /d "DEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:yes /pdb:"$(OUTDIR)\bitmaptester.pdb" /debug /machine:MIPS\
 /out:"$(OUTDIR)\bitmaptester.exe" /subsystem:$(CESubsystem) 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSDbg\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSDbg\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

OUTDIR=.\x86emRel
INTDIR=.\x86emRel
# Begin Custom Macros
OutDir=.\x86emRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /c 
CPP_OBJS=.\x86emRel/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\bitmaptester.res" /d UNDER_CE=$(CEVersion) /d\
 "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d\
 "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d\
 "INTLMSG_CODEPAGE" /d "NDEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\bitmaptester.pdb" /machine:I386\
 /out:"$(OUTDIR)\bitmaptester.exe" /windowsce:emulation 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

EMPFILE=empfile.exe
EMPFILE_FLAGS=-COPY 
EMPFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(EMPFILE_FILES)
    $(EMPFILE) $(EMPFILE_FLAGS) ".\x86emRel\bitmaptester.exe"\
 "$(EMPFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

OUTDIR=.\x86emDbg
INTDIR=.\x86emDbg
# Begin Custom Macros
OutDir=.\x86emDbg
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.ilk"
	-@erase "$(OUTDIR)\bitmaptester.pdb"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /c 
CPP_OBJS=.\x86emDbg/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\bitmaptester.res" /d UNDER_CE=$(CEVersion) /d\
 "UNICODE" /d "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d\
 "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d\
 "INTLMSG_CODEPAGE" /d "_DEBUG" /d "x86" /d "i486" /d "_x86_" 
MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\bitmaptester.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\bitmaptester.exe" /windowsce:emulation 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

EMPFILE=empfile.exe
EMPFILE_FLAGS=-COPY 
EMPFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(EMPFILE_FILES)
    $(EMPFILE) $(EMPFILE_FLAGS) ".\x86emDbg\bitmaptester.exe"\
 "$(EMPFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

OUTDIR=.\WCESHRel
INTDIR=.\WCESHRel
# Begin Custom Macros
OutDir=.\WCESHRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=shcl.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D "$(CEConfigName)" /D\
 "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D UNDER_CE=$(CEVersion) /D "UNICODE"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /c 
CPP_OBJS=.\WCESHRel/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\bitmaptester.res" /d "SHx" /d "SH3" /d\
 "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d\
 "$(CEConfigName)" /d "UNICODE" /d "NDEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"$(OUTDIR)\bitmaptester.pdb" /machine:SH3\
 /out:"$(OUTDIR)\bitmaptester.exe" /subsystem:$(CESubsystem) 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WCESHRel\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WCESHRel\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

OUTDIR=.\WCESHDbg
INTDIR=.\WCESHDbg
# Begin Custom Macros
OutDir=.\WCESHDbg
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ELSE 

ALL : "$(OUTDIR)\bitmaptester.exe" "$(OUTDIR)\bitmaptester.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\bitmaptester.obj"
	-@erase "$(INTDIR)\bitmaptester.pch"
	-@erase "$(INTDIR)\bitmaptester.res"
	-@erase "$(INTDIR)\bitmaptesterDoc.obj"
	-@erase "$(INTDIR)\bitmaptesterView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\bitmaptester.exe"
	-@erase "$(OUTDIR)\bitmaptester.ilk"
	-@erase "$(OUTDIR)\bitmaptester.pdb"
	-@erase "$(OUTDIR)\bitmaptester.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=shcl.exe
CPP_PROJ=/nologo /MTd /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D\
 UNDER_CE=$(CEVersion) /D "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 
CPP_OBJS=.\WCESHDbg/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\bitmaptester.res" /d "SHx" /d "SH3" /d\
 "_SH3_" /d UNDER_CE=$(CEVersion) /d _WIN32_WCE=$(CEVersion) /d\
 "$(CEConfigName)" /d "UNICODE" /d "DEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\bitmaptester.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:yes /pdb:"$(OUTDIR)\bitmaptester.pdb" /debug /machine:SH3\
 /out:"$(OUTDIR)\bitmaptester.exe" /subsystem:$(CESubsystem) 
LINK32_OBJS= \
	"$(INTDIR)\bitmaptester.obj" \
	"$(INTDIR)\bitmaptester.res" \
	"$(INTDIR)\bitmaptesterDoc.obj" \
	"$(INTDIR)\bitmaptesterView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\bitmaptester.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\bitmaptester.exe"

"$(OUTDIR)\bitmaptester.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WCESHDbg\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WCESHDbg\bitmaptester.exe"\
 "$(PFILE_DEST)WCE:bitmaptester.exe">"$(OUTDIR)\bitmaptester.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ENDIF 


!IF "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release" || "$(CFG)" ==\
 "bitmaptester - Win32 (WCE MIPS) Debug" || "$(CFG)" ==\
 "bitmaptester - Win32 (WCE x86em) Release" || "$(CFG)" ==\
 "bitmaptester - Win32 (WCE x86em) Debug" || "$(CFG)" ==\
 "bitmaptester - Win32 (WCE SH) Release" || "$(CFG)" ==\
 "bitmaptester - Win32 (WCE SH) Debug"
SOURCE=.\bitmaptester.cpp

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_CPP_BITMA=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptester.obj" : $(SOURCE) $(DEP_CPP_BITMA) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ENDIF 

SOURCE=.\bitmaptester.rc

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_RSC_BITMAP=\
	".\res\bitmap1.bmp"\
	".\res\bitmaptester.ico"\
	".\res\bitmaptester.rc2"\
	".\res\Cmdbar.bmp"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\bitmaptester.res" : $(SOURCE) $(DEP_RSC_BITMAP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\bitmaptesterDoc.cpp

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_CPP_BITMAPT=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterDoc.obj" : $(SOURCE) $(DEP_CPP_BITMAPT) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ENDIF 

SOURCE=.\bitmaptesterView.cpp

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_CPP_BITMAPTE=\
	".\bitmaptester.h"\
	".\bitmaptesterDoc.h"\
	".\bitmaptesterView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\bitmaptesterView.obj" : $(SOURCE) $(DEP_CPP_BITMAPTE) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_CPP_MAINF=\
	".\bitmaptester.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\bitmaptester.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D\
 "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "DEBUG" /D "MIPS" /D "_MIPS_" /D UNDER_CE=$(CEVersion) /D\
 "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D UNDER_CE=$(CEVersion) /D "UNICODE"\
 /D "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "_DEBUG" /D "x86" /D "i486" /D "_x86_"\
 /Fp"$(INTDIR)\bitmaptester.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "NDEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D\
 UNDER_CE=$(CEVersion) /D "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "bitmaptester - Win32 (WCE SH) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Zi /Od /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "DEBUG" /D "SHx" /D "SH3" /D "_SH3_" /D\
 UNDER_CE=$(CEVersion) /D "UNICODE" /Fp"$(INTDIR)\bitmaptester.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\bitmaptester.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

