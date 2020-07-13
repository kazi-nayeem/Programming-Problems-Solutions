//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    ll num, sum;
    data() {}
    data(ll n, ll s)
    {
        num = n;
        sum = s;
    }
    data operator + (const data & p) const
    {
        return data((num+p.num)%mod,(sum+p.sum)%mod);
    }
};

data dp[65][2][2][2];
ll x, y, k;

data func2(int pos, int fx, int fy, int fk)
{
    //printf("%d %d %d %d\n", pos, fx, fy, fk);
    if(pos == -1)
    {
        //printf("ok");
        return data((fx == 0) && (fy == 0) && (fk == 0),0);
    }
    data & res = dp[pos][fx][fy][fk];
    //printf("res >>>%d %d %d %d %lld\n", pos, fx, fy, fk, res);
    if(res.num != -1ll) return res;
    //printf(">>>%d %d %d %d\n", pos, fx, fy, fk);
    res = data(0,0);
    int lx = (fx)? ((x>>pos)&1) : 1;
    int ly = (fy)? ((y>>pos)&1) : 1;
    int lk = (fk)? ((k>>pos)&1) : 1;
    //printf("%d %d %d %d\n", pos, lx, ly, lk);
    for(int i = 0; i <= lx; i++)
        for(int j = 0; j <= ly; j++)
        {
            int xorr = i^j;
            if(lk<xorr) continue;
            //printf("ok1");
            data tem = func2(pos-1,fx&&(i==lx),fy&&(j==ly),fk&&(xorr==lk));
            if(xorr)
            {
                ll sum = (1ll<<pos)%mod;
                sum *= tem.num;
                sum %= mod;
                tem = tem + data(0ll,sum);
            }
            res = res+tem;
        }
    return res;
}

ll func(ll xx, ll yy, ll kk)
{
    memset(dp,-1,sizeof (dp));
    x = xx;
    y = yy;
    k = kk;
    data res = func2(60,1,1,1);
    return (res.num+res.sum)%mod;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q;
    ll x1, y1, x2, y2, k;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &k);
        ll ans = func(x2,y2,k);
        ans += func(x1-1,y1-1,k);
        ans -= func(x2,y1-1,k);
        ans -= func(x1-1,y2,k);
        ans %= mod;
        printf("%lld\n", (ans+mod)%mod);
    }
    return 0;
}

