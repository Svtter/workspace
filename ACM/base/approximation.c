#include <stdio.h>
#include <math.h>

double calappro(int n, int m)
{
    double sum = 0;
    int i;
    for(i = n; i <= m; i++)
        sum += 1/pow(i, 2);

    return sum;
}

int main()
{
    int m, n;

    while(~scanf("%d %d", &n, &m))
    {
        printf("%.5lf\n", calappro(n, m));
    }

    return 0;
}
