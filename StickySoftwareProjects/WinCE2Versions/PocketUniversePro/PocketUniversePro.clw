; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialogDisplayProperties
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PocketUniversePro.h"
LastPage=0

ClassCount=7
Class1=CPocketUniverseProApp
Class2=CPocketUniverseProDoc
Class3=CPocketUniverseProView
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=17
Resource1=IDD_ABOUTBOX (English (U.S.) - _HPC)
Resource2=IDR_MAINFRAME
Resource4=IDD_ABOUTBOX (English (U.S.) - _PALM)
Resource5=IDD_GOTO_RADEC_DIALOG
Resource6=IDD_WHERE_DIALOG
Resource7=IDD_SEARCH_DIALOG
Resource8=IDR_TOOLBAR
Resource9=IDD_GOTO_ALTAZ_DIALOG
Resource10=IDD_WHEN_TIMEDATE
Resource11=IDD_TOOLBOX_DIALOG
Resource12=IDD_UPDATE_DIALOG
Resource13=IDD_DIALOG_JOVIAN
Resource14=IDD_ABOUTBOX (English (U.S.))
Resource15=IDR_MAINFRAME (English (U.S.))
Resource16=IDD_KEY_DIALOG
Resource3=IDD_SETTINGS_DIALOG
Class6=CTimeDataDialog
Class7=CDialogDisplayProperties
Resource17=IDD_DIALOG_EPHEMERIS

[CLS:CPocketUniverseProApp]
Type=0
HeaderFile=PocketUniversePro.h
ImplementationFile=PocketUniversePro.cpp
Filter=N

[CLS:CPocketUniverseProDoc]
Type=0
HeaderFile=PocketUniverseProDoc.h
ImplementationFile=PocketUniverseProDoc.cpp
Filter=N

[CLS:CPocketUniverseProView]
Type=0
HeaderFile=PocketUniverseProView.h
ImplementationFile=PocketUniverseProView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CPocketUniverseProView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENU_DISPLAY



[CLS:CAboutDlg]
Type=0
HeaderFile=PocketUniversePro.cpp
ImplementationFile=PocketUniversePro.cpp
Filter=D

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_APP_ABOUT
CommandCount=11
Command5=ID_FILE_MRU_FILE1

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
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
Command4=ID_EDIT_UNDO

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_APP_ABOUT
CommandCount=7

[MNU:IDR_MAINFRAME (English (U.S.))]
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
Command11=ID_MENU_SETTIMEDATE
Command12=ID_MENU_DISPLAY
Command13=ID_HELP
Command14=ID_APP_ABOUT
CommandCount=14

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
Command14=ID_HELP
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.) - _PALM)]
Type=1
Class=?
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.) - _HPC)]
Type=1
Class=?
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_EPHEMERIS]
Type=1
Class=?
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDC_STRING_DATE,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STRING_SUN,static,1342308352
Control5=IDC_STRING_MOON,static,1342308352
Control6=IDC_STRING_VENUS,static,1342308352
Control7=IDC_STRING_MARS,static,1342308352
Control8=IDC_STRING_JUPITER,static,1342308352
Control9=IDC_STRING_SATURN,static,1342308352
Control10=IDC_STRING_URANUS,static,1342308352
Control11=IDC_STRING_NEPTUNE,static,1342308352
Control12=IDC_STRING_PLUTO,static,1342308352
Control13=IDC_STRING_USER,static,1342308352
Control14=IDC_STRING_MERCURY,static,1342308352
Control15=IDC_STRING_MOONPHASE,static,1342308352

[DLG:IDD_DIALOG_JOVIAN]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_JOVE_TIME_PLUS,button,1342177280
Control5=IDC_JOVE_TIME_MINUS,button,1342177280

[TB:IDR_TOOLBAR]
Type=1
Class=?
Command1=ID_TASK_AUTOTIME
Command2=IDD_UPDATE_DIALOG
Command3=IDD_FIND_DIALOG
Command4=IDD_HOW_DIALOG
Command5=ID_TASK_INVERT
Command6=ID_TASK_SUNMOON
Command7=ID_TASK_STARS
Command8=ID_TASK_PLANETS
Command9=ID_TASK_OUTLINES
Command10=ID_TASK_MESS
Command11=ID_TASK_LABELS
Command12=ID_TASK_GRID
Command13=ID_BUTTON_GOTOMOON
Command14=ID_BUTTON_GOTOSUN
Command15=ID_BUTTON_GOTO_MERC
Command16=ID_BUTTON_GOTO_VENUS
Command17=ID_BUTTON_GOTO_MARS
Command18=ID_BUTTON_GOTO_JUPITER
Command19=ID_BUTTON_GOTO_SATURN
Command20=ID_BUTTON32846
CommandCount=20

