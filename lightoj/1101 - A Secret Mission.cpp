//C headers
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>

//C++ headers
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

#define MX 50005
#define INF 0
#define step 17

struct data{
    int u, v, w;
    bool operator < (const data & p) const
    {
        return w<p.w;
    }
};
struct data2{
    int v, w;
    data2(){}
    data2(int a, int b)
    {
        v = a;
        w = b;
    }
};

//MST
data arr[100005];
int disjoint_par[MX];
int disjoint_rank[MX];
//LCA
vector<data2> adj[MX];
data2 parent[MX][step+1];
int start[MX];
int finish[MX];
int T;

//MST Function
void MST(int node, int edge);
int find_parent(int u);
//LCA Function
void dfs(int u, int p, int dis);
bool IsAnchestor(int u, int v);
int lca_query(int u, int v);
inline int min(int a, int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int te, ti, node, edge, u, v, q;
    scanf("%d", &ti);
    for(int te = 1; te <= ti; te++)
    {
        scanf("%d %d", &node, &edge);
        for(int i = 0;i < edge; i++)
        {
            scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
        }
        MST(node,edge);
        T = 0;
        dfs(1,1,INF);
        scanf("%d", &q);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", min(lca_query(u,v),lca_query(v,u)));
        }
    }
    return 0;
}

void MST(int node, int edge)
{
    sort(arr,arr+edge);
    for(int i = 0; i <= node; i++)
    {
        adj[i].clear();
        disjoint_par[i] = i;
        disjoint_rank[i] = 1;
    }
    int u, v, w, n = 1;
    for(int i = 0; i < edge; i++)
    {
        u = find_parent(arr[i].u);
        v = find_parent(arr[i].v);
        if(u == v) continue;
        if(disjoint_rank[u]>disjoint_rank[v])
        {
            disjoint_rank[u]+=disjoint_rank[v];
            disjoint_par[v] = u;
        }
        else
        {
            disjoint_rank[v]+=disjoint_rank[u];
            disjoint_par[u] = v;
        }
        u = arr[i].u;
        v = arr[i].v;
        w = arr[i].w;
        adj[u].push_back(data2(v,w));
        adj[v].push_back(data2(u,w));
        //printf("%d\n", w);
        n++;
        if(n == node) break;
    }
    return;
}

int find_parent(int u)
{
    if(u == disjoint_par[u]) return u;
    return disjoint_par[u] = find_parent(disjoint_par[u]);
}

void dfs(int u, int p, int dis)
{
    start[u] = T++;
    parent[u][0].v = p;
    parent[u][0].w = dis;
    for(int i = 0; i < step; i++)
    {
        parent[u][i+1].v = parent[parent[u][i].v][i].v;
        parent[u][i+1].w = min(parent[u][i].w,parent[parent[u][i].v][i].w);
    }
    int v, sz = adj[u].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[u][i].v;
        if(v == p) continue;
        dfs(v,u,adj[u][i].w);
    }
    finish[u] = T++;
}
bool IsAnchestor(int u, int v)
{
    if(start[u] <= start[v] && finish[u] >= finish[v]) return true;
    return false;
}
int lca_query(int u, int v)
{
    if(IsAnchestor(u,v)) return INF;
    int res = INF, temp = u;
    for(int i = step; i>= 0; i--)
    {
        if(!IsAnchestor(parent[temp][i].v,v))
        {
            res = min(res, parent[temp][i].w);
            temp = parent[temp][i].v;
        }
    }
    res = min(res,parent[temp][0].w);
    return res;
}
