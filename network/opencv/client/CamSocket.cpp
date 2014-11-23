// CamSocket.cpp : 구현 파일입니다.
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


// CCamSocket 멤버 함수

void CCamSocket::setdlg(CChatClientDlg *pChatClientDlg){
	m_pCChatClient = pChatClientDlg;
}

void CCamSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->CamClose();
	CSocket::OnClose(nErrorCode);
}


void CCamSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->CamReceive();
	CSocket::OnReceive(nErrorCode);
}
