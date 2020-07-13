//
//  main.cpp
//  E
//
//  Created by Kazi Nayeem on 20/6/18.
//  Copyright © 2018 Kazi Nayeem. All rights reserved.
//

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

#define MX 2005
#define inf 100000000

//const double pi = acos(-1.0);
const ll mod = 1000000007ll;

ll cost[MX];
ll connect[MX];
int n, k, cs;
ll dp[MX][MX];
ll cas_dp[MX][MX];

ll func(int pos, int tk)
{
    if(tk>k) return mod*mod;
    if(pos == n+1)
    {
        if(tk>=1) return 0;
        return mod*mod;
    }
    ll & res = dp[pos][tk];
    if(cas_dp[pos][tk] == cs) return res;
    cas_dp[pos][tk] = cs;
    res = min(func(pos+1, tk+1)+cost[pos],func(pos+1, tk)+connect[pos]);
    return res;
}

void calc()
{
    cs++;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &cost[i]);
        connect[i] = mod;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            ll x;
            scanf("%lld", &x);
            if(i != j)
                connect[i] = min(x,connect[i]);
        }
    printf("%lld\n", func(1,0));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        calc();
    }
    return 0;
}

