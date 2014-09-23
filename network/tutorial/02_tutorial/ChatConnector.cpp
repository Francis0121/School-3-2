// ChatConnector.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "tutorial.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CChatConnector, CDialog)

CChatConnector::CChatConnector(CWnd* pParent /*=NULL*/)
	: CDialog(CChatConnector::IDD, pParent)
{

}

CChatConnector::CChatConnector(CClientSocket *pclient_socket, TCHAR *id)
	: CDialog(CChatConnector::IDD, NULL){
	m_client_socket = pclient_socket;
	p_id = id;
}


CChatConnector::~CChatConnector()
{
}

void CChatConnector::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, strId);
	DDX_Control(pDX, IDC_IPADDRESS, strIP);
	DDX_Control(pDX, IDC_EDIT_PORT, strPort);
}


BEGIN_MESSAGE_MAP(CChatConnector, CDialog)
	ON_BN_CLICKED(IDOK, &CChatConnector::OnBnClickedOk)
END_MESSAGE_MAP()


// CChatConnector �޽��� ó�����Դϴ�.


void CChatConnector::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TCHAR t_ip[20];
	TCHAR t_port[10];

	int port;
	strId.GetWindowText(p_id, 20);
	strIP.GetWindowText(t_ip, 20);
	strPort.GetWindowText(t_port, 10);
#ifdef UNICODE
	port = _wtoi(t_port);
#else
	port = atoi(t_port);
#endif

	if(!m_client_socket->Create()){
		AfxMessageBox(_T("���� ������ �����߽��ϴ�,"));
		return;
	}

	if(!m_client_socket->Connect(t_ip, port)){
		AfxMessageBox(_T("������ ������ �����Ͽ����ϴ�"));
		m_client_socket->Close();
		return;
	}
	CDialog::OnOK();
}
