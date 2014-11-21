#pragma once

// CCamSocket 명령 대상입니다.
class CChatClientDlg;

class CCamSocket : public CSocket
{
public:
	CChatClientDlg *m_pCChatClient;
	CCamSocket();
	virtual ~CCamSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void setdlg(CChatClientDlg *pChatClientDlg);
};


