title: Ubuntu Manual  
date: 7/22/2016 9:13:23 AM  
tags: Ubuntu,usage  
description: Ubuntu is a user-friendly system in the series of linux, but it's still linux. Thus, this paper is going to record my experience in using Ubuntu.  
 
---
## 1. Install the Ubuntu system ##
　　 My Ubuntu system version is Ubuntu 14.04 LTS 
## 2. Install the gnome for Ubuntu ##
　　Here is the way to install the gnome3:  

    sudo add-apt-repository ppa:gnome3-team/gnome3
    sudo apt-get update
    sudo apt-get dist-update
    sudo apt-get install gnome-themes-standard ubuntu-desktop gnome-shell
　　After installing the gnome3, reboot your system or just log out, when you are log in, choose gnome standard, and you will enter gnome3 interface.  
　　If you want to remove the gnome3 completely, just follow the steps:  

    sudo apt-get install ppa-purge
    sudo ppa-purge ppa:gnome3-team/gnome3

## 3. Change the Chinese into English in showing time##
Just add the following contents into `/etc/profile`: 
 
    LC_PAPER=en_US.UTF-8
    LC_ADDRESS=en_US.UTF-8
    LC_MONETARY=en_US.UTF-8
    LC_NUMERIC=en_US.UTF-8
    LC_TELEPHONE=en_US.UTF-8
    LC_IDENTIFICATION=en_US.UTF-8
    LC_MEASUREMENT=en_US.UTF-8
    LC_TIME=en_US.UTF-8
    LC_NAME=en_US.UTF-8
And then reboot your system.  
## 4. Create the shortcut for applications##