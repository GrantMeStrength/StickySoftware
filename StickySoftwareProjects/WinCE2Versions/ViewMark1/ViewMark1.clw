; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CViewMark1View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ViewMark1.h"
LastPage=0

ClassCount=23
Class1=CViewMark1App
Class2=CViewMark1Doc
Class3=CViewMark1View
Class4=CMainFrame
Class5=CAboutDlg

ResourceCount=30
Resource1=IDR_MAINFRAME
Resource2=IDD_GOTO_ALTAZ_DIALOG
Class6=LocationDialog
Resource3=IDD_SETTINGS_DIALOG
Class7=CTimeDateDialog
Resource4=IDD_DIALOG_ALMANAC
Resource5=IDD_TOOLBOX_DIALOG
Class8=CSettingsDialog
Class9=CFindDialog
Resource6=IDD_AUTO_DIALOG1
Resource7=IDD_DIALOG_JOVIAN
Class10=CGotoAltAzDialog
Resource8=IDD_WHERE_DIALOG
Class11=CGotoRaDecDialog
Class12=CKey_Dialog
Resource9=IDD_ABOUTBOX (English (U.K.))
Class13=CCKeyDefineDialog
Resource10=IDR_TOOLBAR
Class14=CAuto_Dialog
Class15=CUpdateDialog2
Class16=CQuick_Dialog
Resource11=IDD_GOTO_RADEC_DIALOG
Resource12="IDR_VIEWMARK1"
Class17=CToolbox_Dialog
Class18=CScroll_Vert_Dialog
Class19=CVertical_Dialog
Resource13=IDD_WHEN_DIALOG
Class20=CJovian_Dialog
Resource14=IDD_UPDATE_DIALOG
Class21=CGotoMessDialog
Resource15=IDD_SEARCH_DIALOG
Resource16=IDD_GOTO_ALTAZ_DIALOG (English (U.K.))
Resource17=IDD_WHEN_DIALOG (English (U.K.))
Resource18=IDD_WHERE_DIALOG (English (U.K.))
Resource19=IDD_UPDATE_DIALOG (English (U.K.))
Resource20=IDD_DIALOG_JOVIAN (English (U.K.))
Resource21=IDD_GOTO_RADEC_DIALOG (English (U.K.))
Resource22=IDD_KEY_DIALOG (English (U.K.))
Resource23=IDR_MAINFRAME (English (U.K.))
Resource24=IDD_SEARCH_DIALOG (English (U.K.))
Resource25=IDD_TOOLBOX_DIALOG (English (U.K.))
Resource26=IDD_SETTINGS_DIALOG (English (U.K.))
Resource27=IDR_TOOLBAR (English (U.K.))
Resource28=IDD_ABOUTBOX
Class22=CAlmanacDialog
Resource29=IDD_KEY_DIALOG
Class23=CDialog_Ephemeris
Resource30=IDD_DIALOG_EPHEMERIS

[CLS:CViewMark1App]
Type=0
HeaderFile=ViewMark1.h
ImplementationFile=ViewMark1.cpp
Filter=N
LastObject=ID_FILE_SAVE_AS

[CLS:CViewMark1Doc]
Type=0
HeaderFile=ViewMark1Doc.h
ImplementationFile=ViewMark1Doc.cpp
Filter=N
LastObject=ID_FILE_OPEN

[CLS:CViewMark1View]
Type=0
HeaderFile=ViewMark1View.h
ImplementationFile=ViewMark1View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDD_KEY_DEFINE

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM32819
BaseClass=CFrameWnd
VirtualFilter=fWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ViewMark1.cpp
ImplementationFile=ViewMark1.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TOP_TIP,static,1342308352
Control5=IDC_CHECK_TIP,button,1342177283
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342177283

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_CONTROL_LOCATION
Command7=IDD_WHEN_DIALOG
Command8=IDD_UPDATE_DIALOG
Command9=IDD_HOW_DIALOG
Command10=IDD_KEY_DIALOG
Command11=IDD_TOOL_DIALOG
Command12=IDD_COMPASS
Command13=ID_MENU_JUPITER
Command14=ID_MENU_ALMANAC
Command15=ID_CONTROL_ZOOM_IN
Command16=ID_CONTROL_ZOOM_OUT
Command17=ID_CONTROL_TIME_NOW
Command18=ID_CONTROL_TIME_PLUS
Command19=ID_CONTROL_TIME_MINUS
Command20=IDD_GOTO_ALTAZ_DIALOG
Command21=IDD_GOTO_RADEC_DIALOG
Command22=IDD_FIND_DIALOG
Command23=ID_HELP
Command24=ID_APP_ABOUT
CommandCount=24

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_CONTROL_TIME_PLUS
Command2=ID_CONTROL_LOOK_EAST
Command3=ID_CONTROL_LOOK_HORIZON
Command4=ID_HELP
Command5=ID_CONTROL_ZOOM_IN
Command6=ID_CONTROL_ZOOM_IN
Command7=ID_CONTROL_LOOK_NORTH
Command8=ID_CONTROL_ZOOM_OUT
Command9=ID_CONTROL_ZOOM_OUT
Command10=ID_CONTROL_TIME_MINUS
Command11=ID_CONTROL_LOOK_SOUTH
Command12=ID_CONTROL_LOOK_DOWN
Command13=ID_CONTROL_LOOK_DOWN
Command14=ID_CONTROL_LOOK_LEFT
Command15=ID_CONTROL_LOOK_LEFT
Command16=ID_CONTROL_LOOK_RIGHT
Command17=ID_CONTROL_LOOK_RIGHT
Command18=ID_CONTROL_LOOK_UP
Command19=ID_CONTROL_LOOK_UP
Command20=ID_CONTROL_LOOK_WEST
Command21=ID_CONTROL_LOOK_ZENITH
CommandCount=21

