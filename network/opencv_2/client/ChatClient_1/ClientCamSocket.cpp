// ClientCamSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ClientCamSocket.h"
#include "ChatClientDlg.h"

// CClientCamSocket

CClientCamSocket::CClientCamSocket()
{
}

CClientCamSocket::~CClientCamSocket()
{
}

void CClientCamSocket::setdlg(CChatClientDlg *pChatClientDlg)
{
	m_pCChatClient = pChatClientDlg;
}

// CClientCamSocket ��� �Լ�


void CClientCamSocket::OnSend(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->CamRecieve();
	CSocket::OnSend(nErrorCode);
}


void CClientCamSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessClose();
	CSocket::OnReceive(nErrorCode);
}
