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

#define MX 5000505
#define inf 100000000

const ll mod = 1000000007ll;

ll cost[MX];
ll pre[MX];

void sieve()
{
    for(ll i = 2; i < MX; i++)
    {
        if(pre[i] != 0) continue;
        for(ll j = i; j < MX; j += i)
        {
            if(pre[j] == 0)
                pre[j] = i;
        }
    }
    for(int i = 2; i < MX; i++)
    {
        ll group = pre[i]*(pre[i]-1)/2;
        group %= mod;
        ll tot = i/pre[i];
        tot = (tot*group)%mod;
        tot += cost[i/pre[i]];
        cost[i] = tot;
        cost[i] %= mod;
    }
//    for(int i = 0; i < 100; i++)
//      printf("%d %lld\n", i, cost[i]);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    sieve();
    ll t;
    int l, r;
    scanf("%lld %d %d",&t, &l, &r);
    ll res = 0;
    ll p = 1;
    for(int i = l; i <= r; i++)
    {
        res += (cost[i]*p)%mod;
        //printf("%lld %lld\n", cost[i], p);
        res %= mod;
        p = (p*t)%mod;
    }
    printf("%lld\n", res);
    return 0;
}

