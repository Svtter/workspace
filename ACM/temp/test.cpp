#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int a[30];
int cal(int n)
{
    int sum = 0;
    int i;
    for (i = 1; i <= n; i++) {
        /* code */
        sum = abs(sum - a[i]);
    }
    return sum;
}

void parray(int a[], int len)
{
    int i;
    for (i = 1; i <= len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void cp(int a[], int b[], int n)
{
    int i;
    for (i = 0; i <= n; i++) {
        a[i] = b[i];
    }
}

int main(int argc, const char *argv[])
{
    int i;
    for (i = 1; i <= 30; i++) {
        a[i] = i;
    }

    int n;
    int maxa[30], mina[30];
    while (~scanf("%d", &n)) {
        int max = -INF;
        int min = INF;
        if (n == 1) {
            cout << "1 1" << endl;
            cout << "1" << endl << "1" << endl;
            continue;
        }
        while (next_permutation(a+1, a+n+1)) {
            /* code */
            int temp = cal(n);
            if (temp >= max) {
                max = temp;
                cp(maxa, a, n);
            }
            if (temp <= min) {
                min = temp;
                cp(mina, a, n);
            }
        }

        cout << min << " " << max << endl;

        for (i = 1; i <= n; i++) {
            cout << mina[i] << " ";
        }
        cout << endl;
        
        for (i = 1; i <= n; i++) {
            cout << maxa[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
