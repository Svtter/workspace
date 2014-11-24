#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define INF int(2e9)
#define LLINF (LL)(8e18)
#define LL long long
#define uLL unsigned long long
#define uint unsigned int
#define D double
#define LD long double
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define M(a) memset(a,0,sizeof(a));
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
LL Pow(LL a,LL b,LL Mod){LL ans=1;a%=Mod;for(;b;b>>=1) ans=b&1?(ans*a%Mod):ans,a=a*a%Mod;return ans;}
int pl,P[100000];
void initprime()
{
    rep(i,2,50000)
    {
        int flag=1;
        for(int j=2;j*j<=i;j++)
        if (i%j==0) {flag=0;break;}
        if (flag) P[++pl]=i;
    }
}
int n;
void work()
{
    if (n==1) {puts("0");return;}
    int ans=-1,nn=n;
    int p=sqrt(n);
    rep(i,1,pl)
    if (P[i]<=p)
    {
        if (n%P[i]==0) ans=max(ans,P[i]);
        while (n%P[i]==0) n/=P[i];
    }
    else break;
    ans=max(ans,n);
    printf("%d\n",nn/ans);
}
int main()
{
    initprime();
    while (scanf("%d",&n)!=EOF) work();
}
