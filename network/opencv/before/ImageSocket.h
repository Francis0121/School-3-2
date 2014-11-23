#pragma once

// CImageSocket 명령 대상입니다.
#define NET_ERASE 0x00001000
#define NET_POINT 0x00002000
#define NET_IMAGE 0x00003000

class ImageView;

class CImageSocket : public CSocket
{
public:
	ImageView *m_pImageView;
	CArchive *m_pArchive;
	CArchive *m_pArchiveOut;
	CImageSocket();
	virtual ~CImageSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	void setview(ImageView *pImageView);
	void setArchive(CArchive *pArchive);
	void setArchiveOut(CArchive *pArchiveOut);
	CArchive* getArchive();
	CArchive* getArchiveOut();
};


