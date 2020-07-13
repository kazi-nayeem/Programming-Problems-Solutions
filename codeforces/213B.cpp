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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll ncr[MX][MX];
int arr[MX];
ll dp[MX][MX];

ll func(int n, int pos)
{
    if(pos == 10)
    {
        if(n == 0) return 1;
        return 0;
    }
    ll & res = dp[n][pos];
    if(res != -1) return res;
    res = 0;
    if(pos > 0)
    {
        for(int i = arr[pos]; i <= n; i++)
        {
            res += (func(n-i,pos+1)*ncr[n][i])%mod;
        }
    }
    else
    {
        for(int i = arr[pos]; i < n; i++)
        {
            res += (func(n-i,pos+1)*ncr[n-1][i])%mod;
        }
    }
    res %= mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < MX; i++)
        ncr[i][0] = ncr[i][i] = 1;
    for(int i = 1; i < MX; i++)
    {
        for(int j = 1; j < i; j++)
            ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%mod;
    }
    /*for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            printf("%3d ", ncr[i][j]);
        puts("");
    }*/
    memset(dp,-1,sizeof dp);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    ll res = 0;
    for(int i = 1; i <= n; i++)
    {
        res += func(i,0);
    }
    printf("%lld\n", res%mod);
    return 0;
}


