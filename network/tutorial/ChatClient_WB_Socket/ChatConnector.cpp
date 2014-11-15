// ChatConnector.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CChatConnector, CDialogEx)

CChatConnector::CChatConnector(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatConnector::IDD, pParent)
{

}


CChatConnector::CChatConnector(CClientSocket *pclient_socket, CImageSocket *pimage_socket, TCHAR *id)
	: CDialogEx(CChatConnector::IDD, NULL)
{
	m_client_socket = pclient_socket;
	m_image_socket = pimage_socket;
	p_id = id;
}


CChatConnector::~CChatConnector()
{
}

void CChatConnector::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_id);
	DDX_Control(pDX, IDC_IPADDRESS1, edit_ip);
	DDX_Control(pDX, IDC_EDIT2, edit_port);
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
	edit_id.GetWindowText(p_id, 20);
	edit_ip.GetWindowText(t_ip, 20);
	edit_port.GetWindowText(t_port, 10);
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
	// ~ image socket �ϳ� �� ���� 
	port+=1;

	// ~ ������ ��� 0�� �ƴ� �� Return
	if(!m_image_socket->Create()){
		AfxMessageBox(_T("���� ������ �����߽��ϴ�,"));
		return; 
	}

	if(!m_image_socket->Connect(t_ip, port)){
		AfxMessageBox(_T("������ ������ �����Ͽ����ϴ�"));
		m_client_socket->Close();
		return;
	}

	CDialog::OnOK();
}
