#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

char str[115][300], pri[10005];
int n, len, arr[10005];

void backtrack(int pos);

int main()
{
    //freopen("input.txt", "r", stdin);
    int test;
    for(int i = 0; i < 10; i++)
        sprintf(str[i], "%d", i);
    while(scanf("%d", &n) == 1)
    {
        getchar();
        n += 10;
        for(int i = 10; i < n; i++)
            gets(str[i]);
        scanf("%d", &test);
        getchar();
        while(test--)
        {
            printf("--\n");
            gets(pri);
            len = strlen(pri);
            backtrack(0);
        }
    }
    return 0;
}

void backtrack(int pos)
{
    if(pos >= len)
    {
        for(int i = 0; i < len; i++)
            printf("%s", str[arr[i]]);
        putchar('\n');
        return;
    }
    if(pri[pos] == '0')
    {
        for(int i = 0; i < 10; i++)
        {
            arr[pos] = i;
            backtrack(pos+1);
        }
        return;
    }
    for(int i = 10; i < n; i++)
    {
        arr[pos] = i;
        backtrack(pos+1);
    }
    return;
}
