// ChatConnector.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "tutorial.h"
#include "ChatConnector.h"
#include "afxdialogex.h"


// CChatConnector ��ȭ �����Դϴ�.

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


// CChatConnector �޽��� ó�����Դϴ�.
