#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

struct data{
    ll a, b;
    data() {}
    data(ll c, ll d)
    {
        a = c;
        b = d;
    }
};

data dp[26][152];

data add(data  tm1, data  tm2)
{
    ll lcm = tm1.b/__gcd(tm1.b,tm2.b)*tm2.b;
    ll sum = tm1.a*(lcm/tm1.b)+tm2.a*(lcm/tm2.b);
    ll gc = __gcd(lcm,sum);
    return data(sum/gc,lcm/gc);
}

data rec(int n, int x)
{
    if(n == 0)
    {
        if(x == 0) return data(1LL,1LL);
        return data(0LL,1LL);
    }
    if(x < 0) return data(0LL,1LL);
    data & res = dp[n][x];
    if(res.a != -1) return res;
    res = data(0LL,1LL);
    data tem;
    for(int i = 1; i <= 6; i++)
    {
        tem = rec(n-1,x-i);
        tem.b *= 6LL;
        res = add(res,tem);
    }
    return res;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int  n, x;

    while(scanf("%d %d", &n, &x) == 2)
    {
        if(n == 0 && x == 0) return 0;
        data res = data(0,1), tm;
        for(int i = x; i <= n*6; i++)
        {
            tm = rec(n,i);
            res = add(res,tm);
        }
        if(res.b != 1)
            printf("%lld/%lld\n", res.a, res.b);
        else
            printf("%lld\n", res.a);
    }
    return 0;
}
