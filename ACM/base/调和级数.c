#include <stdio.h>
#include <math.h>

double calharmony(int a)
{
    double sum = 0;
    int i; 
    for(i = 1; i <= a; i++)
    {
        sum += 1/(double)i;
    }
    return sum;
}
        

int main()
{
    int a;
    while(~scanf("%d", &a))
    {
        printf("%.3lf\n", calharmony(a));
    }
    return 0;
}
        
