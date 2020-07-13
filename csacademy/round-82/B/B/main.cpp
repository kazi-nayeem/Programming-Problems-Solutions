//
//  main.cpp
//  B
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
const ll mod = 1000000007ll;

ll mini[10];
ll price[10];
ll cost;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < 4; i++)
        scanf("%lld", &mini[i]);
    for(int i = 0; i < 4; i++)
        scanf("%lld", &price[i]);
    scanf("%lld", &cost);
    ll ans = 0;
    for(int i = 0; i < 4; i++)
    {
        ll now = 0, last = mod;
        for(int j = 0; j < 4; j++)
        {
            if(mini[j] == 0) continue;
            now += price[j];
            last = min(last,mini[j]);
        }
        if(last == mod || now <= cost) break;
        ans += last*cost;
        for(int j = 0; j < 4; j++)
        {
            if(mini[j]) mini[j]-=last;
        }
    }
    for(int i = 0; i < 4; i++)
        ans += price[i]*mini[i];
    printf("%lld\n", ans);
    return 0;
}


