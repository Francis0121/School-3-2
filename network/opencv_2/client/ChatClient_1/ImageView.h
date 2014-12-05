#pragma once
#include "Data.h"
class CChatClientDlg;

// ImageView ���Դϴ�.

class ImageView : public CView
{
	DECLARE_DYNCREATE(ImageView)

protected:
	ImageView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~ImageView();

public:
	CChatClientDlg *m_CChatClient;
	CPtrList m_dataList;
	Image *image;
	int printImage;

	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void SetView(CChatClientDlg *pCChatClient);
	void PicView();
	void ProcessErase();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};


