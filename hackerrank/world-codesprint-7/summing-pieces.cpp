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

#define MX 2000005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll pow2[MX];
ll dp[MX];
ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pow2[0] = 0;
    pow2[1] = 0;
    pow2[2] = 1;
    for(int i = 3; i < MX; i++)
    {
        pow2[i] = (pow2[i-1]*2)%mod;
    }
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for(int i = 1; i <= n+10; i++)
    {
        dp[i] = (i*pow2[n-i])%mod;
        dp[i] += dp[i-1];
        dp[i] %= mod;
        //printf("dp   %lld\n", dp[i]);
    }
    ll res = 0;
    ll tot = 0;
    for(int i = 2; i < n; i++)
    {
        //if((n+1) >= i*2)
        {
            tot += (dp[n-i]-dp[i-2])%mod;
            tot = (tot+mod)%mod;
            tot = (tot+mod)%mod;
        }

        //printf("%d %lld\n", i, tot);
        res += (arr[i]*tot)%mod;
        res %= mod;

        /*if((n+1) < i*2)
        {
            tot += dp[n-i-2]-dp[i-2];
            tot = (tot+mod)%mod;
        }*/
        res += (n*arr[i])%mod;
        res %= mod;
    }
    //printf("1----- %lld\n", res);
    res += (((arr[1]+arr[n])*n))%mod;
    res %= mod;
    //printf("2----- %lld\n", res);
    dp[0] = 0;
    for(int i = 1; i <= n+1; i++)
    {
        dp[i] = (i*pow2[n-i+1])%mod;
        dp[i] = (dp[i]+dp[i-1])%mod;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i<n)
            res += (arr[i]*((dp[n-1]-dp[i-1]+mod)%mod))%mod;
        res %= mod;

        if(i>1)
            res += (arr[i]*((dp[n-1]-dp[n-i]+mod)%mod))%mod;
        res %= mod;
    }
    printf("%lld\n", res);
    return 0;
}


