/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified:	2014-09-20 12:02
#
# Filename:		A.cpp
#
# Description:
#
=============================================================================*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

#define INF 0xffffff
#define lln long long

#ifdef ONLINE_JUDGE
#define FOI(file) 0
#define FOW(file) 0
#else
#define FOI(file) freopen(file,"r",stdin);
#define FOW(file) freopen(file,"w",stdout);
#endif

using namespace std;

int n;

struct node
{
    int a;
    node *next;
    node(int _a, node *_next)
    {
        a = _a;
        next = _next;
    }
};

bool a[1000000000];
bool b[1000000000];

void Insert(int a[], lln t)
{
    int temp = 1;
    while(a[temp] != -1)
    {
        if(t > a[temp])
        {
            temp = temp *2;
        }
        else
        {
            temp = temp *2+1;
        }
    }
    a[temp] = t;
}

bool search(int a[], lln t)
{
    int temp = 1;
    while(a[temp] != -1)
    {
        if(a[temp] < t)
        {
            temp = temp *2;
        }
        else if(a[temp] > t)
        {
            temp = temp * 2 +1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

lln powermod(lln a, lln b, lln c)
{
    lln ans = 1;
    a = a % c;
    while(b > 0)
    {
        if(b % 2)
            ans = (ans * a) % c;
        b /=2 ;
        a = (a * a) % c;
    }
    return ans;
}



int main()
{
    //FOI("input");
    //FOW("output");
    //write your programme here

    lln m ,a ,b, s, t, p;
    lln i, j;
    lln ast, bst;
    lln temp1, temp2;
    lln k;
    lln n;
    bool cyclea, cycleb, find;
    while(scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &b, &s, &t, &p))
    {
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        // 代表两个循环
        cyclea = cycleb = false;
        find = false;

        if(!m && !a && !b && !s && !t && !p)
            break;
        bst = powermod(b, s, p);
        B[1] = bst;
        ast = m % p;
        A[1] = bst;

        temp1 = bst;
        temp2 = ast;
        i = s;
        k = 0;
        n = -1;
        while(1)
        {
            i++;
            temp1 = (temp1 * b) % p;
            if(temp1 == ast || search(B, temp1))
            {
                cyclea = true;
                break;
            }
            else
                Insert(B, temp1);
            if(i == s)
            {
                cyclea = true;
                break;
            }
            if(search(A, temp1))
            {
                find = true;
                break;
            }

            k++;
            temp2 = (temp2 * a) % p;
            if(temp2 == bst || search(A, temp2))
            {
                cycleb = 1;
                break;
            }
            else
                Insert(A, temp2);
            if(search(B, temp2))
            {
                find = true;
                n = k;
                break;
            }
        }
        if(n != -1)
        {
            cout << n << endl;
            continue;
        }
        while(!cyclea && !find)
        {
            i++;
            temp1 = (temp1 * b) % p;
            if(temp1 == ast || search(B, temp1))
            {
                cyclea = true;
                break;
            }
            else
                Insert(B, temp1);
            if(i == s)
            {
                cyclea = true;
                break;
            }
            if(search(A, temp1))
            {
                find = true;
                break;
            }
        }
        while(!cycleb && !find)
        {
            k++;
            temp2 = (temp2 * a) % p;
            if(temp2 == bst || search(A, temp2))
            {
                cycleb = 1;
                break;
            }
            else
                Insert(A, temp2);
            if(search(B, temp2))
            {
                find = true;
                n = k;
                break;
            }
        }
        if(cycleb && cyclea && !find)
            puts("impossible");
        else if(n == -1)
        {
            int temp;
            temp = m;
            j = 0;
            if(temp == temp1)
                n = j;
            while(j <= k)
            {
                j++;
                temp = (temp *a) % p;
                if(temp == temp1)
                {
                    n = j;
                    break;
                }
            }
            cout << n << endl;
        }
        else
        {
            cout << n << endl;
        }
    }
    return 0;
}

