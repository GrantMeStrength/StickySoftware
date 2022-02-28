; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialog_GameOver
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HangMan.h"
LastPage=0

ClassCount=8
Class1=CHangManApp
Class2=CHangManDoc
Class3=CHangManView
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME (English (U.S.))
Resource4=IDD_DIALOG_GAME_LOST
Resource3=IDD_DIALOG_KEY
Class6=CDialog_Key
Resource5=IDD_DIALOGBAR (English (U.S.))
Resource6=IDD_PROPPAGE_SMALL (English (U.S.))
Class7=CDialog_GameOver
Resource7=IDD_ABOUTBOX (English (U.S.))
Class8=CDialog_Game_Lost
Resource8=IDD_DIALOG_GAME

[CLS:CHangManApp]
Type=0
HeaderFile=HangMan.h
ImplementationFile=HangMan.cpp
Filter=N

[CLS:CHangManDoc]
Type=0
HeaderFile=HangManDoc.h
ImplementationFile=HangManDoc.cpp
Filter=N

[CLS:CHangManView]
Type=0
HeaderFile=HangManView.h
ImplementationFile=HangManView.cpp
Filter=C
LastObject=CHangManView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENU_TEST3
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CAboutDlg]
Type=0
HeaderFile=HangMan.cpp
ImplementationFile=HangMan.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_APP_ABOUT
CommandCount=11

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
CommandCount=13

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308481
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_APP_ABOUT
Command2=ID_APP_EXIT
CommandCount=2

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
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
CommandCount=13

[DLG:IDD_DIALOG_KEY]
Type=1
Class=CDialog_Key
ControlCount=26
Control1=IDC_BUTTON_Q,button,1342177280
Control2=IDC_BUTTON_W,button,1342177280
Control3=IDC_BUTTON_E,button,1342177280
Control4=IDC_BUTTON_R,button,1342177280
Control5=IDC_BUTTON_T,button,1342177280
Control6=IDC_BUTTON_Y,button,1342177280
Control7=IDC_BUTTON_U,button,1342177280
Control8=IDC_BUTTON_I,button,1342177280
Control9=IDC_BUTTON_O,button,1342177280
Control10=IDC_BUTTON_P,button,1342177280
Control11=IDC_BUTTON_A,button,1342177280
Control12=IDC_BUTTON_S,button,1342177280
Control13=IDC_BUTTON_D,button,1342177280
Control14=IDC_BUTTON_F,button,1342177280
Control15=IDC_BUTTON_G,button,1342177280
Control16=IDC_BUTTON_H,button,1342177280
Control17=IDC_BUTTON_J,button,1342177280
Control18=IDC_BUTTON_K,button,1342177280
Control19=IDC_BUTTON_L,button,1342177280
Control20=IDC_BUTTON_Z,button,1342177280
Control21=IDC_BUTTON_X,button,1342177280
Control22=IDC_BUTTON_C,button,1342177280
Control23=IDC_BUTTON_V,button,1342177280
Control24=IDC_BUTTON_B,button,1342177280
Control25=IDC_BUTTON_N,button,1342177280
Control26=IDC_BUTTON_M,button,1342177280

[CLS:CDialog_Key]
Type=0
HeaderFile=Dialog_Key.h
ImplementationFile=Dialog_Key.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_Z

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CDialog_GameOver]
Type=0
HeaderFile=Dialog_GameOver.h
ImplementationFile=Dialog_GameOver.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STRING_TWO
VirtualFilter=dWC

[DLG:IDD_DIALOG_GAME]
Type=1
Class=CDialog_GameOver
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177281
Control3=IDC_STRING_TWO,static,1342308353
Control4=IDC_STATIC,static,1342308353
Control5=IDC_PICTURE,static,1342177294

[DLG:IDD_DIALOG_GAME_LOST]
Type=1
Class=CDialog_Game_Lost
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177281
Control3=IDC_STRING_TWO,static,1342308353
Control4=IDC_STATIC,static,1342308353
Control5=IDC_PICTURE,static,1342177294

[CLS:CDialog_Game_Lost]
Type=0
HeaderFile=Dialog_Game_Lost.h
ImplementationFile=Dialog_Game_Lost.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

