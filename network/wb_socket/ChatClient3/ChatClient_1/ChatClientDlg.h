
// ChatClientDlg.h : 헤더 파일
//

#pragma once
#include "ClientSocket.h"
#include "ClientWhiteBoardSocket.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "ImageView.h"

// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatClientDlg(CClientSocket *pclient_socket, CClientWhiteBoardSocket *pclient_whiteBoard_socket, TCHAR *id);
	CChatClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
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

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ChatClient_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
