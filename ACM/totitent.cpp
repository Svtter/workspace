#include<iostream>
#include<cmath>
using namespace std;

int cal(int n)
{
    int temp=n;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0) n=n/i;
            temp=temp/i*(i-1);
        }
        if(n<i+1)
            break;
    }
    if(n>1)
        temp=temp/n*(n-1);
    return temp;
}

int main()
{
    int n;
    int sum = 0;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            sum += cal(i);
            cout << cal(i) << " ";
        }
        cout << endl;
        cout << sum << endl;
    }
    return 0;
}
