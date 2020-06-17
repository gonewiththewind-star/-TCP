// project2.h : main header file for the PROJECT2 application
//

#if !defined(AFX_PROJECT2_H__459D7FB0_45D2_40C6_A4A9_63AF5B81D74C__INCLUDED_)
#define AFX_PROJECT2_H__459D7FB0_45D2_40C6_A4A9_63AF5B81D74C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProject2App:
// See project2.cpp for the implementation of this class
//

class CProject2App : public CWinApp
{
public:
	CProject2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProject2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProject2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECT2_H__459D7FB0_45D2_40C6_A4A9_63AF5B81D74C__INCLUDED_)
