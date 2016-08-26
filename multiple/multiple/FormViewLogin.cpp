// FormViewLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "multiple.h"
#include "FormViewLogin.h"


// CFormViewLogin

IMPLEMENT_DYNCREATE(CFormViewLogin, CFormView)

CFormViewLogin::CFormViewLogin()
	: CFormView(CFormViewLogin::IDD)
	, m_UserName(_T(""))
	, m_Password(_T(""))
{

}

CFormViewLogin::~CFormViewLogin()
{
}

void CFormViewLogin::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USER, m_UserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_Password);
}

BEGIN_MESSAGE_MAP(CFormViewLogin, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CFormViewLogin::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CFormViewLogin 诊断

#ifdef _DEBUG
void CFormViewLogin::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormViewLogin::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewLogin 消息处理程序

void CFormViewLogin::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	GetParent()->SetWindowText(_T("登录")); // 设置选项卡标题
}

void CFormViewLogin::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
}
