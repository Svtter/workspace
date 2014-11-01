// section_calculus.cpp : 定义控制台应用程序的入口点。
//

#include "time.h"
#include "omp.h"
#include "cstdio"
using namespace std;

static long num_steps=100000000;
double step;
#define NUM_THREADS 2

int main()
{
    double t1, t2;
    int i;
    double pi , x, sum = 0.0;

    step = 1.0/(double)num_steps;
    omp_set_num_threads(NUM_THREADS);

    t1 = omp_get_wtime();

#pragma omp parallel for reduction(+:sum) private(x)
    for(i = 0; i < num_steps; i++)
    {
        x=(i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }

    pi = step*sum;
    t2 = omp_get_wtime();
    printf("PI=%.15f\n", pi);
    printf("parallel time: %lf\n", (t2-t1));

    //serial time
    t1 = omp_get_wtime();
    sum = 0;
    for(int i= 0; i < num_steps; i++)
    {
        x=(i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    pi = step*sum;
    t2 = omp_get_wtime();
    printf("PI=%.15f\n", pi);
    printf("serial time : %lf\n", (t2 - t1));

    return 0;
}

