// ImageSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ImageSocket.h"
#include "ImageView.h"

// CImageSocket

CImageSocket::CImageSocket()
{

}

CImageSocket::~CImageSocket()
{
}

void CImageSocket::setview(ImageView *pImageView){
	m_pImageView = pImageView;
}

void CImageSocket::setArchive(CArchive *pArchive){
	m_pArchive = pArchive;
}

void CImageSocket::setArchiveOut(CArchive *pArchiveOut){
	m_pArchiveOut = pArchiveOut;
}

CArchive* CImageSocket::getArchive(){
	return m_pArchive;
}

CArchive* CImageSocket::getArchiveOut(){
	return m_pArchiveOut;
}

// CImageSocket 멤버 함수

void CImageSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	AsyncSelect(0);
	CData *pData = new CData();

	CSocketFile file(this);
	CArchive arIn(&file, CArchive::load);
	pData->Serialize(arIn);

	switch(pData->m_mode){
	case NET_IMAGE:
		m_pImageView->ProcessImage();
		break;
	case NET_POINT:
		m_pImageView->ProcessPoint(pData);
		break;
	case NET_ERASE:
		m_pImageView->ProcessErase();
		break;
	default:
		break;
	}
	AsyncSelect(FD_READ | FD_WRITE);
	CSocket::OnReceive(nErrorCode);
}


void CImageSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pImageView->ProcessClose();
	CSocket::OnClose(nErrorCode);
}

