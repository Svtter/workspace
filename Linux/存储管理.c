/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-14 16:58
#
# Filename: 存储管理.c
#
# Description: 
#
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


// system define
#define TRUE 1
#define FALSE 0
#define INVALID -1
//#define NULL 0 // some question

#define total_instruction 320 /*instruction length*/
#define total_vp 32 /*virtual page*/
#define clear_period 50 /*clear 0 */

typedef struct
{
    int pn;             //page number
    int pfn;            //physical frame number
    int counter;        //counter
    int time;           //running time
}pl_type;

typedef struct pfc_struct 
{
    int pn;             //page number
    int pfn;            //physical frame number
    struct pfc_struct *next;
}pfc_type;

typedef struct pfc_struct pfc_type;
pfc_type ptc_struct[total_vp], *freepf_head, *busypf_head, *busypf_tail;
int diseffect, a[total_instruction]; /*a[] instruction queue*/
int page[total_instruction], offset[total_instruction]; //address information

int Initialize(int); // give each pl value;
void FIFO(int); // cal the FIFO hit rate;
void LRU(int); // cal LRU hit rate;
void OPT(int); // cal OPT hit rate;
void LFU(int);
void NUR(int);


int main()
{
    int s, i, j;
    srand(10*getpid());
    s = (float)319*rand()/32767/32767/2+1; //normal distribution
    for(i = 0; i < total_instruction; i += 4)
    {
        if(s < 0 || s > 319)
        {
            printf("When i == %d, Error, s == %d\n", i, s);
            exit(0);
        }
    }
    a[i] = s;
    a[i+1] = a[i]+1;
    a[i+2] = (float)a[i]*rand()/32767/32767/2;
    a[i+3] = a[i+2]+1;

    s=(float)(318-a[i+2])*rand()/32767/32767/2 + a[i+2] + 2;
    if(a[i+2] > 318 || (s>319))
        printf("a[%d+2], a number with which is :%d and s == %d\n", i, a[i+2], s);
        
    for(i = 0; i < total_instruction; i++)
    {
        page[i] = a[i]/10;
        offset[i] = a[i]%10;
    }
    
    for(i = 4; i<=32; i++)
    {
        printf("---%2d page frames---\n", i);
        FIFO(i);
        LRU(i);
        OPT(i);
        LFU(i);
        NUR(i);
    }
    return 0;
}

int Initialize(int total_pf)
{
    int i;
    diseffect = 0;
    for(i = 0; i < total_vp; i++)
    {
        
    }
}
