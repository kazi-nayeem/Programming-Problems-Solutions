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
ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    ll nxt, sum, combi;
    data() {}
    data(ll nxt, ll sum, ll combi) : nxt(nxt), sum(sum), combi(combi) {}
};

data dp[MX][2];
ll arr[MX];
int n;

data func(int pos, int flag)
{
    if(pos == n)
    {
        if(flag == 1)
        {
            return data(arr[pos],0,1);
        }
        return data(0,arr[pos],1);
    }
    data & res = dp[pos][flag];
    if(res.nxt != -1) return res;
    res = data(0,0,0);
    data tem1 = func(pos+1,0);
    data tem2 = func(pos+1,1);
    if(flag == 0)
    {
        res = tem1;
        res.sum += (tem1.combi*arr[pos])%mod;
        res.nxt = 0;
        res.combi += (tem2.combi)%mod;
        res.sum += (tem2.nxt*arr[pos])%mod;
        res.sum += tem2.sum;
    }
    else
    {
        res = tem1;
        res.nxt = (arr[pos]*tem1.combi)%mod;
        res.nxt += (tem2.nxt*arr[pos])%mod;
        res.combi += tem2.combi;
        res.sum += tem2.sum;
    }
    //printf("%d %d %lld %lld %lld\n", pos, flag, res.nxt, res.sum, res.combi);
    res.combi %= mod;
    res.nxt %= mod;
    res.sum %= mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {

        scanf("%d", &n);
        ll total = 0;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        memset(dp,-1,sizeof dp);
        printf("%lld\n", func(1,0).sum);
    }
    return 0;
}


