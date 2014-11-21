#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ClientSocket.h"
#include "ImageSocket.h"
#include "CamSocket.h"

// CChatConnector 대화 상자입니다.

class CChatConnector : public CDialogEx
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CClientSocket *pclient_socket, CImageSocket *pimage_socket, CCamSocket *pcam_socket,  TCHAR *id);
	CChatConnector(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChatConnector();
	TCHAR *p_id;
	CClientSocket *m_client_socket;
	CImageSocket *m_image_socket;
	CCamSocket *m_cam_socket;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_id;
	CEdit edit_port;
	CIPAddressCtrl edit_ip;
	afx_msg void OnBnClickedOk();
};
