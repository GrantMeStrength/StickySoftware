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
Resource1=IDD_ABOUTBOX
Resource2=IDR_ACCELERATOR1
Resource3=IDR_MAINFRAME

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
LastObject=ID_MENU_SOUND

[CLS:CAboutDlg]
Type=0
HeaderFile=ZoneCE.cpp
ImplementationFile=ZoneCE.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_GAME_PAUSE
Command2=ID_START_GAME
Command3=ID_DELETE_INFO
Command4=ID_APP_EXIT
Command5=ID_MENU_VFAST
Command6=ID_MENU_FAST
Command7=ID_MENU_MEDIUM
Command8=ID_MENU_SLOW
Command9=ID_MENU_SOUND
Command10=ID_MENU_LANDSCAPE
Command11=ID_MENU_SHADING
Command12=ID_MENU_FLICKER
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_ACCELERATOR1]
Type=1
Command1=ID_GAME_PAUSE
CommandCount=1

