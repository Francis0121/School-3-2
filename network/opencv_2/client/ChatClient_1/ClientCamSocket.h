#pragma once

// CClientCamSocket ��� ����Դϴ�.
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


