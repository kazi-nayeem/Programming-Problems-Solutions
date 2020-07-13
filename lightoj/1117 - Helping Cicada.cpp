#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int

lli res, n, m;
lli arr[16];

void backtrack(lli lcm, lli pos, lli tak);
lli LCM(lli a, lli b);
lli GCD(lli a, lli b);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld %lld", &n, &m);
        for(int i = 0; i < m; i++)
            scanf("%lld", arr+i);
        res = n;
        backtrack(1,0,0);
        printf("Case %d: %lld\n", te, n - res);
    }
    return 0;
}

void backtrack(lli lcm, lli pos, lli tak)
{
    if(pos == m)
    {
        if(tak&1)
            res += n/lcm;
        else
            res -= n/lcm;
        return;
    }
    backtrack(lcm,pos+1,tak);
    backtrack(LCM(lcm,arr[pos]),pos+1,tak+1);
    return;
}
inline lli LCM(lli a, lli b)
{
    return a*b/GCD(a,b);
}
lli GCD(lli a, lli b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}
