title: "[ACM]hdu5086-water"
date: 2014-11-08 11:55:24
categories:
- ACM
- hdu
- water
tags: water
---

题意
---

> 找出子序列和，因为数字过大，mod 1 000 000 007

<!--more-->

输入输出
---

```
2   //test case
1
2
3
1 2 3
```

```
2
20
```

分析
---

本来很简单的题目，但是因为读错了题意做了好久，还没AC

计算每个数字出现的次数，然后相加，记得不要溢出即可。

规律$C_i = (i+1) * (N - i)$ _i从0开始

按照如下方法分析:

假设1 2 3 4, 则1生成的序列为：
```
1 2 3 4
1 2 3
1 2
1
```
此时N为4， i为0, 1的次数为N, 2的次数为N-1, 3的次数为N-2， 4的次数为N-3.
对应2则为:
```
2 3 4
2 3
3
```
此时情况可以用表来表示

|i  |0  |1  |2  |3  |
|:--|:--|:--|:--|:--|
|1  |N  |N-1|N-2|N-3|
|2  |   |N-1|N-2|N-3|
|3  |   |N-1|N-2|N-3|

可以观察出规律




AC\_code
---
```cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;

// 大数，内存处理
#define INF 0x3f3f3f3f
#define ll long long 

// 定义常用工作变量
// #define MAXN 447010
#define MAXN 1000000007

ll tmp;
int main()
{

    int T, n;
    cin >> T;
    ll sum, ci;

    while(T--)
    {
        scanf("%d", &n);
        sum = 0;
        for(int i = 0;  i < n; i++)
        {
            scanf("%lld", &tmp);
            sum +=  tmp %MAXN * (i+1) %MAXN *(n-i) %MAXN ;
            sum = sum %MAXN;
        }
        printf("%lld\n", sum%MAXN);
    }

    return 0;
}

```

