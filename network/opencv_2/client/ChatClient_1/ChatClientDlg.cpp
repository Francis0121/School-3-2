
// ChatClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"
#include "ClientWhiteBoardSocket.h"
#include "Data.h"
#include <afxsock.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct PointData
{
	int id;
	CData data;
};
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

CChatClientDlg::CChatClientDlg(CClientSocket *pclient_socket, CClientWhiteBoardSocket *pclient_whiteBoard_socket, CClientCamSocket *pcam_socket, TCHAR *id)
	: CDialogEx(CChatClientDlg::IDD, NULL)
{
	imageCount = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_client_socket = pclient_socket;
	m_client_whiteBoard_socket = pclient_whiteBoard_socket;
	m_cam_socket = pcam_socket;
	m_client_socket->setdlg(this);
	m_client_whiteBoard_socket->setdlg(this);
	m_cam_socket->setdlg(this);
	p_id = id;
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edt_text);
	DDX_Control(pDX, IDC_RICHEDIT22, edt_list);
	DDX_Control(pDX, IDC_STATIC_SEND, m_ctrPicSend);
	DDX_Control(pDX, IDC_STATIC_RECEIVE, m_ctrPicRecv);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CChatClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CChatClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChatClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CChatClientDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CAM, &CChatClientDlg::OnBnClickedButtonCam)
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

	RECT r = {300,12,1000,535};
	m_context.m_pNewViewClass = RUNTIME_CLASS(ImageView);
	m_pView = (ImageView*)((CFrameWnd*)this)->CreateView(&m_context);
	ASSERT(m_pView);
	m_pView->SetView(this);
	m_pView->OnInitialUpdate();
	m_pView->ShowWindow(SW_NORMAL);
	m_pView->MoveWindow(&r);
	// opencv capture
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
		
		pDC = m_ctrPicSend.GetDC();
		m_ctrPicSend.GetClientRect(cam_rect);

		m_cImage.CopyOf(m_Image);
		m_cImage.DrawToHDC(pDC->m_hDC, cam_rect);

		ReleaseDC(pDC);
		//CDialogEx::OnPaint();
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

	edt_text.GetWindowText(strBuf, 100);

	int nlen;
	nlen = edt_list.GetWindowTextLength();
	edt_list.SetSel(nlen,nlen);
	sprintf(temp,"%s : %s\n",p_id, strBuf);
	m_client_socket->Send(temp,strlen(temp));

	edt_list.ReplaceSel(temp);
	edt_text.SetWindowText(_T(""));
}

void CChatClientDlg::ProcessRecieve()
{
	int nRead;
	int nlen;
	TCHAR rcvBuffer[1024];
	CString strBuffer =_T("");

	nRead = m_client_socket->Receive(rcvBuffer, 1024);
	strBuffer = rcvBuffer;
	nlen = edt_list.GetWindowTextLength();
	edt_list.SetSel(nlen,nlen);
	edt_list.ReplaceSel(strBuffer.Left(nRead));
}
void CChatClientDlg::ProcessClose()
{
	int nlen;
	nlen = edt_list.GetWindowTextLength();
	edt_list.SetSel(nlen,nlen);
	edt_list.ReplaceSel(_T("서버가 종료되었습니다.\n"));

	m_client_socket->Close();
	m_client_whiteBoard_socket->Close();
	delete m_client_socket;
	delete m_client_whiteBoard_socket;

	nlen = edt_list.GetWindowTextLength();
	edt_list.SetSel(nlen,nlen);
	edt_list.ReplaceSel(_T("연결 종료\n"));
}

void CChatClientDlg::ProcessRecievePoint()
{
	CData rcvData;
	int nRead,id;
	int size=0;
	CFile tmpFile1;
	m_client_whiteBoard_socket->Receive((char *)&id,sizeof(int));
	switch(id)
	{
	case NET_ERASE:
		m_pView->ProcessErase();
		break;
	case NET_POINT:
	{
		nRead = m_client_whiteBoard_socket->Receive((char *)&rcvData,sizeof(CData));
		CData *pData = new CData(rcvData.m_ptPos, rcvData.m_crColor, rcvData.m_line);
		m_pView->m_dataList.AddTail(pData);
		m_pView->printImage = FALSE;
		m_pView->Invalidate(FALSE);
		break;
	}
	case NET_IMAGE:
	{
		DWORD dwRead;
		byte *data = new byte[4096];
		char buf[10];
		m_client_whiteBoard_socket->Receive((char *)&size,sizeof(int));
		CString str = "tmpfile.tmp1";
		str.Delete(11,1);
		str = str + itoa(imageCount++,buf,10);
		
		CFile destFile(str, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);
		do
		{    
			dwRead= m_client_whiteBoard_socket->Receive(data, 4096);
			size = size - dwRead;
			destFile.Write(data, dwRead); 
		} while (size > 0);
		destFile.Close();
	
		CString filepath = "tmpfile.tmp";
		WCHAR wtext[200] = {0};
		MultiByteToWideChar(CP_ACP,0,str,-1,wtext,200);
		m_pView->image = Image::FromFile(wtext);
		m_pView->printImage = TRUE;
		m_pView->Invalidate(FALSE);
		break;
	}
	
	
	}

}
void CChatClientDlg::ImageDraw()
{
	m_pView->printImage = TRUE;
	m_pView->Invalidate(FALSE);
}

void CChatClientDlg::CamRecieve()
{

}

BOOL CChatClientDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_client_socket->Close();
	delete m_client_socket;

	return CDialogEx::DestroyWindow();
}


void CChatClientDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if(dlg.DoModal() != IDOK) return;
	m_crCurColor = dlg.GetColor();
}


void CChatClientDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pView->ProcessErase();
	int id = NET_ERASE;
	m_client_whiteBoard_socket->Send((char *)&id,sizeof(int));
	Invalidate(TRUE);
}


void CChatClientDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pView->PicView();
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
	KillTimer(1);
	if(m_capture)
		cvReleaseCapture(&m_capture);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChatClientDlg::OnBnClickedButtonCam()
{	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 30, NULL); // Occur WM_TIMER Message 
}
