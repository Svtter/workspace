    #include <iostream>  
    #include <stdio.h>  
    #include <string.h>  
    #include <math.h>  
    #include <algorithm>  
    #include <queue>  
    #include <stack>  
    #include <map>  
    using namespace std;  
    #define up(i,x,y) for(i=x;i<=y;i++)  
    #define up2(i,x,y) for(i=x;y;i++)  
    #define down(i,x,y) for(i=x;i>=y;i--)  
    #define down2(i,x,y) for(i=x;y;i--)  
    #define pi acos(-1.0)  
    #define ll long long  
    #define s(a) scanf("%d",&a)  
    #define mem(a,b) memset(a,b,sizeof(a))  
    #define ads(a) (a<0?-a:a)  
    #define w(a) while(a)  
      
    void print(int l,int r,int m)  
    {  
        int i=l,j=r;  
        w(i<=j)  
        {  
            if(i==j)  
            {  
                printf("%d ",i);  
                break;  
            }  
            else if(i+1>=j)  
            {  
                printf("%d %d ",i,j);  
                break;  
            }  
            else if(i+2>=j)  
            {  
                printf("%d %d %d ",i,j,i+1);  
                break;  
            }  
            printf("%d %d ",i,i+1);  
            i+=2;  
            printf("%d %d ",j,j-1);  
            j-=2;  
        }  
        printf("%d",m);  
    }  
      
    int main()  
    {  
        int n,sum,i,j;  
        w(~s(n))  
        {  
            sum=0;  
            up(i,1,n)  
            sum+=i;  
            printf("%d %d\n",sum%2,n-(sum-n)%2);  
            if(n%2)  
            {  
                print(2,n,1);  
                printf("\n");  
                print(1,n-1,n);  
                printf("\n");  
            }  
            else  
            {  
                print(3,n,2);  
                printf(" 1\n");  
                print(2,n-1,1);  
                printf(" %d\n",n);  
            }  
        }  
    }  
