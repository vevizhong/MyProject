#pragma once



// CFormViewDraw ������ͼ

class CFormViewDraw : public CFormView
{
	DECLARE_DYNCREATE(CFormViewDraw)

protected:
	CFormViewDraw();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate();

	DECLARE_MESSAGE_MAP()
};


