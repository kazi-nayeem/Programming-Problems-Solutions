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

int flag[MX];
int prime[MX];
int pos;

void sieve()
{
    prime[0] = 2;
    pos = 1 ;
    for(ll i = 3; i < MX; i+=2)
    {
        if(flag[i]) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+= i*2)
            flag[j] = 1;
    }
    //for(int i = 0; i < 100; i++)
        //printf("%d\n", prime[i]);
}

int dp[MX];

int func(int n)
{
    if(n == 0) return 0;
    int & res = dp[n];
    if(res != -1) return res;
    res = 0;
    if(func(n-1) == 0) res = 1;
    for(int i = 0; prime[i] <= n; i++)
    {
        for(ll j = prime[i]; j <= n; j *= prime[i])
        {
            if(res == 1) break;
            if(func(n-j) == 0)
            {
                res = 1;
            }
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*memset(dp,-1,sizeof dp);
    sieve();
    for(int i = 0; i <= 100; i++)
        printf("%d %d\n", i, func(i));*/
    int te,ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int x;
        scanf("%d", &x);
        if(x%6 == 0)
            puts("Misha");
        else
            puts("Chef");
    }
    return 0;
}


