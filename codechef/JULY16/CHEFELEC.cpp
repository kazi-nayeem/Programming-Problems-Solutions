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

const ll mod = 1000000000000007ll;

ll arr[MX];
char str[MX];

ll dp[MX][2];

ll func(int pos, int f)
{
    if(pos == 1)
    {
        if(f == 0 && str[1] == '0') return mod;
        return 0;
    }
    ll & res = dp[pos][f];
    if(res != -1) return res;
    res = mod;
    if(f == 1 || str[pos] == '1')
    {
        res = min(res,func(pos-1,0));
        res = min(res,func(pos-1,1)+arr[pos]-arr[pos-1]);
    }
    else
    {
        res = min(res,func(pos-1,0)+arr[pos]-arr[pos-1]);
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %s", &n, str+1);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("%lld\n", func(n,0));
    }
    return 0;
}


