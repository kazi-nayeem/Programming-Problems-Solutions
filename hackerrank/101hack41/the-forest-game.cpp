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

#define MX 300005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct data
{
    ll node, child;
    int u;
    bool operator < (const data & p)const
    {
        return node+child>p.node+p.child;
    }
};

data total[MX];
ll arr[MX];
vector<int> adj[MX];

ll dfs(int u, int par)
{
    total[u].u = u;
    for(int i = 0; i < adj[u].size(); i++)
    {
        if(adj[u][i] == par) continue;
        total[u].child += dfs(adj[u][i],u);
    }
    return total[u].child+arr[u];
}

bool flag[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    ll tot = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        tot += arr[i];
        total[i].node = arr[i];
        total[i].u = i;
    }
    int u, v;
    for(int i = 2; i <= n; i++)
    {
        u = i;
        scanf("%d", &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    priority_queue<data> qu;
    qu.push(total[1]);
    ll res = 0;
    while(!qu.empty())
    {
        data tem = qu.top();
        qu.pop();
        for(int i = 0; i < adj[tem.u].size(); i++)
        {
            int v = adj[tem.u][i];
            if(flag[v]) continue;
            qu.push(total[v]);
        }
        flag[tem.u] = true;
        //printf("%d\n", tem.u);
        tot -= tem.node;
        res += tot;
    }
    printf("%lld\n", res);
    return 0;
}


