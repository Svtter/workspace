/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-02 13:36
#
# Filename: enum_sort_fork.cpp
#
# Description: 
# ！！！unable
=============================================================================*/
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;


// 定义常用工作变量
int t;

// 最大数组大小
// 最大的大小
// 处理器个数
#define MAXN 20000
#define PMAX 10000
#define NUM_THREADS 2

// 针对ab建立两个随机数数组
void build(int a[], int b[])
{
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++)
        a[i] = b[i] = random()%PMAX;
}

double timeuse(timeval tpstart, timeval tpend)
{
    double timeuse;
    timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
    timeuse/=1000000; 
    return timeuse;
}

//serial enum sort
double serial_enum_sort(int a[], int at[])
{
    timeval t1, t2;
    gettimeofday(&t1, NULL);
    int k, i, j;
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
            if(a[i] > a[j] || (a[i] == a[j] && i > j))
                k++;
        at[k] = a[i];
    }
    gettimeofday(&t2, NULL);
    return timeuse(t1, t2);
}

// parallel enum sort
// 添加管道通信
double parallel_enum_sort(int b[], int bt[])
{
    timeval t1, t2;
    gettimeofday(&t1, NULL);
    int i, j, k;
    int p = fork();
    bool done = 0;
    if(p)
    {
        for(i = 1; i <= MAXN; i+=NUM_THREADS)
        {
            k = 1;
            for(j = 1; j <= MAXN; j++)
            {
                if(b[i] > b[j] || (b[i] == b[j] && i > j))
                    k++;
            }
            bt[k] = b[k];
        }
    }
    else
    {
        for(i = 2; i <= MAXN; i+=NUM_THREADS)
        {
            k = 1;
            for(j = 1; j <= MAXN; j++)
            {
                if(b[i] > b[j] || (b[i] == b[j] && i > j))
                    k++;
            }
            bt[k] = b[k];
        }
    }
    gettimeofday(&t2, NULL);

    return timeuse(t1, t2);
}

#define DEB(x, n) cout << (x) << " " << (n) << endl;

// 调试数组, len为数组长度
void debug(int a[], int len)
{
    for(int i = 1; i <= len; i++) {
        DEB(a[i], '\0');
    }
    cout << endl;
}


int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int a[MAXN+10], b[MAXN+10]; int at[MAXN+10], bt[MAXN+10];
    build(a, b);
    double cost1, cost2;


    //serial
    cost1 = serial_enum_sort(a, at);
    printf("serial cost is:\n%lf\n", cost1);
    // debug(at, 100);
    // puts("have child.");

    //parallel
    cost2 = parallel_enum_sort(b, bt);
    printf("parallel cost is:\n%lf\n", cost2);
    // debug(bt, 100);

    cout << "increse speed is: " << cost1 / cost2;
    cout << endl;

    return 0;
}


