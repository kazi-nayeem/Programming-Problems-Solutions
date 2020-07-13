#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int division(int n);
int comp(int a, int b);

int main()
{
    int n, test = 0;

    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;

        if(test) putchar('\n');
        test = 1;
        if(division(n))
            printf("There are no solutions for %d.\n", n);
    }

    return 0;
}

int division(int n)
{
    int flag = 1;
    for(int  i = 12345 - (12345 % n) + n; i < 99999; i += n)
    {
        //printf("%d %d %d\n", i, n / i, n);
        if(comp(i, i / n))
        {
            printf("%05d / %05d = %d\n", i, i / n, n);
            flag = 0;
        }
    }
    return flag;
}
int comp(int a, int b)
{
    int flag[10];
    memset(flag, 0, sizeof flag);
    char str[10];

    sprintf(str, "%d", a);
    int len = strlen(str);

    if(len < 5) return 0;
    for(int i = 0; i < len; i++)
    {
        if(flag[str[i] - '0'] == 1) return 0;
        flag[str[i] - '0'] = 1;
    }

    sprintf(str, "%d", b);
    len = strlen(str);
    if(len < 4 || (len == 4 && flag[0] == 1)) return 0;

    if(len == 4) flag[0] = 1;
    for(int i = 0; i < len; i++)
    {
        if(flag[str[i] - '0'] == 1) return 0;
        flag[str[i] - '0'] = 1;
    }
    return 1;
}
