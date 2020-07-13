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

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;


const ll mod = 1000000007ll;

int res[MX];
int value[MX];
int arr[MX];
int par_value[MX], timer;
vector<int> adj[MX];
int start[MX];
int fini[MX];

void dfs(int u, int p, int dis)
{
    start[u] = timer++;
    par_value[u] = dis;
    value[u] = dis ^ arr[u];
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(p == v) continue;
        dfs(v,u,value[u]);
    }
    fini[u] = timer++;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, n, u, v;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            scanf("%d", &arr[i]);
        }
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        timer = 0;
        dfs(1,1,0);
        for(int i = 1; i <= n; i++)
        {
            res[i] = 0;
            printf("%d %d %d\n", i, value[i], par_value[i]);
            for(int j = 1; j <= n; j++)
            {
                if(start[i]<=start[j] && fini[i]>=fini[j])
                {
                    res[i] = max(res[i],par_value[i]|value[j]);
                    printf("%d %d\n", )
                }
            }
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}


