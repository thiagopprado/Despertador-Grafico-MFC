
// Lab13.h : main header file for the Lab13 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab13App:
// See Lab13.cpp for the implementation of this class
//

class CLab13App : public CWinAppEx
{
public:
	CLab13App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab13App theApp;
