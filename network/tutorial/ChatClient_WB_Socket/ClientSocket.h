#pragma once

// CClientSocket 명령 대상입니다.

class CChatClientDlg;

class CClientSocket : public CSocket
{
public:
	CChatClientDlg *m_pCChatClient;
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void setdlg(CChatClientDlg *pChatClientDlg);
};


