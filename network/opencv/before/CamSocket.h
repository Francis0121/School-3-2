#pragma once

// CCamSocket 명령 대상입니다.

class CCamSocket : public CSocket
{
public:
	CCamSocket();
	virtual ~CCamSocket();
	virtual void OnClose(int nErrorCode);
	virtual int Receive(void* lpBuf, int nBufLen, int nFlags = 0);
};


