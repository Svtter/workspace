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

int stack[10001];
int top;
int cur;
int n,m ;

void push(int i)
{
    if(top != -1 && stack[top] == i)
        return;
    stack[++top]= i;
}

void pop()
{
    if(top == -1)
        return;
    top--;
}

void play(int i)
{
    push(i);
    cur = i;
}

void pre()
{
    pop();
    if(top == -1)
    {
        cur = 1;
        push(cur);
    }
    else
        cur = stack[top];
}

void next()
{
    cur ++;
    if(cur > n)
        cur = n;
    push(cur);
}

void output()
{
    cout << endl;
    cout << "top: " << top << endl;
    for(int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    int t;
    int j;
    char op[10];
    RI(t);
    int num;
    while(t--)
    {
        RI(n); RI(m);
        top = -1;
        cur = 1;
        push(cur);
        for(j = 0;  j < m ; j++)
        {
            RS(op);
            if(strcmp(op, "PRE") == 0)
            {
                pre();
            }
            else if(strcmp(op, "PLAY") == 0)
            {
                RI(num);
                play(num);
            }
            else if(strcmp(op, "NEXT") == 0)
            {
                next();
            }
            
            // output();

            cout << cur << endl;
        }
    }
    return 0;
}

