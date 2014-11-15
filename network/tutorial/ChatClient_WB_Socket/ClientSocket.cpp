// ClientSocket.cpp : 구현 파일입니다.
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


// CClientSocket 멤버 함수

void CClientSocket::setdlg(CChatClientDlg *pChatClientDlg){
	m_pCChatClient = pChatClientDlg;
}

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessClose();
	CSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode){
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessReceive();
	CSocket::OnReceive(nErrorCode);
}
