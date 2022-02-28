; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPianoView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Piano.h"
LastPage=0

ClassCount=6
Class1=CPianoApp
Class2=CPianoDoc
Class3=CPianoView
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=5
Resource1=IDD_KEYBOARD_DIALOG
Resource2=IDR_MAINFRAME
Resource4=IDD_OLE_PROPPAGE_LARGE (English (U.S.))
Resource3=IDD_FORMVIEW (English (U.S.))
Class6=CPianoKeys
Resource5=IDD_ABOUTBOX

[CLS:CPianoApp]
Type=0
HeaderFile=Piano.h
ImplementationFile=Piano.cpp
Filter=N

[CLS:CPianoDoc]
Type=0
HeaderFile=PianoDoc.h
ImplementationFile=PianoDoc.cpp
Filter=N

[CLS:CPianoView]
Type=0
HeaderFile=PianoView.h
ImplementationFile=PianoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CPianoView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_STOP
BaseClass=CFrameWnd
VirtualFilter=fWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Piano.cpp
ImplementationFile=Piano.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308480
Control5=IDC_STATIC,static,1342308353

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_ABOUT
Command6=ID_APP_EXIT
Command7=IDM_PLAY
Command8=IDM_RECORD
Command9=IDM_STOP
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_HELP
CommandCount=14

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=IDM_RECORD
Command4=IDM_PLAY
Command5=IDM_STOP
CommandCount=5

[DLG:IDD_OLE_PROPPAGE_LARGE (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_KEYBOARD_DIALOG]
Type=1
Class=CPianoKeys
ControlCount=14
Control1=IDC_A1S,button,1342187264
Control2=IDC_E1,button,1342189312
Control3=IDC_F1,button,1342189312
Control4=IDC_G1,button,1342189312
Control5=IDC_A1,button,1342189312
Control6=IDC_B1,button,1342189312
Control7=IDC_C2,button,1342189312
Control8=IDC_C1S,button,1342187264
Control9=IDC_D1S,button,1342187264
Control10=IDC_F1S,button,1342187264
Control11=IDC_G1S,button,1342187264
Control12=IDC_MC,button,1342189312
Control13=IDC_D1,button,1342189312
Control14=IDC_SPACE,button,1342181120

[CLS:CPianoKeys]
Type=0
HeaderFile=PianoKeys.h
ImplementationFile=PianoKeys.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SPACE
VirtualFilter=dWC

