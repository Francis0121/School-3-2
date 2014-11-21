
// ChatClientDlg.h : ��� ����
//

#pragma once
#include "ClientSocket.h"
#include "ImageSocket.h"
#include "CamSocket.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "ImageView.h"
// ~ opencv �߰�
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "CvvImage.h"

// ~ Async�� ���� header �߰�
#include "afxsock.h"

// CChatClientDlg ��ȭ ����
class CChatClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	// ~ image client socket �߰�
	CChatClientDlg(CClientSocket *pclient_socket, CImageSocket *pimage_socket, CCamSocket *pcam_socket, TCHAR *id);
	CChatClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CClientSocket *m_client_socket;
	CImageSocket *m_image_socket;
	CCamSocket *m_cam_socket;
	TCHAR *p_id;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

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
	CEdit edit_text;
	CRichEditCtrl edit_list;
	afx_msg void OnBnClickedOk();
	void ProcessReceive(void);
	void ProcessClose(void);
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedButtonColor();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonDelete();
// 03 tutorial �߰�
	CCreateContext m_context;
	ImageView *m_pView;
	COLORREF m_crCurColor;
	COLORREF getColor(){
		return m_crCurColor;
	}
	// ~ Opencv Picture variable
	CStatic m_ctrPicMe;
	CStatic m_ctrlPicYou;
	// ~ Opencv ���� Member variable
	IplImage* m_Image;
	CvvImage m_cImage;
	CvCapture* m_capture;
	afx_msg void OnBnClickedCamStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
