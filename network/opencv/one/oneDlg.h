
// oneDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "CamSocket.h"
// ~ opencv 추가
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "./CvvImage.h"

// ConeDlg 대화 상자
class ConeDlg : public CDialogEx
{
// 생성입니다.
public:
	ConeDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ONE_DIALOG };

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
