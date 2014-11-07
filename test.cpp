/*************************************************************************
  > File Name: BestCode#16_1001.cpp
  > Author: Enumz
  > Mail: 369372123@qq.com
  > Created Time: 2014年11月01日 星期六 17时43分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <climits>

#define MAXN 447010
#define MOD 1000000007

using namespace std;
long long t;
int main()
{
    freopen("input", "r", stdin);
    int T;
    cin>>T;
    while (T--)
    {
        int N;
        long long sum=0;
        scanf("%d",&N);
        for (int i=1;i<=N;i++)
        {
            scanf("%lld",&t);
            sum+=t%MOD*i%MOD*(N-i+1)%MOD;
            sum=sum%MOD;
        }
        cout<<sum%MOD<<endl;
    }
    return 0;
}
