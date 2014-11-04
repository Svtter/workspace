// win32_parallel_var.cpp : 定义控制台应用程序的入口点。
/*=============================================================================
# Author: svtter - svtter@qq.com
# QQ : 57180160
# Last modified:	2014-10-21 21:13
# Description: 
# 
=============================================================================*/

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

#define MAXN 20000
#define PMAX 10000

int a[MAXN+10], b[MAXN+10], at[MAXN+10], bt[MAXN+10];

// 针对ab建立两个随机数数组
void build(int a[], int b[])
{
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++)
    {
		a[i] = b[i] = rand()%PMAX;
	}
}

//serial enum sort
double serial_enum_sort(int a[], int at[])
{
    double t1, t2;
    t1 = clock();
    int k, i, j;
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
            if(a[i] > a[j] || (a[i] == a[j]) && i > j)
                k++;
        at[k] = a[i];
    }
    t2 = clock();
    return (t2 - t1);
}


// parallel enum sort
int thread_num;
#define NUM_THREADS 4
int count = 1;

DWORD WINAPI ThreadFunc(LPVOID pParam)
{
	DWORD dwResult = 0;
	int k, j;
	int i = (int)pParam;
	//cout << i << "is counting.." << endl;
	for(; i <= MAXN; i += NUM_THREADS)
	{
		k = 1;
		for(j = 1; j <= MAXN; j++)
		{
			if(b[i] > b[j] || (b[i] == b[j] && i > j))
			k++;
		}
		bt[k] = b[i];
	}
	//count --;
	return (dwResult);
}

double parallel_enum_sort(int b[], int bt[])
{
	clock_t t1, t2;
	t1 = clock();
	HANDLE *p;
	p = new HANDLE[NUM_THREADS+1];
	int i;
	for(i = 1; i <= NUM_THREADS; i++)
	{
		p[i] = CreateThread(NULL, 0, ThreadFunc, (LPVOID)i , 0, NULL);
	}

	for(i = 1; i <= NUM_THREADS; i++)
	{
		ResumeThread(p[i]);
	}
	//while(count != 0);
	//WaitForMultipleObjects(sizeof(p), p, TRUE, INFINITE);
	for(i = 1; i <= NUM_THREADS; i++)
		WaitForSingleObject(p[i], INFINITE);
	t2 = clock();
	return (t2 - t1);
}


// 调试数组, len为数组长度
void debug(int a[], int len)
{
    for(int i = 1; i <= len; i++) 
		cout << a[i] << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
    //FOI("input");
    //FOW("output");
    //write your programme here
    build(a, b);
	memset(bt, 0, sizeof(bt));
    double cost, cost2;

    //serial
    cost = serial_enum_sort(a, at);
    cout << "serial cost is: " << cost << endl;
    //debug(at, 100);

    //parallel
	cost2 = parallel_enum_sort(b, bt);
	cout << "parallel cost is: " << cost2 << endl;
	//debug(bt, 100);
    
    printf("并行加速比为: %lf\n", cost / cost2);

	system("pause");
    return 0;
}