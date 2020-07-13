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

#define MX 200005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];
int dist1[MX];
int dist2[MX];
int child[MX];

void dfs(int u, int p)
{
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,u);
        child[u] = max(child[v]+1,child[u]);
    }
}

void bfs(int a, int dis[MX])
{
    queue<int> qu;
    for(int i = 0; i < MX; i++)
        dis[i] = -1;
    dis[a] = 0;
    qu.push(a);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dis[v] != -1) continue;
            dis[v] = dis[u]+1;
            qu.push(v);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,dist1);
    bfs(x,dist2);
    dfs(1,1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        //printf("%d %d\n", dist1[i], dist2[i]);
        if(dist1[i]>dist2[i])
        {
            ans = max(ans,dist1[i]+child[i]);
        }
    }
    //if(n == 2) ans = 1;
    printf("%d\n", 2*ans);
    return 0;
}


