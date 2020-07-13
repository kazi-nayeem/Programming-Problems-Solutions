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
#include<complex>
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

const double pi = acos(-1.0);
const ll mod = 998244353ll;

char str[100];
int len, k;
pll dp[1<<10][20][2][2];
ll power[100];

pll func(int mask, int pos, int zero, int flag)
{
    if (len == pos) {
        if (popc(mask)<=k && zero) return make_pair(0,1);
        return make_pair(0,0);
    }
    pll & res = dp[mask][pos][zero][flag];
    if (res.first != -1) return res;
    res = make_pair(0,0);
    int mx = (flag)?(str[pos]-'0'):9;
    for(int i = 0; i <= mx; i++) {
        pll tem = func(mask|((zero || (i>0))<<i),pos+1,zero || (i>0), flag && (i == mx));
        res.second += tem.second;
        res.first += tem.first;
        res.first += (((i*tem.second)%mod)*power[pos])%mod;
        res.first %= mod;
        res.second %= mod;
        //printf("->>%d %d %d %d %lld %lld i %d %lld %lld\n", mask, pos, zero, flag, res.first, res.second, i, tem.first, tem.second);
    }
    //printf("%d %d %d %d %lld %lld\n", mask, pos, zero, flag, res.first, res.second);
    return res;
}

ll sum(ll n)
{
    if (n  == 0) return 0;
    sprintf(str,"%lld", n);
    len = strlen(str);
    power[len-1] = 1;
    for(int i = len-2; i>=0; i--) {
        power[i] = (power[i+1]*10)%mod;
    }
    memset(dp,-1,sizeof dp);
    pll res = func(0,0,0,1);
    return res.first;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll l, r;
    scanf("%lld %lld %d", &l, &r, &k);
    ll ans = sum(r)-sum(l-1);
    ans %= mod;
    ans += mod;
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}

