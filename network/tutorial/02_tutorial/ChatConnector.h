#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ClientSocket.h"

// CChatConnector ��ȭ �����Դϴ�.

class CChatConnector : public CDialog
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CClientSocket *pclient_socket, TCHAR *id);
	CChatConnector(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChatConnector();
	TCHAR *p_id;
	CClientSocket *m_client_socket;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit strId;
	CEdit strPort;
	CIPAddressCtrl strIP;
	afx_msg void OnBnClickedOk();
};
