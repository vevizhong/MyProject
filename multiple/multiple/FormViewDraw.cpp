// FormViewDraw.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "multiple.h"
#include "FormViewDraw.h"


// CFormViewDraw

IMPLEMENT_DYNCREATE(CFormViewDraw, CFormView)

CFormViewDraw::CFormViewDraw()
	: CFormView(CFormViewDraw::IDD)
{

}

CFormViewDraw::~CFormViewDraw()
{
}

void CFormViewDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewDraw, CFormView)
END_MESSAGE_MAP()


// CFormViewDraw ���

#ifdef _DEBUG
void CFormViewDraw::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormViewDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewDraw ��Ϣ�������
void CFormViewDraw::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowTextW(_T("��ͼ"));
}
