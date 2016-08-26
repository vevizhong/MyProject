title: MFC 多文档多视图切换
 
layout: post  
date: 12/9/2015 1:18:41 PM    
comments: true  
categories: Technical    
tags: [MFC,MultiDocument]  
keywords: MFC,MultiDocument  
description: MFC写出Ribbon风格的界面    
---
# 一. MFC 多文档简介 #
　　MFC引入了“文档/视图”结构的概念，理解这个结构是编写基于MFC编写复杂Visual C++程序的关键，在“文档/视图”中主要涉及了四种类：   
### 1. 文档模版： ###
    class CDocTemplate;//template for document creation  
    class CSingleDocTemplate;//SDI support  
    class CMultiDocTemplate;//MDI support 
### 2. 文档： ###
	class CDocument;//main document adbstraction
### 3. 视图： ###
    class CView;//a view on a document  
    class CScrollView;//a scrolling view  
### 4. 框架窗口：  ###
    // frame windows
    class CFrameWnd; // standard SDI frame
    class CMDIFrameWnd; // standard MDI frame
    class CMDIChildWnd; // standard MDI child
    class CMiniFrameWnd; // half-height caption frame wnd  
---
# 二. MFC 多文档多视图切换 #
## 1. 新建一个MFC工程 ##
　　在vs2008 下新建一个MFC 应用程序，并在选择应用程序类型处选择其视觉样式和颜色时选择“Office 2007 （蓝色主体）”，完成MFC工程的创建。见下图：  
　　　　　　![image](/images/MFC/MFC_project_creating.png)  

## 2. 添加待显示的多个视图 ##
　　需要在资源视图中，给Dialog资源添加多个待显示的视图，资源为FormView类型的Dialog：  
　　　![](/images/MFC/MFC_resource_adding.png)  
 　　然后修改添加资源的ID，并给该资源添加类：  
 　　![](/images/MFC/MFC_class_adding.png)

## 3. 修改代码 ##
> 工程名称为**multiple**，添加的三个类分别为CFormViewLogin、CFormViewDraw、CFormViewCalculate类  

  
## i 在应用程序类给待显示资源的模版进行注册 ##
　　在应用程序类的头文件(multiple.h)中添加文件模版的指针：    
    
	CMultiDocTemplate * m_pLogin;
    CMultiDocTemplate * m_pDraw;
    CMultiDocTemplate * m_pCalculate;
　　接着在应用程序类的cpp文件中给添加的资源类注册：  

	//包含需要显示的三个类的头文件
    #include "FormViewLogin.h"
    #include "FormViewDraw.h"
    #include "FormViewCalculate.h
---
	// 注册应用程序的文档模板。文档模板将用作文档、框架窗口和视图之间的连接
	m_pLogin = new CMultiDocTemplate(IDR_MAINFRAME,
		RUNTIME_CLASS(CmultipleDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CFormViewLogin));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(m_pLogin);

	m_pDraw = new CMultiDocTemplate(IDR_MAINFRAME,
		RUNTIME_CLASS(CmultipleDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CFormViewDraw));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(m_pDraw);

	m_pCalculate = new CMultiDocTemplate(IDR_MAINFRAME,
		RUNTIME_CLASS(CmultipleDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CFormViewCalculate));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(m_pCalculate);  

## ii 修改主框架对Ribbon的初始化 ##

　　Ribbon即功能区，是新的 Microsoft Office Fluent 用户界面 (UI) 的一部分。在仪表板设计器中，功能区包含一些用于创建、编辑和导出仪表板及其元素的上下文工具。它是一个收藏了命令按钮和图示的面板。它把命令组织成一组"标签"，每一组包含了相关的命令。每一个应用程序都有一个不同的标签组，展示了程序所提供的功能。在每个标签里，各种的相关的选项被组在一起。Windows Ribbon是一个Windows Vista或Windows 7自带的GUI构架，外形更加华丽。  
　　在CMainFrame的InitializeRibbon里面注释掉其他没有用的界面，比如“剪切板”面板、“窗口”面板等，但是留下自己定义的东西，然后初始化主页。 
 
    void CMainFrame::InitializeRibbon()
    {
	    BOOL bNameValid;   
    	CString strTemp;
    	bNameValid = strTemp.LoadString(IDS_RIBBON_FILE);
    	ASSERT(bNameValid);  
    	// 加载面板图像:
    	m_PanelImages.SetImageSize(CSize(16, 16));
    	m_PanelImages.Load(IDB_BUTTONS);
    	// 初始主按钮:
    	m_MainButton.SetImage(IDB_MAIN);
    	m_MainButton.SetText(_T("\nf"));
    	m_MainButton.SetToolTipText(strTemp);
    
    	m_wndRibbonBar.SetApplicationButton(&m_MainButton, CSize (45, 45));
    	CMFCRibbonCategory *pRibbonUICategory =
    		m_wndRibbonBar.AddCategory(_T("功能操作"),
    		IDB_WRITESMALL, IDB_WRITELARGE);    
    	// 添加一个面板(Panel)
    	CMFCRibbonPanel *pTestPanel = pRibbonUICategory->AddPanel(_T("选择功能"), m_PanelImages.ExtractIcon(27));   
    	// 在面板上添加Ribbon命令按钮(CMFCRibbonButton)
    	pTestPanel->Add(new CMFCRibbonButton(ID_FUNC_LOGIN,_T("用户登录"), 0, 0));    
    	pTestPanel->Add(new CMFCRibbonButton(ID_FUNC_DRAW, _T("绘图功能"), 0,0));   
    	pTestPanel->Add(new CMFCRibbonButton(ID_FUNC_CALCULATE, _T("计算功能"), 0,0));
    }  
 　　此时，程序已经包含了多个视图的模版，接下来需要在CMainFrame.cpp文件中实现不同视图之间的转换：  

    void CMainFrame::SwitchToView(CDocTemplate * pTemplate, CRuntimeClass * pViewClass)
    {
    
    	CMDIChildWnd *pMDIActive = MDIGetActive();//获得活动子窗口
    	CDocument *pDoc = pMDIActive->GetActiveDocument(); //获得活动doc
    	CView *pView;
    
    	POSITION pos = pDoc->GetFirstViewPosition();   //查询此doc下的所有已创建view
    	while (pos != NULL)
    	{
    		pView = pDoc->GetNextView(pos);
    		if (pView->IsKindOf(pViewClass))   //如果已创建此view 则设其为活动
    		{ 
    			// the requested view class has already been created; show it
    			pView->GetParentFrame()->ActivateFrame();  
    			//pView->UpdateWindow();//视图更新显示；
    			return;
    		}
    		pView->UpdateWindow();
    	}
    
    	CMDIChildWnd *pNewFrame = (CMDIChildWnd *)
    		(pTemplate->CreateNewFrame(pDoc, NULL));   // 如果没有创建，则创建此view的childframe及view
    
    	if (pNewFrame == NULL)
    		return;
    
    	pTemplate->InitialUpdateFrame(pNewFrame, pDoc);
    }  

