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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];
int deg[MX];
int visi[MX];

bool bfs(int n) {
    queue<int> qu;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) continue;
        qu.push(i);
        break;
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        visi[u] = 1;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(visi[v]) continue;
            visi[v] = 1;
            qu.push(v);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(visi[i] == 0 && deg[i] > 0) return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, lop;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        if(v != u)
            adj[v].push_back(u);
        else lop++;
        deg[u]++;
        if(v != u)
            deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    if(!bfs(n)) {
        puts("0");
        return 0;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            //int pos = upper_bound(adj[v].begin(), adj[v].end(), i) - adj[v].begin();
            // printf("%d %d %d\n", i, v, pos);
            ans += adj[v].end() - upper_bound(adj[v].begin(), adj[v].end(), i);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}


