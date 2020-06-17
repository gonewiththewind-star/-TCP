; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProject2Dlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "project2.h"

ClassCount=6
Class1=CProject2App
Class2=CProject2Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CDataSocket
Class5=CListenSocket
Class6=CTcpsocket
Resource3=IDD_PROJECT2_DIALOG

[CLS:CProject2App]
Type=0
HeaderFile=project2.h
ImplementationFile=project2.cpp
Filter=N

[CLS:CProject2Dlg]
Type=0
HeaderFile=project2Dlg.h
ImplementationFile=project2Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CProject2Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=project2Dlg.h
ImplementationFile=project2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROJECT2_DIALOG]
Type=1
Class=CProject2Dlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_OUTMSG,edit,1350631428
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342178055
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_PORT,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CONNECT,button,1342242816
Control12=IDC_COMBO_CS,combobox,1344339971
Control13=IDC_LIST_MSG,listbox,1353793793
Control14=IDC_STATIC_STATE,static,1342308352
Control15=IDC_SET_IPADDR,edit,1350631553

[CLS:CDataSocket]
Type=0
HeaderFile=DataSocket.h
ImplementationFile=DataSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CDataSocket

[CLS:CListenSocket]
Type=0
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp
BaseClass=CAsyncMonikerFile
Filter=N
LastObject=CListenSocket

[CLS:CTcpsocket]
Type=0
HeaderFile=Tcpsocket.h
ImplementationFile=Tcpsocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CTcpsocket
VirtualFilter=q

