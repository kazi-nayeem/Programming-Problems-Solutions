//
//  main.cpp
//  C
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

#define MX 100005
#define inf 100000000

//const double pi = acos(-1.0);
//const ll mod = 1000000007ll;

ll dist[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, s;
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &dist[i]);
    }
    deque<pair<ll, int>> qu;
    for(int i = 1, pos = s; i <= n; i++)
    {
        qu.push_back(make_pair(dist[pos], pos));
        pos++;
        if(pos>n) pos -= n;
    }
    ll ans = 0;
    while(qu.size()>1)
    {
        if(qu.front()<qu.back())
        {
            ll x = qu.front().first;
            ans += x;
            qu.pop_front();
            pair<ll, int> tem = qu.back();
            qu.pop_back();
            tem.first += x;
            qu.push_back(tem);
        }else{
            ll x = qu.back().first;
            ans += x;
            qu.pop_back();
            pair<ll, int> tem = qu.front();
            qu.pop_front();
            tem.first += x;
            qu.push_front(tem);
        }
    }
    printf("%lld\n", ans);
    return 0;
}


