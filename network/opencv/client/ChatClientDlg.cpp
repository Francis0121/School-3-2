
// ChatClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

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


// CChatClientDlg 대화 상자




CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CChatClientDlg::CChatClientDlg(CClientSocket *pclient_socket, CImageSocket *pimage_socket, CCamSocket *pcam_socket, TCHAR *id)
	: CDialogEx(CChatClientDlg::IDD, NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_client_socket = pclient_socket;
	m_client_socket->setdlg(this);
	// ~ image Client 추가
	m_image_socket = pimage_socket;
	// ~ cam 추가
	m_cam_socket = pcam_socket;
	m_cam_socket->setdlg(this);
	p_id = id;
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_text);
	DDX_Control(pDX, IDC_RICHEDIT21, edit_list);
	DDX_Control(pDX, IDC_CAM_ME, m_ctrPicMe);
	DDX_Control(pDX, IDC_CAM_YOU, m_ctrlPicYou);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CChatClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CChatClientDlg::OnBnClickedButtonColor)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CChatClientDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CChatClientDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_CAM_START, &CChatClientDlg::OnBnClickedCamStart)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CChatClientDlg 메시지 처리기

BOOL CChatClientDlg::OnInitDialog()
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
	RECT r = {300, 12, 1000, 535};
	m_context.m_pNewViewClass = RUNTIME_CLASS(ImageView);
	m_pView = (ImageView*)((CFrameWnd*)this)->CreateView(&m_context);
	ASSERT(m_pView);
	m_pView->SetView(this);
	m_pView->OnInitialUpdate();
	m_pView->ShowWindow(SW_NORMAL);
	m_pView->MoveWindow(&r);
	// ~ m_image_socket에 view 
	m_pView->setSocket(m_image_socket);
	m_image_socket->setview(m_pView);

	CSocketFile file(m_image_socket);
	CArchive arIn(&file, CArchive::load);
	m_image_socket->setArchive(&arIn);

	// ~ opencv cam 
	m_capture = cvCreateCameraCapture(0);
	if(!m_capture)
		AfxMessageBox(_T("해당하는 캠 장치가 없습니다."));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatClientDlg::OnPaint()
{

	if (IsIconic())
	{
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
	}
	else
	{
		CPaintDC dc(this);

		CDC *pDC;
		CRect cam_rect;
		
		pDC = m_ctrPicMe.GetDC();
		m_ctrPicMe.GetClientRect(cam_rect);

		m_cImage.CopyOf(m_Image);
		m_cImage.DrawToHDC(pDC->m_hDC, cam_rect);

		if(!m_ImageYou){
			pDC = m_ctrlPicYou.GetDC();
			m_ctrlPicYou.GetClientRect(cam_rect);

			m_cImageYou.CopyOf(m_ImageYou);
			m_cImageYou.DrawToHDC(pDC->m_hDC, cam_rect);
		}

		ReleaseDC(pDC);


		// ~ imencode 가 계속적인 에러로 file로 output
		/*std::vector<int> params;
		params.push_back(CV_IMWRITE_JPEG_QUALITY);
		params.push_back(30);
		cv::Mat mat(m_Image);
		std::vector<uchar> outbuf;
		cv::imencode("jpg", mat, outbuf, params);
		int bytelen = outbuf.size();
		m_cam_socket->Send(outbuf.data(), bytelen);*/

		// ~ Extract Image Test
		int p[3];
		p[0] = CV_IMWRITE_JPEG_QUALITY;
		p[1] = 10;
		p[2] = 0;
		cvSaveImage("0.jpg", m_Image, p);

		IplImage *frame = cvLoadImage("0.jpg");
		if(frame){
			int bufSize = frame->imageSize;
			int width = frame->width;
			int height = frame->height;
			m_cam_socket->Send(&bufSize, 4);
			m_cam_socket->Send(&width, 4);
			m_cam_socket->Send(&height, 4);
			m_cam_socket->Send(frame->imageData, bufSize);
		}


		// CDialog::OnPaint()를 호출하지 마세요.
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChatClientDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TCHAR strBuf[100];
	TCHAR temp[100];

	edit_text.GetWindowText(strBuf, 100);

	int nlen;
	nlen = edit_list.GetWindowTextLength();
	edit_list.SetSel(nlen, nlen);
	sprintf(temp, "%s : %s\n", p_id, strBuf);
	m_client_socket->Send(temp, strlen(temp));

	edit_list.ReplaceSel(temp);
	edit_text.SetWindowTextA(_T(""));

}

void CChatClientDlg::ProcessReceive(void){
	int nRead;
	int nlen;
	TCHAR rcvBuffer[1024];
	CString strBuffer = _T("");

	nRead = m_client_socket->Receive(rcvBuffer, 1024);
	strBuffer = rcvBuffer;

	nlen = edit_list.GetWindowTextLength();
	edit_list.SetSel(nlen, nlen);
	edit_list.ReplaceSel(strBuffer.Left(nRead));
}

void CChatClientDlg::ProcessClose(void){
	int nlen;
	nlen = edit_list.GetWindowTextLength();
	edit_list.SetSel(nlen, nlen);
	edit_list.ReplaceSel(_T("서버가 종료되었습니다.\n"));

	m_client_socket->Close();
	delete m_client_socket;

	nlen = edit_list.GetWindowTextLength();
	edit_list.SetSel(nlen, nlen);
	edit_list.ReplaceSel(_T("연결 종료\n"));
}

BOOL CChatClientDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_client_socket->Close();
	delete m_client_socket;
	return CDialogEx::DestroyWindow();
}


void CChatClientDlg::OnBnClickedButtonColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if(dlg.DoModal() != IDOK) return;
	m_crCurColor = dlg.GetColor();
}


void CChatClientDlg::OnBnClickedButtonLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pView->PicView();
}


void CChatClientDlg::OnBnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pView->ProcessErase();

	CData *pData = new CData();
	pData->setMode(NET_ERASE);
	CSocketFile file(m_image_socket);
	CArchive arOut(&file, CArchive::store);
	pData->Serialize(arOut);

	Invalidate(TRUE);
}

void CChatClientDlg::OnBnClickedCamStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 30, NULL); // Occur WM_TIMER Message 
}


void CChatClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.	
	cvGrabFrame(m_capture); 
	m_Image = cvRetrieveFrame(m_capture);
	Invalidate(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CChatClientDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);
	
	if(m_capture)
		cvReleaseCapture(&m_capture);
}

void CChatClientDlg::CamReceive(void){

	int bufSize;
	m_cam_socket->Receive(&bufSize, 4);
	int width;
	m_cam_socket->Receive(&width, 4);
	int height;
	m_cam_socket->Receive(&height, 4);
	char *buf;
	buf = (char *) malloc(bufSize);

	int i = 0;
	int receiveData = 0;
	while(receiveData < bufSize){
		int readSize = bufSize - receiveData < 2048 ? bufSize - receiveData : 2048;
		int read = m_cam_socket->Receive(buf + (i++ * 2048), readSize);
		receiveData += read;
	}

	CvSize size;
	size.height = width;
	size.width = height;
   
	m_ImageYou = cvCreateImageHeader(size, IPL_DEPTH_8U, 3);
	m_ImageYou->imageData = buf;

	Invalidate(FALSE);
}

void CChatClientDlg::CamClose(void){
	m_cam_socket->Close();
	delete m_cam_socket;
}