#pragma once

// CClientSocket ��� ����Դϴ�.

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


