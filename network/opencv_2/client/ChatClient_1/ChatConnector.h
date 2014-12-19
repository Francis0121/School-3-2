#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ClientSocket.h"
#include "ClientWhiteBoardSocket.h"
#include "ClientCamSocket.h"

// CChatConnector ��ȭ �����Դϴ�.

class CChatConnector : public CDialogEx
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CClientSocket *pclient_socket, CClientWhiteBoardSocket *pclient_whiteBoard_socket, CClientCamSocket *pcam_socket, TCHAR *id);
	CChatConnector(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChatConnector();
	TCHAR *p_id;
	CClientSocket *m_client_socket;
	CClientWhiteBoardSocket	*m_client_whiteBoard_socket;
	CClientCamSocket *m_cam_socket;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit edt_id;
	CEdit edt_port;
	CIPAddressCtrl edt_ip;
};
