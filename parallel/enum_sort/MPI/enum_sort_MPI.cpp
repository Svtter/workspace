/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-02 17:08
#
# Filename: enum_sort_MPI.cpp
#
# Description: 
#
=============================================================================*/
#include "mpich-x86_64/mpi.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAXN 100
#define PMAX 1000

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
    t1 = MPI_Wtime();
    int k, i, j;
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
            if(a[i] > a[j] || (a[i] == a[j] && i > j))
                k++;
        at[k] = a[i];
    }
    t2 = MPI_Wtime();
    return (t2 - t1);
}

// 用于调试数组
void debug(int a[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%5d", a[i]);
    }
}

int a[MAXN+10], b[MAXN+10], at[MAXN+10], bt[MAXN+10];

void sort(int con[], int pos[], int &myid, int &numprocs)
{
    int i, j, k;
    int no = 0;
    for(i = myid; i <= MAXN; i+=numprocs)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
        {
            if(b[i] > b[j] || (b[i] == b[j] && (i > j)))
                k++;
        }
        pos[no] = k;
        con[no] = i;
        no++;
    }
}

int main(int argc, char *argv[])
{
    int myid, numprocs;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    double c1, c2;
    double start, end;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Get_processor_name(processor_name, &namelen); 
    // fprintf(stderr, "Hello world! Processor %d of %d on %s\n", myid, numprocs, processor_name);

    //serial
    if(myid == 0)
    {
        build(a, b); 
        c1 = serial_enum_sort(a, at);
        // debug(a, 100);
        debug(at, 100);
        cout << "serial cost time is: " << c1 << endl;
    }

    int con[MAXN+10];
    int pos[MAXN+10];
    memset(con, 0, sizeof(con));
    memset(pos, 0, sizeof(pos));
    memset(rank, 0, sizeof(rank));
    start = MPI_Wtime();
    // P0 send b to ALL
    MPI_Bcast(b, MAXN+10, MPI_INT, 0, MPI_COMM_WORLD);
    sort(con, pos, myid, numprocs);

    // Gather
    // gather have problem: how can it 
    MPI_Gather(con, MAXN/4, MPI_INT, con, MAXN/4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Gather(pos, MAXN/4, MPI_INT, pos, MAXN/4, MPI_INT, 0, MPI_COMM_WORLD);

    if(myid == 0)
    {
        for(i = 0; i < MAXN; i++)
        {
            bt[con[i]] = b[pos[i]];
        }
        debug(bt, 100);
        end = MPI_Wtime();
        c2 = end - start;
        // debug(bt, 100);
        fprintf(stderr, "parallel cost time is: %lf\n", c2);
        fprintf(stderr, "加速比为： %lf", c1 / c2);
    }

    MPI_Finalize();
    return 0;
}

