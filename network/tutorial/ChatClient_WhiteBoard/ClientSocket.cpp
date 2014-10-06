// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ClientSocket.h"
#include "ChatClientDlg.h"

// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�

void CClientSocket::setdlg(CChatClientDlg *pChatClientDlg){
	m_pCChatClient = pChatClientDlg;
}

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessClose();
	CSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode){
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessReceive();
	CSocket::OnReceive(nErrorCode);
}
