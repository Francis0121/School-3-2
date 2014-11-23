// CamSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "CamSocket.h"


// CCamSocket

CCamSocket::CCamSocket()
{
}

CCamSocket::~CCamSocket()
{
}


// CCamSocket 멤버 함수


void CCamSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CSocket::OnClose(nErrorCode);
}


int CCamSocket::Receive(void* lpBuf, int nBufLen, int nFlags)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CSocket::Receive(lpBuf, nBufLen, nFlags);
}
