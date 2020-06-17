// project2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "project2.h"
#include "project2Dlg.h"
#include "Textprotcol.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_BUFFER 1000
#define CLIENT  ("Paul")
#define SERVER  ("Server")
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProject2Dlg dialog

CProject2Dlg::CProject2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProject2Dlg::IDD, pParent),m_connectsocket(this),m_listensocket(this)
{
	//{{AFX_DATA_INIT(CProject2Dlg)
	m_static_state = _T("");
	m_outmsg = _T("");
	m_set_port = 0;
	m_set_ip = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProject2Dlg)
	DDX_Control(pDX, IDC_LIST_MSG, m_list_msg);
	DDX_Control(pDX, IDC_COMBO_CS, m_cs_set);
	DDX_Text(pDX, IDC_STATIC_STATE, m_static_state);
	DDX_Text(pDX, IDC_EDIT_OUTMSG, m_outmsg);
	DDX_Text(pDX, IDC_EDIT_PORT, m_set_port);
	DDX_Text(pDX, IDC_SET_IPADDR, m_set_ip);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProject2Dlg, CDialog)
	//{{AFX_MSG_MAP(CProject2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_CS, OnSelchangeComboCs)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDOK, OnSendMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProject2Dlg message handlers

BOOL CProject2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_cs_set.SetCurSel(0);
	m_server=TRUE;
	m_set_port=2008;
	m_static_state=_T("     请开始初始化! ");
	m_set_ip="";
	this->GetDlgItem(IDC_SET_IPADDR)->EnableWindow(FALSE);
	UpdateData(false);
	this->SetWindowText("TCP/IP通信－服务器端");
	m_active=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProject2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProject2Dlg::OnPaint() 
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProject2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CProject2Dlg::OnSelchangeComboCs() 
{
	// TODO: Add your control notification handler code here
	int set = m_cs_set.GetCurSel();
	if(set==1)
	{
		m_server=FALSE;	
		this->GetDlgItem(IDC_SET_IPADDR)->EnableWindow(TRUE);
		m_set_ip="127.0.0.1";
		UpdateData(false);
		this->SetDlgItemText(IDC_CONNECT,"连接");
		this->SetWindowText("TCP/IP通信－客户端");
	}
	else if(set==0)
	{
		m_server=TRUE;
		m_set_ip=" ";
		this->GetDlgItem(IDC_SET_IPADDR)->EnableWindow(FALSE);
		UpdateData(FALSE);
		this->SetDlgItemText(IDC_CONNECT,"侦听");
		this->SetWindowText("TCP/IP通信－服务器端");
	}
}

void CProject2Dlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int retb,ret,retc;
	SOCKADDR_IN addr;
	BOOL nret;
	CString ServerIP;
	ServerIP=m_set_ip;
 

	if(m_active==TRUE)
		return;
	if(m_server==TRUE)
	{
		if( ((m_set_port)<=1024 )||((m_set_port)>4096) )
		{
			AfxMessageBox("请输入合理的端口号!");
		}
		
		ret=m_listensocket.Create(m_set_port,SOCK_STREAM);
		if(ret == false)
		{
		     m_static_state="    无法建立服务器!";
			 UpdateData(FALSE);
			 m_listensocket.Close();
		}
		
		retb=m_listensocket.Listen(5);
		if(retb==false)
		{
			m_static_state="    无法侦听!!!";
			UpdateData(FALSE);
		}

		m_static_state="服务器建立成功!正在侦听……";
		m_list_msg.ResetContent();
		m_list_msg.AddString("====>服务器正在侦听……");
		this->GetDlgItem(IDC_CONNECT)->EnableWindow(FALSE);
		this->GetDlgItem(IDC_COMBO_CS)->EnableWindow(FALSE);
		UpdateData(FALSE);
		m_active=TRUE;
	}
	else
	{
		ServerIP.TrimLeft();
		ServerIP.TrimRight();
		if( inet_addr(ServerIP)== INADDR_NONE)
		{
			AfxMessageBox("请输入正确的服务器IP地址!");
		}
		if( ((m_set_port)<=1024 )||((m_set_port)>4096) )
		{
			AfxMessageBox("请输入合理的端口号!");
		}
		
		retc=m_connectsocket.Create(0,SOCK_STREAM);
		if(retc == false)
		{
			m_static_state="    无法建立客户端!";
			UpdateData(FALSE);
			m_connectsocket.Close();
		}
		addr.sin_family=AF_INET;
		addr.sin_port=htons(m_set_port);
		addr.sin_addr.S_un.S_addr = inet_addr(m_set_ip);

        nret=m_connectsocket.Connect((SOCKADDR *)&addr,sizeof(SOCKADDR));
		if(  nret==TRUE )
		{
			AfxMessageBox("连接服务器失败!!");
			m_connectsocket.Close();
		}
		else
		{
			m_static_state="    正在连接服务器……";
			this->GetDlgItem(IDC_CONNECT)->EnableWindow(FALSE);
			this->GetDlgItem(IDC_COMBO_CS)->EnableWindow(FALSE);
			UpdateData(FALSE);
			m_active=TRUE;
		}
	}
}

