#include<stdio.h>

int main()
{
    long int n;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%ld", &n);
        n = n*(n-1)/2;
        if(n&1)
            printf("Case %d: %ld/2\n", te, n);
        else
            printf("Case %d: %ld\n", te, n/2);
    }
    return 0;
}
