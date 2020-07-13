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
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 300005
#define inf 100000000

const ll mod = 10000000007ll;

ll pre[MX];
vector<pii> vc1[MX];
vector<pii> vc2[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++)
    {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        int len = r-l+1;
        vc1[l].push_back(make_pair(len,c));
        vc2[r].push_back(make_pair(len,c));
    }
    for(int i = 0; i < MX; i++)
        pre[i] = mod;
    ll ans = mod;
    for(int i = 0; i < MX; i++)
    {
        for(int j = 0; j < vc1[i].size(); j++)
        {
            int len = vc1[i][j].first;
            if(len>=x) continue;
            ll cost = vc1[i][j].second+pre[x-len];
            ans = min(ans,cost);
        }
        for(int j = 0; j < vc2[i].size(); j++)
        {
            int len = vc2[i][j].first;
            ll cost = vc2[i][j].second;
            pre[len] = min(pre[len],cost);
        }
    }
    if(ans == mod) ans = -1;
    printf("%lld\n", ans);
    return 0;
}