void CProject2Dlg::OnServerAccept()
{
	if(m_active==TRUE)
	{
		m_listensocket.Accept(m_connectsocket,NULL,NULL);
		m_static_state="     客户端已连接上——";
		m_list_msg.AddString("====>客户端连接成功!");
		UpdateData(FALSE);
		CString welcome("Welcome my friend!");
		m_connectsocket.Send(welcome,welcome.GetLength());
	}
}

void CProject2Dlg::OnClientConnect(int nErrorCode)
{
	sockaddr_in name;
	int len;
	CString buf;

	if(m_active==TRUE)
	{
		if(nErrorCode!=0)
		{
			m_list_msg.AddString("连接服务器错误!");
			m_static_state="      服务器连接错误……";
			this->GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
			this->GetDlgItem(IDC_COMBO_CS)->EnableWindow(TRUE);
			UpdateData(FALSE);  
			m_active=FALSE;
			m_connectsocket.Close();
		}
		else
		{
			len=sizeof(sockaddr_in);
			m_connectsocket.GetPeerName((SOCKADDR*)&name,&len);
			m_list_msg.ResetContent();
			buf="成功连接上服务器";
			buf+=inet_ntoa(name.sin_addr);
			m_list_msg.AddString(buf);
			m_static_state="     服务器连接成功!";
			UpdateData(FALSE);
			CString welcome("I am ");
			welcome+=CLIENT;
		    m_connectsocket.Send(welcome,welcome.GetLength());
		}
	}
}

void CProject2Dlg::OnServerClose()
{
	m_connectsocket.Close();
	m_static_state="    正在侦听……";
	m_list_msg.ResetContent();
	m_list_msg.AddString("====>客户端已退出……");
	m_list_msg.AddString("====>服务器正在侦听……");
	UpdateData(FALSE);	
}

void CProject2Dlg::OnSocketClose()
{
	if(m_active==FALSE)
		return;
	if(m_server==TRUE)
	{
		OnServerClose();
	}
	else
	{
		OnClientClose();
	}
}

void CProject2Dlg::OnClientClose()
{
	m_connectsocket.Close();
	m_list_msg.ResetContent();
	m_list_msg.AddString("服务器已断开。成功退出……");
	m_static_state="       已断开连接……";
	this->GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
	this->GetDlgItem(IDC_COMBO_CS)->EnableWindow(TRUE);
	UpdateData(FALSE);
	m_active=FALSE;
}

void CProject2Dlg::OnSocketReceive()
{
	if(m_server==TRUE)
	{
		OnServerReceive();
	}
	else
	{
		OnClientReceive();
	}
}

void CProject2Dlg::OnServerReceive()
{
	BOOL Act=FALSE;
	CString nRev,nret;
	char buf[MAX_BUFFER+1];
	int ret,i,len;
	
	ret=m_connectsocket.Receive(buf,MAX_BUFFER,0);
	if(ret!=SOCKET_ERROR)
	{
		buf[ret]=NULL;
		nRev=buf;
		nret+=CLIENT;
		nret+=":";
		len=nret.GetLength();
		nret=nRev.Right( ( (nRev.GetLength())-len ) );
    	if(nret.GetAt(0)=='/')
		{
			Act=DoAction(nret);
		}
		if(Act==FALSE)
		{
			m_list_msg.AddString((LPCTSTR)nRev);
		}
		i=m_list_msg.GetCount();
		m_list_msg.SetCurSel(i-1);
		m_list_msg.SetCurSel(-1);
		UpdateData(FALSE);
	}
	else
		AfxMessageBox("消息接收错误!");
}

