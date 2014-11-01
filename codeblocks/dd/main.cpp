#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <time.h>
using namespace std;


#define N  1000000//12031230


typedef long long ll;
ll prime[N], nprime, factor[N], numfactor[N], ct;
bool isprime[N];
void makeprime() {// 打 1~N 的素数表
    int i, j, temp;
    nprime = 0;
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = 0;
    temp = sqrt(N + 0.0);
    for(i = 2;i <= temp; ++i) {
        if(isprime[i]) {
            ++nprime;
            prime[nprime] = i;
            for(j=i+i; j < N; j += i) {
                isprime[j] = 0;
            }
        }
    }
}


int main() {
    makeprime();
    return 0;
}
