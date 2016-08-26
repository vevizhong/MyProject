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

// multipleView.cpp : CmultipleView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmultipleView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmultipleView ����/����

CmultipleView::CmultipleView()
{
	// TODO: �ڴ˴���ӹ������

}

CmultipleView::~CmultipleView()
{
}

BOOL CmultipleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmultipleView ����

void CmultipleView::OnDraw(CDC* /*pDC*/)
{
	CmultipleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmultipleView ��ӡ


void CmultipleView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CmultipleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmultipleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmultipleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CmultipleView ���

#ifdef _DEBUG
void CmultipleView::AssertValid() const
{
	CView::AssertValid();
}

void CmultipleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmultipleDoc* CmultipleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmultipleDoc)));
	return (CmultipleDoc*)m_pDocument;
}
#endif //_DEBUG


// CmultipleView ��Ϣ�������
void  CmultipleView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowText(_T("��ҳ")); // ����ѡ�����
}