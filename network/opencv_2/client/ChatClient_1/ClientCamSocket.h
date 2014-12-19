#pragma once

// CClientCamSocket 명령 대상입니다.
class CChatClientDlg;

class CClientCamSocket : public CSocket
{
public:
	CChatClientDlg *m_pCChatClient;
	CClientCamSocket();
	virtual ~CClientCamSocket();
	virtual void OnSend(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void setdlg(CChatClientDlg *pChatClientDlg);
};


