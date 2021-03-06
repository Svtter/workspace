#include "mpich-x86_64/mpi.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 10000
#define PMAX 10000

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

int a[MAXN+10], b[MAXN+10], at[MAXN+10], bt[MAXN+10];
int main(int argc, char **argv)
{

    build(a, b);



    int myid, numprocs;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Get_processor_name(processor_name, &namelen);

    fprintf(stderr, "Hello world! Processor %d of %d on %s\n", myid, numprocs, processor_name);

    MPI_Finalize();
    return 0;
}

