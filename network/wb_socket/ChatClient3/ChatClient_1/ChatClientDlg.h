
// ChatClientDlg.h : ��� ����
//

#pragma once
#include "ClientSocket.h"
#include "ClientWhiteBoardSocket.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "ImageView.h"

// CChatClientDlg ��ȭ ����
class CChatClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChatClientDlg(CClientSocket *pclient_socket, CClientWhiteBoardSocket *pclient_whiteBoard_socket, TCHAR *id);
	CChatClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CClientSocket *m_client_socket;
	CClientWhiteBoardSocket	*m_client_whiteBoard_socket ;

	TCHAR *p_id;
	int imageCount;
	CCreateContext	m_context;

	ImageView	*m_pView;
	COLORREF	m_crCurColor;
	COLORREF getColor()
	{
		return m_crCurColor;
	}

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ChatClient_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit edt_text;
	CRichEditCtrl edt_list;
	void ProcessRecieve();
	void ProcessRecievePoint();
	void ProcessClose();
	void wrap();
	void CChatClientDlg::ImageDraw();
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
