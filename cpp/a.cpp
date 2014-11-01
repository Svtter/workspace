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

bool vis[5][11];

struct sta
{
    bool meat;
    bool veg;
    bool rice;
    int num;
    int m1, m2;
    int v1, v2;
    int r1, r2;

    sta(bool _meat, bool _veg, bool _rice, int _num)
    {
        meat= _meat;
        veg = _veg;
        rice = _rice;
        num = _num;
        m1 = m2 = v1 = v2 = r1 = r2 = 0;
    }
    sta() {}
};

queue <sta> que;

int minn, maxn;
int pri[5][11];
int num[5];

int BFS()
{
    memset(vis, 0, sizeof(vis));
    
    int sum = 0;
    sta root(0, 0, 0, 0);
    sta cur, temp;
    que.push(root);

    while(!que.empty())
    {
        cur = que.front();
        que.pop();

        if(!cur.meat)
        {
            for(int i = 0; i < num[3]; i++)
            {
                temp = cur;
                temp.num += pri[3][i];
                temp.m1 = i;
                temp.meat = true;
                que.push(temp);
                for(int j = 0; j < num[3]; j++)
                {
                    if(temp.m1 != j)
                    {
                        temp.m2 = j;
                        temp.num += pri[3][j];
                        que.push(temp);
                    }
                }
            }
        }
        if(cur.meat && !cur.veg)
        {
            for(int i = 0; i < num[4]; i++)
            {
                temp = cur;
                temp.num += pri[4][i];
                temp.v1 = i;
                temp.veg = true;
                que.push(temp);
                for(int j = 0; j < num[4]; j++)
                {
                    if(temp.v1 != j)
                    {
                        temp.v2 = j;
                        temp.num += pri[4][j];
                        que.push(temp);
                    }
                }
            }
        }
        if(cur.meat && cur.veg && !cur.rice)
        {
            for(int i = 0; i < num[1]; i++)
            {
                temp = cur;
                temp.num += pri[1][i];
                temp.r1 = i;
                for(int j = 0; j < num[0]; j++)
                {
                    temp.r2 = j;
                    temp.num += pri[0][j];
                    temp.rice = 1;
                    que.push(temp);
                }
            }

            for(int i = 0; i < num[2]; i++)
            {
                temp = root;
                temp.num += pri[2][i];
                temp.rice = 1;
                temp.r1 = i;
                temp.r2 = -1;
                que.push(temp);
            }
        }

        if(cur.meat && cur.veg && cur.rice)
        {
            if(cur.num >= minn && cur.num <= maxn)
            {
                printf("CUR: %d %d %d %d %d %d %d\n",
                        cur.m1, cur.m2, cur.v1, cur.v2, cur.r1, cur.r2, cur.num);
                sum++;
            }
        }
    }
    return sum;
}

    
void output()
{
    for(int i = 0; i < 5; i++)
    {
        cout << num[i] << ' ';
    }
    cout << endl;

    
}

int main()
{
    FOI("input");
    //FOW("output");
    //write your programme here
    

    int t;
    int i, j;
    RI(t);
    while(t--)
    {
        for(i = 0; i < 5; i++)
        {
            RI(num[i]);
        }

        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < num[i]; j++)
            {
                RI(pri[i][j]);
            }
        }

        output();

        scanf("%d%d", &minn, &maxn);
        
        cout << BFS() << endl;
    }
    return 0;
}

