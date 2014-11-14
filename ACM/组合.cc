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
    node(node *_pre)
    {
        pre = _pre;
    }
    node(){}
    ~node()
    {
    }
};

// set nothing = -1
void printA(node *root)
{
    node *work = root;
    while(work->val != -1 && work->next != NULL)
    {
        work = work->next;
        printf("%d ", work->val);
    }
}

void buildList(node *root)
{
    node *p = root;
    int len = LEN;
    while(p != NULL && len != 0)
    {
        len --;
        p->val = -1;
        p->next = new node();
        p = p->next;
    }
}

void assemble(int cur, node *pre)
{
    int i, j;
    if(cur == LEN)
        return;
    for(i = 0; i < LEN; i++)
    {
        assemble(i+1, pre);
    }
}

int main()
{
    node *root;
    root = new node();
    
    return 0;
}
