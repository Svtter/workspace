title: "[Linux]基础学习笔记(1)"
date: 2014-11-09 19:53:26
categories:
- Linux
- bash
tags: bash
---

Linux基础学习笔记
===

以鸟哥的私房菜为基础进行学习。

用Linux有接近两年的时间了，还是很水，于是决定从头开始，认真学习基础。

<!--more-->
date的基础用法
---
- `date +%H:%M` 显示`19:54`
- `date +%Y/%m/%d` 显示`2014/11/09`

使用man进行查询
---

`man + (command)`

一般，2代表系统内核可调用的函数与工具，3代表一些常用的函数，7代表惯例与协议，例如Linux文件系统，网络协议，ASCcode，8代表系统管理员可用命令，9

代表与kernel有关的文件。

man的操作方式和vi差不多，而info的操作方式则更接近于emacs（= =莫非又是两大党的斗争？！）

数据同步写入磁盘：sync
---

在Linux中为了避免过多对磁盘的I/O，所以很多操作并未马上写入硬盘，所以使用sync进行写入。对于root而言，则是更新整个磁盘的数据了。

shutdown命令关机
---

- 立即关机`shutdown -h now`

- 定时关机`shutdown -h 20:25` ---会在20:25分关机，如果超过了这个时间使用这个命令，则会在第二天的这个时间关机。

- 再过10分钟关机`shutdown -h +10`

- 警告所有用户`shutdown -k 'this system will reboot.'`

- 重启，并警告所有用户`shutdown -r +30 'The system will reboot.'`

三种执行等级
---

> 因为CentOS7使用systemd启动，所以可能并不支持。

- run level 0 关机
- run level 3 纯命令行
- run level 5 含有图形界面
- run level 6 重启

因此，可以使用`init 0`来关闭系统。


