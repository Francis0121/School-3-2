// ClientCamSocket.cpp : 구현 파일입니다.
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

// CClientCamSocket 멤버 함수


void CClientCamSocket::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->CamRecieve();
	CSocket::OnSend(nErrorCode);
}


void CClientCamSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessClose();
	CSocket::OnReceive(nErrorCode);
}
