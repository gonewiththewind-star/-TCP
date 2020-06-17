// project2Dlg.h : header file
//

#if !defined(AFX_PROJECT2DLG_H__CFE04BDC_981F_485D_8FCC_56EB2E6AF1CD__INCLUDED_)
#define AFX_PROJECT2DLG_H__CFE04BDC_981F_485D_8FCC_56EB2E6AF1CD__INCLUDED_


#include "Tcpsocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProject2Dlg dialog

class CProject2Dlg : public CDialog
{
// Construction
public:

	void OnSocketReceive();
	void OnSocketClose();
	void OnClientConnect(int nErrorCode);
	void OnServerAccept();
	BOOL m_server;
	CProject2Dlg(CWnd* pParent = NULL);	// standard constructor
    
// Dialog Data
	//{{AFX_DATA(CProject2Dlg)
	enum { IDD = IDD_PROJECT2_DIALOG };
	CListBox	m_list_msg;
	CComboBox	m_cs_set;
	CString	m_static_state;
	CString	m_outmsg;
	int		m_set_port;
	CString	m_set_ip;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProject2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProject2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboCs();
	afx_msg void OnConnect();
	afx_msg void OnSendMsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DrawPhone();
	BOOL DoAction(CString act);
	void OnClientReceive();
	void OnServerReceive();
	BOOL m_active;
	CTcpsocket m_listensocket;
	CTcpsocket m_connectsocket;
	void OnClientClose();
	void OnServerClose();
	void DrawNiu();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECT2DLG_H__CFE04BDC_981F_485D_8FCC_56EB2E6AF1CD__INCLUDED_)
