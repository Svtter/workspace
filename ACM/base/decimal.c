#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    while(~scanf("%d %d %d", &a, &b, &c))
    {
        printf("%.*lf", c, a/(double)b);
    }
    return 0;
}
