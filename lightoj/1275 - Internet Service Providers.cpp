#include<cstdio>
#include<cmath>
using namespace std;

#define ll long long

 ll n, c;

ll solve(ll t)
{
    return t*(c-(t*n));
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld%lld", &n, &c);
        if(n == 0) n = c+1;
        ll s = c/(n*2);
        if(solve(s) < solve(s+1))
            s++;
        printf("Case %d: %lld\n", te, s);
    }
    return 0;
}
