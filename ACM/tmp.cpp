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
#define ll long long 

// 定义常用工作变量
// #define MAXN 447010
#define MAXN 1000000007

ll tmp;
int main()
{

    int T, n;
    cin >> T;
    ll sum, ci;

    while(T--)
    {
        scanf("%d", &n);
        sum = 0;
        for(int i = 0;  i < n; i++)
        {
            scanf("%lld", &tmp);
            sum +=  tmp %MAXN * (i+1) %MAXN *(n-i) %MAXN ;
            sum = sum %MAXN;
        }
        printf("%lld\n", sum%MAXN);
    }

    return 0;
}

