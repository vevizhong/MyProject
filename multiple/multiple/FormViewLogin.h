#pragma once



// CFormViewLogin 窗体视图

class CFormViewLogin : public CFormView
{
	DECLARE_DYNCREATE(CFormViewLogin)

protected:
	CFormViewLogin();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate();
	DECLARE_MESSAGE_MAP()
public:
	CString m_UserName;
	CString m_Password;
	afx_msg void OnBnClickedButtonLogin();
};


