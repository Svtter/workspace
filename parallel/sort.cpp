#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cmath>
#include "omp.h"

using namespace std;

// 设置线程数
#define NUM_THREADS 4

// 1. 生成数组
void build(int *data1, int *data2, int len)
{
    int i, j;
    for(i = 0; i < len; i++)
    {
        j = random() % 100000000;
        data1[i] = data2[i] = j;
    }
}

// 2. quicksort
int partition(int *data, int k, int l)
{
    int pivo = data[l];
    int i = k-1;
    for(int j = k; j <= l-1; j++)
    {
        if(data[j] <= pivo)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i+1], data[l]);
    return i+1;
}

void quicksort(int *data, int i, int j)
{
    int r;
    if(i < j)
    {
        r = partition(data, i, j);
        quicksort(data, i, r-1);
        quicksort(data, r+1, j);
    }
}

// end 2;

// para_quicksort

int k;
void para_quicksort(int *data, int i, int j, int m, int id)
{
#pragma omp parallel
    {
        m = omp_get_thread_num();
        int r;
        if(j - i <= k || m == 0)
            quicksort(data, i, j);
        else if(m == 1)
        {
            r = partition(data, i, j);
            // send data[r+1, m-1] to Pid+2^{m-1}
            para_quicksort(data, i,  r-1, m-1, id);
            para_quicksort(data, r+1, j, m-1, id+pow(2, m-1));
            // Pid+2^{m-1} send data[r+1, m-1] back to pid
        }
        else
        {
            r = partition(data, i, j);
            // send data[r+1, m-1] to Pid+2^{m-1}
            para_quicksort(data, i,  r-1, m-1, id);
            para_quicksort(data, r+1, j, m-1, id+pow(2, m-1));
            // Pid+2^{m-1} send data[r+1, m-1] back to pid
        }
    }
}


// debug array
void debug(int *data)
{
    for(int i = 0; i < 100; i++)
    {
        cout << data[i] << ' ';
        if(! i % 5)
            cout << endl;
    }
}


int main()
{
    omp_set_num_threads(NUM_THREADS);
    omp_set_nested(1);
    clock_t t1, t2;

    srand(time(NULL));

    int *d1, *d2;
    int len = 20000000;
    d1 = new int[len];
    d2 = new int[len];
    build(d1, d2, len);

    // serial
    t1 = clock();
    quicksort(d1, 0, len-1);
    t2 = clock();
    printf("serial cost time is: %ld", t2- t1);

    // parallel
    // t1 = clock();
    // 控制不必并行排序的范围
    // k = 100000;
    // int m;
    // para_quicksort(d2, 0, len-1, 0, 0);

    return 0;
}

