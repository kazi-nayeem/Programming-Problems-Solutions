#include<stdio.h>

int main()
{
    int r, n, test = 1;
    while(scanf(" %d %d", &r, &n) == 2)
    {
        if(n == 0 && r == 0) break;
        if(r%n)
            r /= n;
        else
            r = (r/n) - 1;
        if(r < 27)
            printf("Case %d: %d\n", test++, r);
        else
            printf("Case %d: impossible\n", test++);
    }
    return 0;
}
