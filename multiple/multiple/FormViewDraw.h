#pragma once



// CFormViewDraw 窗体视图

class CFormViewDraw : public CFormView
{
	DECLARE_DYNCREATE(CFormViewDraw)

protected:
	CFormViewDraw();           // 动态创建所使用的受保护的构造函数
	virtual ~CFormViewDraw();

public:
	enum { IDD = IDD_FORMVIEW_DRAW };
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


