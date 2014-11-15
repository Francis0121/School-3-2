#pragma once

// CData 명령 대상입니다.
#define NET_ERASE 0x00001000
#define NET_POINT 0x00002000
#define NET_IMAGE 0x00003000

class CData : public CObject
{
public:
	CPoint m_ptPos;
	COLORREF m_crColor;
	int m_line;
	int m_mode;
	int m_imageSize;
	char m_image[200];
	CBitmap *m_pbitmap;
	CData();
	CData(CPoint ptPos, COLORREF crColor, int m_line);
	CData(CData& data);
	void setMode(int mode);
	void setImageSize(int image);
	void setImage(char *pimage, int size);
	void setBitmap(CBitmap *pbitmap);
	virtual ~CData();

	void Serialize( CArchive& archive );
};


