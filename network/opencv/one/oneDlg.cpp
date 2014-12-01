
// oneDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "one.h"
#include "oneDlg.h"
#include "afxdialogex.h"
#include "CamSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// ConeDlg ��ȭ ����




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


// ConeDlg �޽��� ó����

BOOL ConeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ~ init opencv cam
	m_capture = cvCreateCameraCapture(0);
	if(!m_capture)
		AfxMessageBox(_T("�ش��ϴ� ķ ��ġ�� �����ϴ�."));
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
		AfxMessageBox(_T("���� ������ �����߽��ϴ�"));
	}

	if(!m_cam_socket->Connect(t_ip, port)){
		AfxMessageBox(_T("������ ������ �����Ͽ����ϴ�"));
		m_cam_socket->Close();
	}else{
		AfxMessageBox(_T("������ ������ �����Ͽ����ϴ�"));
	}

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void ConeDlg::OnPaint()
{
	if (IsIconic()){
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR ConeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ConeDlg::OnBnClickedButtonSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetTimer(1, 30, NULL); // Occur WM_TIMER Message 
}


void ConeDlg::OnBnClickedButtonCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);
	if(m_capture)
		cvReleaseCapture(&m_capture);
}


void ConeDlg::OnTimer(UINT_PTR nIDEvent){
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	cvGrabFrame(m_capture); 
	m_Image = cvRetrieveFrame(m_capture);
	Invalidate(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void ConeDlg::OnDestroy(){
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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