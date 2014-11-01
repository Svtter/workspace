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
#define e 2.718281828459045

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

    int t, n;
    int i, j;
    double a = pow(e, -0.5*2.0);
    double b = pow(e, -0.4*3.0);
    cout << 1-a << endl;
    cout << 1-b << endl;

    scanf("%d", &t);
    double k[1001];
    double c[1001];
    for(j = 1; j <=t ; j++)
    {
        scanf("%d", &n);
        for(i = 0; i < n ;i++)
            scanf("%lf", &k[i]);
        
        for(i = 0; i < n; i++)
            scanf("%lf", &c[i]);

    }
    return 0;
}

