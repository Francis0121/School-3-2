// ClientWhiteBoardSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ClientWhiteBoardSocket.h"
#include "ClientSocket.h"
#include "ChatClientDlg.h"

// CClientWhiteBoardSocket

CClientWhiteBoardSocket::CClientWhiteBoardSocket()
{
}

CClientWhiteBoardSocket::~CClientWhiteBoardSocket()
{
}


// CClientWhiteBoardSocket ��� �Լ�
void CClientWhiteBoardSocket::setdlg(CChatClientDlg *pChatClientDlg)
{
	m_pCChatClient = pChatClientDlg;
}

void CClientWhiteBoardSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	AsyncSelect(NULL);
	m_pCChatClient->ProcessRecievePoint();
	AsyncSelect(FD_READ|FD_WRITE);
	CSocket::OnReceive(nErrorCode);
}


void CClientWhiteBoardSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pCChatClient->ProcessClose();
	CSocket::OnClose(nErrorCode);
}
