// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// multipleDoc.cpp : CmultipleDoc ���ʵ��
//

#include "stdafx.h"
#include "multiple.h"

#include "multipleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmultipleDoc

IMPLEMENT_DYNCREATE(CmultipleDoc, CDocument)

BEGIN_MESSAGE_MAP(CmultipleDoc, CDocument)
END_MESSAGE_MAP()


// CmultipleDoc ����/����

CmultipleDoc::CmultipleDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CmultipleDoc::~CmultipleDoc()
{
}

BOOL CmultipleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CmultipleDoc ���л�

void CmultipleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CmultipleDoc ���

#ifdef _DEBUG
void CmultipleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmultipleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmultipleDoc ����
