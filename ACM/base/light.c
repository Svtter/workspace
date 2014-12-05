#include <stdio.h>
#include <string.h>

#define bool int
//C语言没有bool
bool light[1010];

//C也没有引用
void trans(bool *a)
{
    if(*a)
        *a = 0;
    else
        *a = 1;
}

int main()
{
    int i, j;
    int n, k;
    while(~scanf("%d %d", &n, &k))
    {
        memset(light, 0, sizeof(light));
        for(i = 1; i <= k; i++)
        {
            j = i;
            while(j <= n)
            {
                trans(&light[j]);
                j += i;
            }
        }
        for(i = 1; i <= n; i++)
        {
            if(light[i])
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
