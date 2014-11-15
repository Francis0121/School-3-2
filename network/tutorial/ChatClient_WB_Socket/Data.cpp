// Data.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "Data.h"



// CData

CData::CData()
{
}

CData::~CData()
{
}

CData::CData(CPoint ptPos, COLORREF crColor, int line){
	m_crColor = crColor;
	m_ptPos = ptPos;
	m_line = line;
}

CData::CData(CData& data){
	m_crColor = data.m_crColor;
	m_ptPos = data.m_ptPos;
	m_line = data.m_line;
}

void CData::setMode(int mode){
	m_mode = mode;
}

void CData::setImageSize(int imageSize){
	m_imageSize = imageSize;
}

void CData::setImage(char *pimage, int size){
	memcpy(m_image, pimage, size);
	m_imageSize = size;
}

// CData 멤버 함수
void CData::Serialize( CArchive& archive )
{
    // now do the stuff for our specific class
    if( archive.IsStoring() ){
		switch(m_mode){
		case NET_POINT:
			archive << (int) NET_POINT;
			archive << m_crColor;
			archive << m_ptPos.x;
			archive << m_ptPos.y;
			archive << m_line;
			break;
		case NET_ERASE:
			archive << (int) NET_ERASE;
			break;
		case NET_IMAGE:
			archive << (int) NET_IMAGE;
			archive << m_imageSize;
			archive << m_image;
		default:
			break;
		}
	}
    else{
		archive >> m_mode;
		switch(m_mode){
		case NET_POINT:
			archive >> m_crColor;
			archive >> m_ptPos.x; 
			archive >> m_ptPos.y;
			archive >> m_line;
			break;
		case NET_ERASE:
			break;
		case NET_IMAGE:
			archive >> m_imageSize;
			archive >> *m_image;
			break;
		}
	}
}