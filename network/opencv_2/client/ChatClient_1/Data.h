#pragma once


// CData

class CData : public CWnd
{
	DECLARE_DYNAMIC(CData)

public:
	CPoint m_ptPos;
	COLORREF m_crColor;
	int m_line;

	CData();
	CData(CPoint ptPos, COLORREF crClor, int m_line);
	CData(CData& data);
	virtual ~CData();

protected:
	DECLARE_MESSAGE_MAP()
};


