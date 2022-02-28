# Microsoft Developer Studio Generated NMAKE File, Based on ViewMark1.dsp
!IF "$(CFG)" == ""
CFG=ViewMark1 - Win32 (WCE x86em) Debug
!MESSAGE No configuration specified. Defaulting to ViewMark1 - Win32 (WCE\
 x86em) Debug.
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

!IF "$(CFG)" != "ViewMark1 - Win32 (WCE x86em) Debug" && "$(CFG)" !=\
 "ViewMark1 - Win32 (WCE MIPS) Release" && "$(CFG)" !=\
 "ViewMark1 - Win32 (WCE SH) Release" && "$(CFG)" !=\
 "ViewMark1 - Win32 (WCE x86em) Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ViewMark1.mak" CFG="ViewMark1 - Win32 (WCE x86em) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ViewMark1 - Win32 (WCE x86em) Debug" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE "ViewMark1 - Win32 (WCE MIPS) Release" (based on\
 "Win32 (WCE MIPS) Application")
!MESSAGE "ViewMark1 - Win32 (WCE SH) Release" (based on\
 "Win32 (WCE SH) Application")
!MESSAGE "ViewMark1 - Win32 (WCE x86em) Release" (based on\
 "Win32 (WCE x86em) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

OUTDIR=.\x86emDbg
INTDIR=.\x86emDbg
# Begin Custom Macros
OutDir=.\x86emDbg
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ViewMark1.exe" "$(OUTDIR)\ViewMark1.pch"\
 "$(OUTDIR)\ViewMark1.trg"

!ELSE 

ALL : "$(OUTDIR)\ViewMark1.exe" "$(OUTDIR)\ViewMark1.pch"\
 "$(OUTDIR)\ViewMark1.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlmanacDialog.obj"
	-@erase "$(INTDIR)\CKeyDefineDialog.obj"
	-@erase "$(INTDIR)\CNameRoutines.obj"
	-@erase "$(INTDIR)\ConstRoutines.obj"
	-@erase "$(INTDIR)\DrawSky.obj"
	-@erase "$(INTDIR)\FindDialog.obj"
	-@erase "$(INTDIR)\GotoAltAzDialog.obj"
	-@erase "$(INTDIR)\GotoRaDecDialog.obj"
	-@erase "$(INTDIR)\Jovian_Dialog.obj"
	-@erase "$(INTDIR)\Key_Dialog.obj"
	-@erase "$(INTDIR)\LocationDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MessRoutines.obj"
	-@erase "$(INTDIR)\MoonView.obj"
	-@erase "$(INTDIR)\OldStarsums.obj"
	-@erase "$(INTDIR)\RegStuff.obj"
	-@erase "$(INTDIR)\SettingsDialog.obj"
	-@erase "$(INTDIR)\StarRoutines.obj"
	-@erase "$(INTDIR)\StarSums.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimeDateDialog.obj"
	-@erase "$(INTDIR)\TimeStuff.obj"
	-@erase "$(INTDIR)\Toolbox_Dialog.obj"
	-@erase "$(INTDIR)\UpdateDialog2.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(INTDIR)\ViewMark1.obj"
	-@erase "$(INTDIR)\ViewMark1.pch"
	-@erase "$(INTDIR)\ViewMark1.res"
	-@erase "$(INTDIR)\ViewMark1Doc.obj"
	-@erase "$(INTDIR)\ViewMark1View.obj"
	-@erase "$(OUTDIR)\ViewMark1.exe"
	-@erase "$(OUTDIR)\ViewMark1.ilk"
	-@erase "$(OUTDIR)\ViewMark1.pdb"
	-@erase "$(OUTDIR)\ViewMark1.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 
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
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\ViewMark1.res" /d "_WIN32_WCE" /d "UNDER_NT" /d\
 "_WIN32_WCE_EMULATION" /d "UNICODE" /d "_DEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ViewMark1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\ViewMark1.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\ViewMark1.exe" /windowsce:emulation 
LINK32_OBJS= \
	"$(INTDIR)\AlmanacDialog.obj" \
	"$(INTDIR)\CKeyDefineDialog.obj" \
	"$(INTDIR)\CNameRoutines.obj" \
	"$(INTDIR)\ConstRoutines.obj" \
	"$(INTDIR)\DrawSky.obj" \
	"$(INTDIR)\FindDialog.obj" \
	"$(INTDIR)\GotoAltAzDialog.obj" \
	"$(INTDIR)\GotoRaDecDialog.obj" \
	"$(INTDIR)\Jovian_Dialog.obj" \
	"$(INTDIR)\Key_Dialog.obj" \
	"$(INTDIR)\LocationDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessRoutines.obj" \
	"$(INTDIR)\MoonView.obj" \
	"$(INTDIR)\OldStarsums.obj" \
	"$(INTDIR)\RegStuff.obj" \
	"$(INTDIR)\SettingsDialog.obj" \
	"$(INTDIR)\StarRoutines.obj" \
	"$(INTDIR)\StarSums.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimeDateDialog.obj" \
	"$(INTDIR)\TimeStuff.obj" \
	"$(INTDIR)\Toolbox_Dialog.obj" \
	"$(INTDIR)\UpdateDialog2.obj" \
	"$(INTDIR)\ViewMark1.obj" \
	"$(INTDIR)\ViewMark1.res" \
	"$(INTDIR)\ViewMark1Doc.obj" \
	"$(INTDIR)\ViewMark1View.obj"

"$(OUTDIR)\ViewMark1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

EMPFILE=empfile.exe
EMPFILE_FLAGS=-NOSHELL -COPY 
EMPFILE_FILES= \
	"$(OUTDIR)\ViewMark1.exe"

"$(OUTDIR)\ViewMark1.trg" : "$(OUTDIR)" $(EMPFILE_FILES)
    $(EMPFILE) $(EMPFILE_FLAGS) ".\x86emDbg\ViewMark1.exe"\
 "$(EMPFILE_DEST)WCE:ViewMark1.exe">"$(OUTDIR)\ViewMark1.trg"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

OUTDIR=.\ViewMark
INTDIR=.\ViewMark
# Begin Custom Macros
OutDir=.\ViewMark
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\PUniverse.exe.MIPS" "$(OUTDIR)\ViewMark1.pch"

!ELSE 

ALL : ".\PUniverse.exe.MIPS" "$(OUTDIR)\ViewMark1.pch"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlmanacDialog.obj"
	-@erase "$(INTDIR)\CKeyDefineDialog.obj"
	-@erase "$(INTDIR)\CNameRoutines.obj"
	-@erase "$(INTDIR)\ConstRoutines.obj"
	-@erase "$(INTDIR)\DrawSky.obj"
	-@erase "$(INTDIR)\FindDialog.obj"
	-@erase "$(INTDIR)\GotoAltAzDialog.obj"
	-@erase "$(INTDIR)\GotoRaDecDialog.obj"
	-@erase "$(INTDIR)\Jovian_Dialog.obj"
	-@erase "$(INTDIR)\Key_Dialog.obj"
	-@erase "$(INTDIR)\LocationDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MessRoutines.obj"
	-@erase "$(INTDIR)\RegStuff.obj"
	-@erase "$(INTDIR)\SettingsDialog.obj"
	-@erase "$(INTDIR)\StarRoutines.obj"
	-@erase "$(INTDIR)\StarSums.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimeDateDialog.obj"
	-@erase "$(INTDIR)\TimeStuff.obj"
	-@erase "$(INTDIR)\Toolbox_Dialog.obj"
	-@erase "$(INTDIR)\UpdateDialog2.obj"
	-@erase "$(INTDIR)\ViewMark1.obj"
	-@erase "$(INTDIR)\ViewMark1.pch"
	-@erase "$(INTDIR)\ViewMark1.res"
	-@erase "$(INTDIR)\ViewMark1Doc.obj"
	-@erase "$(INTDIR)\ViewMark1View.obj"
	-@erase ".\PUniverse.exe.MIPS"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=clmips.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D "_WIN32_WCE"\
 /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 
CPP_OBJS=.\ViewMark/
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
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\ViewMark1.res" /d "MIPS" /d "_MIPS_" /d\
 "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ViewMark1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"WMIPSRel/testmips.pdb" /machine:MIPS\
 /out:"PUniverse.exe.MIPS" /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\AlmanacDialog.obj" \
	"$(INTDIR)\CKeyDefineDialog.obj" \
	"$(INTDIR)\CNameRoutines.obj" \
	"$(INTDIR)\ConstRoutines.obj" \
	"$(INTDIR)\DrawSky.obj" \
	"$(INTDIR)\FindDialog.obj" \
	"$(INTDIR)\GotoAltAzDialog.obj" \
	"$(INTDIR)\GotoRaDecDialog.obj" \
	"$(INTDIR)\Jovian_Dialog.obj" \
	"$(INTDIR)\Key_Dialog.obj" \
	"$(INTDIR)\LocationDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessRoutines.obj" \
	"$(INTDIR)\RegStuff.obj" \
	"$(INTDIR)\SettingsDialog.obj" \
	"$(INTDIR)\StarRoutines.obj" \
	"$(INTDIR)\StarSums.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimeDateDialog.obj" \
	"$(INTDIR)\TimeStuff.obj" \
	"$(INTDIR)\Toolbox_Dialog.obj" \
	"$(INTDIR)\UpdateDialog2.obj" \
	"$(INTDIR)\ViewMark1.obj" \
	"$(INTDIR)\ViewMark1.res" \
	"$(INTDIR)\ViewMark1Doc.obj" \
	"$(INTDIR)\ViewMark1View.obj"

".\PUniverse.exe.MIPS" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

OUTDIR=.\ViewMar0
INTDIR=.\ViewMar0
# Begin Custom Macros
OutDir=.\ViewMar0
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\PUniverse.exe.SH3" "$(OUTDIR)\ViewMark1.pch"

!ELSE 

ALL : ".\PUniverse.exe.SH3" "$(OUTDIR)\ViewMark1.pch"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlmanacDialog.obj"
	-@erase "$(INTDIR)\CKeyDefineDialog.obj"
	-@erase "$(INTDIR)\CNameRoutines.obj"
	-@erase "$(INTDIR)\ConstRoutines.obj"
	-@erase "$(INTDIR)\DrawSky.obj"
	-@erase "$(INTDIR)\FindDialog.obj"
	-@erase "$(INTDIR)\GotoAltAzDialog.obj"
	-@erase "$(INTDIR)\GotoRaDecDialog.obj"
	-@erase "$(INTDIR)\Jovian_Dialog.obj"
	-@erase "$(INTDIR)\Key_Dialog.obj"
	-@erase "$(INTDIR)\LocationDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MessRoutines.obj"
	-@erase "$(INTDIR)\OldStarsums.obj"
	-@erase "$(INTDIR)\RegStuff.obj"
	-@erase "$(INTDIR)\SettingsDialog.obj"
	-@erase "$(INTDIR)\StarRoutines.obj"
	-@erase "$(INTDIR)\StarSums.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimeDateDialog.obj"
	-@erase "$(INTDIR)\TimeStuff.obj"
	-@erase "$(INTDIR)\Toolbox_Dialog.obj"
	-@erase "$(INTDIR)\UpdateDialog2.obj"
	-@erase "$(INTDIR)\ViewMark1.obj"
	-@erase "$(INTDIR)\ViewMark1.pch"
	-@erase "$(INTDIR)\ViewMark1.res"
	-@erase "$(INTDIR)\ViewMark1Doc.obj"
	-@erase "$(INTDIR)\ViewMark1View.obj"
	-@erase ".\PUniverse.exe.SH3"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=shcl.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D "_WIN32_WCE" /D\
 "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 
CPP_OBJS=.\ViewMar0/
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
RSC_PROJ=/l 0x809 /r /fo"$(INTDIR)\ViewMark1.res" /d "SH3" /d "_SH3_" /d\
 "_WIN32_WCE" /d "UNICODE" /d "NDEBUG" /d "_AFXDLL" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ViewMark1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /base:"0x00010000"\
 /incremental:no /pdb:"WCESHDbg/TESTSH3.pdb" /machine:SH3\
 /out:"PUniverse.exe.SH3" /subsystem:windowsce 
LINK32_OBJS= \
	"$(INTDIR)\AlmanacDialog.obj" \
	"$(INTDIR)\CKeyDefineDialog.obj" \
	"$(INTDIR)\CNameRoutines.obj" \
	"$(INTDIR)\ConstRoutines.obj" \
	"$(INTDIR)\DrawSky.obj" \
	"$(INTDIR)\FindDialog.obj" \
	"$(INTDIR)\GotoAltAzDialog.obj" \
	"$(INTDIR)\GotoRaDecDialog.obj" \
	"$(INTDIR)\Jovian_Dialog.obj" \
	"$(INTDIR)\Key_Dialog.obj" \
	"$(INTDIR)\LocationDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessRoutines.obj" \
	"$(INTDIR)\OldStarsums.obj" \
	"$(INTDIR)\RegStuff.obj" \
	"$(INTDIR)\SettingsDialog.obj" \
	"$(INTDIR)\StarRoutines.obj" \
	"$(INTDIR)\StarSums.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimeDateDialog.obj" \
	"$(INTDIR)\TimeStuff.obj" \
	"$(INTDIR)\Toolbox_Dialog.obj" \
	"$(INTDIR)\UpdateDialog2.obj" \
	"$(INTDIR)\ViewMark1.obj" \
	"$(INTDIR)\ViewMark1.res" \
	"$(INTDIR)\ViewMark1Doc.obj" \
	"$(INTDIR)\ViewMark1View.obj"

".\PUniverse.exe.SH3" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

PFILE=pfile.exe
PFILE_FLAGS=COPY 
PFILE_FILES= \
	

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

OUTDIR=.\ViewMar2
INTDIR=.\ViewMar2
# Begin Custom Macros
OutDir=.\ViewMar2
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\x86emRel\plop.exe" "$(OUTDIR)\ViewMark1.pch" ".\x86emRel\plop.trg"

!ELSE 

ALL : ".\x86emRel\plop.exe" "$(OUTDIR)\ViewMark1.pch" ".\x86emRel\plop.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlmanacDialog.obj"
	-@erase "$(INTDIR)\CKeyDefineDialog.obj"
	-@erase "$(INTDIR)\CNameRoutines.obj"
	-@erase "$(INTDIR)\ConstRoutines.obj"
	-@erase "$(INTDIR)\DrawSky.obj"
	-@erase "$(INTDIR)\FindDialog.obj"
	-@erase "$(INTDIR)\GotoAltAzDialog.obj"
	-@erase "$(INTDIR)\GotoRaDecDialog.obj"
	-@erase "$(INTDIR)\Jovian_Dialog.obj"
	-@erase "$(INTDIR)\Key_Dialog.obj"
	-@erase "$(INTDIR)\LocationDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MessRoutines.obj"
	-@erase "$(INTDIR)\RegStuff.obj"
	-@erase "$(INTDIR)\SettingsDialog.obj"
	-@erase "$(INTDIR)\StarSums.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimeDateDialog.obj"
	-@erase "$(INTDIR)\TimeStuff.obj"
	-@erase "$(INTDIR)\Toolbox_Dialog.obj"
	-@erase "$(INTDIR)\UpdateDialog2.obj"
	-@erase "$(INTDIR)\ViewMark1.obj"
	-@erase "$(INTDIR)\ViewMark1.pch"
	-@erase "$(INTDIR)\ViewMark1Doc.obj"
	-@erase "$(INTDIR)\ViewMark1View.obj"
	-@erase ".\x86emRel\plop.exe"
	-@erase ".\x86emRel\plop.res"
	-@erase ".\x86emRel\plop.trg"
	-@erase "c:\devstudio\myprojects\StarRoutines.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT"\
 /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D\
 "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 
CPP_OBJS=.\ViewMar2/
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
RSC_PROJ=/l 0x809 /fo"x86emRel/plop.res" /d "_WIN32_WCE" /d "UNDER_NT" /d\
 "_WIN32_WCE_EMULATION" /d "UNICODE" /d "NDEBUG" 
MTL=midl.exe
MTL_PROJ=
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ViewMark1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=\
"e:\Program Files\DevStudio\MyProjects\WinCE2Versions\StarLibrary\x86emRel\starlibary.lib"\
 /nologo /entry:"wWinMainCRTStartup /windowsce:emulation " /subsystem:windows\
 /pdb:none /machine:I386 /out:"x86emRel/plop.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AlmanacDialog.obj" \
	"$(INTDIR)\CKeyDefineDialog.obj" \
	"$(INTDIR)\CNameRoutines.obj" \
	"$(INTDIR)\ConstRoutines.obj" \
	"$(INTDIR)\DrawSky.obj" \
	"$(INTDIR)\FindDialog.obj" \
	"$(INTDIR)\GotoAltAzDialog.obj" \
	"$(INTDIR)\GotoRaDecDialog.obj" \
	"$(INTDIR)\Jovian_Dialog.obj" \
	"$(INTDIR)\Key_Dialog.obj" \
	"$(INTDIR)\LocationDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MessRoutines.obj" \
	"$(INTDIR)\RegStuff.obj" \
	"$(INTDIR)\SettingsDialog.obj" \
	"$(INTDIR)\StarSums.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimeDateDialog.obj" \
	"$(INTDIR)\TimeStuff.obj" \
	"$(INTDIR)\Toolbox_Dialog.obj" \
	"$(INTDIR)\UpdateDialog2.obj" \
	"$(INTDIR)\ViewMark1.obj" \
	"$(INTDIR)\ViewMark1Doc.obj" \
	"$(INTDIR)\ViewMark1View.obj" \
	".\x86emRel\plop.res" \
	"c:\devstudio\myprojects\StarRoutines.obj"

".\x86emRel\plop.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

EMPFILE=empfile.exe
EMPFILE_FLAGS=-NOSHELL -COPY 
EMPFILE_FILES= \
	".\x86emRel\plop.exe"

".\x86emRel\plop.trg" : "$(OUTDIR)" $(EMPFILE_FILES)
    $(EMPFILE) $(EMPFILE_FLAGS) ".\x86emRel\plop.exe"\
 "$(EMPFILE_DEST)WCE:plop.exe">"$(OUTDIR)\plop.trg"

!ENDIF 


!IF "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug" || "$(CFG)" ==\
 "ViewMark1 - Win32 (WCE MIPS) Release" || "$(CFG)" ==\
 "ViewMark1 - Win32 (WCE SH) Release" || "$(CFG)" ==\
 "ViewMark1 - Win32 (WCE x86em) Release"
SOURCE=.\AlmanacDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_ALMAN=\
	".\AlmanacDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\AlmanacDialog.obj" : $(SOURCE) $(DEP_CPP_ALMAN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_ALMAN=\
	".\AlmanacDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\AlmanacDialog.obj" : $(SOURCE) $(DEP_CPP_ALMAN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_ALMAN=\
	".\AlmanacDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\AlmanacDialog.obj" : $(SOURCE) $(DEP_CPP_ALMAN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_ALMAN=\
	".\AlmanacDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\AlmanacDialog.obj" : $(SOURCE) $(DEP_CPP_ALMAN) "$(INTDIR)"


!ENDIF 

SOURCE=.\CKeyDefineDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\CKeyDefineDialog.obj" : $(SOURCE) $(DEP_CPP_CKEYD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\CKeyDefineDialog.obj" : $(SOURCE) $(DEP_CPP_CKEYD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\CKeyDefineDialog.obj" : $(SOURCE) $(DEP_CPP_CKEYD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CKEYD=\
	".\CKeyDefineDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\CKeyDefineDialog.obj" : $(SOURCE) $(DEP_CPP_CKEYD) "$(INTDIR)"


!ENDIF 

SOURCE=.\CNameRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\CNameRoutines.obj" : $(SOURCE) $(DEP_CPP_CNAME) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\CNameRoutines.obj" : $(SOURCE) $(DEP_CPP_CNAME) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\CNameRoutines.obj" : $(SOURCE) $(DEP_CPP_CNAME) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CNAME=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /Ob0 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\CNameRoutines.obj" : $(SOURCE) $(DEP_CPP_CNAME) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ConstRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\ConstRoutines.obj" : $(SOURCE) $(DEP_CPP_CONST) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\ConstRoutines.obj" : $(SOURCE) $(DEP_CPP_CONST) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\ConstRoutines.obj" : $(SOURCE) $(DEP_CPP_CONST) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_CONST=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /Ob0 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\ConstRoutines.obj" : $(SOURCE) $(DEP_CPP_CONST) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DrawSky.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\DrawSky.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\DrawSky.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\DrawSky.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_DRAWS=\
	".\CNameRoutines.h"\
	".\ConstRoutines.h"\
	".\globalstuff.h"\
	".\MessRoutines.h"\
	".\StarRountines.h"\
	".\StdAfx.h"\
	".\TripleClass.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\DrawSky.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\FindDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\FindDialog.obj" : $(SOURCE) $(DEP_CPP_FINDD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\FindDialog.obj" : $(SOURCE) $(DEP_CPP_FINDD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\FindDialog.obj" : $(SOURCE) $(DEP_CPP_FINDD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_FINDD=\
	".\FindDialog.h"\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\FindDialog.obj" : $(SOURCE) $(DEP_CPP_FINDD) "$(INTDIR)"


!ENDIF 

SOURCE=.\GotoAltAzDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoAltAzDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoAltAzDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoAltAzDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_GOTOA=\
	".\GotoAltAzDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoAltAzDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOA) "$(INTDIR)"


!ENDIF 

SOURCE=.\GotoRaDecDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoRaDecDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoRaDecDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoRaDecDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_GOTOR=\
	".\GotoRaDecDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\GotoRaDecDialog.obj" : $(SOURCE) $(DEP_CPP_GOTOR) "$(INTDIR)"


!ENDIF 

SOURCE=.\Jovian_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_JOVIA=\
	".\Jovian_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Jovian_Dialog.obj" : $(SOURCE) $(DEP_CPP_JOVIA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_JOVIA=\
	".\Jovian_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Jovian_Dialog.obj" : $(SOURCE) $(DEP_CPP_JOVIA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_JOVIA=\
	".\Jovian_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Jovian_Dialog.obj" : $(SOURCE) $(DEP_CPP_JOVIA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_JOVIA=\
	".\Jovian_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Jovian_Dialog.obj" : $(SOURCE) $(DEP_CPP_JOVIA) "$(INTDIR)"


!ENDIF 

SOURCE=.\Key_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Key_Dialog.obj" : $(SOURCE) $(DEP_CPP_KEY_D) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Key_Dialog.obj" : $(SOURCE) $(DEP_CPP_KEY_D) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Key_Dialog.obj" : $(SOURCE) $(DEP_CPP_KEY_D) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_KEY_D=\
	".\Key_Dialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Key_Dialog.obj" : $(SOURCE) $(DEP_CPP_KEY_D) "$(INTDIR)"


!ENDIF 

SOURCE=.\LocationDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\LocationDialog.obj" : $(SOURCE) $(DEP_CPP_LOCAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\LocationDialog.obj" : $(SOURCE) $(DEP_CPP_LOCAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\LocationDialog.obj" : $(SOURCE) $(DEP_CPP_LOCAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_LOCAT=\
	".\LocationDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\LocationDialog.obj" : $(SOURCE) $(DEP_CPP_LOCAT) "$(INTDIR)"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\RegStuff.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


!ENDIF 

SOURCE=.\MessRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\MessRoutines.obj" : $(SOURCE) $(DEP_CPP_MESSR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\MessRoutines.obj" : $(SOURCE) $(DEP_CPP_MESSR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\MessRoutines.obj" : $(SOURCE) $(DEP_CPP_MESSR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_MESSR=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /Ob0 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\MessRoutines.obj" : $(SOURCE) $(DEP_CPP_MESSR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MoonView.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_MOONV=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MoonView.obj" : $(SOURCE) $(DEP_CPP_MOONV) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

!ENDIF 

SOURCE=.\OldStarsums.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_OLDST=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\OldStarsums.obj" : $(SOURCE) $(DEP_CPP_OLDST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_OLDST=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\OldStarsums.obj" : $(SOURCE) $(DEP_CPP_OLDST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

!ENDIF 

SOURCE=.\RegStuff.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RegStuff.obj" : $(SOURCE) $(DEP_CPP_REGST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RegStuff.obj" : $(SOURCE) $(DEP_CPP_REGST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RegStuff.obj" : $(SOURCE) $(DEP_CPP_REGST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_REGST=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RegStuff.obj" : $(SOURCE) $(DEP_CPP_REGST) "$(INTDIR)"


!ENDIF 

SOURCE=.\SettingsDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\SettingsDialog.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\SettingsDialog.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\SettingsDialog.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_SETTI=\
	".\SettingsDialog.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\SettingsDialog.obj" : $(SOURCE) $(DEP_CPP_SETTI) "$(INTDIR)"


!ENDIF 

SOURCE=.\StarRoutines.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\StarRoutines.obj" : $(SOURCE) $(DEP_CPP_STARR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\StarRoutines.obj" : $(SOURCE) $(DEP_CPP_STARR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\StarRoutines.obj" : $(SOURCE) $(DEP_CPP_STARR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_STARR=\
	".\newfk5data.h"\
	".\StdAfx.h"\
	
INTDIR_SRC=c:\devstudio\myprojects
"$(INTDIR_SRC)" :
    if not exist "$(INTDIR_SRC)/$(NULL)" mkdir "$(INTDIR_SRC)"

CPP_SWITCHES=/nologo /MT /W3 /O2 /Ob0 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR_SRC)\\" /Zm200 /c 

"c:\devstudio\myprojects\StarRoutines.obj" : $(SOURCE) $(DEP_CPP_STARR)\
 "$(INTDIR_SRC)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StarSums.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STARS=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\StarSums.obj" : $(SOURCE) $(DEP_CPP_STARS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STARS=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\StarSums.obj" : $(SOURCE) $(DEP_CPP_STARS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_STARS=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\StarSums.obj" : $(SOURCE) $(DEP_CPP_STARS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_STARS=\
	".\globalstuff.h"\
	".\StarSums2.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "STRICT"\
 /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE" /D\
 "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\StarSums.obj" : $(SOURCE) $(DEP_CPP_STARS) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fp"$(INTDIR)\ViewMark1.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ViewMark1.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\ViewMark1.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ViewMark1.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\ViewMark1.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ViewMark1.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fp"$(INTDIR)\ViewMark1.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ViewMark1.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TimeDateDialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TIMED=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\TimeDateDialog.obj" : $(SOURCE) $(DEP_CPP_TIMED) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TIMED=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\TimeDateDialog.obj" : $(SOURCE) $(DEP_CPP_TIMED) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_TIMED=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\TimeDateDialog.obj" : $(SOURCE) $(DEP_CPP_TIMED) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TIMED=\
	".\StdAfx.h"\
	".\TimeDateDialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\TimeDateDialog.obj" : $(SOURCE) $(DEP_CPP_TIMED) "$(INTDIR)"


!ENDIF 

SOURCE=.\TimeStuff.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

"$(INTDIR)\TimeStuff.obj" : $(SOURCE) $(DEP_CPP_TIMES) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

"$(INTDIR)\TimeStuff.obj" : $(SOURCE) $(DEP_CPP_TIMES) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

"$(INTDIR)\TimeStuff.obj" : $(SOURCE) $(DEP_CPP_TIMES) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TIMES=\
	".\StdAfx.h"\
	

"$(INTDIR)\TimeStuff.obj" : $(SOURCE) $(DEP_CPP_TIMES) "$(INTDIR)"


!ENDIF 

SOURCE=.\Toolbox_Dialog.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Toolbox_Dialog.obj" : $(SOURCE) $(DEP_CPP_TOOLB) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Toolbox_Dialog.obj" : $(SOURCE) $(DEP_CPP_TOOLB) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Toolbox_Dialog.obj" : $(SOURCE) $(DEP_CPP_TOOLB) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_TOOLB=\
	".\globalstuff.h"\
	".\StdAfx.h"\
	".\Toolbox_Dialog.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\Toolbox_Dialog.obj" : $(SOURCE) $(DEP_CPP_TOOLB) "$(INTDIR)"


!ENDIF 

SOURCE=.\UpdateDialog2.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\UpdateDialog2.obj" : $(SOURCE) $(DEP_CPP_UPDAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\UpdateDialog2.obj" : $(SOURCE) $(DEP_CPP_UPDAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\UpdateDialog2.obj" : $(SOURCE) $(DEP_CPP_UPDAT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_UPDAT=\
	".\StdAfx.h"\
	".\UpdateDialog2.h"\
	".\ViewMark1.h"\
	

"$(INTDIR)\UpdateDialog2.obj" : $(SOURCE) $(DEP_CPP_UPDAT) "$(INTDIR)"


!ENDIF 

SOURCE=.\ViewMark1.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

"$(INTDIR)\ViewMark1.obj" : $(SOURCE) $(DEP_CPP_VIEWM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

"$(INTDIR)\ViewMark1.obj" : $(SOURCE) $(DEP_CPP_VIEWM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

"$(INTDIR)\ViewMark1.obj" : $(SOURCE) $(DEP_CPP_VIEWM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWM=\
	".\globalstuff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	".\ViewMark1View.h"\
	

"$(INTDIR)\ViewMark1.obj" : $(SOURCE) $(DEP_CPP_VIEWM) "$(INTDIR)"


!ENDIF 

SOURCE=.\ViewMark1.rc

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_RSC_VIEWMA=\
	".\res\appicon.ico"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\bmp00004.bmp"\
	".\res\bmp00005.bmp"\
	".\res\bmp00006.bmp"\
	".\res\button_d.bmp"\
	".\res\button_r.bmp"\
	".\res\button_u.bmp"\
	".\res\buttondo.bmp"\
	".\res\buttonle.bmp"\
	".\res\buttonno.bmp"\
	".\res\buttonri.bmp"\
	".\res\buttonti.bmp"\
	".\res\buttonup.bmp"\
	".\res\buttonzo.bmp"\
	".\res\icon1.ico"\
	".\res\littlemoon.bmp"\
	".\res\toolbar1.bmp"\
	".\res\ViewMark1.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\ViewMark1.res" : $(SOURCE) $(DEP_RSC_VIEWMA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_RSC_VIEWMA=\
	".\res\appicon.ico"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\bmp00004.bmp"\
	".\res\bmp00005.bmp"\
	".\res\bmp00006.bmp"\
	".\res\button_d.bmp"\
	".\res\button_r.bmp"\
	".\res\button_u.bmp"\
	".\res\buttondo.bmp"\
	".\res\buttonle.bmp"\
	".\res\buttonno.bmp"\
	".\res\buttonri.bmp"\
	".\res\buttonti.bmp"\
	".\res\buttonup.bmp"\
	".\res\buttonzo.bmp"\
	".\res\icon1.ico"\
	".\res\littlemoon.bmp"\
	".\res\toolbar1.bmp"\
	".\res\ViewMark1.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\ViewMark1.res" : $(SOURCE) $(DEP_RSC_VIEWMA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_RSC_VIEWMA=\
	".\res\appicon.ico"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\bmp00004.bmp"\
	".\res\bmp00005.bmp"\
	".\res\bmp00006.bmp"\
	".\res\button_d.bmp"\
	".\res\button_r.bmp"\
	".\res\button_u.bmp"\
	".\res\buttondo.bmp"\
	".\res\buttonle.bmp"\
	".\res\buttonno.bmp"\
	".\res\buttonri.bmp"\
	".\res\buttonti.bmp"\
	".\res\buttonup.bmp"\
	".\res\buttonzo.bmp"\
	".\res\icon1.ico"\
	".\res\littlemoon.bmp"\
	".\res\toolbar1.bmp"\
	".\res\ViewMark1.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

"$(INTDIR)\ViewMark1.res" : $(SOURCE) $(DEP_RSC_VIEWMA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_RSC_VIEWMA=\
	".\res\appicon.ico"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\bmp00004.bmp"\
	".\res\bmp00005.bmp"\
	".\res\bmp00006.bmp"\
	".\res\button_d.bmp"\
	".\res\button_r.bmp"\
	".\res\button_u.bmp"\
	".\res\buttondo.bmp"\
	".\res\buttonle.bmp"\
	".\res\buttonno.bmp"\
	".\res\buttonri.bmp"\
	".\res\buttonti.bmp"\
	".\res\buttonup.bmp"\
	".\res\buttonzo.bmp"\
	".\res\icon1.ico"\
	".\res\littlemoon.bmp"\
	".\res\toolbar1.bmp"\
	".\res\ViewMark1.rc2"\
	{$(INCLUDE)}"wceres.rc"\
	

".\x86emRel\plop.res" : $(SOURCE) $(DEP_RSC_VIEWMA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ViewMark1Doc.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWMAR=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

"$(INTDIR)\ViewMark1Doc.obj" : $(SOURCE) $(DEP_CPP_VIEWMAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWMAR=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

"$(INTDIR)\ViewMark1Doc.obj" : $(SOURCE) $(DEP_CPP_VIEWMAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_VIEWMAR=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

"$(INTDIR)\ViewMark1Doc.obj" : $(SOURCE) $(DEP_CPP_VIEWMAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWMAR=\
	".\StdAfx.h"\
	".\ViewMark1.h"\
	".\ViewMark1Doc.h"\
	

"$(INTDIR)\ViewMark1Doc.obj" : $(SOURCE) $(DEP_CPP_VIEWMAR) "$(INTDIR)"


!ENDIF 

SOURCE=.\ViewMark1View.cpp

!IF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Debug"

DEP_CPP_VIEWMARK=\
	".\AlmanacDialog.h"\
	".\Data_Dialog.h"\
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
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D\
 "UNICODE" /D "_UNICODE" /D "_X86_" /D "_AFXDLL" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /c 

"$(INTDIR)\ViewMark1View.obj" : $(SOURCE) $(DEP_CPP_VIEWMARK) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE MIPS) Release"

DEP_CPP_VIEWMARK=\
	".\AlmanacDialog.h"\
	".\Data_Dialog.h"\
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
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "MIPS" /D "_MIPS_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\ViewMark1View.obj" : $(SOURCE) $(DEP_CPP_VIEWMARK) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE SH) Release"

DEP_CPP_VIEWMARK=\
	".\AlmanacDialog.h"\
	".\Data_Dialog.h"\
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
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "NDEBUG" /D "SH3" /D "_SH3_" /D\
 "_WIN32_WCE" /D "UNICODE" /D "_AFXDLL" /Fo"$(INTDIR)\\" /c 

"$(INTDIR)\ViewMark1View.obj" : $(SOURCE) $(DEP_CPP_VIEWMARK) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ViewMark1 - Win32 (WCE x86em) Release"

DEP_CPP_VIEWMARK=\
	".\AlmanacDialog.h"\
	".\Data_Dialog.h"\
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
	
CPP_SWITCHES=/nologo /MT /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "STRICT" /D "_WIN32_WCE" /D "UNDER_NT" /D "_WIN32_WCE_EMULATION" /D "UNICODE"\
 /D "_UNICODE" /D "_X86_" /Fo"$(INTDIR)\\" /Zm200 /c 

"$(INTDIR)\ViewMark1View.obj" : $(SOURCE) $(DEP_CPP_VIEWMARK) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

