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

#define MX 600005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct data {
    ll a, in;
};

data tree[MX*4];

void update(int node, int b, int e, int i, int j, ll a, ll inc) {
    //printf("%d\n", node);
    if(b > j || e < i) return;
    if(i <= b && e <= j) {
        tree[node].in += inc;
        tree[node].a += a+(b-i)*inc;
        return;
    }

    int mid = (b+e)/2;
    int lef = node<<1;
    int rig = lef+1;
    if(tree[node].a != 0 || tree[node].in != 0) {
        update(lef,b,mid,b,e,tree[node].a,tree[node].in);
        update(rig,mid+1,e,b,e,tree[node].a,tree[node].in);
        tree[node].a = 0;
        tree[node].in = 0;
    }
    update(lef,b,mid,i,j,a,inc);
    update(rig,mid+1,e,i,j,a,inc);
}

ll query(int node, int b, int e, int i) {
    if(b>i || e < i) return 0;
    if(i == b && e == i) {
        return tree[node].a;
    }
    int mid = (b+e)/2;
    int lef = node<<1;
    int rig = lef+1;
    if(tree[node].a != 0 || tree[node].in != 0) {
        update(lef,b,mid,b,e,tree[node].a,tree[node].in);
        update(rig,mid+1,e,b,e,tree[node].a,tree[node].in);
        tree[node].a = 0;
        tree[node].in = 0;
    }
    if(i>=b && i <= mid)
        return query(lef,b,mid,i);
    return query(rig,mid+1,e,i);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n, m;
    char ty, di;
    ll a, in;
    int st, en;
    scanf("%d", &ti);
    while(ti--) {
        scanf("%d %d", &m, &n);
        memset(tree,0,sizeof tree);
        for(int i = 0; i < m; i++) {
            scanf(" %c", &ty);
            if(ty == 'Q') {
                scanf("%d", &st);
                printf("%lld\n", query(1,1,n,st));
            } else {
                scanf(" %c %d %lld %lld %d", &di, &st, &a, &in, &en);
                //printf("%c %c %d %lld %lld %d\n", ty, di, st, a, in, en);
               // continue;
                if(di == 'E') {
                    update(1,1,n,st,st+en-1,a,in);
                } else {
                    update(1,1,n,st-en+1,st,a+(en-1)*in,-in);
                }
            }
        }
    }
    return 0;
}


