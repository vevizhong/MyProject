// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// multipleDoc.cpp : CmultipleDoc 类的实现
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


// CmultipleDoc 构造/析构

CmultipleDoc::CmultipleDoc()
{
	// TODO: 在此添加一次性构造代码

}

CmultipleDoc::~CmultipleDoc()
{
}

BOOL CmultipleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CmultipleDoc 序列化

void CmultipleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CmultipleDoc 诊断

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


// CmultipleDoc 命令
