// ClientSocket.cpp : 구현 파일입니다.
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

// CClientSocket 멤버 함수


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessReceive();
	CSocket::OnClose(nErrorCode);
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pCChatClient->ProcessClose();
	CSocket::OnReceive(nErrorCode);
}
