#if !defined(AFX_TCPSOCKET_H__9BF1DE11_0420_4072_B4C6_87A5B54F29BE__INCLUDED_)
#define AFX_TCPSOCKET_H__9BF1DE11_0420_4072_B4C6_87A5B54F29BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tcpsocket.h : header file
//

class CProject2Dlg;

/////////////////////////////////////////////////////////////////////////////
// CTcpsocket command target

class CTcpsocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CTcpsocket();
	CTcpsocket(CProject2Dlg *pdlg);
	virtual ~CTcpsocket();

// Overrides
public:
	CProject2Dlg* m_pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcpsocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTcpsocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSOCKET_H__9BF1DE11_0420_4072_B4C6_87A5B54F29BE__INCLUDED_)
