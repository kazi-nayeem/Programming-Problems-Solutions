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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int dp[MX][8], n;
ll a[MX];
ll b[MX], mk;

int func(int pos, int mask)
{
    if(pos == n+1)
    {
        if(mask == 1) return 1;
        return 0;
    }
    int & res = dp[pos][mask];
    if(res != -1) return res;
    res = 0;
    ll now = a[pos];
    if((mask & 1) == 0)
    {
        now += b[pos-1];
    }
    mask = mask>>1;
    for(int i = 0; i < 4; i++)
    {
        if(mask&i) continue;
        ll tem = now;
        if(i&1)
        {
            tem += b[pos];
        }
        if(i&2)
        {
            tem += b[pos+1];
        }
        if(tem != mk) continue;
        res = func(pos+1,mask|i);
        if(res == 1) return res;
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        ll to = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i]);
            to += b[i];
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            to += a[i];
        }
        mk = to/n;
        memset(dp,-1,sizeof dp);
        ll ans = -1;
        if(func(1,1))
            ans = mk;
        printf("%lld\n", ans);
    }
    return 0;
}


