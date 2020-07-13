#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int
#define MX 1000005

int mob[MX];

void mobius(void);

int main()
{
    mobius();

    lli a, b, res;
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &a, &b);
        if(a == 0 || b == 0)
        {
            if(a+b>0)
                printf("Case %d: 1\n", te);
            else
                printf("Case %d: 0\n", te);
            continue;
        }
        res = 0ll;
        lli M = min(a,b);
        for(lli i = 1; i <= M; i++)
            res += mob[i]*(a/i)*(b/i);
        printf("Case %d: %lld\n", te, res+2);
    }
    return 0;
}

void mobius(void)
{
    for(lli i = 2; i < MX; i++) mob[i] = 4;
    mob[1] = 1;

    for(lli i = 2; i < MX; i++)
        if(mob[i] == 4)
    {
        mob[i] = -1;
        for(lli j = i << 1; j < MX; j+=i)
            mob[j] = (mob[j] == 4)? -1:(mob[j]*(-1));
        lli ad = i*i;
        for(lli j = ad; j < MX; j += ad)
            mob[j] = 0;
    }
    return;
}
