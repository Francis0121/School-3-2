#pragma once

// CCamSocket 명령 대상입니다.
class ConeDlg;

class CCamSocket : public CSocket
{
public:
	ConeDlg *m_pConeDlg;
	CCamSocket();
	virtual ~CCamSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	void setdlg(ConeDlg *pConeDlg);
};


