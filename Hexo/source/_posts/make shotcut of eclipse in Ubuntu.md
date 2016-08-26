title: Ubuntu 下创建快捷方式  
 
layout: post  
date: 11/23/2015 11:16:07 PM   
comments: true  
categories: Technical    
tags: [Ubuntu,eclipse]  
keywords: Ubuntu, eclipse  
description: 如题！    
---

　　前提：在成功安装好eclipse的请提下，我们才进行下一步的操作，将安装目录下的eclipse的快捷方式发送到桌面：  
1  填写eclipse.desktop文件：
---
`sudo gedit /usr/share/applications/eclipse.desktop`
#### 文件内容: ####
    [DesktopEntry]
    Encoding=UTF-8
    Name=eclipse
    Comment=Eclipse IDE
    Exec=/usr/local/eclipse/eclipse/eclipse
    Icon=/usr/local/eclipse/eclipse/icon.xpm
    Terminal=false
    StartupNotify=true
    Type=Application
    Categories=Application;Development;
　　其中Exec后面填写的是执行文件的路径，Icon后面填写的是图标的路径，所以每个人的eclipse的解压缩路径不同，就进行相应的更改即可；  
2  关于/usr/share/applications文件夹：
---
　　这是一个关于应用程序快捷方式的文件夹，里面存放的都是应用程序的desktop文件，这里，我们需要将eclipse.desktop拷贝到桌面文件夹中：进入/usr/share/applications文件夹后，

    sudo cp eclipse.desktop /home/geeks/桌面/

3.给刚刚拷到桌面的这个文件赋权：进入桌面文件夹后，
---
    sudo chmod 777 eclipse.desktop

　　现在显示桌面看看，是不是已经有eclipse的快捷方式存在了呢？

　　转载自[博客园](http://www.cnblogs.com/qq19831030qq/archive/2012/05/09/2491275.html "转载")