[DLG:IDD_WHERE_DIALOG]
Type=1
Class=LocationDialog
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

[CLS:LocationDialog]
Type=0
HeaderFile=LocationDialog.h
ImplementationFile=LocationDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_EAST_WEST
VirtualFilter=dWC

[DLG:IDD_WHEN_DIALOG]
Type=1
Class=CTimeDateDialog
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TIME_HOUR,edit,1350639744
Control4=IDC_SPIN_HOUR,msctls_updown32,1342177334
Control5=IDC_TIME_MIN,edit,1350639744
Control6=IDC_SPIN_MIN,msctls_updown32,1342177335
Control7=IDC_TIME_SEC,edit,1350639744
Control8=IDC_SPIN_SEC,msctls_updown32,1342177335
Control9=IDC_DAY_BOX,edit,1350639744
Control10=IDC_SPIN_DAY,msctls_updown32,1342177334
Control11=IDC_MONTH_BOX,edit,1350639744
Control12=IDC_SPIN_MONTH,msctls_updown32,1342177335
Control13=IDC_YEAR_BOX,edit,1350639744
Control14=IDC_SPIN_YEAR,msctls_updown32,1342177463
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_CHECK_DAYLIGHT,button,1342242819

[CLS:CTimeDateDialog]
Type=0
HeaderFile=TimeDateDialog.h
ImplementationFile=TimeDateDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CHECK_DAYLIGHT

[DLG:IDD_SETTINGS_DIALOG]
Type=1
Class=CSettingsDialog
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
Class=CFindDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_GOTOSOLAR,combobox,1344339971
Control4=IDC_COMBO_GOTOSTAR,combobox,1344339971
Control5=IDC_COMBO_GOTOCONST,combobox,1344339971
Control6=IDC_MESS_NUMBER,edit,1350639616
Control7=IDC_SPIN_MESS_NUMBER,msctls_updown32,1342177334
Control8=IDC_STATIC,static,1342308352

[CLS:CSettingsDialog]
Type=0
HeaderFile=SettingsDialog.h
ImplementationFile=SettingsDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHECK_CONTRAST
VirtualFilter=dWC

[CLS:CFindDialog]
Type=0
HeaderFile=FindDialog.h
ImplementationFile=FindDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CFindDialog
VirtualFilter=dWC

[DLG:IDD_GOTO_ALTAZ_DIALOG]
Type=1
Class=CGotoAltAzDialog
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

[DLG:IDD_GOTO_RADEC_DIALOG]
Type=1
Class=CGotoRaDecDialog
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

[CLS:CGotoAltAzDialog]
Type=0
HeaderFile=GotoAltAzDialog.h
ImplementationFile=GotoAltAzDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SPIN_GOTO_AZ_SEC

[CLS:CGotoRaDecDialog]
Type=0
HeaderFile=GotoRaDecDialog.h
ImplementationFile=GotoRaDecDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SPIN_GOTO_DEC_MIN
VirtualFilter=dWC

[DLG:IDD_KEY_DIALOG]
Type=1
Class=CKey_Dialog
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352

[CLS:CKey_Dialog]
Type=0
HeaderFile=Key_Dialog.h
ImplementationFile=Key_Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CKey_Dialog

[CLS:CAuto_Dialog]
Type=0
HeaderFile=Auto_Dialog.h
ImplementationFile=Auto_Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAuto_Dialog

[DLG:IDD_AUTO_DIALOG1]
Type=1
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_DELAY,edit,1350639744
Control4=IDC_SPIN_DELAY,msctls_updown32,1342177335
Control5=IDC_EDIT_JUMP,edit,1350639744
Control6=IDC_SPIN_JUMP,msctls_updown32,1342177334
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_COMBO1,combobox,1344339971

