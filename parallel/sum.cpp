#include "omp.h"
#include <time.h>
#include <stdio.h>

#define NUM_THREADS 4
int main(int argc, char * argv[])
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    omp_set_num_threads(NUM_THREADS);
    long long sum = 0;
    long long sumtmp[NUM_THREADS];
    double t1 ,t2;
    t1 = omp_get_wtime();
#pragma omp parallel
    {
        long i;
        long id = omp_get_thread_num();
        // printf("hello from %ld\n", id);
        long long temp = 0l;

        for(i = id; i <= 1000000000; i = i + NUM_THREADS)
        {
            temp += i;
        }
        sumtmp[id]=temp;
    }
    for(long i = 0; i < NUM_THREADS; i++)
    {
        sum += sumtmp[i];
    }
    t2 = omp_get_wtime(); 
    printf("%lld\n", sum);
    printf("parallel time: %lf\n",(t2 - t1));

    sum = 0;
    t1 = omp_get_wtime();
    for(long i = 1; i <= 1000000000; i++)
    {
        sum = sum + i;
    }
    t2 = omp_get_wtime();
    printf("%lld\n", sum);
    printf("serial time: %lf\n", (t2 - t1));

    return 0;
}
