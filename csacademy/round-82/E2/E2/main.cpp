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
ll matrix[MX][MX];
int flag[MX];
int visi[MX];
int n, k;

struct data{
    ll u, w;
    data(ll u, ll w): u(u), w(w) { }
    bool operator < (const data & p) const
    {
        return w>p.w;
    }
};

ll dist[MX];

ll func()
{
    vector<pll> vc;
    for(ll i = 1; i <= n; i++)
    {
        vc.push_back(make_pair(cost[i]-connect[i], i));
        dist[i] = mod*mod;
        flag[i] = 0;
        visi[i] = 0;
    }
    sort(vc.begin(), vc.end());
    //printf("ok1");
    for(int i = 0; i < n; i++)
    {
        //printf("%lld %lld\n", vc[i].first, vc[i].second);
        if(i<k && vc[i].first<0)
        {
            flag[vc[i].second] = 1;
        }
    }
    //printf("ok2\n");
    priority_queue<data> qu;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i])
        {
            qu.push(data(i,0));
            dist[i] = 0;
        }
    }
    if(qu.empty())
    {
        int id = 1;
        for(int i = 1; i <= n; i++)
        {
            if(cost[i]<cost[id])
            {
                id = i;
            }
        }
        flag[id] = 1;
        qu.push(data(id,0));
        dist[id] = 0;
    }
    //printf("ok3\n");
    while (!qu.empty()) {
        ll u = qu.top().u;
        ll w = qu.top().w;
        qu.pop();
        visi[u] = 1;
        //printf("pp %lld %lld\n", u, w);
        if(dist[u]<w) continue;
        //printf("%lld\n", u);
        for(int i = 1; i <= n; i++)
        {
            if(i==u || visi[i]) continue;
            if(dist[i]<=matrix[u][i]) continue;
            //printf("->%lld %d\n", u, i);
            dist[i] = matrix[u][i];
            qu.push(data(i,dist[i]));
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        if(flag[i]) ans += cost[i];
        else ans += dist[i];
    return ans;
}

void calc()
{
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
            matrix[i][j] = x;
            if(i != j)
                connect[i] = min(x,connect[i]);
        }
    printf("%lld\n", func());
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

