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

#define MX 10005
#define step 14

struct data
{
    int v, w;
    data() {}
    data(int a, int b)
    {
        v = a;
        w = b;
    }
};

int n, T;
int parent[MX][step+1];
int start[MX];
int finish[MX];
int distan[MX];
int level[MX];
vector<data> adj[MX];

void dfs(int u, int p, int dis, int lev)
{
    int v;
    start[u] = T++;
    level[u] = lev;
    distan[u] = dis;

    parent[u][0] = p;
    for(int i = 1; i <= step; i++)
        parent[u][i] = parent[parent[u][i-1]][i-1];

    int sz = adj[u].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[u][i].v;
        if(v != p)
            dfs(v,u,dis+adj[u][i].w,lev+1);
    }
    finish[u] = T++;
    return;
}

bool Is_Anchestor(int u, int v)
{
    if(start[u] <= finish[v] && finish[u] >= finish[v]) return true;
    return false;
}

int LCA_Query(int u, int v)
{
    if(Is_Anchestor(u,v)) return u;
    if(Is_Anchestor(v,u)) return v;
    int w = -1, tem = u;
    for(int i = step; i>=0;i--)
        if(!Is_Anchestor(parent[tem][i],v))
            tem = parent[tem][i];
    w = parent[tem][0];
    return w;
}

int Kth_Query(int u, int k)
{
    //printf("%d %d\n", u, k);
    int w , tem = u;
    for(int i = step; i>=0;i--)
        if((k>>i)&1 == 1)
            tem = parent[tem][i];
    return tem;
}

int main()
{
    int te, ti, u, v, w, res;
    char str[10];
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
        {
            adj[i].clear();
            for(int j = 0; j <= step; j++)
                parent[i][j] = 1;
        }
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(data(v,w));
            adj[v].push_back(data(u,w));
        }
        T = 0;
        dfs(1,1,0,1);
        while(scanf(" %s", str) == 1)
        {
            if(strcmp(str,"DONE") == 0) break;
            scanf("%d%d", &u, &v);
            int lca = LCA_Query(u,v);
            if(str[0] == 'D')
                res = distan[u]+distan[v]-2*distan[lca];
            else
            {
                scanf("%d", &w);
                w--;
                //printf("%d %d %d\n", level[lca], level[u], level[v]);
                if(level[u]-level[lca] == w) res = lca;
                else if(level[u]-level[lca] > w)
                {
                    res = Kth_Query(u,w);
                }
                else
                    res = Kth_Query(v,level[u]+level[v]-2*level[lca]-w);
            }
            printf("%d\n", res);
        }
        printf("\n");
    }
    return 0;
}
