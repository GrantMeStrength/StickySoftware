; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CZoneCEView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ZoneCE.h"
LastPage=0

ClassCount=5
Class1=CZoneCEApp
Class2=CZoneCEDoc
Class3=CZoneCEView
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDR_ACCELERATOR1
Resource3=IDD_ABOUTBOX

[CLS:CZoneCEApp]
Type=0
HeaderFile=ZoneCE.h
ImplementationFile=ZoneCE.cpp
Filter=N

[CLS:CZoneCEDoc]
Type=0
HeaderFile=ZoneCEDoc.h
ImplementationFile=ZoneCEDoc.cpp
Filter=N

[CLS:CZoneCEView]
Type=0
HeaderFile=ZoneCEView.h
ImplementationFile=ZoneCEView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CZoneCEView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame

[CLS:CAboutDlg]
Type=0
HeaderFile=ZoneCE.cpp
ImplementationFile=ZoneCE.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308481
Control2=IDC_STATIC,static,1342308353
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342177283
Control5=IDC_STATIC,static,1342308353

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_GAME_PAUSE
Command2=ID_START_GAME
Command3=ID_DELETE_INFO
Command4=ID_APP_ABOUT
Command5=ID_APP_EXIT
Command6=ID_MENU_VFAST
Command7=ID_MENU_FAST
Command8=ID_MENU_MEDIUM
Command9=ID_MENU_SLOW
Command10=ID_MENU_SOUND
CommandCount=10

[ACL:IDR_ACCELERATOR1]
Type=1
Class=?
Command1=ID_GAME_PAUSE
CommandCount=1

