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

int max_len[1001];

int find_max_len_method2(int *A, int N) {  
    memset(max_len, 0, sizeof(max_len));
    max_len[0] = 1;
    for(int i=1; i<N; i++) { // 依次考虑以A[1],...,A[N-1]结尾的子序列 
        max_len[i] = 1;
        for(int j=0; j<i; j++) {
            if(A[i] > A[j]) {
                max_len[i] = max_len[j]+1>max_len[i] ? (max_len[j]+1):max_len[i];
            }
        }
    }


    // for(int i = 0; i < N; i++)
    // {
        // cout << max_len[i] << endl;
    // }

    int result = 0;
    int res2 = 0;
    for(int i=0; i<N; i++)
    {
        if(max_len[i] >= result)
        {
            res2 = result;
            result = max_len[i];
            // if(res2 == 4)
            // {
                // DEB("i: ", i);
                // DEB("r1: ", result);
                // DEB("r2: ", res2);
            // }
        }
        else if(max_len[i] < result)
        {
            if(max_len[i] > res2)
            {
                res2 = max_len[i];
            }
        }
    }
    // DEB("r1:",result);
    // DEB("r2:",res2);
    return res2;
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    scanf("%d", &t);
    int n;
    int a[1001];
    int res;

    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        res = find_max_len_method2(a, n);
        printf("%d\n", res);
    }
    return 0;
}

