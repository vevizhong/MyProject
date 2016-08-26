#pragma once



// CFormViewCalculate 窗体视图

class CFormViewCalculate : public CFormView
{
	DECLARE_DYNCREATE(CFormViewCalculate)

protected:
	CFormViewCalculate();           // 动态创建所使用的受保护的构造函数
	virtual ~CFormViewCalculate();

public:
	enum { IDD = IDD_FORMVIEW_CALCULATE };
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
};


