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

// multipleView.cpp : CmultipleView 类的实现
//

#include "stdafx.h"
#include "multiple.h"

#include "multipleDoc.h"
#include "multipleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmultipleView

IMPLEMENT_DYNCREATE(CmultipleView, CView)

BEGIN_MESSAGE_MAP(CmultipleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmultipleView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmultipleView 构造/析构

CmultipleView::CmultipleView()
{
	// TODO: 在此处添加构造代码

}

CmultipleView::~CmultipleView()
{
}

BOOL CmultipleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmultipleView 绘制

void CmultipleView::OnDraw(CDC* /*pDC*/)
{
	CmultipleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CmultipleView 打印


void CmultipleView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CmultipleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmultipleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmultipleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CmultipleView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmultipleView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CmultipleView 诊断

#ifdef _DEBUG
void CmultipleView::AssertValid() const
{
	CView::AssertValid();
}

void CmultipleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmultipleDoc* CmultipleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmultipleDoc)));
	return (CmultipleDoc*)m_pDocument;
}
#endif //_DEBUG


// CmultipleView 消息处理程序
void  CmultipleView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowText(_T("首页")); // 设置选项卡标题
}