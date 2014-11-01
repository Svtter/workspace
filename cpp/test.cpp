#include <math.h>
#include <cstdio>
#include <iostream>
using namespace std;

float integral(float(*fun)(float x),float a,float b,int n)
{
    float s,h,y;
    int i;
    s=(fun(a)+fun(b))/2;
    h=(b-a)/n; /*积分步长*/
    for(i=1;i<n;i++)
        s=s+fun(a+i*h);
    y=s*h;
    return y;/*返回积分值*/
}

float f(float x)
{
    return(x*sin(x));  /*修改此处可以改变被积函数*/
}

// 计算数位算法[ESAY]
int count(int n)
{
    int a = 0;
    if(n / 1000 == 5)
        a++;
    n -= n/1000 * 1000;
    if(n / 100 == 5)
        a++;
    n -= n/100 * 100;
    if(n / 10 == 5)
        a++;
    n -= n/10 * 10;
    if(n == 5)
        a++;
    return a;

}

int main()
{
    // int a = 5555; cout << count(a);
    cout << 'a' << '\0' << 'b' << endl;
    return 0;
}
