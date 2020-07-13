#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

#define ll long long int

ll  gcd(ll  a, ll  b)
{
    if(b == 0) return a;
    if(a%b == 0) return b;
    return gcd(b,a%b);
}

int  main()
{
    ll  te, ti, ax, bx, ay, by;
    scanf("%lld", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld %lld %lld", &ax, &ay, &bx, &by);
        printf("Case %lld: %lld\n", te, 1+gcd(abs(ax-bx),abs(ay-by)));
    }
    return 0;
}
