
// tutorial.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CtutorialApp:
// �� Ŭ������ ������ ���ؼ��� tutorial.cpp�� �����Ͻʽÿ�.
//

class CtutorialApp : public CWinApp
{
public:
	CtutorialApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CtutorialApp theApp;