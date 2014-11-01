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

#define INF 0x3f3f3f3f
#define ll long long int
#define MEM(a) memset(a, 0, sizeof(a))
#define MEMM(a) memset(b, -1, sizeof(b))
#define DBG(x, n) cout << (x) << " " << (n) << endl;

#define SL(a) strlen(a)
#define RS(s) scanf("%s", (s))
#define PI(r) printf("%d\n", (r))
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

#ifdef ONLINE_JUDGE
#define FOI(file) 0
#define FOW(file) 0
#else
#define FOI(file) freopen(file,"r",stdin);
#define FOW(file) freopen(file,"w",stdout);
#endif

struct name
{
    char n[100];
};

int cmp(const name &a, const name &b)
{
    if(strcmp(a.n, b.n) > 0)
        return 0;
    else
        return 1;
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int t;
    int n, i;
    name na[10001];
    scanf("%d", &t);
    while(t--)
    {
        RI(n);
        for(i = 0; i < n; i++)
            scanf("%s", na[i].n);

        sort(na, na+n, cmp);
        
        for(i = 0; i < n; i++)
            printf("%s", na[i].n);
        cout << endl;
    }
    return 0;
}

