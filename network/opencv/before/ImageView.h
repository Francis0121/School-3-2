#pragma once
#include "Data.h"
#include "ImageSocket.h"
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
	CImageSocket *m_image_socket;
	CPtrList m_dataList;
	Image *image;
	int printImage;

	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void SetView(CChatClientDlg *pCChatClient);
	void PicView();
	void ProcessErase(void);
	void ProcessImage(void);
	void ProcessPoint(CData *pData);
	void ProcessClose(void);
	void setSocket(CImageSocket *pimage_socket);

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
	virtual BOOL DestroyWindow();
};


