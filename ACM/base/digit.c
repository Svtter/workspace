#include <stdio.h>
#include <math.h>


// 整数位数
int cal(int a)
{
    if(a == 0) return 0;
    return (int) log10( (double) a)+1;
}

int main()
{
    int a = 0;
    while(~scanf("%d", &a))
    {
        printf("%d\n", cal(a));
    }
    return 0;
}
    
