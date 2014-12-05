/**/
#include <stdio.h>
#include <math.h>

int main()
{
    double i;
    for(i = 0; i != 10; i += 0.1)
    {
        printf("%.1lf\n", i);
        if(floor (i+0.5) == 10)
            break;
    }
    return 0;
}
