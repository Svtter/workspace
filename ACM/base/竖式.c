#include <stdio.h>
#include <string.h>

char str[20];
char buf[90];

int main(int argc, const char *argv[])
{
    int abc, de;
    int x, y, z, i;
    int num;
    int get;
    while(~scanf("%s", str))
    {
        num = 0;

        for(abc = 100; abc < 999; abc++)
        {
            for(de = 10; de < 99; de++)
            {
                x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
                // 所有数字写入一个buf
                sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
                get = 1;
                // 检索
                for(i = 0; i < strlen(buf); i++)
                    if(!strchr(str, buf[i]))
                    {
                        get = 0;
                        break;
                    }
                if(get)
                {
                    num++;
                    printf("<%d>\n", num);
                    printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
                }
            }
        }
        printf("The number of solutions = %d\n", num);
    }

    return 0;
}
