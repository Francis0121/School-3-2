// CamSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "one.h"
#include "CamSocket.h"
#include "oneDlg.h"

// CCamSocket

CCamSocket::CCamSocket()
{
}

CCamSocket::~CCamSocket()
{
}


// CCamSocket 멤버 함수
void CCamSocket::setdlg(ConeDlg *pConeDlg){
	m_pConeDlg = pConeDlg;
}

void CCamSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pConeDlg->CamReceive();
	CSocket::OnReceive(nErrorCode);
}


void CCamSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pConeDlg->CamClose();
	CSocket::OnClose(nErrorCode);
}
