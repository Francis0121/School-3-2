#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CChatConnector ��ȭ �����Դϴ�.

class CChatConnector : public CDialog
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChatConnector();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit strId;
	CEdit strPort;
	CIPAddressCtrl strIP;
};
