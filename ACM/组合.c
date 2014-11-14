#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//assemble


#define LEN 4
int a[LEN] = {2, 3, 5, 7};

struct node
{
    int val;
    node *pre;
    node *next;
    node(){}
    node(node *_pre)
    {
        pre = _pre;
    }
    ~node()
    {
    }
};

void assemble(int cur, node *pre)
{
    int i, j;
    for(i = 0; i < LEN; i++)
    {
        assemble(i+1, pre);
    }
}

int main()
{
    
}
