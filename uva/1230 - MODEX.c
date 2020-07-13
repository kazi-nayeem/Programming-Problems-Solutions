#include<stdio.h>

#define lli long long int

lli x, n;
lli bigmod(lli p);

int main()
{
    lli te, y;

    while(scanf("%lld", &te) == 1)
    {
        if(te == 0) return 0;
        while(te--)
        {
            scanf("%lld %lld %lld", &x, &y, &n);
            printf("%lld\n", bigmod(y));
        }
    }
    return 0;
}

lli bigmod(lli p)
{
    if(p == 0) return 1;

    lli ret;

    ret = bigmod(p/2);

    if( p % 2 == 1)
       return (ret * ret * (x % n)) % n;
    return (ret * ret) % n;
}
