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

ll dp[MX][2][2];
char str[MX];
int len;

ll func(int pos, int f1, int f2)
{
    //printf("%d %d %d\n", pos,f1, f2);
    if(len == pos)
    {
        if(f1 == 1 && f2 == 1) return 1;
        return 0;
    }
    ll & res = dp[pos][f1][f2];
    if(res != -1) return res;
    //printf("ok");
    res = 0;
    int low = 'A';
    if(f1 == 0)
        low = str[pos];
    int now = str[pos];
    for(int i = low; i <= 'Z'; i++)
    {
        if(i>now)
            res += func(pos+1,f1||(i>now),1);
        else if(i == now)
            res += func(pos+1,f1||(i>now),f2);
        else
            res += func(pos+1,f1||(i>now),0);
    }
    res %= mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(gets(str))
    {
        len = strlen(str);
        memset(dp,-1,sizeof dp);
        printf("%lld\n", func(0,0,0)%mod);
    }
    return 0;
}


