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


int num[10001];
int list[10001];

void init()
{
    for(int i = 0; i <=200; i++)
    {
        num[i] = 10000 - (100-i)*(100-i);
    }
}

struct g
{
    int val;
    int num;
};

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int t;
    int n, temp;
    int i;
    init();
    cin >> t;
    int c;
    g gg[10001];
    g ma[10001];
    for(int j = 1; j <= t; j++)
    {
        MEM(list);
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            list[num[temp]]++;
        }

        c = 0;
        for(i = 0; i <= 10000; i++)
        {
            if(list[i] != 0)
            {
                gg[c].val = i;
                gg[c].num = list[i];
                // cout << i << " " << list[i] << endl;
                // cout << gg[c].val << " " << gg[c].num<< endl;
                c++;
            }
            if(c == n)
                break;
        }

        // for(i = 0; i < c; i++) {
            // cout << gg[i].val << " " << gg[i].num << endl;
        // }
                
        int cc = 0;
        int max = 0;
        for(i = 0; i < c;i ++)
        {
            // num 频率
            if(gg[i].num > max)
            {
                cc = 0;
                ma[cc].val = gg[i].val;
                ma[cc].num = gg[i].num;
                max = gg[i].num;
            }
            else if(gg[i].num == max)
            {
                cc++;
                ma[cc].val = gg[i].val;
                ma[cc].num = gg[i].num;
            }
            else
                continue;
        }

        printf("Case #%d:\n", j);
        // cout << cc << endl;

        if(cc == c-1 && cc != 0)
        {
            puts("Bad Mushroom");
            continue;
        }
        else 
        {
            if(cc == 0)
                printf("%d\n", ma[0].val);
            else
            {
                for(i = 0; i <= cc; i++)
                {
                    if(i != cc )
                        printf("%d ", ma[i].val);
                    else
                        printf("%d\n", ma[i].val);
                }
            }
        }
    }
    return 0;
}

