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
int t, i, j, k;

#define MOD 1000000007

template <class Type>
int Perm(Type list[], int k, int m)
{
    if(k > m)//list[m] > list[0];
    {
        for(int i = 0; i <= m ; i++)
        {
            int sum = 0;
            sum ^= list[i];
            if(sum == 0)
                return 0;
        }
        return -1;
    }
    else
    {
        for(int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            if(Perm(list, k+1, m) == 0)
                return 0;
            swap(list[k], list[i]);
        }
    }
}

template <class Type>
void Perm(Type list[], int k, int m, int a)
{
    if(k > m)//list[m] > list[0];
    {
        for(int i = 0; i <= m ; i++)
            cout << list[i];
        cout << endl;
    }
    else
    {
        for(int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            Perm(list, k+1, m, 0);
            swap(list[k], list[i]);
        }
    }
}
int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int a[1001];
    scanf("%d", &t);
    int n;
    int res;

    int b[] = {1,6,7,9};
    Perm(b, 0, 3, 0);

    // while(t--)
    // {
        // scanf("%d", &n);
        // for(i = 0; i < n; i++)
        // {
            // scanf("%d", &a[i]);
        // }
        // if(n == 1)
        // {
            // puts("No");
            // continue;
        // }
        // res = Perm(a, 0, n);
        // if(res == 0)
            // puts("Yes");
        // else
            // puts("No");
    // }
    return 0;
}

