/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-14 16:59
#
# Filename: 进程控制.c
#
# Description: 
#
=============================================================================*/
#include <stdio.h>
#include <wait.h>

// 利用lockf(1, 1, 0)锁定输出设备
// lockf(1, 0, 0)解锁输出设备

int main()
{
    int p1, p2, i;
    if(p1 = fork())
    {
        lockf(1, 1, 0);
        for(i = 0; i < 500; i++)
            printf("parent%d\n", i);
        lockf(1, 0, 0);
        wait(0);        //confirm the father killed after child
        exit(0);
    }
    else
    {
        if(p2 = fork())
        {
            lockf(1, 1, 0);
            for(i = 0; i < 500; i++)
            printf("son %d\n", i);
            lockf(1, 0, 0);
            wait(0);        //
            exit(0);
        }
        else
        {
            lockf(1, 1,0);
            for(i = 0; i < 500; i++)
                printf("grandchild%d\n", i);
            lockf(1, 0,0);
            exit(0);
        }
    }
}
