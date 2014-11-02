/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-10-03 20:35
#
# Filename: producer_consumer.cc
#
# Description: 
#
=============================================================================*/
#include <cstdio>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define N 5
#define item int

// P/V操作
void P(sem_t* sem)
{
    if(sem_wait(sem))
        perror("P error!");
    
}

void V(sem_t* sem)
{
    if(sem_post(sem))
        perror("V error!");
}

sem_t mutex;
sem_t full;
sem_t empty;
item buffer[N];
int i = 0, j = -1;

void init_sem()
{
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);
}

void* producer(void *arg)
{
    int product;
    while(1)
    {
        //生成随机数字
        product = rand()%100;
        // cout << "producer running..." << endl;
        P(&empty);
        P(&mutex);
        buffer[i] = product;
        printf("producer produced %d @ %d pos\n",
                product, i);
        i=(i+1)%N;
        V(&mutex);
        V(&full);
        sleep(1);
    }
}

void* consumer(void *arg)
{
    int product, temp;
    while(1)
    {
        // cout << "consumer running..." << endl;
        P(&full);
        P(&mutex);
        j = (j+1)%N;
        product = buffer[j];
        V(&mutex);
        V(&empty);
        printf("Consumer consumed %d @ %d pos\n",
                product, j);
        sleep(3);
    }
}

int main()
{
    //random num
    srand(time(NULL));
    init_sem();
    
    int error;
    pthread_t producer_t, consumer_t;

    error = pthread_create(&producer_t, NULL, producer, NULL);
    if(error != 0)
        printf("error in create producer.\n");
    else
        printf("create producer success!\n");

    pthread_create(&consumer_t, NULL, consumer, NULL);
    if(error != 0)
        printf("error in create consumer.\n");
    else
        printf("create consumer success!\n");
    
    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    return 0;
}
