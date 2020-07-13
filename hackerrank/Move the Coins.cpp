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

const ll mod = 1000000007ll;

int start[MX];
int finis[MX];
int even[MX];
int odd[MX];
int dist[MX];

int T = 1;
vector<int> adj[MX];
int value[MX];

void dfs(int u, int p, int dep)
{
    start[u] = T++;
    dist[u] = dep;
    even[u] = value[u];
    odd[u] = 0;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u,dep+1);
        even[u] ^= odd[v];
        odd[u] ^= even[v];
    }
    finis[u] = T++;
}

bool isChild(int u, int v)
{
    return (start[u]<=start[v])&&(finis[u]>=start[v]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q, u, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &value[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1,0);
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &u, &v);
        if(isChild(u,v))
        {
            puts("INVALID");
        }
        else
        {
            if(dist[u]%2 == dist[v]%2)
            {
                int res = odd[1];
                res ^= odd[u];
                res ^= even[u];
                if(res == 0)
                    puts("NO");
                else
                    puts("YES");
            }
            else
            {
                if(odd[1] == 0)
                    puts("NO");
                else
                    puts("YES");
            }
        }
    }
    return 0;
}


