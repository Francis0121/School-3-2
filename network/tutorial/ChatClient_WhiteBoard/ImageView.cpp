// ImageView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ImageView.h"
#include "ChatClientDlg.h"


// ImageView

IMPLEMENT_DYNCREATE(ImageView, CView)

ImageView::ImageView()
{
	image = NULL;
	printImage = FALSE;
}

ImageView::~ImageView()
{
}

BEGIN_MESSAGE_MAP(ImageView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ImageView �׸����Դϴ�.

void ImageView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// ImageView �����Դϴ�.

#ifdef _DEBUG
void ImageView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void ImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// ImageView �޽��� ó�����Դϴ�.

void ImageView::SetView(CChatClientDlg *pCChatClient){
	m_CChatClient = pCChatClient;
}

void ImageView::ProcessErase(){
	image = NULL;
	m_dataList.RemoveAll();
	Invalidate(TRUE);
}

void ImageView::PicView(){
	CFileDialog fileDialog(TRUE, NULL, NULL, 0, "�׸�����|*.jpg;*.jpeg*.bmp;*.png;*.gif|Bitmap(*.bmp)|*.bmp|Jpeg Image (*.jpg, *.jpeg)|*.jpg;*.jpeg|All Files(*.*)|*.*||");
	if(fileDialog.DoModal() == IDOK){
		CFileStatus fs;
		CString filepath = fileDialog.GetPathName();
		if(!CFile::GetStatus(filepath, fs))
			return;
		WCHAR wtext[200] = {0};
		MultiByteToWideChar(CP_ACP, 0, filepath, -1, wtext, 200);
		image = Image::FromFile(wtext);
		printImage =TRUE;
		Invalidate(FALSE);
	}
}

void ImageView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetCapture();
	CData *pData = new CData(point, m_CChatClient->getColor(), FALSE);
	m_dataList.AddTail(pData);
	printImage = FALSE;
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}


void ImageView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void ImageView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(!GetCapture()) return;
	//m_Data.Add(point);
	CData *pData = new CData(point, m_CChatClient->getColor(), TRUE);
	m_dataList.AddTail(pData);
	printImage = FALSE;
	Invalidate(FALSE);
	
	CView::OnMouseMove(nFlags, point);
}


void ImageView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	if(image != NULL && printImage == TRUE){
		Graphics g(this->GetDC()->m_hDC);
		CRect m_rect;

		GetWindowRect(m_rect);
		ScreenToClient(m_rect);

		g.DrawImage(image, m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height());
		g.~Graphics();
	}

	for(POSITION pos = m_dataList.GetHeadPosition(); pos!= NULL; ){
		CData *pData = (CData *)(m_dataList.GetNext(pos));
		CPen pen, *pOldPen;
		pen.CreatePen(PS_SOLID, 2, pData->m_crColor);
		pOldPen = dc.SelectObject(&pen);

		if(!pData->m_line){
			dc.MoveTo(pData->m_ptPos);
			dc.LineTo(pData->m_ptPos);
		}else if(pData->m_line && pos != NULL){
			CPoint temp = pData->m_ptPos;
			POSITION temppos = pos;
			pData = (CData *)(m_dataList.GetNext(pos));
			if(pData->m_line){
				dc.MoveTo(temp);
				dc.LineTo(pData->m_ptPos);
			}
			pos = temppos;
		}
		dc.SelectObject(pOldPen);
	}
}
