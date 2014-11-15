// ChatConnector.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatConnector.h"
#include "ClientWhiteBoardSocket.h"
#include "afxdialogex.h"


// CChatConnector ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CChatConnector, CDialogEx)

CChatConnector::CChatConnector(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatConnector::IDD, pParent)
{

}

CChatConnector::CChatConnector(CClientSocket *pclient_socket, CClientWhiteBoardSocket *pclient_whiteBoard_socket, TCHAR *id)
	: CDialogEx(CChatConnector::IDD, NULL)
{
	m_client_socket= pclient_socket;
	m_client_whiteBoard_socket = pclient_whiteBoard_socket;
	p_id = id;
}

CChatConnector::~CChatConnector()
{
}

void CChatConnector::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edt_id);
	DDX_Control(pDX, IDC_IPADDRESS1, edt_ip);
	DDX_Control(pDX, IDC_EDIT2, edt_port);
}


BEGIN_MESSAGE_MAP(CChatConnector, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChatConnector::OnBnClickedOk)
END_MESSAGE_MAP()


// CChatConnector �޽��� ó�����Դϴ�.


void CChatConnector::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TCHAR t_ip[20];
	TCHAR t_port[10];
	int port;
	edt_id.GetWindowText(p_id,20);
	edt_ip.GetWindowText(t_ip,20);
	edt_port.GetWindowText(t_port, 10);
#ifdef UNICODE
	port = _wtoi(t_port);
#else
	port = atoi(t_port);
#endif

	if(!m_client_socket->Create())
	{
		AfxMessageBox(_T("���� ������ �����߽��ϴ�"));
		return;
	}
	if(!m_client_socket->Connect(t_ip,port))
	{
		AfxMessageBox(_T("������ ������ �����߽��ϴ�"));
		m_client_socket->Close();
		return;
	}
	if(!m_client_whiteBoard_socket->Create())
	{
		AfxMessageBox(_T("���� ������ �����߽��ϴ�"));
		return;
	}
	if(!m_client_whiteBoard_socket->Connect(t_ip,port))
	{
		AfxMessageBox(_T("������ ������ �����߽��ϴ�"));
		m_client_socket->Close();
		return;
	}

	CDialogEx::OnOK();
}
