#pragma once



// CFormViewCalculate ������ͼ

class CFormViewCalculate : public CFormView
{
	DECLARE_DYNCREATE(CFormViewCalculate)

protected:
	CFormViewCalculate();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate();

	DECLARE_MESSAGE_MAP()
};