[DLG:IDD_WHERE_DIALOG]
Type=1
Class=?
ControlCount=24
Control1=IDC_LAT_BOX_DEG,edit,1350631552
Control2=IDC_SPIN_LAT_DEG,msctls_updown32,1342177334
Control3=IDC_LAT_BOX_MIN,edit,1350639744
Control4=IDC_SPIN_LAT_MIN,msctls_updown32,1342177335
Control5=IDC_LAT_BOX_SEC,edit,1350639744
Control6=IDC_SPIN_LAT_SEC,msctls_updown32,1342177335
Control7=IDC_BUTTON_NORTH_SOUTH,button,1342242816
Control8=IDC_LONG_BOX_DEG,edit,1350631552
Control9=IDC_SPIN_LONG_DEG,msctls_updown32,1342177334
Control10=IDC_LONG_BOX_MIN,edit,1350639744
Control11=IDC_SPIN_LONG_MIN,msctls_updown32,1342177335
Control12=IDC_LONG_BOX_SEC,edit,1350639744
Control13=IDC_SPIN_LONG_SEC,msctls_updown32,1342177335
Control14=IDC_BUTTON_EAST_WEST,button,1342242816
Control15=IDC_TIME_TZ,edit,1350631552
Control16=IDC_SPIN_TZ,msctls_updown32,1342177335
Control17=IDC_COMBO_WHERE,combobox,1344339971
Control18=IDOK,button,1342242817
Control19=IDCANCEL,button,1342242816
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342177280
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352

[DLG:IDD_UPDATE_DIALOG]
Type=1
Class=?
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_JUMP_VALUE,edit,1350639744
Control4=IDC_SPIN_JUMPVALUE,msctls_updown32,1342177335
Control5=IDC_COMBO_HOW,combobox,1344339971
Control6=IDC_EDIT_DELAY_VALUE,edit,1350639744
Control7=IDC_SPIN_DELAYVALUE,msctls_updown32,1342177335
Control8=IDC_COMBO_WHO,combobox,1344339971
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_TOOLBOX_DIALOG]
Type=1
Class=?
ControlCount=13
Control1=IDC_ZOOM_SLIDER,msctls_trackbar32,1342177283
Control2=IDC_BUTTON_NORTH,button,1342181131
Control3=IDC_BUTTON_SOUTH,button,1342181131
Control4=IDC_BUTTONUP,button,1342177291
Control5=IDC_BUTTONDOWN,button,1342181131
Control6=IDC_BUTTONLEFT,button,1342181131
Control7=IDC_BUTTONRIGHT,button,1342181131
Control8=IDC_BUTTON_WEST,button,1342181131
Control9=IDC_BUTTON_EAST,button,1342181131
Control10=IDC_BUTTON_TIMEMINUS,button,1342181131
Control11=IDC_BUTTON_TIMEPLUS,button,1342181131
Control12=IDC_BUTTON_ZOOMOUT,button,1342181131
Control13=IDC_BUTTON_ZOOMIN,button,1342181131

[DLG:IDD_SETTINGS_DIALOG]
Type=1
Class=CDialogDisplayProperties
ControlCount=27
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK_SITES,button,1342243107
Control4=IDC_CHECK_HORIZON,button,1342243107
Control5=IDC_CHECK_INVERT,button,1342243107
Control6=IDC_CHECK_MARKERS,button,1342243107
Control7=IDC_CHECK_PLANETS,button,1342243107
Control8=IDC_CHECK_LABELS,button,1342243107
Control9=IDC_CHECK_DETAILS,button,1342243107
Control10=IDC_CHECK_STARS,button,1342243107
Control11=IDC_COMBO_MAGNITUDES,combobox,1344339971
Control12=IDC_CHECK_MESS,button,1342243107
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CHECK_PARALLAX,button,1342243107
Control15=IDC_CHECK_HIDE,button,1342243107
Control16=IDC_CHECK_SM,button,1342243107
Control17=IDC_CHECK_OUTLINE,button,1342243107
Control18=IDC_CHECK_REALSIZE,button,1342243107
Control19=IDC_STATIC,static,1342308352
Control20=IDC_CHECK_GRID,button,1342243107
Control21=IDC_CHECK_HOURGLASS,button,1342243107
Control22=IDC_CHECK_MOONGFX,button,1342243107
Control23=IDC_CHECK_ECLIPTIC,button,1342243107
Control24=IDC_RADIO_RED,button,1342177289
Control25=IDC_RADIO_CONTRAST,button,1342177289
Control26=IDC_RADIO_STANDARD,button,1342177289
Control27=IDC_STATIC,static,1342308352

