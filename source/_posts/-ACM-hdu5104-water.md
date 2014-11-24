title: "[ACM]-hdu5104-water"
date: 2014-11-16 14:18:42
categories:
- ACM
- hdu
- water
tags: [enum, water]
---

这个题目的总结就是不作不会死- -好端端的暴力我非要用个bfs。

看见自己wrong了还以为是哈希的问题- =

题意
===

- p1+p2+p3 = n，$p1 <= p2 <= p3$
- 输出符合条件的组数

输入输出
===

- 给100组n，输出组数

分析
===

- 只有3个数，暴力解就可以，注意循环终止条件。

<!--more-->

AC代码
===

```cc
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;

// 大数，内存处理
#define INF 0x3f3f3f3f
#define ll long long int
#define MEM(a) memset(a, 0, sizeof(a))
#define MEMM(a) memset(b, -1, sizeof(b))
#define DEB(x, n) cout << (x) << " " << (n) << endl;

// 字符串处理
#define SL(a) strlen(a)
#define SCM(a, b) strcmp(a, b)
#define SCP(a, b) strcpy(a, b)

// 输入函数
#define RS(s) scanf("%s", (s))
#define RI(a) scanf("%d", &(a))
#define PI(r) printf("%d\n", (r))
#define PS(s) printf("%s\n", (s))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

// 应对ONLINE_JUDGE, 读入读出处理
// 利用bash脚本调试数据
#ifdef ONLINE_JUDGE
#define FOI(file) 0
#define FOW(file) 0
#else
#define FOI(file) freopen(file,"r",stdin);
#define FOW(file) freopen(file,"w",stdout);
#endif

// 定义常用工作变量
//
#define MAXN 20010

int Prime[10010];
bool IsPrime[MAXN];
int num;
void init()
{
    int i, j;
    num = 0;
    IsPrime[0] = IsPrime[1] = 1;
    for(i = 2 ; i <  MAXN ; i ++)    
    {    
        if(!IsPrime[i])    
            Prime[num++]=i;    
        for(j = 0 ; j < num && i * Prime[j] <  MAXN ; j ++)    
        {    
            IsPrime[i * Prime[j]] = 1;    
            if(!(i % Prime[j]))    
                break;    
        }    
    }
}

int counter;
void bfs(int cur, int n, int id)
{
    int i;
    int temp;
    for(i = cur; Prime[i] <= n; i++)
    {
        temp = n - Prime[i];
        if(temp == 0 && id == 3)
        {
            counter++;
            return;
        }
        else if(temp > 0 && id < 3)
            bfs(i, temp, id+1);
        else if(temp < 0)
            break;
    }
}


void debug(bool a[], int len)
{
    for(int i = 0; i <len ; i++)
    {
        if(!a[i]) cout << i << " " ;
        // cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    init();
    // debug(IsPrime, 100);
    int i, j;
    int n;
    int temp;
    int temp2;
    while(~scanf("%d", &n))
    {
        counter = 0;
        // bfs(0, n, 1);
        for(i = 0; Prime[i] <= n; i++)
        {
            temp = n - Prime[i];
            for(j = i; Prime[j] <= temp; j++)
            {
                temp2 = temp - Prime[j];
                if(temp2 < Prime[j])
                    break;
                if(!IsPrime[temp2])
                    counter++;
                else if(temp2 < 0)
                    break;
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}



```
