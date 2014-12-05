#include <stdio.h>
#include <string.h>

int a[10][10];

int main()
{
    int i, j;
    int x, y;
    int counter;
    int n;
    while(~scanf("%d", &n))
    {
        memset(a, 0, sizeof(a));
        y = n-1;
        x = 0;
        a[x][y] = counter = 1;
        while(counter < n*n)
        {
            while( x+1 < n && !a[x+1][y]) a[++x][y] = ++counter;
            while( y-1 >= 0 && !a[x][y-1]) a[x][--y]= ++counter;
            while( x-1 >= 0 && !a[x-1][y]) a[--x][y] = ++counter;
            while( y+1 < n && !a[x][y+1]) a[x][++y] = ++counter;
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                printf("%3d", a[i][j]);
            printf("\n");
        }
    }

    return 0;
}
