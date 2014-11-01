#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define INF 0xffffff
#define ll long long int
#define MEM(a) memset(a, 0, sizeof(a))
#define MEMM(a) memset(b, -1, sizeof(b))

#ifdef ONLINE_JUDGE
#define FOI(file) 0
#define FOW(file) 0
#else
#define FOI(file) freopen(file,"r",stdin);
#define FOW(file) freopen(file,"w",stdout);
#endif

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int t;
    scanf("%d", &t);
    int i, k, j; 
    int n;
    double sum;
    double temp;
    for(j = 1; j <= t; j++)
    {
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i < n;i ++)
        {
            scanf("%lf", &temp);
            sum += temp;
        }
        for(i = 0; i < n; i++)
        {
            scanf("%d", &k);
        }
        
        printf("Case #%d: ",j);
        printf("%.6f\n", (n+1)/sum);
    }
    return 0;
}

