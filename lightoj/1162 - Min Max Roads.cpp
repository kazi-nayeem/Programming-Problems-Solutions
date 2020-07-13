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

#define MX 100010
#define step 18
#define INF 1000
#define pii pair<int,int>

struct data{int v, w;
    data(){}
    data(int a, int b)
    {
        v = a;
        w = b;
    }
};
struct data2{int p, mini, maxi;};
vector<data> adj[MX];
data2 parent[MX][step+1];
int start[MX], finish[MX], tim;

inline int fmin(int a, int b)
{
    if(a<b) return a;
    return b;
}

inline int fmax(int a, int b)
{
    if(a>b) return a;
    return b;
}

void dfs(int u, int p, int dis1, int dis2)
{
    start[u] = tim++;
    parent[u][0].p = p;
    parent[u][0].mini = dis1;
    parent[u][0].maxi = dis2;
    for(int i = 0; i < step; i++)
    {
        parent[u][i+1].p = parent[parent[u][i].p][i].p;
        parent[u][i+1].mini = fmin(parent[u][i].mini,parent[parent[u][i].p][i].mini);
        parent[u][i+1].maxi = fmax(parent[u][i].maxi,parent[parent[u][i].p][i].maxi);
    }
    int v, sz = adj[u].size(), w;
    for(int i = 0; i < sz; i++)
    {
        v = adj[u][i].v;
        w = adj[u][i].w;
        if(v == p) continue;
        dfs(v,u,w,w);
    }
    finish[u] = tim++;
}
bool IsAnchestor(int u, int v)
{
    if(start[u] <= start[v] && finish[u]>=finish[v]) return true;
    return false;
}

pii lca_query(int u, int v)
{
    if(IsAnchestor(u,v)) return make_pair(1000000,0);
    pii res = make_pair(1000000,0);
    int temp = u;
    for(int i = step; i>= 0;i--)
        if(!IsAnchestor(parent[temp][i].p,v))
    {
        res = make_pair(fmin(res.first,parent[temp][i].mini),fmax(res.second,parent[temp][i].maxi));
        temp = parent[temp][i].p;
    }
    return res = make_pair(fmin(res.first,parent[temp][0].mini),fmax(res.second,parent[temp][0].maxi));
}
int main()
{
    int te, ti, node, u, v, w, q;
    scanf("%d", &ti);
    for(int te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        for(int i = 0; i <= node; i++) adj[i].clear();
        for(int i = 1; i < node; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(data(v,w));
            adj[v].push_back(data(u,w));
        }
        dfs(1,1,1000000,0);
        pii res1, res2;
        printf("Case %d:\n", te);
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d %d", &u, &v);
            res1 = lca_query(u,v);
            res2 = lca_query(v,u);
            printf("%d %d\n", fmin(res1.first,res2.first),fmax(res1.second,res2.second));
        }
    }
    return 0;
}
