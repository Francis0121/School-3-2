// ChatConnector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "tutorial.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChatConnector, CDialog)

CChatConnector::CChatConnector(CWnd* pParent /*=NULL*/)
	: CDialog(CChatConnector::IDD, pParent)
{

}

CChatConnector::~CChatConnector()
{
}

void CChatConnector::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID, strId);
	DDX_Control(pDX, IDC_IPADDRESS, strIP);
	DDX_Control(pDX, IDC_EDIT_PORT, strPort);
}


BEGIN_MESSAGE_MAP(CChatConnector, CDialog)
END_MESSAGE_MAP()


// CChatConnector 메시지 처리기입니다.
