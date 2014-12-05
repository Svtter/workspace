#include <stdio.h>


typedef struct
{
    int a, b;
}test;

test b;

int main(int argc, const char *argv[])
{
    b.a = 1;
    b.b = 2;
    printf("%d %d\n", b.a, b.b);
    
    return 0;
}
