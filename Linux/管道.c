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
