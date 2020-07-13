#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main()
{
    int te, ti;
    ll a, b, c, l, lcm, tm, res;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld %lld", &a, &b, &l);
        lcm = (a / __gcd(a,b)) * b;
        if(l%lcm != 0)
        {
            printf("Case %d: impossible\n", te);
            continue;
        }
        res = c = l/lcm;
        tm = __gcd(c,lcm);
        while(tm != 1)
        {
            res *= tm;
            lcm /= tm;
            tm = __gcd(c,lcm);
        }
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
