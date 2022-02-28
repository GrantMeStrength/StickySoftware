void CZoneCEView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

//	Score=nChar;
//	switch (nChar) {
//	case 38:Key_left=true;break;
//	case 33:Key_left=true;break;
//
//	case 40:Key_right=true;break;
//	case 34:Key_right=true;break;

//	case 13:Key_up=true;break;
	//case 40:Key_down=true;break;

	//case KEYFIRE:Key_fire=true;break;

//	}

	if (nChar==KEYFIRE) Key_fire=true;
	if (nChar==KEYLEFT) Key_left=true; // 38
	if (nChar==KEYRIGHT) Key_right=true;
	if (nChar==KEYFORWARD) Key_up=true;

	if (GameState==55) // waiting for key press
	{
		if (keycount==1) KEYFIRE=nChar;
		if (keycount==2) KEYRIGHT=nChar;
		if (keycount==3) KEYLEFT=nChar;
		if (keycount==4) KEYFORWARD=nChar;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CZoneCEView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

	if (nChar==KEYFIRE) Key_fire=false;
	if (nChar==KEYLEFT) Key_left=false; // 38
	if (nChar==KEYRIGHT) Key_right=false;
	if (nChar==KEYFORWARD) Key_up=false;

if (GameState==55) // waiting for key press
	{

		if (keycount==5) GameState=20;
		if ((keycount==4) && (nChar!=KEYLEFT)) keycount++;
		if ((keycount==3) && (nChar!=KEYRIGHT)) keycount++;
		if ((keycount==2) && (nChar!=KEYFIRE)) keycount++;
		if (keycount==1) keycount++;
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);



}========================================================================
     Microsoft Foundation Class Library for Windows CE: ZoneCE
========================================================================


AppWizard has created this ZoneCE application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your ZoneCE application.

ZoneCE.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CZoneCEApp application class.

ZoneCE.cpp
    This is the main application source file that contains the application
    class CZoneCEApp.

ZoneCE.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons and bitmaps that are stored in
    the RES subdirectory.  This file can be directly edited in Microsoft
	Developer Studio.

res\ZoneCE.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file ZoneCE.rc.

res\ZoneCE.rc2
    This file contains resources that are not edited by Microsoft 
	Developer Studio.  You should place all resources not
	editable by the resource editor in this file.

ZoneCE.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived 
    from CFrameWnd and controls all SDI frame features.

res\Cmdbar.bmp
    This bitmap file is used to create tiled images for the command bar.
    The initial command bar is constructed in the CMainFrame class. 
    Edit this cmdbar bitmap along with the array in MainFrm.cpp 
    to add more command bar buttons.

/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

ZoneCEDoc.h, ZoneCEDoc.cpp - the document
    These files contain your CZoneCEDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CZoneCEDoc::Serialize).

ZoneCEView.h, ZoneCEView.cpp - the view of the document
    These files contain your CZoneCEView class.
    CZoneCEView objects are used to view CZoneCEDoc objects.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ZoneCE.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Developer Studio reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
