// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "tutorial.h"
#include "ClientSocket.h"
#include "tutorialDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

void CClientSocket::setdlg(CtutorialDlg *pChatClientDlg){
	m_pCChatClient = pChatClientDlg;
}

// CClientSocket ��� �Լ�


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessReceive();
	CSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessClose();
	CSocket::OnReceive(nErrorCode);
}
