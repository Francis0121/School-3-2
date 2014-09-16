#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CChatConnector 대화 상자입니다.

class CChatConnector : public CDialog
{
	DECLARE_DYNAMIC(CChatConnector)

public:
	CChatConnector(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChatConnector();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit strId;
	CEdit strPort;
	CIPAddressCtrl strIP;
};
