// ChatConnector.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector ��ȭ �����Դϴ�.

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


// CChatConnector �޽��� ó�����Դϴ�.
