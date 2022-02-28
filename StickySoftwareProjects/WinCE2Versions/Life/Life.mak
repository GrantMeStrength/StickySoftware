# Microsoft Developer Studio Generated NMAKE File, Based on Life.dsp
!IF "$(CFG)" == ""
CFG=Life - Win32 (WCE MIPS) Debug
!MESSAGE No configuration specified. Defaulting to Life - Win32 (WCE MIPS)\
 Debug.
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

!IF "$(CFG)" != "Life - Win32 (WCE MIPS) Release" && "$(CFG)" !=\
 "Life - Win32 (WCE MIPS) Debug" && "$(CFG)" != "Life - Win32 (WCE SH) Release"\
 && "$(CFG)" != "Life - Win32 (WCE x86em) test"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

OUTDIR=.\WMIPSRel
INTDIR=.\WMIPSRel
# Begin Custom Macros
OutDir=.\WMIPSRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ELSE 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\FileHandler.obj"
	-@erase "$(INTDIR)\GamePlusPlus.obj"
	-@erase "$(INTDIR)\Life.obj"
	-@erase "$(INTDIR)\Life.pch"
	-@erase "$(INTDIR)\Life.res"
	-@erase "$(INTDIR)\LifeDoc.obj"
	-@erase "$(INTDIR)\LifeView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\Life.exe"
	-@erase "$(OUTDIR)\Life.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=clmips.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE"\
 /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /QMRWCE /c 
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
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\Life.res" /d "MIPS" /d "_MIPS_" /d\
 "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Life.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"$(OUTDIR)\Life.pdb" /machine:MIPS\
 /out:"$(OUTDIR)\Life.exe" /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\FileHandler.obj" \
	"$(INTDIR)\GamePlusPlus.obj" \
	"$(INTDIR)\Life.obj" \
	"$(INTDIR)\Life.res" \
	"$(INTDIR)\LifeDoc.obj" \
	"$(INTDIR)\LifeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Life.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\Life.exe"

"$(OUTDIR)\Life.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSRel\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSRel\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

OUTDIR=.\WMIPSDbg
INTDIR=.\WMIPSDbg
# Begin Custom Macros
OutDir=.\WMIPSDbg
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ELSE 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\FileHandler.obj"
	-@erase "$(INTDIR)\Game.obj"
	-@erase "$(INTDIR)\GamePlusPlus.obj"
	-@erase "$(INTDIR)\Life.obj"
	-@erase "$(INTDIR)\Life.pch"
	-@erase "$(INTDIR)\Life.res"
	-@erase "$(INTDIR)\LifeDoc.obj"
	-@erase "$(INTDIR)\LifeView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Life.exe"
	-@erase "$(OUTDIR)\Life.ilk"
	-@erase "$(OUTDIR)\Life.pdb"
	-@erase "$(OUTDIR)\Life.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=clmips.exe
CPP_PROJ=/nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /QMRWCE /c 
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
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\Life.res" /d "MIPS" /d "_MIPS_" /d\
 "_WIN32_WCE" /d "UNICODE" /d "DEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Life.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:yes /pdb:"$(OUTDIR)\Life.pdb" /debug /machine:MIPS\
 /out:"$(OUTDIR)\Life.exe" /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\FileHandler.obj" \
	"$(INTDIR)\Game.obj" \
	"$(INTDIR)\GamePlusPlus.obj" \
	"$(INTDIR)\Life.obj" \
	"$(INTDIR)\Life.res" \
	"$(INTDIR)\LifeDoc.obj" \
	"$(INTDIR)\LifeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Life.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\Life.exe"

"$(OUTDIR)\Life.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSDbg\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\WMIPSDbg\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

OUTDIR=.\Life___W
INTDIR=.\Life___W
# Begin Custom Macros
OutDir=.\Life___W
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ELSE 

