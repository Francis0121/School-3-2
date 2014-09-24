// ChatConnector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChatConnector, CDialogEx)

CChatConnector::CChatConnector(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatConnector::IDD, pParent)
{

}

CChatConnector::~CChatConnector()
{
}

void CChatConnector::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_id);
	DDX_Control(pDX, IDC_IPADDRESS1, edit_ip);
	DDX_Control(pDX, IDC_EDIT2, edit_port);
}


BEGIN_MESSAGE_MAP(CChatConnector, CDialogEx)
END_MESSAGE_MAP()


// CChatConnector 메시지 처리기입니다.
