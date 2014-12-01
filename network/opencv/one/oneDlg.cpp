
// oneDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "one.h"
#include "oneDlg.h"
#include "afxdialogex.h"
#include "CamSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ConeDlg 대화 상자




ConeDlg::ConeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ConeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ConeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ME, m_ctrlPicMe);
	DDX_Control(pDX, IDC_STATIC_YOU, m_ctrlPcYou);
}

BEGIN_MESSAGE_MAP(ConeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &ConeDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &ConeDlg::OnBnClickedButtonCancel)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// ConeDlg 메시지 처리기

BOOL ConeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// ~ init opencv cam
	m_capture = cvCreateCameraCapture(0);
	if(!m_capture)
		AfxMessageBox(_T("해당하는 캠 장치가 없습니다."));
	// ~ init client
	m_cam_socket = new CCamSocket();
	TCHAR t_ip[20] = _T("127.0.0.1");
	TCHAR t_port[10] = _T("9000");
	int port;
#ifdef UNICODE
	port = _wtoi(t_port);
#else
	port = atoi(t_port);
#endif
	if(!m_cam_socket->Create()){
		AfxMessageBox(_T("소켓 생성을 실패했습니다"));
	}

	if(!m_cam_socket->Connect(t_ip, port)){
		AfxMessageBox(_T("서버와 연결을 실패하였습니다"));
		m_cam_socket->Close();
	}else{
		AfxMessageBox(_T("서버와 연결을 성공하였습니다"));
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void ConeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void ConeDlg::OnPaint()
{
	if (IsIconic()){
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}else	{
		CPaintDC dc(this);

		CDC *pDC;
		CRect cam_rect;
		
		pDC = m_ctrlPicMe.GetDC();
		m_ctrlPicMe.GetClientRect(cam_rect);

		m_cImage.CopyOf(m_Image);
		m_cImage.DrawToHDC(pDC->m_hDC, cam_rect);

		ReleaseDC(pDC);

		std::vector<int> params;
		params.push_back(CV_IMWRITE_JPEG_QUALITY);
		params.push_back(30);
		cv::Mat mat(m_Image);
		std::vector<uchar> outbuf;
		cv::imencode(".jpg", mat, outbuf, params);
		int bytelen = outbuf.size();
		m_cam_socket->Send(outbuf.data(), bytelen);

		//CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR ConeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ConeDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 30, NULL); // Occur WM_TIMER Message 
}


void ConeDlg::OnBnClickedButtonCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(1);
	if(m_capture)
		cvReleaseCapture(&m_capture);
}


void ConeDlg::OnTimer(UINT_PTR nIDEvent){
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	cvGrabFrame(m_capture); 
	m_Image = cvRetrieveFrame(m_capture);
	Invalidate(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void ConeDlg::OnDestroy(){
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);
	if(m_capture)
		cvReleaseCapture(&m_capture);
	
	m_cam_socket->Close();
	delete m_cam_socket;

	CDialogEx::OnDestroy();
}

// ~ Cam
void ConeDlg::CamReceive(void){

}

void ConeDlg::CamClose(void){

}