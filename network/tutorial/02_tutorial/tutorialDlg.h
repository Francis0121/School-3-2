
// tutorialDlg.h : ��� ����
//

#pragma once
#include "ClientSocket.h"
#include "afxwin.h"
#include "afxcmn.h"


// CtutorialDlg ��ȭ ����
class CtutorialDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CtutorialDlg(CClientSocket *pclient_socket, TCHAR *id);
	CtutorialDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CClientSocket *m_client_socket;
	TCHAR *p_id;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TUTORIAL_DIALOG };

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
	CEdit strMessage;
	CRichEditCtrl listMessage;
	afx_msg void OnBnClickedOk();

	void ProcessReceive(void);
	void ProcessClose(void);
	virtual BOOL DestroyWindow();
};
