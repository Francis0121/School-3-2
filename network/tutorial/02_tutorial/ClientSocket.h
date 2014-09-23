#pragma once

// CClientSocket 명령 대상입니다.
class CtutorialDlg;

class CClientSocket : public CSocket
{
public:
	CtutorialDlg *m_pCChatClient;
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void setdlg(CtutorialDlg *pChatClientDlg);
};


