
// ChatClientDlg.h : 헤더 파일
//

#pragma once
#include "ClientSocket.h"
#include "ImageSocket.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "ImageView.h"

// ~ Async를 위한 header 추가
#include "afxsock.h"

// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	// ~ image client socket 추가
	CChatClientDlg(CClientSocket *pclient_socket, CImageSocket *pimage_socket, TCHAR *id);
	CChatClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CClientSocket *m_client_socket;
	CImageSocket *m_image_socket;
	TCHAR *p_id;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

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
	CEdit edit_text;
	CRichEditCtrl edit_list;
	afx_msg void OnBnClickedOk();
	void ProcessReceive(void);
	void ProcessClose(void);
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButtonColor();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonDelete();
// 03 tutorial 추가
	CCreateContext m_context;
	ImageView *m_pView;
	COLORREF m_crCurColor;
	COLORREF getColor(){
		return m_crCurColor;
	}
};
