// FormViewLogin.cpp : ʵ���ļ�
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


// CFormViewLogin ���

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


// CFormViewLogin ��Ϣ�������

void CFormViewLogin::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	GetParent()->SetWindowText(_T("��¼")); // ����ѡ�����
}

void CFormViewLogin::OnBnClickedButtonLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
