#include<stdio.h>

int main()
{
    int te, ti, n, mod, res, digi;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &mod, &digi);
        res = digi % mod;
        for(n = 1; res != 0; n++)
            res = (res*10+digi)%mod;
        printf("Case %d: %d\n", te, n);
    }
    return 0;
}
