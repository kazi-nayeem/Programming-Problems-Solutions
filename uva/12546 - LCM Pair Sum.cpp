#include<stdio.h>
#include<string.h>

#define ll long long

const ll mod = 1000000007LL;

ll bigmod(ll a, ll p)
{
    if(p == 0LL) return 1;
    if(p&1LL)
        return (a*bigmod(a,p-1))%mod;
    ll res = bigmod(a,p/2);
    return (res*res)%mod;
}

int main()
{
    ll sum, num, res;
    int te, ti, x, y, i, q;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        num = sum = 1;
        scanf("%d", &q);
        for(i = 0; i < q; i++)
        {
            scanf("%d%d", &x, &y);
            num *= bigmod(x,y);
            num %= mod;
            res = bigmod(x,y)-1+mod;
            res %= mod;
            res *= bigmod(x-1,mod-2);
            res %= mod;
            res += bigmod(x,y);
            res %= mod;
            sum = (sum*res)%mod;
        }
        printf("%lld\n", (sum+num)%mod);
    }
    return 0;
}
