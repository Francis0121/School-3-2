#pragma once

// CClientSocket ��� ����Դϴ�.
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


