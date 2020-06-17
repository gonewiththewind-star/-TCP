// Tcpsocket.cpp : implementation file
//

#include "stdafx.h"
#include "project2.h"
#include "Tcpsocket.h"
#include "project2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTcpsocket

CTcpsocket::CTcpsocket()
{
}

CTcpsocket::CTcpsocket(CProject2Dlg *pdlg)
{
	m_pDlg=pdlg;
}

CTcpsocket::~CTcpsocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CTcpsocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CTcpsocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CTcpsocket member functions

void CTcpsocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pDlg->OnServerAccept();
//	CAsyncSocket::OnAccept(nErrorCode);
}

void CTcpsocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		m_pDlg->OnSocketClose();
	}
//	CAsyncSocket::OnClose(nErrorCode);
}

void CTcpsocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pDlg->OnClientConnect(nErrorCode);
	
//	CAsyncSocket::OnConnect(nErrorCode);
}

void CTcpsocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		m_pDlg->OnSocketReceive();
	}
//	CAsyncSocket::OnReceive(nErrorCode);
}


