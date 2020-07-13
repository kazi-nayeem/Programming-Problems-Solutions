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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int dp[100][100][100][2];
vector<pii> adj[MX];

int func(int low, int hi, int k, int f) {
    if(k == 0) return 0;
    int & res = dp[low][hi][k][f];
    if(res != -1) return res;
    int u;
    res = mod;
    if(f) u = low;
    else u = hi;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if(low<v && v < hi) {
            //printf("%d %d %d\n", u, v, k);
            res = min(res,func(v,hi,k-1,1)+w);
            res = min(res,func(low,v,k-1,0)+w);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, u, v, w, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
        //adj[v].push_back(make_pair(u,w));
    }
    memset(dp,-1,sizeof dp);
    int ans = mod;
    for(int i = 1; i <= n; i++) {
        ans = min(ans,func(i,n+1,k-1,1));
        ans = min(ans,func(0,i,k-1,0));
    }
    if(ans == mod) ans = -1;
    printf("%d\n", ans);
    return 0;
}


