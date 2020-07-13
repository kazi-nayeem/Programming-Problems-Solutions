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
#define step 19

int n, T;
int parent[MX][step+1];
int start[MX];
int finish[MX];
int child[MX];
int level[MX];
vector<int> adj[MX];

int dfs(int u, int p, int lev)
{
    int v;
    start[u] = T++;
    level[u] = lev;
    child[u] = 1;

    parent[u][0] = p;
    for(int i = 1; i <= step; i++)
        parent[u][i] = parent[parent[u][i-1]][i-1];

    int sz = adj[u].size();

    for(int i = 0; i < sz; i++)
    {
        v = adj[u][i];
        if(v != p)
            child[u] += dfs(v,u,lev+1);
    }
    finish[u] = T++;
    return child[u];
}

bool Is_Anchestor(int u, int v)
{
    if(start[u] <= start[v] && finish[u] >= finish[v]) return true;
    return false;
}

int LCA_Query(int u, int v)
{
    if(Is_Anchestor(u,v)) return u;
    if(Is_Anchestor(v,u)) return v;
    int w = -1, tem = u;
    for(int i = step; i>=0; i--)
        if(!Is_Anchestor(parent[tem][i],v))
            tem = parent[tem][i];
    w = parent[tem][0];
    return w;
}

int Kth_Query(int u, int k)
{
    //printf("%d %d\n", u, k);
    int w , tem = u;
    for(int i = step; i>=0; i--)
        if((k>>i)&1 == 1)
            tem = parent[tem][i];
    return tem;
}

int find_node(int u, int v, int lca, int w)
{
    int res;
    //printf("%d %d %d\n", level[lca], level[u], level[v]);
    if(level[u]-level[lca] == w) res = lca;
    else if(level[u]-level[lca] > w)
    {
        res = Kth_Query(u,w);
    }
    else
        res = Kth_Query(v,level[u]+level[v]-2*level[lca]-w);
    return res;
}

int main()
{
    int te, ti, u, v, w, res, q;

    //while(scanf("%d", &n) == 1)
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
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        T = 0;
        dfs(1,1,1);
        //for(int i = 1; i <= n; i++)
           // printf("child %d %d\n", i, child[i]);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &u, &v);
            int lca = LCA_Query(u,v);
            int dis = level[u]+level[v]-2*level[lca];
            //printf("lca %d dis %d\n", lca, dis);
            if(u == v)
                res = n;
            else if(dis % 2 == 0)
            {
                if(level[u] == level[v])
                {
                    int d1 = Kth_Query(u,(dis/2)-1);
                    int d2 = Kth_Query(v,(dis/2)-1);
                    res = n-child[d1]-child[d2];
                }
                else
                {
                    int nod1 = find_node(u,v,lca,(dis/2));
                    int nod2;
                    if(Is_Anchestor(nod1,u))
                        nod2 = find_node(u,v,lca,(dis/2)-1);
                    else
                        nod2 = find_node(v,u,lca,(dis/2)-1);
                    //printf("nod1 = %d nod2 = %d\n", nod1,nod2);
                    res = child[nod1] - child[nod2];
                }
            }
            else
                res = 0;

            printf("%d\n", res);
        }
        //printf("\n");
    }
    return 0;
}
