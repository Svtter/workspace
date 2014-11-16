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


double a, b, c, d, L, R; 
double res;

inline double cc(double x)
{
    return a * x * x *x + b * x *x + c*x;
}

double aa[4];
void cal()
{
    int temp;
    aa[0] = cc(L);
    aa[1] = cc(R);
    // 
    if(L <= 0 && R >= 0)
        aa[2] = cc(0);
    else
        aa[2] = aa[0];
    // a != 0
    if(a != 0)
    {
        temp = -b/(2*a);
        if(temp >= L && temp <= R)
            aa[3] = cc(temp);
        else
            aa[3] = aa[0];
    }
    else
    {
        if(0 >= L && 0 <= R)
            aa[3] = 0;
        else
            aa[3] = aa[0];
    }
    double max = aa[0];
    double min = aa[0];
    for(int i = 0; i < 4; i++)
    {
        if(aa[i] > max)
            max = aa[i]; 
        if(aa[i] < min)
            min = aa[i];
    }
    max = abs(max+d);
    min = abs(min+d);
    if(max > min)
        res = max;
    else
        res = min;
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here
    while(~scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &L, &R))
    {
        cal();
        printf("%.2lf\n", res);
    }
    return 0;
}

