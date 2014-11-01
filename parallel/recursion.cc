#include "omp.h"
#include <cstdio>
#include <iostream>

using namespace std;

omp_nest_lock_t lock;

void debug(int d)
{
    omp_set_nest_lock(&lock);
    cout << "first thread " << d << endl;
    omp_unset_nest_lock(&lock);
}

void debug2(int d)
{
    omp_set_nest_lock(&lock);
    cout << "thread " << d << endl;
    omp_unset_nest_lock(&lock);
}

void roll(int d)
{
    debug(d);
#pragma omp parallel
    {
        int d = omp_get_thread_num();
        debug2(d);
    }
}

int main()
{
    omp_set_num_threads(4);
    omp_set_nested(1);  //允许嵌套并行,注释掉这句看效果,注释掉这句看效果
    omp_init_nest_lock(&lock);
#pragma omp parallel
    {
        int d = omp_get_thread_num();
        roll(d);
    }
    omp_destroy_nest_lock(&lock);
    return 0;
}
