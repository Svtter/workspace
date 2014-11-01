/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-10-15 18:48
#
# Filename: lock.cc
#
# Description: 
#
=============================================================================*/
#include "omp.h"
#include <cstdio>

omp_nest_lock_t lock;
int counter = 0;
void inc_counter()
{
    printf("Thread id = %d\n", omp_get_thread_num());
    for(int i = 0; i < 10000000; i++)
    { 
        omp_set_nest_lock(&lock);
        counter++;
        omp_unset_nest_lock(&lock);
    }
}

void dec_counter()
{
    printf("Thread id = %d\n", omp_get_thread_num());
    for(int i = 0; i < 10000000; i++)
    {
        omp_set_nest_lock(&lock);
        counter--;
        omp_unset_nest_lock(&lock);
    }
}

int main()
{
    omp_init_nest_lock(&lock);
    omp_set_num_threads(4);
#pragma omp parallel sections
    {
#pragma omp section
        inc_counter();
#pragma omp section
        dec_counter();
    }
    omp_destroy_nest_lock(&lock);
    printf("counter=%d\n", counter);

    return 0;
}
