#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000
int sum[MAX + 7];

void findsum()
{
    for(int i = 1; i <= MAX; ++i)
        for(int j = 1; j <= i; ++j)
            if(!(i % j)) sum[i] += j;
}

int main()
{
#ifdef DIPU
    freopen("11728.inp", "r", stdin);
#endif

    findsum();

    int n, cas = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        bool found = false;

        for(int i = n; i > 0; --i)
            if(sum[i] == n)
            {
                printf("Case %d: %d\n", cas++, i);
                found = true;
                break;
            }

        if(!found)
            printf("Case %d: -1\n", cas++);
    }

    return 0;
}
