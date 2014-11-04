/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-02 13:57
#
# Filename: enum_sort.cpp
#
# Description: 
#     1.9
#     
=============================================================================*/
#include <iostream>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
using namespace std;

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

void debug(int a[], int len)
{
    for(int i = 1; i <= len; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}



int a[MAXN+10], b[MAXN+10]; 
int at[MAXN+10], bt[MAXN+10];
int n = 1;
void* parallel_enum_sort(void *arg)
{
    int k;
    for(int i = n ; i <= MAXN; i+=NUM_THREADS)
    {
        k = 1;
        for(int j = 1; j <= MAXN; j++)
        {
            if(b[i] > b[j] || (b[i] == b[j] && i > j))
                k++;
        }
        bt[k] = b[i];
    }
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    build(a, b);
    double cost1, cost2;


    //serial
    cost1 = serial_enum_sort(a, at);
    printf("serial cost is: %lf\n", cost1);
    // debug(at, 100);
    // puts("have child.");

    //parallel
    timeval t1, t2;
    gettimeofday(&t1, NULL);

    pthread_t pt[NUM_THREADS+1];
    for(int i = 1; i <= NUM_THREADS; i++)
    {
        pthread_create(&pt[i], NULL, parallel_enum_sort, NULL);
        n++;
    }

    for(int i = 1; i <= NUM_THREADS; i++)
    {
        pthread_join(pt[i], NULL);
        // n++;
    }
    // pthread_t p,q;
    // pthread_create(&p, NULL,  parallel_enum_sort, NULL);
    // pthread_create(&q, NULL,  parallel_enum_sort, NULL);
    // pthread_join(p, NULL);
    // n++;
    // pthread_join(q, NULL);
    
    
    gettimeofday(&t2, NULL);
    cost2 = timeuse(t1, t2);
    cout << "parallel time is: " << cost2 << endl;
    // debug(bt, 100);

    cout << "加速比为：" << cost1 /cost2;

    return 0;
}

