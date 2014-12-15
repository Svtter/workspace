/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-02 13:38
#
# Filename: enum_sort_openmp.cpp
#
# Description: 
#
=============================================================================*/
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;

// 大数，内存处理
#define INF 0x3f3f3f3f
#define ll long long int
#define MEM(a) memset(a, 0, sizeof(a))
#define MEMM(a) memset(b, -1, sizeof(b))
#define DEB(x, n) cout << (x) << " " << (n) << endl;

// 字符串处理
#define SL(a) strlen(a)
#define SCM(a, b) strcmp(a, b)
#define SCP(a, b) strcpy(a, b)

// 输入函数
#define RS(s) scanf("%s", (s))
#define RI(a) scanf("%d", &(a))
#define PI(r) printf("%d\n", (r))
#define PS(s) printf("%s\n", (s))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

// 应对ONLINE_JUDGE, 读入读出处理
// 利用bash脚本调试数据
#ifdef ONLINE_JUDGE
#define FOI(file) 0
#define FOW(file) 0
#else
#define FOI(file) freopen(file,"r",stdin);
#define FOW(file) freopen(file,"w",stdout);
#endif

// 定义常用工作变量
int t;

// 最大数组大小
// 最大的大小
// 处理器个数
#define MAXN 2000
#define PMAX 10000
#define NUM_THREADS 4

// 针对ab建立两个随机数数组
void build(int a[], int b[])
{
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++)
        a[i] = b[i] = random()%PMAX;
}


//serial enum sort
double serial_enum_sort(int a[], int at[])
{
    double t1, t2;
    t1 = omp_get_wtime();
    int k, i, j;
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
            if(a[i] > a[j] || (a[i] == a[j] && i > j))
                k++;
        at[k] = a[i];
    }
    t2 = omp_get_wtime();
    return (t2 - t1);
}

// parallel enum sort
double parallel_enum_sort(int b[], int bt[])
{
    double t1, t2;
    t1 = omp_get_wtime();
    int i, j, k;
#pragma omp parallel for schedule(static, 1) private(i, j, k)
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
        {
            if(b[i] > b[j] || (b[i] == b[j] && i > j))
                k++;
        } 
        bt[k] = b[i];
    }
    t2 = omp_get_wtime();
    return (t2 - t1);
}


// 调试数组, len为数组长度
void debug(int a[], int len)
{
    for(int i = 1; i <= len; i++) {
        cout << a[i] << " ";
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
	omp_set_num_threads(NUM_THREADS);
    double cost1, cost2;

    cout << "origin array: " <<endl;
    debug(a, 100);

    //serial
    cost1 = serial_enum_sort(a, at);
    printf("serial cost is:\n%lf\n", cost1);
    debug(at, 100);
    
    //parallel
    cost2 = parallel_enum_sort(b, bt);
    printf("parallel cost is:\n%lf\n", cost2);
    debug(bt, 100);

    cout << "increse speed is: " << cost1 / cost2;
    cout << endl;

    return 0;
}

