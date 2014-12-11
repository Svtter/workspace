#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXN 5000 + 10
char buf[MAXN], s[MAXN];
int p[MAXN];

// fgets 读取一行，遇到\n停止
int main(int argc, const char *argv[])
{
    int n, m = 0, max = 0, x, y;
    int i, j, k;
    // 使用fgets获取信息
    // stdin标准输入流
    // C语言中的gets存在漏洞
    fgets(buf, sizeof(buf), stdin);
    n = strlen(buf);
    // 忽略符号，全部转换成大写
    for(i = 0; i < n; i++)
        if(isalpha(buf[i])) s[m++] = toupper(buf[i]);
    n = strlen(buf);
    for(i = 0; i < n; i++)
    {
        for(j = 0; i + j < n && j <= i; j++)
        {

        }
        
        for(j = 0; i + j + 1 < n && j <= i; j++)
        {

        }
    }

    return 0;
}
