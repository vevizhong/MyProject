title: System GNU GRUB  
layout: post  
date: 2016-03-08 16:31:54  
comments: true  
categories: Technical  
tags: System,Ubuntu,grub  
description: This is an approach to fix your grub when you reinstall your Windows 7.  

---
# Problem #
　　Usually when we want to play the linux system, most of us want to play the Ubuntu. Obviously, the Ubuntu system is the most popular linux system for the newbie. Due to the lack of physical devise, we may try to install two system in one computer so that we can enjoy the convenience of the Windows system as well as try the linux system to develop something.  
　　But there will always be something wrong with your Windows system and you have no choice but to reinstall your Windows system. There comes the problem that after reinstalling your Windows system, the GNU GRUB of your Ubuntu system have been replaced by the Windows bootmgr in the Main Boot Record(MBR). So you can not enter the Ubuntu system even though you do have you Ubuntu in your disk.  
　　So we must rewrite the GNU GRUB of your Ubuntu system.  

---

# Solution #
　　There are some steps as following:  
1. Download a ISO file of [Ubuntu system](http://www.ubuntu.com/download/desktop),and then download a tool called [Ultraiso](http://www.ezbsystems.com/ultraiso/download.htm), and prepare a empty U-disk;  
2. Burn the ISO file you downloaded into your U-disk by using the tool Ultraiso;  
3. Connect your U-disk to your computer and reboot your computer. Then enter your BIOS and set the way of startup your computer as the U-disk;  
4. Enter the system in your U-disk and choose trying Ubuntu;  
5. Open the terminal(ctrl+alt+t), and input the command:  `sudo -i` and get the authority of administrator;  
6. Input the command: `fdisk -l` and get a list of all your partition in your computer and find the partition of your Ubuntu root(find the partition whose ID is 83 ) as below:  
![](/images/2016/03/System Grub/disk_result.png)  
7. Input the command: `mount /dev/sda6 /mnt`, to mount your system partition to the folder mnt;  
8. Install your Ubuntu system grub by inputting command as: `grub-install --root-directory=/mnt /dev/sda` then wait for a mount and you would see the message:`Installation finished, No error reported`  which means you are successful.