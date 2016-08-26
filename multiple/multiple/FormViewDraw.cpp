// FormViewDraw.cpp : 实现文件
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


// CFormViewDraw 诊断

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


// CFormViewDraw 消息处理程序
void CFormViewDraw::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowTextW(_T("绘图"));
}
