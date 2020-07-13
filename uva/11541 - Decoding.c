#include<stdio.h>
#include<string.h>

int main()
{
    char ch;
    int n;
    int t, tcount;
    scanf(" %d", &t);
    getchar();
    for(tcount = 1; tcount<=t; ++tcount)
    {
        ch = getchar();
        printf("Case %d: ", tcount);
        while(ch != '\n')
        {
            scanf("%d", &n);
            while(n--)
                putchar(ch);
            ch = getchar();
        }
        putchar('\n');
    }
    return 0;
}