[DLG:IDD_SEARCH_DIALOG]
Type=1
Class=?
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_GOTOSOLAR,combobox,1344339971
Control4=IDC_COMBO_GOTOSTAR,combobox,1344339971
Control5=IDC_COMBO_GOTOCONST,combobox,1344339971
Control6=IDC_MESS_NUMBER,edit,1350639616
Control7=IDC_SPIN_MESS_NUMBER,msctls_updown32,1342177334
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_KEY_DIALOG]
Type=1
Class=?
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_GOTO_RADEC_DIALOG]
Type=1
Class=?
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_GOTO_RA_HOUR,edit,1350631552
Control4=IDC_SPIN_GOTO_RA_HOUR,msctls_updown32,1342177334
Control5=IDC_GOTO_RA_MIN,edit,1350639744
Control6=IDC_SPIN_GOTO_RA_MIN,msctls_updown32,1342177335
Control7=IDC_GOTO_RA_SEC,edit,1350631552
Control8=IDC_SPIN_GOTO_RA_SEC,msctls_updown32,1342177335
Control9=IDC_GOTO_DEC_DEG,edit,1350631552
Control10=IDC_SPIN_GOTO_DEC_DEG,msctls_updown32,1342177334
Control11=IDC_GOTO_DEC_MIN,edit,1350639744
Control12=IDC_SPIN_GOTO_DEC_MIN,msctls_updown32,1342177335
Control13=IDC_GOTO_DEC_SEC,edit,1350631552
Control14=IDC_SPIN_GOTO_DEC_SEC,msctls_updown32,1342177335
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342177280

[DLG:IDD_GOTO_ALTAZ_DIALOG]
Type=1
Class=?
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_GOTO_ALT_DEG,edit,1350631552
Control4=IDC_SPIN_GOTO_ALT_DEG,msctls_updown32,1342177334
Control5=IDC_GOTO_ALT_MIN,edit,1350639744
Control6=IDC_SPIN_GOTO_ALT_MIN,msctls_updown32,1342177335
Control7=IDC_GOTO_ALT_SEC,edit,1350631552
Control8=IDC_SPIN_GOTO_ALT_SEC,msctls_updown32,1342177335
Control9=IDC_GOTO_AZ_DEG,edit,1350631552
Control10=IDC_SPIN_GOTO_AZ_DEG,msctls_updown32,1342177334
Control11=IDC_GOTO_AZ_MIN,edit,1350639744
Control12=IDC_SPIN_GOTO_AZ_MIN,msctls_updown32,1342177335
Control13=IDC_GOTO_AZ_SEC,edit,1350631552
Control14=IDC_SPIN_GOTO_AZ_SEC,msctls_updown32,1342177335
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342177280

[DLG:IDD_WHEN_TIMEDATE]
Type=1
Class=CTimeDataDialog
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TIME_HOUR,edit,1350639744
Control4=IDC_SPIN_HOUR2,msctls_updown32,1342177334
Control5=IDC_TIME_MIN,edit,1350639744
Control6=IDC_SPIN_MIN2,msctls_updown32,1342177335
Control7=IDC_TIME_SEC,edit,1350639744
Control8=IDC_SPIN_SEC2,msctls_updown32,1342177335
Control9=IDC_TIME_DAY,edit,1350639744
Control10=IDC_SPIN_DAY2,msctls_updown32,1342177334
Control11=IDC_TIME_MONTH,edit,1350639744
Control12=IDC_SPIN_MONTH2,msctls_updown32,1342177335
Control13=IDC_TIME_YEAR,edit,1350639744
Control14=IDC_SPIN_YEAR2,msctls_updown32,1342177463
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_TIME_DAYLIGHT,button,1342242819

[CLS:CTimeDataDialog]
Type=0
HeaderFile=TimeDataDialog.h
ImplementationFile=TimeDataDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TIME_DAYLIGHT
VirtualFilter=dWC

[CLS:CDialogDisplayProperties]
Type=0
HeaderFile=DialogDisplayProperties.h
ImplementationFile=DialogDisplayProperties.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDialogDisplayProperties

