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

#define MX 100005
#define inf 100000000


typedef long long ll;
typedef unsigned long long ull;
const ll mod =1000000007ll;

ll BigMod(ll B,ll P,ll M) {
    ll R=1%M;    /// (B^P)%M
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

ll value[MX];
vector<int> adj[MX];
int T;
int start[MX];
int en[MX];

ll tree[MX*4];

void update(int node, int beg, int en, int pos, ll val) {
    if(beg > pos || pos > en) return;
    if(beg == en && beg == pos) {
        tree[node] += val;
        tree[node] %= mod;
        return;
    }
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    update(left,beg,mid,pos,val);
    update(right,mid+1,en,pos,val);
    tree[node] = (tree[left]+tree[right])%mod;
}

ll query(int node, int beg, int en, int i, int j) {
    if(beg > j || i > en) return 0;
    if(i <= beg && en <= j)
        return tree[node];
    int mid = (beg+en)>>1;
    int left = node<<1;
    int right = left+1;
    ll ans = query(left,beg,mid,i,j);
    ans += query(right,mid+1,en,i,j);
    return ans%mod;
}

void dfs(int u, int p, ll w) {
    value[u] = w;
    start[u] = ++T;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u,(w*2ll)%mod);
    }
    en[u] = T;
}

int main() {
    int node, q, te, ti;
    scanf("%d", &ti);
    for(int te = 1; te <= ti; te++) {
        scanf("%d", &node);
        for(int i = 0; i <= node; i++) {
            adj[i].clear();
        }
        T = 0;
        memset(tree,0,sizeof tree);
        adj[1].push_back(1);
        for(int i = 1; i < node; i++) {
            int u,v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,1,1);
        printf("Case %d:\n", te);
        scanf("%d", &q);
        while(q--) {
            int u, t;
            scanf("%d %d", &t, &u);
            if(t == 1) {
                ll res = query(1,start[1],en[1],start[u],en[u]);
                /*printf("rang %d %d\n", start[u], en[u]);
                for(int i = start[u]; i <= en[u]; i++)
                    printf("i = %d %lld\n",i, query(1,start[1],en[1],i,i));*/
                res *= BigMod(value[u],mod-2,mod);
                res %= mod;
                if(start[u] != en[u])
                {
                    res *= BigMod(2,mod-2,mod);
                    res %= mod;
                }
                printf("%lld\n", res);
            } else {
                ll v;
                scanf("%lld", &v);
                v += mod;
                v %= mod;
                v *= value[u];
                v %= mod;
                update(1,start[1],en[1],start[u],v);
            }
        }
    }
    return 0;
}

