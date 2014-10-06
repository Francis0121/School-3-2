#pragma once

// CData 명령 대상입니다.

class CData : public CObject
{
public:
	CPoint m_ptPos;
	COLORREF m_crColor;
	int m_line;
	CData();
	CData(CPoint ptPos, COLORREF crColor, int m_line);
	CData(CData& data);
	virtual ~CData();
};


