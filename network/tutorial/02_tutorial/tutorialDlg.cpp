
// tutorialDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "tutorial.h"
#include "tutorialDlg.h"
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


// CtutorialDlg 대화 상자




CtutorialDlg::CtutorialDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtutorialDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CtutorialDlg::CtutorialDlg(CClientSocket *pclient_socket, TCHAR *id)
	: CDialogEx(CtutorialDlg::IDD, NULL){
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_client_socket = pclient_socket;
	m_client_socket->setdlg(this);
	p_id = id;
}

void CtutorialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, strMessage);
	DDX_Control(pDX, IDC_RICHEDIT_MESSAGE, listMessage);
}

BEGIN_MESSAGE_MAP(CtutorialDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtutorialDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtutorialDlg 메시지 처리기

BOOL CtutorialDlg::OnInitDialog()
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
	listMessage.ReplaceSel("Welcome to chatting room\n");
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CtutorialDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtutorialDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CtutorialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtutorialDlg::OnBnClickedOk()
{
	TCHAR strBuf[100];
	TCHAR temp[100];
	
	strMessage.GetWindowText(strBuf, 100);

	int nlen;
	nlen = listMessage.GetWindowTextLength();
	listMessage.SetSel(nlen, nlen);
	sprintf(temp, "%s : %s\n", p_id, strBuf);
	m_client_socket->Send(temp, strlen(temp));

	listMessage.ReplaceSel(temp);
	strMessage.SetWindowText(_T(""));
}

void CtutorialDlg::ProcessReceive(void){
	int nRead;
	int nlen;
	TCHAR rcvBuffer[1024];
	CString strBuffer = _T("");

	nRead = m_client_socket->Receive(rcvBuffer, 1024);
	strBuffer = rcvBuffer;

	nlen = listMessage.GetWindowTextLength();
	listMessage.SetSel(nlen, nlen);
	listMessage.ReplaceSel(strBuffer.Left(nRead));
}

void CtutorialDlg::ProcessClose(void){
	int nlen;
	nlen = listMessage.GetWindowTextLengthA();
	listMessage.SetSel(nlen, nlen);
	listMessage.ReplaceSel(_T("서버가 종료되었습니다.\n"));

	m_client_socket->Close();
	delete m_client_socket;

	nlen = listMessage.GetWindowTextLength();
	listMessage.SetSel(nlen, nlen);
	listMessage.ReplaceSel(_T("연결 종료\n"));
}

BOOL CtutorialDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_client_socket->Close();
	delete m_client_socket;

	return CDialogEx::DestroyWindow();
}
