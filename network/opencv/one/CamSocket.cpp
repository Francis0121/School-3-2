// CamSocket.cpp : ���� �����Դϴ�.
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


// CCamSocket ��� �Լ�
void CCamSocket::setdlg(ConeDlg *pConeDlg){
	m_pConeDlg = pConeDlg;
}

void CCamSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pConeDlg->CamReceive();
	CSocket::OnReceive(nErrorCode);
}


void CCamSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pConeDlg->CamClose();
	CSocket::OnClose(nErrorCode);
}
