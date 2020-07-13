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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];

int mx, node;

void dfs(int u, int p, int d+1)
{
    if(mx > d){
        mx = d;
        node = u;
    }

    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v,p, d+1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx = -1;
    dfs(1,1,0);

    mx = -1;
    int st = node;
    dfs(node,node,0);
    return 0;
}