ALL : "$(OUTDIR)\Life.exe" "$(OUTDIR)\Life.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\FileHandler.obj"
	-@erase "$(INTDIR)\GamePlusPlus.obj"
	-@erase "$(INTDIR)\Life.obj"
	-@erase "$(INTDIR)\Life.pch"
	-@erase "$(INTDIR)\Life.res"
	-@erase "$(INTDIR)\LifeDoc.obj"
	-@erase "$(INTDIR)\LifeView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\Life.exe"
	-@erase "$(OUTDIR)\Life.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=shcl.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D\
 "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /QMRWCE /c 
CPP_OBJS=.\Life___W/
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
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\Life.res" /d "SH3" /d "_SH3_" /d\
 "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Life.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"$(OUTDIR)\Life.pdb" /machine:SH3\
 /out:"$(OUTDIR)\Life.exe" /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\FileHandler.obj" \
	"$(INTDIR)\GamePlusPlus.obj" \
	"$(INTDIR)\Life.obj" \
	"$(INTDIR)\Life.res" \
	"$(INTDIR)\LifeDoc.obj" \
	"$(INTDIR)\LifeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Life.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	"$(OUTDIR)\Life.exe"

"$(OUTDIR)\Life.trg" : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\Life___W\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"

DOWNLOAD : "$(OUTDIR)" $(PFILE_FILES)
    $(PFILE) $(PFILE_FLAGS) ".\Life___W\Life.exe"\
 "$(PFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"
    $(PFILE) @<<
  $(PFILE_FLAGS) $(PFILE_FILES)
<<

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

OUTDIR=.\Life
INTDIR=.\Life
# Begin Custom Macros
OutDir=.\Life
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\Life.exe" ".\Life.trg" "$(OUTDIR)\Life.pch"

!ELSE 

ALL : ".\Life.exe" ".\Life.trg" "$(OUTDIR)\Life.pch"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\FileHandler.obj"
	-@erase "$(INTDIR)\GamePlusPlus.obj"
	-@erase "$(INTDIR)\Life.obj"
	-@erase "$(INTDIR)\Life.pch"
	-@erase "$(INTDIR)\LifeDoc.obj"
	-@erase "$(INTDIR)\LifeView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase ".\Life.exe"
	-@erase ".\Life.res"
	-@erase ".\Life.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /Fo"$(INTDIR)\\"\
 /QMRWCE /c 
CPP_OBJS=.\Life/
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
RSC_PROJ=/l 0x809 /fo"Life.res" /d UNDER_CE=$(CEVersion) /d "UNICODE" /d\
 "_UNICODE" /d "WIN32" /d "STRICT" /d _WIN32_WCE=$(CEVersion) /d\
 "$(CEConfigName)" /d "_WIN32_WCE_EMULATION" /d "INTERNATIONAL" /d "USA" /d\
 "INTLMSG_CODEPAGE" /d "NDEBUG" 
MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Life.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=commctrl.lib coredll.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"Life.pdb" /machine:IX86 /out:"Life.exe"\
 /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\FileHandler.obj" \
	"$(INTDIR)\GamePlusPlus.obj" \
	"$(INTDIR)\Life.obj" \
	"$(INTDIR)\LifeDoc.obj" \
	"$(INTDIR)\LifeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	".\Life.res"

".\Life.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

EMPFILE=empfile.exe
EMPFILE_FLAGS=-COPY 
EMPFILE_FILES= \
	".\Life.exe"

".\Life.trg" : "$(OUTDIR)" $(EMPFILE_FILES)
    $(EMPFILE) $(EMPFILE_FLAGS) ".\Life.exe"\
 "$(EMPFILE_DEST)WCE:Life.exe">"$(OUTDIR)\Life.trg"

!ENDIF 


!IF "$(CFG)" == "Life - Win32 (WCE MIPS) Release" || "$(CFG)" ==\
 "Life - Win32 (WCE MIPS) Debug" || "$(CFG)" == "Life - Win32 (WCE SH) Release"\
 || "$(CFG)" == "Life - Win32 (WCE x86em) test"
SOURCE=.\FileHandler.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\FileHandler.obj" : $(SOURCE) $(DEP_CPP_FILEH) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\FileHandler.obj" : $(SOURCE) $(DEP_CPP_FILEH) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\FileHandler.obj" : $(SOURCE) $(DEP_CPP_FILEH) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_FILEH=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /ML /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_" /Fo"$(INTDIR)\\"\
 /QMRWCE /c 