[DLG:IDD_UPDATE_DIALOG]
Type=1
Class=CUpdateDialog2
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

[CLS:CUpdateDialog2]
Type=0
HeaderFile=UpdateDialog2.h
ImplementationFile=UpdateDialog2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_DELAY_VALUE
VirtualFilter=dWC

[CLS:CQuick_Dialog]
Type=0
HeaderFile=Quick_Dialog.h
ImplementationFile=Quick_Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQuick_Dialog

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
Command20=ID_BUTTON32845
CommandCount=20

[CLS:CToolbox_Dialog]
Type=0
HeaderFile=Toolbox_Dialog.h
ImplementationFile=Toolbox_Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CToolbox_Dialog

[CLS:CScroll_Vert_Dialog]
Type=0
HeaderFile=Scroll_Vert_Dialog.h
ImplementationFile=Scroll_Vert_Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScroll_Vert_Dialog

[CLS:CVertical_Dialog]
Type=0
HeaderFile=Vertical_Dialog.h
ImplementationFile=Vertical_Dialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CVertical_Dialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_JOVIAN]
Type=1
Class=CJovian_Dialog
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_JOVE_TIME_PLUS,button,1342177280
Control5=IDC_JOVE_TIME_MINUS,button,1342177280

[CLS:CJovian_Dialog]
Type=0
HeaderFile=Jovian_Dialog.h
ImplementationFile=Jovian_Dialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_JOVE_TIME_MINUS
VirtualFilter=dWC

[CLS:CCKeyDefineDialog]
Type=0
HeaderFile=CKeyDefineDialog.h
ImplementationFile=CKeyDefineDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CCKeyDefineDialog
VirtualFilter=dWC

[MNU:"IDR_VIEWMARK1"]
Type=1
Command1=ID_CONTOL_SAVE
Command2=ID_CONTROL_DELETE
Command3=ID_FILE_OPEN
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_CONTROL_LOCATION
Command9=IDD_WHEN_DIALOG
Command10=IDD_UPDATE_DIALOG
Command11=IDD_HOW_DIALOG
Command12=IDD_KEY_DEFINE
Command13=IDD_KEY_DIALOG
Command14=IDD_TOOL_DIALOG
Command15=IDD_COMPASS
Command16=ID_MENU_JUPITER
Command17=ID_CONTROL_ZOOM_IN
Command18=ID_CONTROL_ZOOM_OUT
Command19=ID_CONTROL_TIME_NOW
Command20=ID_CONTROL_TIME_PLUS
Command21=ID_CONTROL_TIME_MINUS
Command22=IDD_GOTO_ALTAZ_DIALOG
Command23=IDD_GOTO_RADEC_DIALOG
Command24=IDD_FIND_DIALOG
Command25=ID_HELP
Command26=ID_APP_ABOUT
CommandCount=26

[CLS:CGotoMessDialog]
Type=0
HeaderFile=GotoMessDialog.h
ImplementationFile=GotoMessDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CGotoMessDialog

[DLG:IDD_TOOLBOX_DIALOG]
Type=1
Class=CToolbox_Dialog
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

[DLG:IDD_GOTO_ALTAZ_DIALOG (English (U.K.))]
Type=1
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
Class=CGotoAltAzDialog

[DLG:IDD_WHEN_DIALOG (English (U.K.))]
Type=1
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TIME_HOUR,edit,1350639744
Control4=IDC_SPIN_HOUR,msctls_updown32,1342177334
Control5=IDC_TIME_MIN,edit,1350639744
Control6=IDC_SPIN_MIN,msctls_updown32,1342177335
Control7=IDC_TIME_SEC,edit,1350639744
Control8=IDC_SPIN_SEC,msctls_updown32,1342177335
Control9=IDC_DAY_BOX,edit,1350639744
Control10=IDC_SPIN_DAY,msctls_updown32,1342177334
Control11=IDC_MONTH_BOX,edit,1350639744
Control12=IDC_SPIN_MONTH,msctls_updown32,1342177335
Control13=IDC_YEAR_BOX,edit,1350639744
Control14=IDC_SPIN_YEAR,msctls_updown32,1342177463
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_CHECK_DAYLIGHT,button,1342242819
Class=CTimeDateDialog

[DLG:IDD_WHERE_DIALOG (English (U.K.))]
Type=1
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
Class=LocationDialog

[DLG:IDD_UPDATE_DIALOG (English (U.K.))]
Type=1
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
Class=CUpdateDialog2

[DLG:IDD_DIALOG_JOVIAN (English (U.K.))]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Class=CJovian_Dialog

[DLG:IDD_GOTO_RADEC_DIALOG (English (U.K.))]
Type=1
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
Class=CGotoRaDecDialog

