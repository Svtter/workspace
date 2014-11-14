/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-14 16:58
#
# Filename: 进程创建.c
#
# Description: 
#
=============================================================================*/
#include <stdio.h>

void main()
{
    int p1, p2;
    if (p1 = fork()) //父进程返回1， 子进程返回0
        putchar('b');
    else
    {
        if(p2 = fork())
            putchar('c');
        else
            putchar('a');
    }
}
