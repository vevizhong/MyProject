#pragma once



// CFormViewLogin ������ͼ

class CFormViewLogin : public CFormView
{
	DECLARE_DYNCREATE(CFormViewLogin)

protected:
	CFormViewLogin();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CFormViewLogin();

public:
	enum { IDD = IDD_FORMVIEW_LOGIN };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
	CString m_Password;
	afx_msg void OnBnClickedButtonLogin();
};