[DLG:IDD_KEY_DIALOG (English (U.K.))]
Type=1
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Class=CKey_Dialog

[MNU:IDR_MAINFRAME (English (U.K.))]
Type=1
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_CONTROL_LOCATION
Command7=IDD_WHEN_DIALOG
Command8=IDD_UPDATE_DIALOG
Command9=IDD_HOW_DIALOG
Command10=IDD_KEY_DIALOG
Command11=IDD_TOOL_DIALOG
Command12=IDD_COMPASS
Command13=ID_MENU_JUPITER
Command14=ID_CONTROL_ZOOM_IN
Command15=ID_CONTROL_ZOOM_OUT
Command16=ID_CONTROL_TIME_NOW
Command17=ID_CONTROL_TIME_PLUS
Command18=ID_CONTROL_TIME_MINUS
Command19=IDD_GOTO_ALTAZ_DIALOG
Command20=IDD_GOTO_RADEC_DIALOG
Command21=IDD_FIND_DIALOG
Command22=ID_HELP
Command23=ID_APP_ABOUT
CommandCount=23

[DLG:IDD_SEARCH_DIALOG (English (U.K.))]
Type=1
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_GOTOSOLAR,combobox,1344339971
Control4=IDC_COMBO_GOTOSTAR,combobox,1344339971
Control5=IDC_COMBO_GOTOCONST,combobox,1344339971
Control6=IDC_MESS_NUMBER,edit,1350639616
Control7=IDC_SPIN_MESS_NUMBER,msctls_updown32,1342177334
Control8=IDC_STATIC,static,1342308352
Class=CFindDialog

[DLG:IDD_TOOLBOX_DIALOG (English (U.K.))]
Type=1
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
Class=CToolbox_Dialog

[DLG:IDD_SETTINGS_DIALOG (English (U.K.))]
Type=1
ControlCount=23
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
Control22=IDC_CHECK_CONTRAST,button,1342243107
Control23=IDC_CHECK_MOONGFX,button,1342243107
Class=CSettingsDialog

[DLG:IDD_ABOUTBOX (English (U.K.))]
Type=1
ControlCount=7
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TOP_TIP,static,1342308352
Control5=IDC_CHECK_TIP,button,1342177283
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342177283
Class=CAboutDlg

[TB:IDR_TOOLBAR (English (U.K.))]
Type=1
Command1=ID_TASK_AUTOTIME
Command2=IDD_UPDATE_DIALOG
Command3=IDD_FIND_DIALOG
Command4=IDD_HOW_DIALOG
Command5=ID_TASK_INVERT
Command6=ID_TASK_STARS
Command7=ID_TASK_PLANETS
Command8=ID_TASK_OUTLINES
Command9=ID_TASK_MESS
Command10=ID_TASK_LABELS
Command11=ID_HELP
CommandCount=11

[ACL:IDR_MAINFRAME (English (U.K.))]
Type=1
Command1=ID_CONTROL_TIME_PLUS
Command2=ID_CONTROL_LOOK_EAST
Command3=ID_CONTROL_LOOK_HORIZON
Command4=ID_HELP
Command5=ID_CONTROL_ZOOM_IN
Command6=ID_CONTROL_ZOOM_IN
Command7=ID_CONTROL_LOOK_NORTH
Command8=ID_CONTROL_ZOOM_OUT
Command9=ID_CONTROL_ZOOM_OUT
Command10=ID_CONTROL_TIME_MINUS
Command11=ID_CONTROL_LOOK_SOUTH
Command12=ID_CONTROL_LOOK_DOWN
Command13=ID_CONTROL_LOOK_DOWN
Command14=ID_CONTROL_LOOK_LEFT
Command15=ID_CONTROL_LOOK_LEFT
Command16=ID_CONTROL_LOOK_RIGHT
Command17=ID_CONTROL_LOOK_RIGHT
Command18=ID_CONTROL_LOOK_UP
Command19=ID_CONTROL_LOOK_UP
Command20=ID_CONTROL_LOOK_WEST
Command21=ID_CONTROL_LOOK_ZENITH
CommandCount=21

[DLG:IDD_DIALOG_ALMANAC]
Type=1
Class=CAlmanacDialog
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

[CLS:CAlmanacDialog]
Type=0
HeaderFile=AlmanacDialog.h
ImplementationFile=AlmanacDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CAlmanacDialog
VirtualFilter=dWC

[DLG:IDD_DIALOG_EPHEMERIS]
Type=1
Class=CDialog_Ephemeris
ControlCount=14
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

[CLS:CDialog_Ephemeris]
Type=0
HeaderFile=Dialog_Ephemeris.h
ImplementationFile=Dialog_Ephemeris.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STRING_DATE

