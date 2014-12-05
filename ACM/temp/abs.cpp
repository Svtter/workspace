#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define INF 0x3f3f3f3f  
#define N 100  
using namespace std;  
  
int f[N];  
int mi[N],ma[N];  
int cal(int n)  
{  
    int p=1;  
    for(int i=1;i<=n;i++)  
        p*=i;  
    return p;  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)==1)  
    {  
        for(int i=1;i<=n;i++)  
            f[i]=i;  
        int k=cal(n),Min=INF,Max=-INF;  
        for(int i=0;i<k;i++)  
        {  
            int b;  
            next_permutation(f+1,f+n+1);  
            for(int i=1;i<=n;i++)  
            {  
                if(i==1) b=f[i];  
                else b=abs(b-f[i]);  
            }  
            if(b<=Min)  
            {  
                Min=b;  
                for(int i=1;i<=n;i++)  
                    mi[i]=f[i];  
            }  
            if(b>=Max)  
            {  
                Max=b;  
                for(int i=1;i<=n;i++)  
                    ma[i]=f[i];  
            }  
        }  
        printf("%d %d\n",Min,Max);  
        for(int i=1;i<=n;i++)  
            printf("%d ",mi[i]);  
        puts("");  
        for(int i=1;i<=n;i++)  
            printf("%d ",ma[i]);  
        puts("");  
    }  
    return 0;  
}  
