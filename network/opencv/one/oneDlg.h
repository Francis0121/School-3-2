
// oneDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "CamSocket.h"
// ~ opencv �߰�
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "./CvvImage.h"

// ConeDlg ��ȭ ����
class ConeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	ConeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ONE_DIALOG };

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
	// ~ Socket
	CCamSocket *m_cam_socket;
	// ~ Dlg member varaiable
	CStatic m_ctrlPicMe;
	CStatic m_ctrlPcYou;
	// ~ Opencv member variable
	IplImage* m_Image;
	CvvImage m_cImage;
	cv::Mat m_mMat;
	CvCapture* m_capture;
	// ~ Cam function
	void CamReceive(void);
	void CamClose(void);
	// ~ Event function
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
