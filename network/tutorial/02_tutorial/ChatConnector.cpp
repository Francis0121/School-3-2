// ChatConnector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "tutorial.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector 대화 상자입니다.

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


// CChatConnector 메시지 처리기입니다.


void CChatConnector::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox(_T("소켓 생성을 실패했습니다,"));
		return;
	}

	if(!m_client_socket->Connect(t_ip, port)){
		AfxMessageBox(_T("서버와 연결을 실패하였습니다"));
		m_client_socket->Close();
		return;
	}
	CDialog::OnOK();
}
