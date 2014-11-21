#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ClientSocket.h"
#include "ImageSocket.h"
#include "CamSocket.h"

// CChatConnector ��ȭ �����Դϴ�.

class CChatConnector : public CDialogEx
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CClientSocket *pclient_socket, CImageSocket *pimage_socket, CCamSocket *pcam_socket,  TCHAR *id);
	CChatConnector(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChatConnector();
	TCHAR *p_id;
	CClientSocket *m_client_socket;
	CImageSocket *m_image_socket;
	CCamSocket *m_cam_socket;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_id;
	CEdit edit_port;
	CIPAddressCtrl edit_ip;
	afx_msg void OnBnClickedOk();
};
