#include<stdio.h>

int main()
{
    int t, test;
    int n, k, p;
    scanf("%d", &test);
    for(t = 0; t < test; ++t)
    {
        scanf("%d%d%d", &n, &k, &p);
        k = (k+p) % n;
        if(k)
            printf("Case %d: %d\n", t+1, k);
        else
            printf("Case %d: %d\n", t+1, n);
    }
    return 0;
}
