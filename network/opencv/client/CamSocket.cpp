// CamSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "CamSocket.h"
#include "ChatClientDlg.h"

// CCamSocket

CCamSocket::CCamSocket()
{
}

CCamSocket::~CCamSocket()
{
}


// CCamSocket ��� �Լ�

void CCamSocket::setdlg(CChatClientDlg *pChatClientDlg){
	m_pCChatClient = pChatClientDlg;
}

void CCamSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->CamClose();
	CSocket::OnClose(nErrorCode);
}


void CCamSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->CamReceive();
	CSocket::OnReceive(nErrorCode);
}
