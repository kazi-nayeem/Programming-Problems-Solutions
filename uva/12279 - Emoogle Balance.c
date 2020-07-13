#include<stdio.h>

int main()
{
    int m, n;
    int test= 0;
    int p, i;
    while(scanf("%d", &m) == 1)
    {
        if(m == 0) break;
        for(i = 0, p = 0; i < m; i++)
        {
            scanf("%d", &n);
            if(n == 0)
                p++;
        }
        printf("Case %d: %d\n", ++test, m - p - p);
    }
    return 0;
}
