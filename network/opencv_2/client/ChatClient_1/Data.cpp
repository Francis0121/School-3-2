// Data.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Data.h"


// CData

IMPLEMENT_DYNAMIC(CData, CWnd)

CData::CData()
{

}
CData::CData(CPoint ptPos,COLORREF crColor, int line)
{
	m_crColor = crColor;
	m_ptPos = ptPos;
	m_line = line;
}

CData::CData(CData &data)
{
	m_crColor = data.m_crColor;
	m_ptPos = data.m_ptPos;
	m_line = data.m_line;
}

CData::~CData()
{
}


BEGIN_MESSAGE_MAP(CData, CWnd)
END_MESSAGE_MAP()



// CData �޽��� ó�����Դϴ�.


