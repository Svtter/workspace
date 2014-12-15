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
#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAXN 10000
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
    for(int i = 1; i <= len; i++)
    {
        fprintf(stderr, "%5d", a[i]);
    }
    fprintf(stderr, "\n");
}

int a[MAXN+10], b[MAXN+10], at[MAXN+10], bt[MAXN+10];

void ensort(int rank[], int &myid, int &numprocs)
{
    int i, j, k;
    for(i = myid; i <= MAXN; i+=numprocs)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
        {
            if(b[i] > b[j] || (b[i] == b[j] && (i > j)))
                k++;
        }
        rank[i] = k;
    }
}

int main(int argc, char *argv[])
{
    int myid, numprocs;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    double c1 = 0, c2;
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
        cout << "original array is: " << endl;
        debug(a, 100);
        cout << endl;
        cout << "serial sorted array is: " << endl;
        debug(at, 100);
        cout << endl;
        cout << "serial cost time is: " << c1 << endl;
        cout << endl;
    }

    int con[numprocs][MAXN+10];
    int pt[MAXN+10];
    memset(con ,0, sizeof(con));
    memset(pt,0, sizeof(pt));
    // int **con = new int*[numprocs];
    // for(int i = 0; i < numprocs; i++)
        // con[i] = new int[MAXN+10];
    start = MPI_Wtime();

    // P0 send b to ALL
    MPI_Bcast(b, MAXN+10, MPI_INT, 0, MPI_COMM_WORLD);
    ensort(pt, myid, numprocs);

    // Gather
    MPI_Gather(pt, MAXN+10, MPI_INT, con[myid], MAXN+10, MPI_INT, 0, MPI_COMM_WORLD);
    // if(myid == 0)
    // {
        // fprintf(stderr, "myid: %d\n", myid);
        // fprintf(stderr, "con: %d\n", myid);
        // debug(con[1], 100);
        // fprintf(stderr, "pt: %d\n", myid);
        // debug(pt, 100);
        // fprintf(stderr, "\n");
    // }

    if(myid == 0)
    {
        int j;
        // for(i = 0; i < numprocs; i++)
        // {
            // printf("i: %d\n", i);
            // for(j = 1; j <= MAXN; j++)
                // printf("%5d", con[i][j]);
            // puts("");
        // }

        // rank[k] = i
        for(i = 0; i < numprocs; i++) 
            for(j = 1; j <= MAXN; j++)
                bt[con[i][j]] = b[j]; 
        
        // fprintf(stderr, "bt: \n");
        cout << "parallel sorted array is: " << endl;
        debug(bt, 100);
        cout << endl;
        end = MPI_Wtime();
        c2 = end - start;
        fprintf(stderr, "parallel cost time is: %lf\n", c2);
        fprintf(stderr, "加速比为： %lf\n", c1 / c2);
    }

    // for(i = 0; i < numprocs; i++)
        // delete con[i];
    // delete con;
    MPI_Finalize();
    return 0;
}

