// ClientWhiteBoardSocket.cpp : 구현 파일입니다.
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


// CClientWhiteBoardSocket 멤버 함수
void CClientWhiteBoardSocket::setdlg(CChatClientDlg *pChatClientDlg)
{
	m_pCChatClient = pChatClientDlg;
}

void CClientWhiteBoardSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	AsyncSelect(NULL);
	m_pCChatClient->ProcessRecievePoint();
	AsyncSelect(FD_READ|FD_WRITE);
	CSocket::OnReceive(nErrorCode);
}


void CClientWhiteBoardSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessClose();
	CSocket::OnClose(nErrorCode);
}
