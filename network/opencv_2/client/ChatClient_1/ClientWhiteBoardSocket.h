#pragma once

// CClientWhiteBoardSocket ��� ����Դϴ�.

#pragma once

// CClientSocket ��� ����Դϴ�.
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
