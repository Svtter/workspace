#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int main()
{
    int p1;
    p1 = fork();
    if(p1)
        puts("build child process.");
    else
        puts("build parent process.");
    return 0;
}