void CProject2Dlg::OnClientReceive()
{
	char buf[MAX_BUFFER+1];
	BOOL Act=FALSE;
	int ret,i,len;
	CString nRev,nret;
	ret=m_connectsocket.Receive(buf,MAX_BUFFER,0);
	if(ret!=SOCKET_ERROR)
	{
		buf[ret]=NULL;
		nRev=buf;
		nret+=SERVER;
		nret+=":";
		len=nret.GetLength();
		nret=nRev.Right( ( (nRev.GetLength())-len ) );
		if(nret.GetAt(0)=='/')
		{
			Act=DoAction(nret);
		}
		if(Act==FALSE)
		{
			m_list_msg.AddString((LPCTSTR)nRev);
		}
		i=m_list_msg.GetCount();
		m_list_msg.SetCurSel(i-1);
		m_list_msg.SetCurSel(-1);
		UpdateData(FALSE);
	}
	else
		AfxMessageBox("消息接收错误!");
}

void CProject2Dlg::OnSendMsg() 
{
	// TODO: Add your control notification handler code here
	CString buf;
	int nret;
	BOOL Act=FALSE;
	int nLen,i;

	UpdateData(TRUE);
	m_outmsg.TrimLeft();
	if(m_outmsg.IsEmpty())
	{
		AfxMessageBox("对不起，不能发送空消息!");
		return;
	}
	if(m_server==TRUE)
	{
		buf+=SERVER;
		buf+=":";
	}
	else
	{
		buf+=CLIENT;
		buf+=":";
	}
	buf+=m_outmsg;
	nLen=buf.GetLength();

	nret = m_connectsocket.Send((LPCTSTR)buf,nLen);
	if(nret!=SOCKET_ERROR)
	{
		if(m_outmsg.GetAt(0)=='/')
		{
			Act=DoAction(m_outmsg);
		}
		if(Act==FALSE)
		{
			m_list_msg.AddString((LPCTSTR)buf);
		}
		m_outmsg.Empty();
		i=m_list_msg.GetCount();
		m_list_msg.SetCurSel(i-1);
		m_list_msg.SetCurSel(-1);
		UpdateData(FALSE);
	}
	else
		AfxMessageBox("消息发送失败!  :(");
}


BOOL CProject2Dlg::DoAction(CString act)
{
/*	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	rect.DeflateRect(50, 50);
	CDC * pDC=GetDC();
	CPen pen(PS_SOLID,3,RGB(255,0,0));
 	pDC->SelectObject(&pen);
    pDC->Rectangle(10,10,10,10);*/


  	switch(act.GetAt(1))
	{
		case 'm':ShellExecute(NULL,NULL,"老人与海.mp3","wmplayer.exe",NULL,SW_SHOWMAXIMIZED );
			return TRUE;
		case 'q':AfxMessageBox("Quit");return TRUE;
		case 'l':AfxMessageBox("Laugh*_* :-)");return TRUE;
		case 'c':
			AfxMessageBox("Circle OoOoOo");
				return TRUE;
		case 'r':
			//AfxMessageBox("Rectangle  ");	
			ShellExecute(NULL,"explore","C:/windows/media",NULL,NULL,SW_SHOWNORMAL);
			return TRUE;
		case 'n':DrawNiu();return TRUE;
		case 'p':DrawPhone();return TRUE;
		default: return FALSE;
	}

}

void CProject2Dlg::DrawNiu()
{	
	for(int i=0;i<TP_niu_int;i++)
	{
		m_list_msg.AddString(TP_niu_str[i]);
	}
}

void CProject2Dlg::DrawPhone()
{
	for(int i=0;i<TP_phone_int;i++)
	{
		m_list_msg.AddString(TP_phone_str[i]);
	}
}
