#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;

#define MX 100005
#define step 18

int n;
int parent[MX][step+1];
int arr[MX];
vector<int> adj[MX];

void dfs(int u, int p)
{
    int v, sz = adj[u].size();
    parent[u][0] = p;
    for(int i = 1; i <= step;i++)
        parent[u][i] = parent[parent[u][i-1]][i-1];
    for(int i = 0;i < sz; i++)
    {
        v = adj[u][i];
        dfs(v,u);
    }
    return;
}

int query(int u, int v)
{
    int w = u;
    for(int i = step; i >= 0; i--)
        {
            if(arr[parent[w][i]] >= v)
            w = parent[w][i];
        }
    return w;
}

int main()
{
    int te, ti, q, p, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &q);
        arr[0] = 1;
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &p, &arr[i]);
            adj[p].push_back(i);
        }
        dfs(0,0);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &p, &v);
            printf("%d\n", query(p,v));
        }
    }
    return 0;
}
