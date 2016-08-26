// FormViewCalculate.cpp : 实现文件
//

#include "stdafx.h"
#include "multiple.h"
#include "FormViewCalculate.h"


// CFormViewCalculate

IMPLEMENT_DYNCREATE(CFormViewCalculate, CFormView)

CFormViewCalculate::CFormViewCalculate()
	: CFormView(CFormViewCalculate::IDD)
{

}

CFormViewCalculate::~CFormViewCalculate()
{
}

void CFormViewCalculate::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewCalculate, CFormView)
END_MESSAGE_MAP()


// CFormViewCalculate 诊断

#ifdef _DEBUG
void CFormViewCalculate::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormViewCalculate::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewCalculate 消息处理程序
void CFormViewCalculate::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowTextW(_T("计算"));
}