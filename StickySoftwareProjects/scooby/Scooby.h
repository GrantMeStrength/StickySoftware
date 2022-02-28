// scooby.h : main header file for the SCOOBY application
//

#if !defined(AFX_SCOOBY_H__CD859157_602B_11D2_B64C_00A0C9B5E577__INCLUDED_)
#define AFX_SCOOBY_H__CD859157_602B_11D2_B64C_00A0C9B5E577__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CScoobyApp:
// See scooby.cpp for the implementation of this class
//

class CScoobyApp : public CWinApp
{
public:
	CScoobyApp(LPCTSTR lpszAppName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoobyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScoobyApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CScooby dialog

class CScooby : public CDialog
{
// Construction
public:
	CScooby(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScooby)
	enum { IDD = IDD_SCOOBY };
	BOOL	m_calculator;
	BOOL	m_calendar;
	BOOL	m_channels;
	BOOL	m_contacts;
	BOOL	m_inbox;
	BOOL	m_notes;
	BOOL	m_tasks;
	BOOL	m_voice;
	BOOL	m_graphic;
	CString	m_graphicname;
	int		m_dropuser1;
	BOOL	m_date;
	BOOL	m_utilities;
	int		m_dropbut;
	BOOL	m_pilot;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScooby)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScooby)
	afx_msg void OnCheckGraphic();
	afx_msg void OnCheckAppVoice();
	afx_msg void OnCheckAppTasks();
	afx_msg void OnCheckAppChannels();
	afx_msg void OnCheckAppContacts();
	afx_msg void OnCheckAppInbox();
	afx_msg void OnCheckAppNotes();
	afx_msg void OnCheckAppCalendar();
	afx_msg void OnCheckAppCalculator();
	afx_msg void OnCheckAppUser1();
	afx_msg void OnCheckAppUser2();
	afx_msg void OnCheckAppUser3();
	afx_msg void OnCheckAppUser4();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckDate();
	afx_msg void OnCheckUtilities();
	afx_msg void OnButtonClean();
	afx_msg void OnCloseupComboButlist();
	afx_msg void OnCloseupComboUser1();
	afx_msg void OnCheckPilot();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOOBY_H__CD859157_602B_11D2_B64C_00A0C9B5E577__INCLUDED_)