## iii 将ID与响应的执行函数进行绑定，并写出该执行函数 ##

定义响应函数：  
在MainFrame.h文件中添加：  

    public:
    	afx_msg void OnLogin();
    	afx_msg void OnDraw();
    	afx_msg void OnCalculate();
绑定ID和响应函数：  
在MainFrame.cpp文件中添加：  

    #include "FormViewLogin.h"
    #include "FormViewDraw.h"
    #include "FormViewCalculate.h"
    BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
    	ON_COMMAND(ID_FUNC_LOGIN,&CMainFrame::OnLogin)
    	ON_COMMAND(ID_FUNC_DRAW,&CMainFrame::OnDraw)
		ON_COMMAND(ID_FUNC_CALCULATE,&CMainFrame::OnCalculate)
    END_MESSAGE_MAP()
然后对响应函数进行编写：  

    // CMainFrame 消息处理程序
    void CMainFrame::OnLogin()
    {
    	SwitchToView(theApp.m_pLogin,RUNTIME_CLASS(CFormViewLogin));
    }
    
    void CMainFrame::OnDraw()
    {
    	SwitchToView(theApp.m_pDraw,RUNTIME_CLASS(CFormViewDraw));
    }
    
    void CMainFrame::OnCalculate()
    {
    	SwitchToView(theApp.m_pCalculate,RUNTIME_CLASS(CFormViewCalculate));
    }  

## iv 修改视图的标题栏 ##

对主窗口的标题进行修改--在multiple.cpp的InitInstance函数中添加： 
 
	// 主窗口已初始化，因此显示它并对其进行更新
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	m_pMainWnd->SetWindowText(L"VeviZhong 的工具箱");
分别在三个添加的类中重写CView的虚函数OnInitialUpdate（）函数，并对标题栏进行修改：  

    // CFormViewDraw 消息处理程序
    void CFormViewDraw::OnInitialUpdate()
    {
    	CView::OnInitialUpdate();
    	GetParent()->SetWindowTextW(_T("绘图"));
    }
修改主窗口的CREATESTRUCT结构体的变量值，从而达到自定义固定的窗口标题的目的：
在ChildFrame.cpp文件中增加：

    BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
    {
    	
    	cs.style &= ~FWS_ADDTOTITLE;//在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
    	if( !CMDIChildWndEx::PreCreateWindow(cs) )
    		return FALSE;
    
    	return TRUE;
    }
并在CMainFrame.cpp文件中的PreCreateWindow函数中也增加该修改：  

    BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
    {
    	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
    		return FALSE;
    	cs.style   &=   ~FWS_ADDTOTITLE;//在此处通过修改CREATESTRUCT cs 来修改窗口类或样式
    	return TRUE;
    }
在单文档应用程序中，缺省的窗口类型是*WS_OVERLAPPEDWINDOW*和*FWS_ADDTOTITLE*，其中*FWS_ADDTOTITLE* 用来增加文档的标题到窗口的标题。如果想自定义固定的窗口标题，就要去掉*FWS_ADDTOTITLE*这种类型，参照如下代码：

     cs.style &= ~FWS_ADDTOTITLE;       //取反、并进行“与”操作

或者  
 
	cs.style = WS_OVERLAPPEDWINDOW;    //或者直接赋值
    cs.lpszName = "固定的标题";
---
整个程序的运行结果图如下：  
![](/images/MFC/MFC_running_result.png)