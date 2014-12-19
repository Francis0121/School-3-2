#pragma once

// CClientWhiteBoardSocket 명령 대상입니다.

#pragma once

// CClientSocket 명령 대상입니다.
class CChatClientDlg;

class CClientWhiteBoardSocket : public CSocket
{
public:
	CChatClientDlg *m_pCChatClient;
	CClientWhiteBoardSocket();
	virtual ~CClientWhiteBoardSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	void setdlg(CChatClientDlg *pChatClientDlg);
};
