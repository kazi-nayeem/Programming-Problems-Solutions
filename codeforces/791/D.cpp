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

struct data {
    ll arr[7];
    ll cost;
    ll child;
    data() {
        child = 0;
        cost = 0;
        memset(arr,0,sizeof arr);
    }
};

vector<int> adj[MX];
int k;
ll ans;

data func(int u, int par) {
    //printf("%d %d\n", u, par);
    data prev;
    prev.child = 1;
    prev.cost = 1;
    prev.arr[0] = 1;
    ll total = 0;
    for(int l = 0; l < adj[u].size(); l++) {
        int v = adj[u][l];
        if(v == par) continue;
        data tem = func(v,u);
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= k; j++) {
                if(i+j>k) continue;
                total -= (ll) prev.arr[i]*tem.arr[j];
            }
            prev.arr[i] += tem.arr[i];
        }
        total += prev.child*tem.cost+prev.cost*tem.child;
        //printf("-->%lld %d %d\n", total, u, v);
        prev.cost += tem.cost;
        prev.child += tem.child;
    }

    for(int i = k+1; i > 0; i--) {
        prev.arr[i]= prev.arr[i-1];
    }
    prev.arr[0] = 0;
    prev.cost += prev.arr[k+1];
    prev.arr[1] += prev.arr[k+1];
    prev.arr[k+1] = 0;
    //printf("------%d %lld tot %lld chi %d\n", u, prev.cost, total,prev.child);
    ans += total;
//    for(int i = 0; i <= k; i++)
//    {
//        printf("%d ", prev.arr[i]);
//    }
//    puts("");
    return prev;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    func(1,1);
    printf("%lld\n", ans);
    return 0;
}