"$(INTDIR)\FileHandler.obj" : $(SOURCE) $(DEP_CPP_FILEH) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Game.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_GAME_=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\Game.obj" : $(SOURCE) $(DEP_CPP_GAME_) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

!ENDIF 

SOURCE=.\GamePlusPlus.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GamePlusPlus.obj" : $(SOURCE) $(DEP_CPP_GAMEP) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GamePlusPlus.obj" : $(SOURCE) $(DEP_CPP_GAMEP) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GamePlusPlus.obj" : $(SOURCE) $(DEP_CPP_GAMEP) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_GAMEP=\
	".\FileHandler.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GamePlusPlus.obj" : $(SOURCE) $(DEP_CPP_GAMEP) "$(INTDIR)"


!ENDIF 

SOURCE=.\Life.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Life.obj" : $(SOURCE) $(DEP_CPP_LIFE_) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Life.obj" : $(SOURCE) $(DEP_CPP_LIFE_) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Life.obj" : $(SOURCE) $(DEP_CPP_LIFE_) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFE_=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Life.obj" : $(SOURCE) $(DEP_CPP_LIFE_) "$(INTDIR)"


!ENDIF 

SOURCE=.\Life.rc

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_RSC_LIFE_R=\
	".\res\bitmap2.bmp"\
	".\res\Cmdbar.bmp"\
	".\res\Life.ico"\
	".\res\Life.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\Life.res" : $(SOURCE) $(DEP_RSC_LIFE_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_RSC_LIFE_R=\
	".\res\bitmap2.bmp"\
	".\res\Cmdbar.bmp"\
	".\res\Life.ico"\
	".\res\Life.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\Life.res" : $(SOURCE) $(DEP_RSC_LIFE_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_RSC_LIFE_R=\
	".\res\bitmap2.bmp"\
	".\res\Cmdbar.bmp"\
	".\res\Life.ico"\
	".\res\Life.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\Life.res" : $(SOURCE) $(DEP_RSC_LIFE_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_RSC_LIFE_R=\
	".\res\bitmap2.bmp"\
	".\res\Cmdbar.bmp"\
	".\res\Life.ico"\
	".\res\Life.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

".\Life.res" : $(SOURCE) $(DEP_RSC_LIFE_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\LifeDoc.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeDoc.obj" : $(SOURCE) $(DEP_CPP_LIFED) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeDoc.obj" : $(SOURCE) $(DEP_CPP_LIFED) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeDoc.obj" : $(SOURCE) $(DEP_CPP_LIFED) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFED=\
	".\Life.h"\
	".\LifeDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeDoc.obj" : $(SOURCE) $(DEP_CPP_LIFED) "$(INTDIR)"


!ENDIF 

SOURCE=.\LifeView.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeView.obj" : $(SOURCE) $(DEP_CPP_LIFEV) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeView.obj" : $(SOURCE) $(DEP_CPP_LIFEV) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeView.obj" : $(SOURCE) $(DEP_CPP_LIFEV) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_LIFEV=\
	".\Game.h"\
	".\Life.h"\
	".\LifeDoc.h"\
	".\LifeView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\LifeView.obj" : $(SOURCE) $(DEP_CPP_LIFEV) "$(INTDIR)"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Life.pch"


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_MAINF=\
	".\Life.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Life - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Life.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE MIPS) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Zi /Od /D "DEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Life.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE SH) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\Life.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Life.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Life - Win32 (WCE x86em) test"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /ML /W3 /GX- /O2 /D UNDER_CE=$(CEVersion) /D "UNICODE" /D\
 "_UNICODE" /D "WIN32" /D "STRICT" /D _WIN32_WCE=$(CEVersion) /D\
 "$(CEConfigName)" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D\
 "INTLMSG_CODEPAGE" /D "NDEBUG" /D "x86" /D "i486" /D "_x86_"\
 /Fp"$(INTDIR)\Life.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /QMRWCE /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Life.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

