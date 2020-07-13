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

#define MX 200005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];
int flag[MX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = true;
    for(int i = 1; i <= n && ans; i++) {
        if(flag[i] != 0) continue;
        flag[i] = 1;
        for(int j = 0; j < adj[i].size(); j++) {
            flag[adj[i][j]] = 1;
        }
        for(int j = 0; ans && j < adj[i].size(); j++) {
            int u = adj[i][j];
            if(adj[i].size() != adj[u].size()) ans = false;
            for(int k = 0; ans && k < adj[u].size(); k++) {
                int v = adj[u][k];
                //printf("%d %d\n", u, v);
                if(flag[v] != 1) {
                    ans = false;
                }
            }
        }
        for(int j = 0; j < adj[i].size(); j++) {
            flag[adj[i][j]] = 2;
        }
        flag[i] = 2;
    }
    if(ans)
        puts("YES");
    else
        puts("NO");
    return 0;
}

