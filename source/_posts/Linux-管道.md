title: Linux-管道
date: 2014-11-21 16:57:11
categories:
- Linux
- pipe管道
tags: [pipe]
---
- 本文出自[svtter.com](svtter.com)

- __头文件__: #include<unistd.h>
- __使用方法__: int pipe(int chan[2]);
- __说明__: pipe会建立管道，并将文件描述词通过chan返回。一般chan[0]为管道的读取端，chan[1]是写入端。
- __返回值__: 成功返回0，失败返回-1，错误信息保存在errno中
- __错误信息__:
    - EMFILE 进程已用完文件描述词最大量。
    - ENFILE 系统已无文件描述词可用。
    - EFAULT 参数filedes数组地址不合法


```cc
/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-21 16:20
#
# Filename: 管道.c
#
# Description: 
#
=============================================================================*/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

char parent[] = "a message from parent";
char child[] = "a message from child";

int main ()
{
    int p2c[2], c2p[2];
    int pid;
    char buf[100];
    pipe(p2c);
    pipe(c2p);
    pid = fork();
    if(pid > 0)
    {
        close(c2p[0]);
        close(p2c[1]);
        write(c2p[1], parent, sizeof(parent));
        close(c2p[1]);
        read(p2c[0], buf, 100);
        printf("%s\n", buf);
        close(p2c[0]);
    }
    else if(pid == 0)
    {
        close(p2c[0]);
        close(c2p[1]);
        read(c2p[0], buf, 100);
        printf("%s\n", buf);
        write(p2c[1], child, sizeof(child));
        close(c2p[0]);
        close(p2c[0]);
    }
    return 0;
}

```

运行结果：
---
![管道运行结果](http://ww3.sinaimg.cn/mw690/c53b1907jw1emivfwrkquj20cs05hwel.jpg)
