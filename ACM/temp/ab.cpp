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

int n;

void ace()
{
    //min
    int temp = n % 4;
    if(temp == 2 || temp == 1)
        printf("1 ");
    else
        printf("0 ");
    if(temp == 3 || temp == 2)
        printf("%d\n", n);
    else
        printf("%d\n", n-1);
    
    for(int i = n; i > 1; i--)
        printf("%d ", i);
    printf("1\n");
    
    if(temp == 3 || temp == 2)
    {
        printf("%d ", n);
        for(int i = n-2; i >= 1; i--)
            printf("%d ", i);
        printf("%d\n", n-1);
    }
    else
    {
        for(int i = n-1; i >= 1; i--)
            printf("%d ", i);
        printf("%d\n", n);
    }
}


int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here
    

    while(~scanf("%d", &n))
    {
        if(n == 1)
        {
            puts("1 1");
            puts("1");
            puts("1");
            continue;
        }
        
        else if(n == 3)
        {
            puts("0 2");
            puts("3 2 1");
            puts("1 2 3");
            continue;
        }

        else
        {
            ace();
        }
    }
    


    return 0;
}

