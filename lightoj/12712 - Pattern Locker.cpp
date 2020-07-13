#include<cstdio>

#define ull unsigned long long int
#define mod 10000000000007llu

int main()
{
    ull n, l, h, res, tem;
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%llu %llu %llu", &n, &l, &h);
        n = n*n;
        tem = 1llu;
        for(ull i = n, j = l; j > 0; i--, j--)
            tem = (tem*i)%mod;
        res = tem;
        for(ull i = n-l, j = l; j < h; j++, i--)
        {
            tem = (tem*i)%mod;
            res = (res+tem)%mod;
        }
        printf("Case %d: %llu\n", te, res);
    }
    return 0;
}
